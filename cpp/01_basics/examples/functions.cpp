/*

*/
// functions.cpp
#include <iostream>
#include <string>

// Funktion mit verschiedenen Parametertypen
void printInfo(std::string name, int age, double height)
{
    std::cout << name << " ist " << age << " Jahre alt und " << height << "m groß." << std::endl;
}

// Überladene Funktionen
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }

// Funktion mit Referenzparameter
void increment(int &value) { ++value; }

int main()
{
    // Verwendung der Funktion mit verschiedenen Parametertypen
    printInfo("Max Mustermann", 30, 1.80);

    // Verwendung überladener Funktionen
    std::cout << "3 + 4 = " << add(3, 4) << std::endl;
    std::cout << "3.14 + 2.86 = " << add(3.14, 2.86) << std::endl;

    // Verwendung von Referenzparametern
    int value = 5;
    std::cout << "Vor Inkrement: " << value << std::endl;
    increment(value);
    std::cout << "Nach Inkrement: " << value << std::endl;

    return 0;
}