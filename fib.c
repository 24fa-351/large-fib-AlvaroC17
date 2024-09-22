// // This was code was done last week I just procrastinated accepting the github... 
// NVM no file reading! 

#include <stdio.h>
#include <stdlib.h>

// Recursive Fibonacci 
unsigned long long fib_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Iterative Fibonacci 
unsigned long long fib_iterative(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    unsigned long long prev = 1, current = 1, next;
    for (int i = 3; i <= n; i++) {
        next = prev + current;
        prev = current;
        current = next;
    }
    return current;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <integer> <r|i>\n", argv[0]);
        return 1;
    }

    // Convert first argument to an integer
    int N = atoi(argv[1]);

    // Determine Fibonacci number
    unsigned long long result;
    if (argv[2][0] == 'r') {
        result = fib_recursive(N - 1);
    } else if (argv[2][0] == 'i') {
        result = fib_iterative(N - 1);
    } else {
        printf("Invalid method. Use 'r' for recursive or 'i' for iterative.\n");
        return 1;
    }

    // Output the result 
    printf("%llu\n", result);

    return 0;
}
