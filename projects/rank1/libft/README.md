_This project has been created as part of the 42 curriculum by lecavall._

# Description

This project serves for the creator to use a new set of funtcions for use in later projects in the 42 Core Curriculum. It also serves the purpose of giving him the understanding of some core functions that enhance C code.

# Instructions

Makefile:
make: compile all files in the library, the library itself, and make an exacutable of it

make bonus: include the bonus files in make

clean: remove all created object files, including bonus if present

fclean: do clean and delete executable

re: do clean, fclean and make

# Resources

The 42 Guide helped me a lot, since I am under time pressure right now.
I used AI to get an initial understanding of what I didn't know, then read more about it later. 

# Libft

This library contains the following functions, explained below:

**LibC functions:**

isalpha - Checks whether a character is an alphabetic letter (A–Z or a–z) according to the C locale.

isdigit - Checks whether a character is a decimal digit from 0 to 9.

isalnum - Checks whether a character is alphanumeric, meaning a letter or a digit.

isascii - Checks whether a character value fits into the 7-bit ASCII character set.

isprint - Checks whether a character is printable, including space.

strlen - Computes the length of a null-terminated string, excluding the terminating '\0'.

memset - Fills a block of memory with a given byte value for a specified number of bytes.

bzero - Sets a block of memory to zero bytes. Deprecated, equivalent to memset with zero.

memcpy - Copies a fixed number of bytes from one memory area to another. Overlap is undefined.

memmove - Copies bytes from one memory area to another safely, even if the regions overlap.

strlcpy - Copies a string into a destination buffer with size limitation and guarantees null termination.

strlcat - Appends a string to another with size limitation and guarantees null termination.

toupper - Converts a lowercase letter to uppercase if possible.

tolower - Converts an uppercase letter to lowercase if possible.

strchr - Locates the first occurrence of a character in a string.

strrchr - Locates the last occurrence of a character in a string.

strncmp - Compares two strings up to a specified number of characters.

memchr - Scans a block of memory for the first occurrence of a given byte.

memcmp - Compares two blocks of memory byte by byte.

strnstr - Locates a substring within another string, searching at most a given number of characters.

atoi - Converts a string representation of an integer into an int value. No error handling.

calloc - Allocates memory for an array and initializes all bytes to zero.

strdup - Allocates new memory and duplicates a given string into it.

**Additional functions required by 42:**

ft_substr - Allocates and returns a substring from a string starting at a given index with a maximum length.

ft_strjoin - Allocates and returns a new string formed by concatenating two strings.

ft_strtrim - Allocates and returns a copy of a string with specified characters trimmed from the start and end.

ft_split - Splits a string into an array of substrings using a delimiter character.

ft_itoa - Converts an integer into its string representation.

ft_strmapi - Creates a new string by applying a function to each character of a string with its index.

ft_striteri - Applies a function to each character of a string in place, passing the index.

ft_putchar_fd - Writes a single character to a given file descriptor.

ft_putstr_fd - Writes a string to a given file descriptor.

ft_putendl_fd - Writes a string followed by a newline to a given file descriptor.

ft_putnbr_fd - Writes an integer to a given file descriptor.

**Linked List functions:**

ft_lstnew - Allocates and returns a new linked list node with given content.

ft_lstadd_front - Adds a node at the beginning of a linked list.

ft_lstsize - Returns the number of nodes in a linked list.

ft_lstlast - Returns the last node of a linked list.

ft_lstadd_back - Adds a node at the end of a linked list.

ft_lstdelone - Frees a single linked list node using a provided delete function.

ft_lstclear - Deletes and frees all nodes of a linked list and sets it to NULL.

ft_lstiter - Iterates over a linked list and applies a function to each node’s content.

ft_lstmap - Creates a new linked list by applying a function to each node’s content.