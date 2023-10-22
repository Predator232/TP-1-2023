#include "BaseAnimal.h"

Animal::Animal(const std::string& breed, const std::string& color)
    : breed(breed), color(color) {
    std::cout << "Animal constructor called." << std::endl;
}


void Animal::serialize(std::ostream& os) const {
    os << breed << " " << color;
}

void Animal::deserialize(std::istream& is) {
    is >> breed >> color;
}
Animal::~Animal() {
    std::cout << "Animal destructor called." << std::endl;
}

const std::string& Animal::getBreed() const {
    return breed;
}

const std::string& Animal::getColor() const {
    return color;
}

void Animal::printInfo() {
    std::cout << "Breed: " << breed << ", Color: " << color << std::endl;
}