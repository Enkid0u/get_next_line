# Get_next_line

### Goal of the project

This project is about creating a function that returns a line, ending with a newline, from a file descriptor. In this project we learned a highly interesting new concept in C programming: static variables.

## Mandatory part
The function reads from a single file descriptor at the time.

## bonus part
Multiples file descriptors can be read from at the same time.

The prototype of the function is:
```
char  *get_next_line(int fd);
```

# Getting started
### Installation
* Clone the repo:
```
git clone git@github.com:RRebois/get_next_line.git
```
### Compilation
* Include the appropriate header file it to your project
```
Include get_next_line.h
```
* Compilation
```
gcc my_project.c -o my_project_name srcs/get_next_line.c srcs/get_next_line_utils.c -I include -D BUFFER_SIZE=42
```
Adding this option to the compiler call: -D BUFFER_SIZE=n will define the buffer size for read().
