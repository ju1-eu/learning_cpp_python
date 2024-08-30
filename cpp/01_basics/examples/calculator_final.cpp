/*

*/
// Finale Version des calculator.cpp
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <iomanip>

struct Calculation
{
    double num1, num2, result;
    std::string operation;
};

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

int main()
{
    std::vector<Calculation> history;

    while (true)
    {
        std::cout << "\n=== Taschenrechner ===" << std::endl;
        double num1 = getNumber("Geben Sie die erste Zahl ein: ");
        std::string operation = getOperation();
        double num2 = (operation != "sqrt") ? getNumber("Geben Sie die zweite Zahl ein: ") : 2;

        try
        {
            double result;
            if (operation == "+")
                result = add(num1, num2);
            else if (operation == "-")
                result = subtract(num1, num2);
            else if (operation == "*")
                result = multiply(num1, num2);
            else if (operation == "/")
                result = divide(num1, num2);
            else if (operation == "^")
                result = power(num1, num2);
            else if (operation == "root")
                result = root(num1, num2);
            else
                throw std::runtime_error("Ungültige Operation!");

            std::cout << "Ergebnis: " << result << std::endl;

            history.push_back({num1, num2, result, operation});
        }
        catch (const std::exception &e)
        {
            std::cout << "Fehler: " << e.what() << std::endl;
        }

        char choice;
        std::cout << "Möchten Sie den Verlauf anzeigen? (j/n): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 'j' || choice == 'J')
        {
            displayHistory(history);
        }

        std::cout << "Möchten Sie eine weitere Berechnung durchführen? (j/n): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice != 'j' && choice != 'J')
            break;
    }

    std::cout << "Vielen Dank für die Nutzung des Taschenrechners!" << std::endl;
    return 0;
}