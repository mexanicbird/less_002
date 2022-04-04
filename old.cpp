// Created by Алексей Куликов on 03.04.2022//

#include <iostream>

class Animal {
protected:
    Animal(){}
    int yearOfBirth;
    std::string name;
    std::string color;
public:

    Animal (std::string name, std::string color, int yearOfBirth ){
        this->name = name;
        this->color = color;
        this->yearOfBirth = yearOfBirth;
    }

    void move() {
        std::cout << name << " walks on paws" << std::endl;
    }
    void setName(std::string n) { name = n; }
    int getAge() const { return 2022 - yearOfBirth; }
    std::string getName() const { return name; }
    std::string getColor() const { return color; }
    void info() {
        printf("%s is %s and %d years of age\n", getName().c_str(), color.c_str(), getAge());
    }
};

class Cat : public Animal {
private:
public:
    Cat (std::string name, std::string color, int yearOfBirth ) : Animal(name, color, yearOfBirth){
    }
    ~Cat() {
        std::cout << "cat..." << std::endl;
    }
    void voice() {
        std::cout << name << " meow" << std::endl;
    }
};
void makeCatMove(Cat* c) {
    (*c).move();
    //c->move();
}
void makeCatMove(Cat& c) {
    c.move();
}

class Dog : public Animal {
private:
public:
    Dog (std::string name, std::string color, int yearOfBirth=2021) {
        this->name = name;
        this->color = color;
        this->yearOfBirth = yearOfBirth;
    }
    ~Dog() {
        std::cout << "cat..." << std::endl;
    }
    void voice() {
        std::cout << name << " meow" << std::endl;
    }
};
void makeCatMove(Dog* c) {
    (*c).move();
    //c->move();
}
void makeCatMove(Dog& c) {
    c.move();
}

int mains(int argc, const char** argv) {
    std::cout << "Lesson 002" << std::endl;
    Cat c0("Barsik", "White", 2017); // Cat c0 = new Cat();
    Cat c1("Kotik", "Peachy", 2017); // Cat c0 = new Cat();
    Dog d1("Pat", "White", 2010); // Cat c0 = new Cat();
    c0.info();
    c1.info();
    d1.info();
    return 0;
}


