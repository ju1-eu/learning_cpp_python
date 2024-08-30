// calculator.cpp (Kontrollstrukturen)
#include <iostream>

int main()
{
    double num1, num2, result;
    char operation;
    bool continueCalculating = true;

    while (continueCalculating)
    {
        std::cout << "Geben Sie die erste Zahl ein: ";
        while (!(std::cin >> num1))
        {
            std::cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << "Geben Sie die zweite Zahl ein: ";
        while (!(std::cin >> num2))
        {
            std::cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

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
                continue;
            }
            break;
        default:
            std::cout << "Ungültige Operation!" << std::endl;
            continue;
        }

        std::cout << "Ergebnis: " << result << std::endl;

        char choice;
        std::cout << "Möchten Sie eine weitere Berechnung durchführen? (j/n): ";
        std::cin >> choice;
        continueCalculating = (choice == 'j' || choice == 'J');
    }

    return 0;
}