#ifndef BIRD_H
#define BIRD_H

#include "BaseAnimal.h"

class Bird : public Animal {
public:
    Bird(const std::string& breed, const std::string& color, const std::string& diet, const std::string& habitat);

    void serialize(std::ostream& os) const override;
    void deserialize(std::istream& is) override;

    ~Bird();

    void printInfo() override;

private:
    std::string diet;
    std::string habitat;
};

#endif  // BIRD_H