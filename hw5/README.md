#Multiple definition of ... linker error

##Don't define variables in headers. Put declarations in header and definitions in one of the .c files

In config.h
```
extern const char *names[];
```
In config.c
```
const char *names[] = {"brian", "stefan", "steve"};
```

If you put a definition of a global variable in a header file, then this definition will go to every .c file that includes this header, and you will get multiple definition error because a varible may be declared multiple times but can be defined only once.

Also, one more thing you can do if you have to define your variables inside of a header file you can use the static keyword.
```
static const char *names[] = {"brian", "stefan",  "steve" };
```

This way variable names will be defined only once in your entire program and can be accessed multiple number of times.



Reference: https://stackoverflow.com/questions/17764661/multiple-definition-of-linker-error
