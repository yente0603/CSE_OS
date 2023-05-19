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

* If you put a definition of a global variable in a header file, then this definition will go to every .c file that includes this header, and you will get multiple definition error because a varible may be declared multiple times but can be defined only once.
Also, one more thing you can do if you have to define your variables inside of a header file you can use the static keyword.
```
static const char *names[] = {"brian", "stefan",  "steve" };
```
* Declarations of public functions go in header files, yes, but definitions are absolutely valid in headers as well! You may declare the definition as static (only 1 copy allowed for the entire program) if you are defining things in a header for utility functions that you don't want to have to define again in each c file. I.E. defining an enum and a static function to translate the enum to a string. Then you won't have to rewrite the enum to string translator for each .c file that includes the header.


This way variable names will be defined only once in your entire program and can be accessed multiple number of times.  


Reference: https://stackoverflow.com/questions/17764661/multiple-definition-of-linker-error
