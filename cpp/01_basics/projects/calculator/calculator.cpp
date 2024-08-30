#include "calculator.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>

// Arithmetische Operationen
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b)
{
    if (b == 0)
        throw std::runtime_error("Division durch Null!");
    return a / b;
}
double power(double a, double b) { return std::pow(a, b); }
double root(double a, double b)
{
    if (a < 0 && std::fmod(b, 2) == 0)
        throw std::runtime_error("Reelle Wurzel aus negativer Zahl nicht möglich!");
    return std::pow(a, 1.0 / b);
}

// Hilfsfunktionen
bool isValidNumber(const std::string &str)
{
    try
    {
        std::stod(str);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

double getNumber(const std::string &prompt)
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (isValidNumber(input))
        {
            return std::stod(input);
        }
        std::cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << std::endl;
    }
}

std::string getOperation()
{
    std::string op;
    std::cout << "Wählen Sie eine Operation (+, -, *, /, ^, root): ";
    std::getline(std::cin, op);
    return op;
}

void displayHistory(const std::vector<Calculation> &history)
{
    std::cout << "\nBerechnungsverlauf:" << std::endl;
    std::cout << std::setw(10) << "Num1" << std::setw(10) << "Op" << std::setw(10) << "Num2" << std::setw(15) << "Ergebnis" << std::endl;
    std::cout << std::string(45, '-') << std::endl;
    for (const auto &calc : history)
    {
        std::cout << std::setw(10) << calc.num1 << std::setw(10) << calc.operation
                  << std::setw(10) << calc.num2 << std::setw(15) << calc.result << std::endl;
    }
}