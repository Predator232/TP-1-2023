#ifndef FISH_H
#define FISH_H

#include "BaseAnimal.h"

class Fish : public Animal {
public:
    Fish(const std::string& breed, const std::string& color, const std::string& diet);

    void serialize(std::ostream& os) const override;
    void deserialize(std::istream& is) override;

    ~Fish();

    void printInfo() override;

private:
    std::string diet;
};

#endif  // FISH_H
