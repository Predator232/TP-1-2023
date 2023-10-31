#ifndef CAT_H
#define CAT_H

#include "BaseAnimal.h"

class Cat : public Animal {
public:
    Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& name);

    void updateOwnerName(const std::string& newOwnerName) override {
        ownerName = newOwnerName;
    }

    void serialize(std::ostream& os) const override;
    void deserialize(std::istream& is) override;

    ~Cat();

    void printInfo() override;

private:
    std::string ownerName;
    std::string name;
};

#endif  // CAT_H
