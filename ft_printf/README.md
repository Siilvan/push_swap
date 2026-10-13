*This project has been created as part of the 42 curriculum by sgroenve.*

# ft_printf

## Description
**ft_printf** is about a popular and useful C function printf(). The goal of this project is to make your own partial printf. Which will probably be useful in later projects when you have to write something.

---

## Instructions

### Compilation
The project has a `Makefile` to make compiling easier. The available commands are:

*   `make` - Compiles the project this project depends on "libft", and creates libftprintf.a
*   `make clean` - Deletes all object files (`.o`).
*   `make fclean` - Deletes all object files and the library file (`libftprintf.a`).
*   `make re` - Recompiles the entire project.

### Technical Integration
To  be able to use the library in another C project, you have to include the header file in your code:
```c
#include "ft_printf.h"
```

When compiling your project, link the compiled library file:
```bash
cc main.c -L. -lft -o my_program
```

---

## Library Features

The printf consists of two parts:

### 1. Conversion (Mandatory):
My ft_printf has to handle the following conversions just like the original printf:
*	`%c`	   - Prints a single character.
*	`%s` 	   - Prints a string.
*	`%p`	   - Prints a void pointer in hexadecimal format.
*	`%d`, `%i` - Prints a decimal number in base 10.
*	`%u`	   - Prints an unsigned decimal number in base 10.
*	`%X`, `%x` - Prints a number in hexadecimal upper/lowercase format.
*	`%%`	   - Prints a percent sign.

### 2. Flags (Bonus):
For this part my ft_printf has to handle any combination of these flags like the original printf:
*	`0`		- The value should be zero padded.
*	`#`		- The value should be converted to alternate form when possible.
*	`-`		- The value has to be left aligned.
*	` `, `+`- A space/plus should be left before a postive number.
---

## Resources

### Documentation & References
*   [Man 3 Pages](https://linux.die.net/man/) - Standard documentation of the orignal printf.
*   [Stack overflow](https://stackoverflow.com/questions) - General questions.
*   [Youtube](https://www.youtube.com/) - Tutorials for multiple things, mostly variadic functions.

### AI Usage & Acknowledgments
LLMs were used during this project for:
*   **Explanation:** AI was used to explain concepts I didn't understand yet.

## Algorithm explanation
1.	`Writing`: The main function iterates through the given format, when it finds a % it passes its current position to a different functions that handles the flags and conversions, otherwise it just prints the current character.
2.	`Conversion`: ft_format is called when a % is found. From here we look until we find a valid conversion, and enables any flags in a struct it finds before it. When it finds a conversion it passes it to its related print function, which returns the amount of character it printed including the flags.
3.	`Code structure`: The code was split up into multiple functoins, to keep the code readable and easier to understnad.
