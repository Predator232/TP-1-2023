#ifndef BIRD_H
#define BIRD_H

#include "BaseAnimal.h"

class Bird : public Animal {
public:
    Bird(const std::string& breed, const std::string& color, const std::string& diet, const std::string& habitat);

    void updateHabitat(const std::string& newHabitat) override {
        habitat = newHabitat;
    }

    void updateDiet(const std::string& newDiet) {
        diet = newDiet;
    }

    void serialize(std::ostream& os) const override;
    void deserialize(std::istream& is) override;

    ~Bird();

    void printInfo() override;

private:
    std::string diet;
    std::string habitat;
};

#endif  // BIRD_H