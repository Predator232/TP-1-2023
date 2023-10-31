#include "Bird.h"

Bird::Bird(const std::string& breed, const std::string& color, const std::string& diet, const std::string& habitat)
    : Animal(breed, color), diet(diet), habitat(habitat) {
    std::cout << "Bird constructor called." << std::endl;
}


void Bird::serialize(std::ostream& os) const {
    os << "Bird\n";
    os << "Breed: " << breed << "\n";
    os << "Color: " << color << "\n";
    os << "Diet: " << diet << "\n";
    os << "Habitat: " << habitat << "\n";
}

void Bird::deserialize(std::istream& is) {
    std::string line;
    getline(is, line); 
    getline(is, line); 
    breed = line.substr(line.find(":") + 2); 
    getline(is, line); 
    color = line.substr(line.find(":") + 2); 
    getline(is, line);
    diet = line.substr(line.find(":") + 2); 
    getline(is, line);
    habitat = line.substr(line.find(":") + 2);
}

Bird::~Bird() {
    std::cout << "Bird destructor called." << std::endl;
}

void Bird::printInfo() {
    std::cout << "Bird - Breed: " << getBreed() << ", Color: " << getColor()
        << ", Diet: " << diet << ", Habitat: " << habitat << std::endl;
}