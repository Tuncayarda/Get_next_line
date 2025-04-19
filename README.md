# get_next_line

`get_next_line` is a C function that reads and returns the next line from a file descriptor, one line at a time. This project is typically part of the curriculum at 42 schools and focuses on handling dynamic memory, buffer management, and edge cases associated with reading from a file descriptor.

## 🛠 Features

- Reads from any valid file descriptor
- Returns a line including the newline character (`\n`)
- Handles multiple file descriptors simultaneously
- Efficient buffer-based reading
- Manages memory to avoid leaks

## 📁 Project Structure

```
get_next_line/
├── get_next_line.c          # Main implementation
├── get_next_line_utils.c    # Helper functions
├── get_next_line.h          # Function prototypes and macros
├── main.c                   # Test file (optional)
├── Makefile                 # Build script
```

## 📌 Function Prototype

```c
char *get_next_line(int fd);
```

- `fd`: The file descriptor to read from
- Returns the next line read from the file, or `NULL` on EOF or error

## 📦 Compilation

To compile the project, use the provided `Makefile`:

```bash
make
```

This will generate the necessary object files and can be linked into your application.

To clean up:

```bash
make clean      # Removes .o files
make fclean     # Removes .o and executables
make re         # Recompiles everything
```

## 🚀 Usage Example

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## ⚙️ Buffer Size

The buffer size can be defined via a macro (usually in `get_next_line.h` or passed during compilation):

```c
#define BUFFER_SIZE 42
```

Or during compilation:

```bash
cc -D BUFFER_SIZE=42 ...
```

## 📑 Notes

- The function must work correctly with multiple file descriptors at the same time.
- It must return `NULL` when there is nothing more to read (EOF).
- Memory must be properly managed to avoid leaks.
- Successive calls should return successive lines from the input.

## ✅ Mandatory Rules (42 School)

- No use of `static` variables outside of `get_next_line.c`
- No memory leaks
- Must handle multiple FDs without interference
