# 42_philosophers
A classic multithread program to learn how to avoid `data racing` and `dead lock` issues

![philosopherse](https://github.com/user-attachments/assets/3a5e657f-80cf-4da6-accd-279d1fdc21da)


## My take-aways about Philosophers project are:

## How to run:
Here is a few pre-setup possibilities:
- $\color{BurntOrange}{make\ go}\$ :: **Let's Go mode** :: If you wanna just check how the threads are running, without changes. It will calls the argumnets registrered at my `Makefile` from the variable definition `args_to_test`
- $\color{BurntOrange}{make\ val}\$ :: **Valgrind mode** :: If you wanna check for memory leaks. It will calls valgridn with a lot of options, and will add the `args_to_test` variable
-$\color{BurntOrange}{make\ hel}\$ :: **Helgrind mode** :: xxxx
- $\color{BurntOrange}{make\ gdb}\$ :: **GDB debugger mode** :: xxx
- $\color{BurntOrange}{make\ drd}\$ :: **Data Race Detector - DRD mode** :: xxx
- $\color{BurntOrange}{make\ sani_t}\$ :: **Fsanitize for Threads mode** :: xxx
- $\color{BurntOrange}{make\ sani_a}\$ :: **Fsanitize for Address mode** :: xxx
- `make gdb` :: **GDB debugger mode** :: xxx
- `make gdb` :: **GDB debugger mode** :: xxx

![image](https://github.com/user-attachments/assets/d090497b-f9fd-47de-a8d8-be8b7330d541)

