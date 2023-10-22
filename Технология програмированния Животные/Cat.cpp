#include "Cat.h"

Cat::Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& name)
    : Animal(breed, color), ownerName(ownerName), name(name) {
    std::cout << "Cat constructor called." << std::endl;
}

void Cat::serialize(std::ostream& os) const {
    os << "Cat ";
    Animal::serialize(os);
    os << " " << ownerName << " " << name;
}

void Cat::deserialize(std::istream& is) {
    Animal::deserialize(is);
    is >> ownerName >> name;
}

Cat::~Cat() {
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::printInfo() {
    std::cout << "Cat - Breed: " << getBreed() << ", Color: " << getColor()
        << ", Owner: " << ownerName << ", Name: " << name << std::endl;
}