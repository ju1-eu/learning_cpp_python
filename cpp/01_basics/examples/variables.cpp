/*

*/
// variables.cpp
#include <iostream>

int main()
{
    // Deklaration und Initialisierung verschiedener Variablentypen
    int integerVar = 10;
    float floatVar = 3.14f;
    double doubleVar = 3.14159;
    char charVar = 'A';
    bool boolVar = true;

    // Durchführung einfacher arithmetischer Operationen
    int sum = integerVar + 5;
    float product = floatVar * 2;
    double difference = doubleVar - 1.5;

    // Typkonvertierungen
    int intFromFloat = static_cast<int>(floatVar);
    float floatFromInt = static_cast<float>(integerVar);

    // Ausgabe der Ergebnisse
    std::cout << "Integer: " << integerVar << std::endl;
    std::cout << "Float: " << floatVar << std::endl;
    std::cout << "Double: " << doubleVar << std::endl;
    std::cout << "Char: " << charVar << std::endl;
    std::cout << "Bool: " << std::boolalpha << boolVar << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Int from Float: " << intFromFloat << std::endl;
    std::cout << "Float from Int: " << floatFromInt << std::endl;

    return 0;
}