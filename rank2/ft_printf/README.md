_This project has been created as part of the 42 curriculum by lecavall._

# Description 

Recreation of the libc function printf.

The following conversions are being implemented:

• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

# Instructions

compile ...
Makefile
Names
Equal to normal printf


# Resources 

1. https://medium.com/@andrew_johnson_4/mastering-variadic-functions-the-null-terminated-argument-list-in-c-7186950f020a

2. https://stackoverflow.com/questions/77300562/variadic-functions-in-c-concept

3. https://www.geeksforgeeks.org/c/variadic-functions-in-c/

# Algorithm and Data Structure

First attempt: Just write a function for each conversion