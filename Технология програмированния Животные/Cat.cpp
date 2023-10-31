#include "Cat.h"

Cat::Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& name)
    : Animal(breed, color), ownerName(ownerName), name(name) {
    std::cout << "Cat constructor called." << std::endl;
}

void Cat::serialize(std::ostream& os) const {
    os << "Cat\n";
    os << "Breed: " << breed << "\n";
    os << "Color: " << color << "\n";
    os << "Owner Name: " << ownerName << "\n";
    os << "Name: " << name << "\n";
}

void Cat::deserialize(std::istream& is) {
    std::string line;
    getline(is, line); 
    getline(is, line);
    breed = line.substr(line.find(":") + 2); 
    getline(is, line); 
    color = line.substr(line.find(":") + 2); 
    getline(is, line); 
    ownerName = line.substr(line.find(":") + 2); 
    getline(is, line); 
    name = line.substr(line.find(":") + 2); 
}

Cat::~Cat() {
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::printInfo() {
    std::cout << "Cat - Breed: " << getBreed() << ", Color: " << getColor()
        << ", Owner: " << ownerName << ", Name: " << name << std::endl;
}