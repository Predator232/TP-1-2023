#include "Fish.h"

Fish::Fish(const std::string& breed, const std::string& color, const std::string& diet)
    : Animal(breed, color), diet(diet) {
    std::cout << "Fish constructor called." << std::endl;
}

void Fish::serialize(std::ostream& os) const {
    os << "Fish\n";
    os << "Breed: " << getBreed() << "\n";
    os << "Color: " << getColor() << "\n";
    os << "Diet: " << diet << "\n";
}

void Fish::deserialize(std::istream& is) {
    std::string line;
    getline(is, line); 
    getline(is, line); 
    breed = line.substr(line.find(":") + 2); 
    getline(is, line); 
    color = line.substr(line.find(":") + 2); 
    getline(is, line); 
    diet = line.substr(line.find(":") + 2); 
}

Fish::~Fish() {
    std::cout << "Fish destructor called." << std::endl;
}

void Fish::printInfo() {
    std::cout << "Fish - Breed: " << getBreed() << ", Color: " << getColor() << ", Diet: " << diet << std::endl;
}