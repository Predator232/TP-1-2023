#include "Bird.h"

Bird::Bird(const std::string& breed, const std::string& color, const std::string& diet, const std::string& habitat)
    : Animal(breed, color), diet(diet), habitat(habitat) {
    std::cout << "Bird constructor called." << std::endl;
}


void Bird::serialize(std::ostream& os) const {
    os << "Bird ";
    Animal::serialize(os);
    os << " " << diet << " " << habitat;
}

void Bird::deserialize(std::istream& is) {
    Animal::deserialize(is);
    is >> diet >> habitat;
}

Bird::~Bird() {
    std::cout << "Bird destructor called." << std::endl;
}

void Bird::printInfo() {
    std::cout << "Bird - Breed: " << getBreed() << ", Color: " << getColor()
        << ", Diet: " << diet << ", Habitat: " << habitat << std::endl;
}