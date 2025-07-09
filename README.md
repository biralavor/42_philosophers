# 42_philosophers

| ![philosopherse](https://github.com/user-attachments/assets/3a5e657f-80cf-4da6-accd-279d1fdc21da) | A classic multithread program <br> to learn how to avoid <br> `data racing` and `dead lock` issues | ![100sucess](https://github.com/biralavor/42_libft/assets/80487147/814c0fe9-cf93-4f9d-bd18-5d588a896ea4) |
| :-: | :-: | :-: |



## My take-aways about Philosophers project are:

## How to run:
Here is a few pre-setup possibilities. Note that all of them are adding the `args_to_test` variable as an argument to run `./philo`
- `make go` :: **Let's Go mode**
  - For checking how the threads are running, without changes.
- `make gdb` :: **GNU DeBugger mode**
  - For debugging propuses, with a lot of pre-setup executables, like `run`, breakpoint at `main`,  and `set args`.
- `make val` :: **Valgrind mode**
  - For checking memory leaks, this will calls valgridn with a lot of options.
- `make hel` :: **Helgrind mode**
  - For checking Threads errors, this will calls valgrind with the `helgrind` tool activated.
- `make drd` :: **Data Race Detector - DRD mode**
  - For checking Data Race errors from Threads, this will calls valgrind with the `drd` tool activated.
- `make sani_t` :: **Fsanitize for Threads mode**
  - For checking various forms of undefined or suspicious behaviors, switching to `threads` mode.
- `make sani_a` :: **Fsanitize for Address mode**
  - For checking various forms of undefined or suspicious behaviors, switching to `address` mode.

![image](https://github.com/user-attachments/assets/d090497b-f9fd-47de-a8d8-be8b7330d541)


