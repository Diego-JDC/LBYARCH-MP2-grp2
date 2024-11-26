## TODO
1. comparative execution time and short analysis of the performance of the kernels
2. Take a screenshot of the program output with the correctness check (C).
3. Take a screenshot of the program output, including the correctness check (x86-64).
4. short videos (5-10mins) showing your source code, compilation, and execution of the C and x86-64 program

## To compile the program
Run the following commands
```
nasm -f win64 mp2a.asm
gcc -c mp2c.c -0 mp2c.obj -m64
gcc mp2c.obj mp2a.obj -o mp2.exe -m64
mp2e 
```