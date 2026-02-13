# 🍽️ The Dining Philosophers (Philo)

![Language](https://img.shields.io/badge/language-C-blue.svg)
![Concurrency](https://img.shields.io/badge/concurrency-pthreads-brightgreen.svg)
![Build](https://img.shields.io/badge/build-make-red.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

## Description

Philo is a C project that implements a classic synchronization problem in computer science: the Dining Philosophers problem. This simulation demonstrates various synchronization mechanisms using POSIX threads (pthreads) and mutexes to prevent deadlocks and race conditions, ensuring that no philosopher starves while dining. The project aims to provide a robust solution to manage shared resources in a multi-threaded environment.

## ✨ Features

*   **Concurrency Simulation**: Implements a multi-threaded simulation of the Dining Philosophers problem.
*   **POSIX Threads**: Utilizes `pthreads` for efficient parallel execution of philosopher routines.
*   **Mutex Synchronization**: Employs mutexes to control access to shared resources (forks and simulation state) and prevent race conditions.
*   **Configurable Parameters**: Allows users to define the number of philosophers and critical timing parameters (time to die, eat, and sleep).
*   **Starvation Prevention**: Designed to prevent any single philosopher from starving indefinitely.
*   **Death Monitoring**: Includes a separate control thread to monitor philosophers and detect starvation, printing a "died" message if a philosopher doesn't eat in time.
*   **Meal Limit Option**: Supports an optional parameter to end the simulation after each philosopher has eaten a specified number of times.
*   **Edge Case Handling**: Correctly handles the special case of a single philosopher.

## 📚 Tech Stack

*   **Language:** C
*   **Concurrency:** POSIX Threads (pthreads)
*   **Build System:** Make
*   **Standard Libraries:** `stdio.h`, `stdlib.h`, `unistd.h`, `sys/time.h`, `stdbool.h`

## 🚀 Installation

To get a local copy up and running, follow these simple steps:

1.  **Clone the repository:**
    ```bash
    git clone git@github.com:bsen0/philo.git
    ```
2.  **Navigate into the project directory:**
    ```bash
    cd philo
    ```
3.  **Compile the source code using Make:**
    ```bash
    make
    ```
    This will generate an executable named `philo` in the current directory.

## ▶️ Usage

The `philo` program runs a simulation of the dining philosophers problem. It requires 4 or 5 command-line arguments:

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

### Arguments:

*   `<number_of_philosophers>`: The total number of philosophers participating in the simulation. This also dictates the number of forks available.
*   `<time_to_die>`: The maximum time (in milliseconds) a philosopher can go without eating before they "die".
*   `<time_to_eat>`: The duration (in milliseconds) a philosopher spends eating.
*   `<time_to_sleep>`: The duration (in milliseconds) a philosopher spends sleeping.
*   `[number_of_times_each_philosopher_must_eat]` (optional): If provided, the simulation will terminate once every philosopher has eaten at least this many times. If omitted, the simulation continues until a philosopher dies.

### Example:

To simulate 5 philosophers, where a philosopher dies after 800ms of not eating, takes 200ms to eat, 200ms to sleep, and the simulation ends when each philosopher has eaten at least 7 times:

```bash
./philo 5 800 200 200 7
```

### Output:

The program will print messages indicating the actions of each philosopher in real-time. Each message includes a timestamp (in milliseconds relative to the start of the simulation), the philosopher's ID, and their current status:

```
<timestamp_in_ms> <philosopher_id> <status_message>
```

**Example output snippets:**

```
0 1 is thinking
50 1 has taken a fork
70 2 has taken a fork
100 1 is eating
300 1 is sleeping
800 3 died
```

## 🤝 Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## 📝 License

This project is typically developed as part of the 42 School curriculum. For explicit licensing details, please refer to the project's repository or contact the author. A common open-source license like MIT is often applied to such projects. Consider adding a `LICENSE` file for clarity.