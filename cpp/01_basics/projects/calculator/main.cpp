#include "calculator.h"
#include <iostream>
#include <vector>
#include <limits>

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