#include <iostream>

class Cat {
private:
    // private-public
    int yearOfBirth;
    std::string name;
    // mutable
    mutable std::string color;

public:
    // initialization lists
    Cat() : yearOfBirth(2022) {
        color = "Peachy"; // here can be color randomizer
        std::cout << "MEOW!" << std::endl;
    }
    Cat(std::string name, std::string color, int yearOfBirth=2021) {
        this->name = name;
        this->color = color;
        this->yearOfBirth = yearOfBirth;
    }
    // copy constructor
    Cat(Cat& c)
        : name(c.name), color(c.color), yearOfBirth(c.yearOfBirth) {}


    // destructors
    ~Cat() {
        std::cout << "cat..." << std::endl;
    }
    
    // functions constructors
    void voice() {
        std::cout << name << " meow" << std::endl;
    }

    void move() {
        std::cout << name << " walks on paws" << std::endl;
    }
    void setName(std::string n) { name = n; }

    // const methods
    int getAge() const { return 2022 - yearOfBirth; }
    std::string getName() const { return name; }
    std::string getColor() const { return color; }
    void info() {
        printf("%s is %s and %d years of age\n", getName().c_str(), color.c_str(), getAge());
    }
};

// links vs pointers
void makeCatMove(Cat* c) {
    (*c).move();
    //c->move();
}
void makeCatMove(Cat& c) {
    c.move();
}

int mainag(int argc, const char** argv) { // 1TBS
	// classes vs objects, fields
    Cat c0("Barsik", "White", 2017); // Cat c0 = new Cat();
    c0.info();
    Cat c1("Murzik", "Black", 2020);
    c1.info();
    Cat c2;
    c2.setName("Kotik");
    c2.info();
    
    //    Cat.voice(); //compile error
    c0.voice();
    c1.voice();
    c0.move();
    c1.move();

    // pointer to object
    Cat* c2p = &c2;
    c2p->setName("pointer");
    c2.info();

    Cat c4(c1);
    c4.setName("Clone");
    c4.info();
    c1.info();
    
    // this

    
    return 0; 
}
