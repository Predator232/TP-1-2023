#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
public:
    Animal(const std::string& breed, const std::string& color);

    virtual void serialize(std::ostream& os) const;
    virtual void deserialize(std::istream& is);

    virtual ~Animal();

    const std::string& getBreed() const;
    const std::string& getColor() const;

    virtual void printInfo();

private:
    std::string breed;
    std::string color;
};

#endif  // ANIMAL_H
