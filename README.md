# 42_philosophers
A classic multithread program to learn how to avoid `data racing` and `dead lock` issues

![philosopherse](https://github.com/user-attachments/assets/3a5e657f-80cf-4da6-accd-279d1fdc21da)


## My take-aways about Philosophers project are:

## How to run:
Here is a few pre-setup possibilities:
### Let's Go mode
If you wanna just check how the threads are running, without changes, type:

```
make go
```

It will calls the argumnets registrered at my `Makefile` from the variable definition `args_to_test`:

![image](https://github.com/user-attachments/assets/b9380e1f-1384-431f-a3c9-34180f994c23)

### Valgrind mode
If you wanna check for memory leaks, type:

```
make val
```
It will calls valgridn with a lot of options, and will add the `args_to_test` variable:

![image](https://github.com/user-attachments/assets/2d73b873-0beb-4ace-9253-37341ebbee0d)


### Helgrind mode

```
make hel
```

![image](https://github.com/user-attachments/assets/cf4ad510-b339-4273-ae92-52305e64845e)



### GDB debugger mode

```
make gdb
```

![image](https://github.com/user-attachments/assets/594ba913-2c9c-4bbf-ad7b-488fba1cfea0)

### Data Race Detector - DRD mode

```
make drd
```

![image](https://github.com/user-attachments/assets/80d365a4-a5a0-4efc-90ea-80634f69ee83)


### Fsanitize for Threads mode

```
make sani_t
```

![image](https://github.com/user-attachments/assets/36467921-6580-4b2e-ae18-b633e0e69d31)

![image](https://github.com/user-attachments/assets/d114d313-3fbe-408f-9c06-d464b94d55cd)


### Fsanitize for Address mode

```
make sani_a
```

![image](https://github.com/user-attachments/assets/7fa6f8f8-762d-408c-9710-f55be0b69701)

![image](https://github.com/user-attachments/assets/5bd4c671-e965-4e53-be60-458ee89abce8)


