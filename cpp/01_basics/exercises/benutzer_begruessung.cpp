/*
Übung 1: Personalisierte Begrüßung

Algorithmus:
1. Benutzernamen einlesen
2. Benutzeralter einlesen
3. Personalisierte Begrüßung ausgeben

Struktogramm (textuell):
Beginn
|
+-- Funktion: clearInputBuffer()
|   |
|   +-- Lösche Eingabepuffer
|   +-- Ignoriere verbleibende Zeichen bis Zeilenumbruch
|
+-- Funktion: getName()
|   |
|   +-- Wiederhole
|   |   |
|   |   +-- Ausgabe: "Bitte geben Sie Ihren Namen ein: "
|   |   +-- Eingabe: name
|   |   |
|   |   +-- Wenn name leer ist
|   |       |
|   |       +-- Ausgabe: Fehlermeldung
|   |
|   +-- Bis name nicht leer ist
|   |
|   +-- Rückgabe: name
|
+-- Funktion: getAge()
|   |
|   +-- Wiederhole
|   |   |
|   |   +-- Ausgabe: "Bitte geben Sie Ihr Alter ein: "
|   |   +-- Eingabe: alter
|   |   |
|   |   +-- Wenn alter gültig (> 0 und < 150)
|   |   |   |
|   |   |   +-- clearInputBuffer()
|   |   |   +-- Rückgabe: alter
|   |   |
|   |   +-- Sonst
|   |       |
|   |       +-- Ausgabe: Fehlermeldung
|   |       +-- clearInputBuffer()
|   |
|   +-- Endlosschleife
|
+-- Funktion: printGreeting(name, alter)
|   |
|   +-- Ausgabe: "Hallo [name]! "
|   |
|   +-- Wenn alter < 18
|   |   |
|   |   +-- Ausgabe: Jugend-Nachricht
|   |
|   +-- Sonst wenn alter < 60
|   |   |
|   |   +-- Ausgabe: Erwachsenen-Nachricht
|   |
|   +-- Sonst
|   |   |
|   |   +-- Ausgabe: Senioren-Nachricht
|   |
|   +-- Ausgabe: Zeilenumbruch
|
+-- Hauptprogramm: main()
    |
    +-- name = getName()
    |
    +-- alter = getAge()
    |
    +-- printGreeting(name, alter)
    |
    +-- Rückgabe: 0
|
Ende
*/

// benutzer_begruessung.cpp
#include <iostream>
#include <string>
#include <limits>

void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getName()
{
    std::string name;
    do
    {
        std::cout << "Bitte geben Sie Ihren Namen ein: ";
        std::getline(std::cin, name);
        if (name.empty())
        {
            std::cout << "Der Name darf nicht leer sein. Bitte versuchen Sie es erneut." << std::endl;
        }
    } while (name.empty());
    return name;
}

int getAge()
{
    int alter;
    while (true)
    {
        std::cout << "Bitte geben Sie Ihr Alter ein: ";
        if (std::cin >> alter && alter > 0 && alter < 150)
        {
            clearInputBuffer();
            return alter;
        }
        else
        {
            std::cout << "Ungültige Eingabe. Bitte geben Sie ein gültiges Alter ein." << std::endl;
            clearInputBuffer();
        }
    }
}

void printGreeting(const std::string &name, int alter)
{
    std::cout << "Hallo " << name << "! ";
    if (alter < 18)
    {
        std::cout << "Mit " << alter << " Jahren bist du ja noch jung!";
    }
    else if (alter < 60)
    {
        std::cout << "Mit " << alter << " Jahren sind Sie im besten Alter!";
    }
    else
    {
        std::cout << "Mit " << alter << " Jahren haben Sie schon viel erlebt!";
    }
    std::cout << std::endl;
}

int main()
{
    std::string name = getName();
    int alter = getAge();
    printGreeting(name, alter);
    return 0;
}