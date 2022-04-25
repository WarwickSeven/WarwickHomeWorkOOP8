//lesson H Task 2
#include <iostream>

class Ex {
public:
    double x;
    Ex(const double &x) {
        this->x = x;
        throw "Error. y+a > 100";
    }
};

class Bar {
    double y;
public:
    Bar(double y = 0) {
        this->y=y;
    }
    void setBar(double a) {
        if (y+a> 100) {
            throw(Ex(a*y));
        } else {
            y = a;
        }
    }
};

int main() {
    Bar p1;
    double n;
    do {
        std::cout << "n: ";
        std::cin >> n;
        try {
           p1.setBar(n);
        } catch (const char * a) {
           std::cerr << a << std::endl;
        }
    } while (n!=0);
    return 0;
}
