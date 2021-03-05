/*
*   geekbrains.ru, OOP
*   Konstantin N. Terskikh, kostus.online@gmail.com
*   Lesson 1
*   Win10, MSVS 2019
*/

/*
WELL DONE!
*/

#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

class Power {
    double m_x;
    double m_y;

public:
    void set(double x, double y) {
        m_x = x;
        m_y = y < 0 ? 0 : y; // :)
    }

    double calculate(double x, double y, bool print = true) {
        set(x, y);
        return calculate(print);
    }

    double calculate(bool print = true) {
        double p = pow(m_x, m_y);
        if (print) {
            cout << m_x << " ^ " << m_y << " = " << p << endl;
        }
        return p;
    }

public:
    Power() {
        set(0, 0);
    }

    Power(double x, double y) {
        set(x, y);
    }
};

class RGBA {
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;

    void init() {
        m_red = 0;
        m_green = 0;
        m_blue = 0;
        m_alpha = 255;
    }

public:
    RGBA() {
        init();
    }

    RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        set(r, g, b, a);
    }
    
    /*RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        :_m_red(r), m_green(g), m_blue(b), m_alpha(a){}
    also good variant    
    */

public:
    void set(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        m_red = r;
        m_green = g;
        m_blue = b;
        m_alpha = a;
    }

    void print() {
        cout 
            << "red: " << unsigned(m_red)
            << ", green: " << unsigned(m_green) <<
            ", blue: " << unsigned(m_blue)
            << ", alpha: " << unsigned(m_alpha) << endl;
    }
};

#define STACK_SIZE 10
class Stack {
    int m_arr[STACK_SIZE] = { 0 };
    int count;

    void reset() {
        count = 0;
        for (int i = 0; i < STACK_SIZE; i++)
            m_arr[i] = 0;
        
        //std::memset  could be useful here
    }

public:
    Stack() {
        reset();
    }

public:
    bool is_empty() {
        bool empty = count <= 0;
        if (empty)
            cout << "stack is empty!" << endl;
        return empty;
    }

    bool is_over() {
        bool over = (count + 1) >= STACK_SIZE;
        return over;
    }

    bool push(int n) {
        if (is_over())
            return false;

        m_arr[count++] = n;
        return true;
    }

    int pop() {
        if (is_empty())
            return 0;
        return m_arr[count--];
    }

    void print() {
        cout << "{";
        for (int i = 0; i < count; i++)
            cout << " " << m_arr[i];
        cout << " }" << endl;
    }
};

int main()
{
    cout << "Part 1:" << endl;
    Power p(12, 13);
    p.calculate();
    p.calculate(43.1, 2.7);

    cout << endl << "Part 2:" << endl;
    RGBA rgba(77, 88, 12, 200);
    rgba.print();

    cout << endl << "Part 3:" << endl;
    Stack s;
    s.push(1); // < 0
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10); // < 9
    s.push(11); // stack over, no warnings
    s.print();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.print();

    s.pop();
    s.pop();
    s.print();

    s.pop();
    s.pop();
    s.print();

    s.pop();
    s.pop(); // stack is empty! warning printed
    s.print();

    cout << endl << "Done" << endl;
}
