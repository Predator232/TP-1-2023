#ifndef ANIMAL_KEEPER_H
#define ANIMAL_KEEPER_H

#include "BaseAnimal.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"
#include <fstream>
#include <vector>

class AnimalKeeper {
public:
    AnimalKeeper();
    ~AnimalKeeper();

    void addFish(const std::string& breed, const std::string& color, const std::string& diet);
    void addBird(const std::string& breed, const std::string& color, const std::string& diet, const std::string& habitat);
    void addCat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& name);
    void removeLastAnimal();
    void printAllAnimals();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);

private:
    std::vector<Animal*> animals;
};

#endif  // ANIMAL_KEEPER_H
