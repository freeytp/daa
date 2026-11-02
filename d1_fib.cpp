/*
 * QUESTION 1 (DAA):
 * Write a C++ program to generate Fibonacci series using
 * recursive and non-recursive methods and analyze their
 * time and space complexity.
 *
 * FIBONACCI SERIES:
 * The Fibonacci series starts with 0 and 1.
 * Every next number is the sum of the previous two numbers.
 *
 * Example:
 * 0, 1, 1, 2, 3, 5, 8, 13, 21 ...
 *
 * Mathematical Formula:
 * F(0) = 0
 * F(1) = 1
 * F(n) = F(n-1) + F(n-2)
 *
 * ---------------------------------------------------------
 * 1. NON-RECURSIVE (ITERATIVE) METHOD:
 *
 * - Uses a for loop to calculate Fibonacci numbers.
 * - Uses three variables: a, b and c.
 * - a stores the previous-to-previous number.
 * - b stores the previous number.
 * - c stores the sum of a and b.
 * - Updates the values in every iteration.
 * - Does not use recursive function calls.
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 *
 * ---------------------------------------------------------
 * 2. RECURSIVE METHOD:
 *
 * - A function calls itself to calculate Fibonacci numbers.
 * - Uses the Fibonacci formula directly.
 * - Base conditions:
 *      F(0) = 0
 *      F(1) = 1
 * - If n is greater than 1, the function calls itself
 *   with n-1 and n-2 and adds their results.
 * - Recalculates the same values multiple times.
 *
 * Time Complexity  : O(2^n) upper bound
 * Space Complexity : O(n)
 *
 * ---------------------------------------------------------
 * DIFFERENCE:
 *
 * Iterative method is faster because it avoids repeated
 * calculations and uses constant extra space.
 *
 * Recursive method is slower because it makes repeated
 * function calls and uses call stack memory.
 *
 * ---------------------------------------------------------
 * PROGRAM WORKING:
 *
 * 1. Accept the number of terms from the user.
 * 2. Validate the input.
 * 3. Generate and print the series using iterative method.
 * 4. Generate and print the series using recursive method.
 * 5. Both methods produce the same Fibonacci series.
 *
 * NOTE:
 * Input is restricted to 40 terms because recursive
 * Fibonacci becomes very slow for larger inputs.
 * The int data type is sufficient for the first 40 terms.
 *
 * SAMPLE OUTPUT:
 *
 * Enter number of terms: 7
 *
 * Iterative Fibonacci Series: 0 1 1 2 3 5 8
 * Recursive Fibonacci Series: 0 1 1 2 3 5 8
 *
 * ---------------------------------------------------------
 * IMPORTANT:
 * This program prints n terms, starting from F(0).
 * For n = 7, it prints F(0) to F(6).
 */

//   * COMMANDS (run from inside this folder):
//  *   install dependencies : sudo apt install g++
//  *   compile and run      : g++ -std=c++17 -Wall q1_Fibonacci.cpp -o q1_Fibonacci && ./q1_Fibonacci




#include <iostream>
using namespace std;

// Non-recursive Fibonacci
int iterative(int n) {
    if (n <= 1)
        return n;

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Recursive Fibonacci
int recursive(int n) {
    if (n <= 1)
        return n;

    return recursive(n - 1) + recursive(n - 2);
}

int main() {
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    if (n < 1 || n > 40) {
        cout << "Invalid input";
        return 0;
    }
    cout << "Non-recursive: " << iterative(n) << endl;
    cout << "Recursive: " << recursive(n) << endl;


    // cout << "\nIterative Fibonacci Series: ";
    // for (int i = 0; i < n; i++) {
    //     cout << iterative(i) << " ";
    // }

    // cout << "\nRecursive Fibonacci Series: ";
    // for (int i = 0; i < n; i++) {
    //     cout << recursive(i) << " ";
    // }

    return 0;
}
