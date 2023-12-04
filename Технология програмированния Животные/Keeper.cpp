#include "Keeper.h"
#include <fstream>

const Animaloperator& operator++(Animaloperator& i) {
    i.value++;
    return i;
}

AnimalKeeper::AnimalKeeper() {}

AnimalKeeper::~AnimalKeeper() {
    for (auto animal : animals) {
        delete animal;
    }
}

void AnimalKeeper::modifyAnimalInfo() {
    system("cls");
    if (animals.empty()) {
        std::cout << "No animals are currently stored." << std::endl;
        return;
    }

    std::cout << "Select an animal to modify:\n";
    for (size_t i = 0; i < animals.size(); ++i) {
        std::cout << i + 1 << ". ";
        animals[i]->printInfo();
    }

    int selectedIndex;
    std::cout << "Enter the index of the animal you want to modify: ";
    std::cin >> selectedIndex;

    if (selectedIndex > 0 && selectedIndex <= static_cast<int>(animals.size())) {
        Animal* selectedAnimal = animals[selectedIndex - 1];

        int modificationType;
        std::cout << "Select the type of modification:\n";
        std::cout << "1. Breed and Color\n";
        std::cout << "2. Diet (for Birds/Fish)\n";
        std::cout << "3. Habitat (for Birds)\n";
        std::cout << "4. Owner Name (for Cats)\n";
        std::cout << "Enter your choice: ";
        std::cin >> modificationType;
        std::cin.ignore();

        if (modificationType == 1) {
            std::string newBreed, newColor;
            std::cout << "Enter new breed: ";
            getline(std::cin, newBreed);
            std::cout << "Enter new color: ";
            getline(std::cin, newColor);
            selectedAnimal->updateInfo(newBreed, newColor);
        }
        else if (modificationType == 2) {

            if (Fish* fish = dynamic_cast<Fish*>(selectedAnimal)) {
                std::string newDiet;
                std::cout << "Enter new diet: ";
                getline(std::cin, newDiet);
                fish->updateDiet(newDiet);
            }
            else if (Bird* bird = dynamic_cast<Bird*>(selectedAnimal)) {
                std::string newDiet;
                std::cout << "Enter new diet: ";
                getline(std::cin, newDiet);
                bird->updateDiet(newDiet);
            }
        }
        else if (modificationType == 3) {

            if (Bird* bird = dynamic_cast<Bird*>(selectedAnimal)) {
                std::string newHabitat;
                std::cout << "Enter new habitat: ";
                getline(std::cin, newHabitat);
                bird->updateHabitat(newHabitat);
            }
        }
        else if (modificationType == 4) {

            if (Cat* cat = dynamic_cast<Cat*>(selectedAnimal)) {
                std::string newOwnerName;
                std::cout << "Enter new owner name: ";
                getline(std::cin, newOwnerName);
                cat->updateOwnerName(newOwnerName);
            }
        }
        else {
            std::cout << "Invalid modification type. No changes were made." << std::endl;
        }
        std::cout << "Animal information updated successfully." << std::endl;
    }
    else {
        std::cout << "Invalid index. No animal was modified." << std::endl;
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