//Lesson H Task 1
#include <iostream>

double division(double const &a, double const &b) {
    if (b==0)
        throw "DivisionByZero";
    return a/b;
}

int main() {
    double a = 10;
    double b = 4;
    try {
        std::cout << division(a,b) << std::endl;
        } catch (const char* e) {
            std::cerr << e << std::endl;
        }
    return 0;
}
 
