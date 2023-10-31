#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Keeper.h"

int main() {
    AnimalKeeper keeper;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a Fish\n";
        std::cout << "2. Add a Bird\n";
        std::cout << "3. Add a Cat\n";
        std::cout << "4. Remove the last animal\n";
        std::cout << "5. Print all animals\n";
        std::cout << "6. Save animals to a file\n";
        std::cout << "7. Load animals from a file\n";
        std::cout << "8. Modify an Animal\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cin.ignore();

        switch (choice) {
        case 1:
        {
            system("cls");
            std::string fishBreed, fishColor, fishDiet;
            std::cout << "Enter breed for the Fish: ";
            getline(std::cin, fishBreed);
            std::cout << "Enter color for the Fish: ";
            getline(std::cin, fishColor);
            std::cout << "Enter diet for the Fish: ";
            getline(std::cin, fishDiet);
            keeper.addFish(fishBreed, fishColor, fishDiet);
            break;
        }
        case 2:
        {
            system("cls");
            std::string birdBreed, birdColor, birdDiet, birdHabitat;
            std::cout << "Enter breed for the Bird: ";
            getline(std::cin, birdBreed);
            std::cout << "Enter color for the Bird: ";
            getline(std::cin, birdColor);
            std::cout << "Enter diet for the Bird: ";
            getline(std::cin, birdDiet);
            std::cout << "Enter habitat for the Bird: ";
            getline(std::cin, birdHabitat);
            keeper.addBird(birdBreed, birdColor, birdDiet, birdHabitat);
            break;
        }
        case 3:
        {
            system("cls");
            std::string catBreed, catColor, ownerName, catName;
            std::cout << "Enter breed for the Cat: ";
            getline(std::cin, catBreed);
            std::cout << "Enter color for the Cat: ";
            getline(std::cin, catColor);
            std::cout << "Enter owner's name: ";
            getline(std::cin, ownerName);
            std::cout << "Enter name for the Cat: ";
            getline(std::cin, catName);
            keeper.addCat(catBreed, catColor, ownerName, catName);
            break;
        }
        case 4:
        {
            system("cls");
            keeper.removeLastAnimal();
            break;
        }
        case 5:
        {
            system("cls");
            keeper.printAllAnimals();
            break;
        }
        case 6:
        {
            system("cls");
            std::string filename;
            std::cout << "Enter the filename to save animals: ";
            std::cin >> filename;
            try {
                keeper.saveToFile(filename);
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;

        }
        case 7:
        {   
            system("cls");
            std::string filename;
            std::cout << "Enter the filename to load animals: ";
            std::cin >> filename;
            try {
                keeper.loadFromFile(filename);
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 8:

            keeper.modifyAnimalInfo();
            break;
        case 0:
            break;
        default:
            system("cls");
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}