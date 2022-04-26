#include <iostream>

class OffTheField {
    std::string m_error;
public:
    OffTheField(std::string error) : m_error(error) { }
    const char* getError() {
        return m_error.c_str();
    }
};

class IllegalCommands {
    std::string m_error;
public:
    IllegalCommands(std::string error) : m_error(error) { }
    const char* getError() {
        return m_error.c_str();
    }
};

class Robot {
    int m_x;
    int m_y;
public:
    Robot(const int x, const int y) : m_x(x), m_y(y) { }
    virtual ~Robot() { }
    void getCoord() {
        std::cout << "Robot (x:" << m_x << ", y:" << m_y << ")" << std::endl;
    }
    void move(const char m);
};

void Robot::move(char m) {
    if ((m=='w') || (m=='s') || (m=='a') || (m=='d') || (m=='e')) {
        switch (m) {
            case ('w'):
                if (m_y == 1)
                    throw OffTheField("You can't go Up");
                else
                    m_y--;
                break;
            case ('s'):
                if (m_y == 10)
                    throw OffTheField("You can't go Down");
                else
                    m_y++;
                break;
            case ('a'):
                if (m_x == 1)
                    throw OffTheField("You can't go Left");
                else
                    m_x--;
                break;
            case ('d'):
                if (m_x == 10)
                    throw OffTheField("You can't go Right");
                else
                    m_x++;
                break;
            case ('e'):
                std::cout << "Game over" << std::endl;
        }
    } else {
        throw IllegalCommands("incorrect input");
    }
}

int main() {
    Robot r1(5, 5);
    char move;
    
    do {
        r1.getCoord();
        std::cout << "Where to move W(Up),S(Down),A(Left),D(Right),E(exit): ";
        std::cin >> move;
        try {
            r1.move(move);
        } catch(IllegalCommands &exception) {
            std::cout << exception.getError() << std::endl;
        } catch(OffTheField &exception) {
            std::cout << exception.getError() << std::endl;
        }
    } while (move !='e');
    return 0;
}

