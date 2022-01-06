# csortlib
Sorting algorithms for integer arrays implemented in C.

Each .c file contains a main function where an array is defined and sorted using the related sorting algorithm.
Functions that are used throughout the algorithm implementations are put into the header file (sorthelpers.h) and corresponding source file (sorthelpers.c).

## How to run the .c files using the gcc compiler
Because the .c files use the local sorthelpers.h file they have to be compiled into object files first. Follow the below steps to produce an executable.
1) Compile the sorthelpers.c passing the -c argument to gcc
 ```gcc -c sorthelpers.c```.
 This will produce an object file, namely sorthelpers.o.
2) Compile the .c file (eg. shell_sort.c) passing the -c argument to gcc
```gcc -c shell_sort.c```.
This wil produce a shell_sort.o file.
3) Now in order to produce the executable you can do
```gcc shell_sort.o sorthelpers.o```.
This will produce an executable named a.out, if you want to give the executable a different name (eg. shell_sort) use the -o argument:
```gcc shell_sort.o sorthelpers.o -o shell_sort```

You're ready to go! Execute the executable with ```./shell_sort``` and watch the sorting take place.
