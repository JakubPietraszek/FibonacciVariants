#include<iostream>
class Fibonacci {
public:
    void arrayInitialising(int* arr, int arrSize);
    int isNumber(std::string number);
    int withoutRecursion(int n);
    int naiveRecursion(int n);
    int memorizationRecursion(int n, int* arr, int a);
    int tailRecursive(int n, int a = 0, int b = 1);
};
