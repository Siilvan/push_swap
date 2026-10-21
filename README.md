*This project has been created as part of the 42 curriculum by sgroenve, ngero.*

# Description
**Push Swap** is a program that sorts a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) provided to it via the command line. The program returns the list of operations necessary to sort said stack.

# Instructions

To compile the program use the `make` utility.
```sh
$ make
```
this will generate all the necessary object files, as well as build the `libftprintf.a` library. To clean up the object
files use `make clean`, and to also clean up the library `make fclean`

To redo the entire build process, consider `re`
```sh
$ make re
```

# Resources
- [stack wikipedia page](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
A.I. has not been used within this project

# Algorithms

## Simple
The simple algorithm simply walks the stack to find the largest number; once found, the stack is rotated enough times
to have this number appear on the top, that number is then pushed onto stack B.

This operation is repeated until Stack A is fully empty, at which point stack B pushes all its items one by one onto
stack A.

>[!info]
> *complexity*: O(n^2)
> *average number of operations for 500 numbers*: 30k

## Medium

## Complex
