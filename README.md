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
- [Stack Overflow](https://stackoverflow.com/questions)
- [Youtube](https://youtube.com)
A.I. has not been used within this project

# Algorithms

## Simple
The simple algorithm simply walks the stack to find the largest number; once found, the stack is rotated enough times
to have this number appear on the top, that number is then pushed onto stack B.

This operation is repeated until stack A is fully empty, at which point stack B pushes all its items one by one onto
stack A.

>[!info]
> *complexity*: O(n^2)
> *average number of operations for 500 numbers*: 30k

## Medium
Before the medium algorithm starts, each number gets assigned a rank based on where they should be in a sorted stack, this makes it easier to work with the numbers. (e.g. 25 random numbers, get assigned ranks 0-24.)

The medium algorithm works in chunks, the size of the chunks is based on the amount of numbers. It rotates stack A to find any number in the range of the current chunk and pushes it to stack B, it repeats this until all numbers of the chunk are in stack B. Then it moves onto the next chunk.

Once the algorithm has gone through all the chunks, stack B should now be semi-sorted. Now the algorithm goes through each chunk, starting at the highest range, and pushes each number of the chunk in the correct order. Since stack B was semi-sorted in the previous phase, the stack only has to rotate a maximum of the chunk size to find the number it has to push next.

### [!info]
***complexity***: O(n√n)<br>
***average number of operations for 500 numbers:*** 5k

## Complex
For the complex algorithm uses a version of radix sort, since radix sort cant deal with negative numbers, we normalise the numbers in this algorithm as well. (see medium algorithm.) Normally, radix sort is in base 10, but since we only have two "buckets" (stack A and B), this version does it in base 2 a.k.a. binary.

The algorithm starts by finding the maximum amount of bits we have to check, this is the amount of times we have to run the algorithm. Next, it iterates through each bit from the least to the most significant bit. If the current bit is 0 its pushed to stack B, otherwise it rotates stack A to leave it there. once all numbers have been checked it all gets pushed back to stack A. Then we repeat this for the next bit.

Once the algorithm has gone through all the bits, the stack should be sorted. Each time a loop is done and the numbers get pushed to stack A, the numbers are now sorted on the current bit and on previously checked bits. When the final loop finishes, the numbers are now sorted on every useful bit, which in turn also sorts the numbers.

### [!info]
***complexity***: O(nlog(n))
***average number of operations for 500 numbers:*** 7k
