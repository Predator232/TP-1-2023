#include "Keeper.h"
#include <fstream>

AnimalKeeper::AnimalKeeper() {}

AnimalKeeper::~AnimalKeeper() {
    for (auto animal : animals) {
        delete animal;
    }
}

void AnimalKeeper::addFish(const std::string& breed, const std::string& color, const std::string& diet) {
    animals.push_back(new Fish(breed, color, diet));
}

void AnimalKeeper::addBird(const std::string& breed, const std::string& color, const std::string& diet, const std::string& habitat) {
    animals.push_back(new Bird(breed, color, diet, habitat));
}

void AnimalKeeper::addCat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& name) {
    animals.push_back(new Cat(breed, color, ownerName, name));
}

void AnimalKeeper::removeLastAnimal() {
    if (!animals.empty()) {
        delete animals.back();
        animals.pop_back();
    }
}

void AnimalKeeper::printAllAnimals() {
    for (auto animal : animals) {
        animal->printInfo();
    }
}

void AnimalKeeper::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& animal : animals) {
            animal->serialize(file);
            file << "\n";
        }
        file.close();
        std::cout << "Animals saved to file: " << filename << std::endl;
    }
    else {
        throw std::runtime_error("Failed to open the file for saving.");
    }
}

void AnimalKeeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string type;
        while (file >> type) {
            Animal* animal = nullptr;
            if (type == "Fish") {
                animal = new Fish("", "", "");
            }
            else if (type == "Bird") {
                animal = new Bird("", "", "", "");
            }
            else if (type == "Cat") {
                animal = new Cat("", "", "", "");
            }

            if (animal) {
                animal->deserialize(file);
                animals.push_back(animal);
            }
        }
        file.close();
        std::cout << "Animals loaded from file: " << filename << std::endl;
    }
    else {
        throw std::runtime_error("Failed to open the file for loading.");
    }
}