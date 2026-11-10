# Codexion

Completed and evaluated at **42 Heilbronn**.

GitHub author: [LF-hub42](https://github.com/LF-hub42)

## Description

Codexion is a multithreaded C simulation of coders competing for a limited set
of USB dongles. Each coder runs in its own thread and sits at a round table,
where the dongles are shared circularly between neighbours.

A coder needs **two dongles at the same time** in order to compile. Once both
are acquired, the coder goes through the cycle:

```
compile -> debug -> refactor -> compile -> ...
```

The dongles are released as soon as compiling is finished, so debugging and
refactoring never block other coders. A separate monitor thread watches every
coder and detects burnout: a coder burns out if it has not started compiling
within `time_to_burnout` milliseconds. The simulation ends either when all
coders have reached the required number of compiles, or as soon as one coder
burns out.

Dongle access is granted by one of two scheduling policies, **FIFO** or
**EDF** (Earliest Deadline First). Each dongle keeps its waiting requests in a
custom **binary heap**, so the next request to be served can always be found at
the root.

## Instructions

Build the program:

```sh
make
```

Cleaning rules:

```sh
make clean
make fclean
make re
```

Run the program:

```sh
./codexion number_of_coders time_to_burnout time_to_compile time_to_debug \
time_to_refactor number_of_compiles_required dongle_cooldown fifo|edf
```

Example:

```sh
./codexion 3 800 200 100 100 2 10 edf
```

Three coders share three dongles. A coder burns out if it does not start
compiling within 800 ms. Compiling takes 200 ms, debugging and refactoring
100 ms each. The simulation stops once every coder has compiled twice. A
released dongle stays unavailable for 10 ms, and requests are ordered by
earliest deadline.

### Arguments

| Argument | Meaning |
| --- | --- |
| `number_of_coders` | Number of coders, and also the number of dongles. |
| `time_to_burnout` | If a coder has not started compiling within this time (in ms) since its last compile started, it burns out. |
| `time_to_compile` | Time (in ms) spent compiling, while holding two dongles. |
| `time_to_debug` | Time (in ms) spent debugging. |
| `time_to_refactor` | Time (in ms) spent refactoring. Afterwards the coder immediately tries to acquire dongles again. |
| `number_of_compiles_required` | Once every coder has compiled at least this many times, the simulation stops. |
| `dongle_cooldown` | After being released, a dongle stays unavailable for this time (in ms). |
| `scheduler` | Must be exactly `fifo` or `edf`. |

Input rules:

- The scheduler must be exactly `fifo` or `edf`.
- `dongle_cooldown` may be `0`, which means a released dongle can be reused
  immediately.
- All other numeric values must be positive integers.
- Invalid arguments are rejected and the program exits with an error.

Output follows the format `timestamp_in_ms X message`, where `X` is the coder
number and the timestamp is relative to the start of the simulation.

## Testing / Evaluation

The following commands provide a simple step-by-step check of the main project
requirements before an evaluation.

### 1. Build

```sh
make
```

The project should compile without warnings or errors and create the
`codexion` executable.

### 2. FIFO

```sh
./codexion 2 800 200 200 200 3 100 fifo
```

Both coders should repeatedly acquire two dongles and complete their
compile/debug/refactor cycles. The simulation should stop normally after both
coders reach the required number of compiles.

### 3. EDF

```sh
./codexion 2 800 200 200 200 3 100 edf
```

The same simulation is executed using Earliest Deadline First scheduling.
Requests with the earliest burnout deadline receive priority.

### 4. Completion after required compiles

```sh
./codexion 3 1000 100 100 100 2 0 fifo
```

The simulation should stop once all three coders have completed the required
two compiles.

### 5. Burnout

```sh
./codexion 2 200 300 100 100 3 0 fifo
```

The timings deliberately make successful scheduling difficult. A coder that
does not start compiling before its burnout deadline should be reported and
the simulation should stop.

### 6. Single coder

```sh
./codexion 1 400 100 100 100 2 0 fifo
```

With only one dongle, the coder cannot obtain the two dongles required for
compiling. The monitor should eventually report burnout and the program should
terminate cleanly.

### 7. Invalid scheduler

```sh
./codexion 2 800 200 200 200 3 100 invalid
```

The program should reject the scheduler and exit cleanly instead of crashing.

### 8. Invalid numeric argument

```sh
./codexion 0 800 200 200 200 3 100 fifo
```

The program should reject invalid numeric input.

### 9. Missing arguments

```sh
./codexion 2
```

The program should display its usage information and exit cleanly.

### 10. Valgrind

```sh
valgrind --leak-check=full --show-leak-kinds=all ./codexion 2 800 200 200 200 3 100 fifo
```

After the simulation finishes, Valgrind should report no memory leaks or
invalid memory accesses.

### 11. Helgrind

```sh
valgrind --tool=helgrind ./codexion 2 800 200 200 200 3 100 fifo
```

Helgrind can be used to check the synchronization code for data races and
threading errors.

### 12. Norminette

```sh
norminette
```

All submitted C source and header files should pass the 42 Norm.

### 13. Clean

```sh
make clean
```

Object files should be removed while the executable remains.

### 14. Full clean

```sh
make fclean
```

Object files and the `codexion` executable should be removed.

### 15. Rebuild

```sh
make re
```

The project should be rebuilt successfully from a clean state.

## Scheduling

### FIFO

Every dongle keeps a heap of pending requests ordered by the arrival sequence
of that dongle. A coder is served once its own request sits at the root of the
heap, the dongle is not held, and the cooldown has expired.

The two dongles are acquired **sequentially**, one after the other — not
atomically. To make this safe, every coder always requests the two dongles in
the same consistent order, derived from their addresses. Because all threads
follow the same global order, no circular wait can form.

### EDF

The priority of a request is its burnout deadline:

```
deadline = last_compile_start + time_to_burnout
```

The earliest deadline is served first. EDF works differently from FIFO in one
important way: a request is registered in **both** required dongle queues at
once, and the two dongles are then taken **together**, in a single step, only
when both are actually available.

While waiting for its pair, a coder holds **no** dongle at all. This is what
removes the hold-and-wait situation and the priority inversion that occurs
when an urgent coder occupies one dongle while blocking on the second one.
Because the request is visible in both queues the whole time, an urgent coder
never becomes invisible to the dongle it is still waiting for.

### Equal deadlines

The requirement is that the coder with the **earliest** burnout deadline is
served first, and that rule is always respected.

No arrival-order tie-break is defined for requests that share exactly the same
deadline. During pair acquisition a request therefore only yields to a
*strictly earlier* deadline. Coders with identical deadlines may proceed in
the order determined by synchronization and lock timing. Arrival order is used
as the ordering criterion in `fifo` mode.

## Blocking Cases Handled

### Deadlock prevention

- In FIFO mode the two dongles are acquired sequentially, but always in the
  same consistent order for every coder, so a circular wait cannot form.
- In EDF mode a coder waits without holding either dongle and acquires the
  required pair together, which removes hold-and-wait on that path.
- If a coder gives up because the simulation was stopped, it removes its
  pending requests from the queues and wakes the other waiters.

These measures target the circular-wait and hold-and-wait conditions on the
acquisition paths; mutual exclusion on a dongle is of course still required by
the problem itself.

### Starvation and scheduling

- FIFO serves requests in arrival order per dongle.
- EDF gives priority to the earliest burnout deadline, so the coder closest to
  burning out is served first.
- Registering an EDF request in both queues keeps an urgent coder visible to
  both dongles while it waits for its pair.

This does not guarantee that burnout can be avoided for every possible
combination of parameters — with tight timings there may simply not be enough
dongle time for all coders. What the scheduler guarantees is the ordering
policy, not feasibility.

### Dongle cooldown

- When a dongle is released, its availability timestamp is pushed
  `dongle_cooldown` milliseconds into the future, and it cannot be granted
  before that point.
- Waiters use timed condition waits that expire exactly at the cooldown
  deadline, so the dongle is picked up as soon as it becomes available again.
- A cooldown of `0` means the dongle can be reused immediately.

### Precise burnout detection

- A dedicated monitor thread supervises all coders.
- It computes each coder's deadline as `last_compile_start + time_to_burnout`
  and determines the earliest one.
- It then performs a timed condition wait that expires exactly at that
  deadline, instead of polling.
- The completion check and the transition into the timed wait are both
  performed while holding `state_mutex`, so a state change signalled by a
  coder cannot be missed between the check and the wait.
- This keeps the burnout message well within the required 10 ms of the actual
  burnout.

### Log serialization

- All output goes through a single logging path protected by a log mutex, so
  two messages can never interleave.
- The timestamp is taken inside that serialized path, so printed timestamps
  stay in the same order as the lines themselves.
- Burnout logging and the stop flag are updated together under `state_mutex`,
  which guarantees that no further state message is printed after the burnout
  line.

### Single coder

- With one coder there is exactly one dongle, so the coder's left and right
  dongle are the same one.
- The coder takes that dongle but can never satisfy the requirement of two
  dongles simultaneously.
- It therefore waits until the simulation is stopped, and the monitor reports
  its burnout at the correct time. The dongle is released afterwards so that
  cleanup stays consistent.

## Thread Synchronization

The simulation runs one `pthread` per coder plus one monitor thread, all
created at start-up and joined at the end.

- **Dongle mutexes** — each dongle has its own mutex protecting its held flag,
  its cooldown timestamp, and its request queue.
- **Dongle condition variables** — a coder waiting for a dongle blocks on the
  dongle's condition variable instead of busy-looping. A release or a stop
  broadcasts to it.
- **Coder mutexes** — each coder has a mutex guarding its last compile time and
  its compile counter, which both the coder and the monitor read.
- **State mutex and condition variable** — shared simulation state, in
  particular the stop flag, is guarded by `state_mutex`. Coders broadcast on
  `state_cond` when they finish a compile; the monitor waits on it.
- **Timed condition waits** — waits are bounded by an absolute deadline, either
  a cooldown expiry or a burnout deadline, so threads wake up exactly when
  something is due rather than by polling.
- **Log mutex** — serializes all output.
- **Binary heaps** — every dongle owns a small binary heap of pending requests.
  The comparator implements the active policy, so the next request to serve is
  always the heap root. Requests can also be removed from the middle of the
  heap when a coder abandons its attempt.

## Technical Focus / What I Learned

This project was mostly about getting concurrency right rather than about
writing a lot of code. The main things I took away from it:

- Designing a program around several threads that share a limited resource.
- Using mutexes and condition variables properly, including the fact that a
  predicate has to be checked under the same mutex that the wait uses —
  otherwise a signal can be lost.
- Avoiding deadlocks in practice: consistent lock ordering, and avoiding
  hold-and-wait by taking both resources together.
- Implementing two scheduling policies on top of the same data structure and
  understanding how the priority rule changes the behaviour.
- Debugging race conditions, which are not reproducible on every run. Stress
  testing over many runs and tools like Valgrind, Helgrind and DRD were far
  more useful here than reading the code alone.
- Working with precise timing in milliseconds and keeping output ordered.
- Cleaning up threads, mutexes and heap allocations reliably, including on
  error paths.

## Resources

- The Codexion subject.
- POSIX threads documentation: `man 3 pthread_create`, `pthread_join`,
  `pthread_mutex_lock`, `pthread_cond_wait`, `pthread_cond_timedwait`,
  `pthread_cond_broadcast`.
- `man 2 gettimeofday`, `man 3 usleep` and `man 2 write` for timing and output.
- General reading on the dining philosophers problem and on classic deadlock
  conditions.
- Valgrind, Helgrind and DRD documentation for memory and thread-error
  checking.
- Discussions with peers at 42 while testing edge cases.

## AI Usage

The project was developed through independent work, research, and peer
learning. AI was used afterwards as a supporting tool for final review and
README preparation. The implementation and project logic were written and
understood by me.
