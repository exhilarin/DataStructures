#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

int linearSearch(int arr[], int n, int key) 
{
    for(int i = 0; i < n; i++)
        if(arr[i] == key) return i;
    return -1;
}

int countPairs(int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            count++;
    return count;
}

int fib(int n)
{
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

void multiplyMatrices(int n)
{
    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n)), C(n, vector<int>(n,0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
        {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
}

double measureLinearSearch(int n) 
{
    vector<int> arr(n);
    for(int i = 0; i < n; i++) arr[i] = i;
    int key = n - 1;
    double total = 0;
    for(int t = 0; t < 3; t++) {
        auto start = chrono::high_resolution_clock::now();
        linearSearch(arr.data(), n, key);
        auto end = chrono::high_resolution_clock::now();
        total += chrono::duration<double, milli>(end - start).count();
    }
    return total/3.0;
}

double measureCountPairs(int n) {
    double total = 0;
    for(int t = 0; t < 3; t++) {
        auto start = chrono::high_resolution_clock::now();
        countPairs(n);
        auto end = chrono::high_resolution_clock::now();
        total += chrono::duration<double, milli>(end - start).count();
    }
    return total/3.0;
}

double measureFibonacci(int n) {
    double total = 0;
    for(int t = 0; t < 3; t++) {
        auto start = chrono::high_resolution_clock::now();
        fib(n);
        auto end = chrono::high_resolution_clock::now();
        total += chrono::duration<double, milli>(end - start).count();
    }
    return total/3.0;
}

double measureMatrixMultiplication(int n) {
    double total = 0;
    for(int t = 0; t < 3; t++) {
        auto start = chrono::high_resolution_clock::now();
        multiplyMatrices(n);
        auto end = chrono::high_resolution_clock::now();
        total += chrono::duration<double, milli>(end - start).count();
    }
    return total/3.0;
}

int main() {
    vector<int> arraySizes = {10, 100, 1000, 5000, 10000};
    vector<int> fibSizes = {10, 20, 30, 35};
    vector<int> matrixSizes = {50, 100, 200};

    cout << "----- Linear Search -----\n";
    cout << "n\tRuntime(ms)\n";
    for(int n : arraySizes) {
        cout << n << "\t" << measureLinearSearch(n) << endl;
    }

    cout << "\n----- Nested Loops Counting -----\n";
    cout << "n\tRuntime(ms)\n";
    for(int n : arraySizes) {
        cout << n << "\t" << measureCountPairs(n) << endl;
    }

    cout << "\n----- Recursive Fibonacci -----\n";
    cout << "n\tRuntime(ms)\n";
    for(int n : fibSizes) {
        cout << n << "\t" << measureFibonacci(n) << endl;
    }

    cout << "\n----- Matrix Multiplication -----\n";
    cout << "n\tRuntime(ms)\n";
    for(int n : matrixSizes) {
        cout << n << "\t" << measureMatrixMultiplication(n) << endl;
    }

    return 0;
}
