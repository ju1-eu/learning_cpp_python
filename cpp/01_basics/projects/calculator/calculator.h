#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>

struct Calculation
{
    double num1, num2, result;
    std::string operation;
};

// Arithmetische Operationen
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);
double root(double a, double b);

// Hilfsfunktionen
bool isValidNumber(const std::string &str);
double getNumber(const std::string &prompt);
std::string getOperation();
void displayHistory(const std::vector<Calculation> &history);

#endif // CALCULATOR_H