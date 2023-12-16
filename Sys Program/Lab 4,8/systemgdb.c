/*

Debugging C code in Unix can be done using several tools. One of the most common debuggers is `gdb` (GNU Debugger). Here's a brief guide on how to use `gdb` for debugging C code in Unix:

### Compiling with Debug Symbols

When compiling your C code, include the `-g` flag to include debug symbols. For example:

```bash
gcc -g -o my_program my_code.c
```

### Using GDB

1. **Start GDB**: Run `gdb` followed by your compiled program:

    ```bash
    gdb ./my_program
    ```

2. **Setting Breakpoints**:
   
    - Set breakpoints where you suspect issues might be occurring using the `break` command:
    
        ```bash
        break <line_number>
        ```
        
        You can also set breakpoints at function names or file locations.

3. **Running the Program**: Start your program within GDB:

    ```bash
    run
    ```

4. **Debugging Commands**:

    - `next` (`n`): Execute the next line of code.
    - `step` (`s`): Step into functions being called.
    - `print` (`p`): Print the value of a variable.
    - `continue` (`c`): Continue running the program until the next breakpoint is reached.
    - `backtrace` (`bt`): Show the call stack.
    - `quit`: Exit GDB.

5. **Inspecting Variables**:

    - Use `print` or `display` followed by the variable name to inspect its value.
    
6. **Handling Segmentation Faults**:

    If your program encounters a segmentation fault, GDB will stop at the point of the fault. You can use the backtrace (`bt`) command to see where the fault occurred and inspect variables to identify the issue.

Remember, `gdb` offers many more commands and functionalities for debugging C programs in Unix. Its documentation and online tutorials can provide comprehensive guidance on using it effectively for debugging.

*/