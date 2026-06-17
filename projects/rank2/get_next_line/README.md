_This project has been created as part of the 42 curriculum by lecavall._

# Description

This project's goal is to create a function get_next_line, which returns a line read from a file. It is comprised of three files: get_next_line.c; get_next_line_utils.c; get_next_line.h. The function returns NULL if there is nothing else to read or an error occured, else it returns the line read. It reads from the file descriptor given as an argument.

Mandatory behavior:

- Return the next line, including `\n` when present.
- Return the last line without `\n` if file ends without newline.
- Return `NULL` on end of input or on error.
- Preserve unread bytes between calls using a static variable.

### Prototype

char *get_next_line(int fd);

# Instructions

cc:

```sh
cp ~/CC/rank1/main.c ./ && cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test
```
Memory allocation control

```sh
cc -g -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test && valgrind ./gnl_test
```
# Dependencies

External functions allowed/used:

- `read`
- `malloc`
- `free`

Headers:

- `<unistd.h>` for `read`
- `<stdlib.h>` for `malloc`, `free`

# Resources

New concepts include static variables, setting a constant variable through a flag during compilation and using the read function.

Resources I used:
1. https://www.geeksforgeeks.org/c/static-variables-in-c/
2. https://man7.org/linux/man-pages/man1/gcc.1.html
3. Brave Browser AI for brief inquiries like "give me this command" or "how long is long long data type"
4. https://cdn.intra.42.fr/pdf/pdf/192153/en.subject.pdf



# Algorithm justification

The algorithm aims to use 3 functions handling the main tasks, managing the errors, memory allocation, and output: reading from the file, and seperating a line and storing it in case more than a line was read. It uses 4 helper functions. This strucute makes it readable.
