#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class abstraktnie {
public:
    virtual void virtfunc() = 0;   // virtual func
};

class Animal {
public:
    Animal(const std::string& breed, const std::string& color);
    Animal();          // constructor without parameters
    Animal(const Animal& animal_copy); // constructor copy


    void virtfunc() {
        std::cout << "virtual function works" << std::endl; // virtual function
    }

    virtual void updateInfo(const std::string& newBreed, const std::string& newColor) {
        breed = newBreed;
        color = newColor;
    }
    virtual void updateDiet(const std::string& newDiet) {}
    virtual void updateHabitat(const std::string& newHabitat) {}
    virtual void updateOwnerName(const std::string& newOwnerName) {}

    virtual void serialize(std::ostream& os) const;
    virtual void deserialize(std::istream& is);

    virtual ~Animal();

    const std::string& getBreed() const;
    const std::string& getColor() const;

    virtual void printInfo();

protected:
    std::string breed;
    std::string color;
};

#endif  // ANIMAL_H
