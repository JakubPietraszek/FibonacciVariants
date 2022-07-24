#include "Fibonacci.h"
#include<string>

    void Fibonacci::arrayInitialising(int* arr, int arrSize) {

        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i < arrSize; i++) {
            arr[i] = -1;
        }
    }
    int Fibonacci::isNumber(std::string number) { // returning -1 in case there is an invalid input

        //checking for negative numbers
        if (number[0] == '-')
            return -1;

        for (int i = 0; number[i] != 0; i++) {
            if (number[i] > '9' || number[i] < '0')
                return -1;
        }
        int x = stoi(number);
        return x;
    }
    int Fibonacci::withoutRecursion(int n) {
        if (n <= 1)
            return n;
        else {
            int a = 0, b = 1, i = 2;
            std::cout << "0: 0" << "\n1: 1\n";
            while (n) {
                std::cout << i << ": " << a << "+" << b << "=" << a + b << std::endl;
                b = a + b;
                a = b - a;
                i++;
                n--;
            }
            return b;
        }
    }
    int Fibonacci::naiveRecursion(int n) {
        static int i = 0;
        i++;
        if (n <= 1) {
            std::cout << i << "\n";
            return n;
        }
        else {
            std::cout << i << "\n";
            return Fibonacci::naiveRecursion(n - 1) + Fibonacci::naiveRecursion(n - 2);
        }
    }
    int Fibonacci::memorizationRecursion(int n, int* arr, int a) { //n - which one in a Fibonacci sequence you want to get, a - size of the array
        static int i = 0;
        if (i == 0)
            arrayInitialising(arr, a);
        i++;
        if (n <= 1)
            return n;
        else if (arr[n - 1] != -1)
            return arr[n - 1];
        else {
            arr[n - 1] = memorizationRecursion(n - 1, arr, a) + memorizationRecursion(n - 2, arr, a);
            return arr[n - 1];
        }
    }
    int Fibonacci::tailRecursive(int n, int a , int b) {
        static int counter = 0;
        if (counter == 0) {
            a = 0;
            b = 1;
        }
        if (n == 0)
            return a;
        if (n == 1)
            return b;
        return tailRecursive(n - 1, b, a + b);
    }
