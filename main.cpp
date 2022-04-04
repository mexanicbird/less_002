// Created by Алексей Куликов on 03.04.2022//
/* Lesson 002 */
#include <iostream>
int count = 0;
int *pointer_count = &count;

/* task 001 */
class Person {
protected:
    Person(){}
    std::string name = "People";
    int age = 0;
    std::string sex = "transgender";
    int weight = 0;
public:
    Person (std::string name, int age, std::string sex, int weight ){
        this->name = name;
        this->age = age;
        this->sex = sex;
        this->weight = weight;
        //std::cout << "I was born! " << std::endl;
    }
    ~Person() {
        //std::cout << "I went to Dante!" << std::endl;
        }

    void live() {
        std::cout << name << " eat, work and sleep" << std::endl;
    }

    void setName(std::string name) {this->name = name; }
    void setAge (int age) {this->age = age;}
    void setSex(std::string sex) { this->sex = sex; }
    void setWeight (int weight) {this->weight = weight;}

    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getSex() const { return sex; }
    int getWeight() const { return weight; }
    void info() {
        printf(" My name is %s, I am a %s, I am %d years old, my weight is %d\n",
               getName().c_str(), getSex().c_str(), getAge(), getWeight());
    }
};

class Student : public Person {
private:
    int yearOfStudy = 0;
public:
    Student (std::string name, int age, std::string sex, int weight,
             int yearOfStudy ) : Person (name, age, sex, weight){
        this->yearOfStudy = yearOfStudy;
        *pointer_count = ++(*pointer_count);
        //std::cout << "I entered the university!" << std::endl;
    }
    ~Student() {
        *pointer_count = --(*pointer_count);
        //std::cout << "I have completed my studies!" << std::endl;
    }
    void setYearOfStudy (int yearOfStudy) {this->yearOfStudy = yearOfStudy;}
    int getYearOfStudy () { return yearOfStudy; }
    void info() {
        printf("My name is %s, I am a %s, I am %d years old, my weight is %d, year of study %d \n",
               getName().c_str(), getSex().c_str(), getAge(), getWeight(), getYearOfStudy());
    }
};

/* task 002 */
class Fruit {
protected:
    std::string name = "None";
    std::string color = "None";
    Fruit(){};
public:
    Fruit  (std::string name, std::string color){
        this->name = name;
        this->color = color;}
    void setName(std::string name) {this->name = name; }
    void setColor(std::string color) {this->color = color; }
    std::string getName() { return name; }
    std::string getColor() { return color; }
};

class Apple : public Fruit {
protected:
public:
    Apple(){
        name = "Apple";
        color = "red";
    };
    Apple(std::string color) : Fruit (name, color) {
        name = "Apple";
    }
    Apple(std::string name, std::string color) : Fruit (name, color) {
    }
};

class Banana : public Fruit {
protected:
public:
    Banana(){
        name = "Banana";
        color = "yellow";
};
    Banana(std::string name, std::string color) : Fruit (name, color) {
    }
};

class GrannySmith : public Apple {
protected:
public:
    GrannySmith() {
        name = "Granny Smith Apple";
        color = "green";
};
    GrannySmith(std::string name, std::string color) : Apple(name, color) {
    }
};

int main(int argc, const char** argv) {
    std::cout << "Lesson 002" << std::endl;
    std::cout << "Task 1" << std::endl;
    Student s1("Alex", 20, "Men", 65, 1);
    Student s2("Andrey", 20, "Men", 75, 1);
    Student s3("Valeria", 20, "Women", 55, 1);
    s1.info();
    s2.info();
    s3.info();
    std::cout << "Count Student = " <<  *pointer_count << ".\n";
    std::cout << "\n";

    std::cout << "Task 2" << std::endl;
    Apple a ("red");
    Banana b;
    GrannySmith c;
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    return 0;
}

/* task 003 */
/* Структура игры в следующем:
   родительский класс карта (параметры значение) наследники: черви, пики, крести, буби
   родительский класс игрок, наследники: человек, компьютер
   в целом игра использует базовые функции:циклы, операторы сравнения, псевдогенератор случайных чисел,
   возможно используются очереди (для заполнения колоды карт переед раздачей)
 */