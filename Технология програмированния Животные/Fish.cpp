#include "Fish.h"

Fish::Fish(const std::string& breed, const std::string& color, const std::string& diet)
    : Animal(breed, color), diet(diet) {
    std::cout << "Fish constructor called." << std::endl;
}

void Fish::serialize(std::ostream& os) const {
    os << "Fish ";
    Animal::serialize(os);
    os << " " << diet;
}

void Fish::deserialize(std::istream& is) {
    Animal::deserialize(is);
    is >> diet;
}

Fish::~Fish() {
    std::cout << "Fish destructor called." << std::endl;
}

void Fish::printInfo() {
    std::cout << "Fish - Breed: " << getBreed() << ", Color: " << getColor() << ", Diet: " << diet << std::endl;
}