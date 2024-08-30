// calculator.cpp (Syntax und Datentypen)
#include <iostream>

int main()
{
    double num1, num2, result;
    char operation;

    std::cout << "Geben Sie die erste Zahl ein: ";
    std::cin >> num1;

    std::cout << "Geben Sie die zweite Zahl ein: ";
    std::cin >> num2;

    std::cout << "Wählen Sie eine Operation (+, -, *, /): ";
    std::cin >> operation;

    switch (operation)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
        }
        else
        {
            std::cout << "Fehler: Division durch Null!" << std::endl;
            return 1;
        }
        break;
    default:
        std::cout << "Ungültige Operation!" << std::endl;
        return 1;
    }

    std::cout << "Ergebnis: " << result << std::endl;

    return 0;
}