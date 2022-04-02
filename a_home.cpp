#include <iostream>
#include <cstdint>
// Создать класс Power, который содержит два вещественных числа.
// Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел.
// Еще создать два метода: один с именем set, который позволит присваивать значения переменным, второй — calculate, который будет выводить результат возведения первого числа в степень второго числа.
// Задать значения этих двух чисел по умолчанию.
class Power {
    double base = 2;
    double sign = 16;
public:
    //    Power() : base(2), sign(16) {}
    //    Power(double b=2, double s=16) : base(b), sign(s) {}
    void setValues(double base, double sign) {
        this->base = base;
        this->sign = sign;
    }
    double calculate();
};
double Power::calculate() {
    int s = sign;
    double result = 1;
    while (s) {             // s != 0
        if (s % 2) {        // s % 0 != 0
            result *= base;
            s -= 1;
        } else {            
            base *= base;
            s /= 2;
        }
    }
    return result;
}

// Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов.
class RGBA {
    std::uint8_t m_red;
    std::uint8_t m_green;
    std::uint8_t m_blue;
    std::uint8_t m_alpha;
public:
    RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255) {}
    RGBA(std::uint8_t red, std::uint8_t blue, std::uint8_t green, std::uint8_t alpha) :
        m_red(red), m_green(blue), m_blue(green), m_alpha(alpha) {}
    void print();
};
void RGBA::print() {
    printf("RGBA: r=%d, g=%d, b=%d, a=%d\n", m_red, m_green, m_blue, m_alpha);
}

// Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
// private-массив целых чисел длиной 10;
// private целочисленное значение для отслеживания длины стека;
// public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
// public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
// public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
// public-метод с именем print(), который будет выводить все значения стека.
class Stack {
    #define STACK_LENGTH 10
    int arr[STACK_LENGTH] = {0};
    int capacity = 0;
public:
    Stack() {
        //free(arr);
        //arr = (int*) calloc(STACK_LENGTH, sizeof(int));
        for (int i = 0; i < STACK_LENGTH; i++) {
            arr[i] = 0;
        }
    }
    void reset();
    bool push(int e);
    int pop();
    void print();
};
void Stack::reset() {
    while (capacity > 0) {
        arr[capacity--] = 0;
    }
}
bool Stack::push(int e) {
    if (capacity < STACK_LENGTH) {
        arr[capacity++] = e;
        return true;
    } else {
        return false;
    }
}
int Stack::pop() {
    if (capacity >= 0) {
        return arr[capacity--];
    } else {
        std::cout << "Warning: stack is empty, returned value is invalid!" << std::endl;
        return -1;
    }
}
void Stack::print() {
    std::cout << "(";
    for (int i = 0; i < capacity; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << ")";
    std::cout << std::endl;

}

int main(int argc, const char** argv) { // 1TBS
    Power p;
    std::cout << p.calculate() << std::endl;
    p.setValues(2, 10);
    std::cout << p.calculate() << std::endl;

    RGBA r0;
    r0.print();
    RGBA r1(1,2,3,4);
    r1.print();

    Stack stack;
    stack.reset();
    stack.print();
    
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.print();
    
    return 0;
    return 0; 
}
