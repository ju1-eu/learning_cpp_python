// calculator.cpp (Funktionen, modularisiert)
#include <iostream>

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b)
{
    if (b != 0)
        return a / b;
    throw std::runtime_error("Division durch Null!");
}

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
        std::cin >> input;
        if (isValidNumber(input))
        {
            return std::stod(input);
        }
        std::cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << std::endl;
    }
}

char getOperation()
{
    char op;
    std::cout << "Wählen Sie eine Operation (+, -, *, /): ";
    std::cin >> op;
    return op;
}

int main()
{
    while (true)
    {
        double num1 = getNumber("Geben Sie die erste Zahl ein: ");
        double num2 = getNumber("Geben Sie die zweite Zahl ein: ");
        char operation = getOperation();

        try
        {
            double result;
            switch (operation)
            {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                result = divide(num1, num2);
                break;
            default:
                throw std::runtime_error("Ungültige Operation!");
            }
            std::cout << "Ergebnis: " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Fehler: " << e.what() << std::endl;
        }

        char choice;
        std::cout << "Möchten Sie eine weitere Berechnung durchführen? (j/n): ";
        std::cin >> choice;
        if (choice != 'j' && choice != 'J')
            break;
    }

    return 0;
}