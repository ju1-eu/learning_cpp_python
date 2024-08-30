/*
Übung 4: Durchschnitt berechnen

Algorithmus:
1. Summe initialisieren
2. Schleife über alle Array-Elemente:
   a. Element zur Summe addieren
3. Durchschnitt berechnen (Summe / Anzahl der Elemente)
4. Durchschnitt zurückgeben

Struktogramm (textuell):
Beginn
|
+-- Funktion: berechneDurchschnitt(zahlen)
|   |
|   +-- Wenn zahlen leer ist
|   |   |
|   |   +-- Wirf Ausnahme: "Das Array ist leer."
|   |
|   +-- summe = 0.0
|   |
|   +-- Für jede zahl in zahlen
|   |   |
|   |   +-- summe += zahl
|   |
|   +-- Rückgabe: summe / zahlen.size()
|
+-- Funktion: druckeArray(zahlen)
|   |
|   +-- Ausgabe: "Array-Elemente: "
|   |
|   +-- Für jede zahl in zahlen
|   |   |
|   |   +-- Ausgabe: zahl + " "
|   |
|   +-- Ausgabe: Zeilenumbruch
|
+-- Hauptprogramm: main()
    |
    +-- Try-Block
    |   |
    |   +-- Erstelle vector<int> zahlen = {1, 2, 3, 4, 5}
    |   |
    |   +-- Rufe druckeArray(zahlen) auf
    |   |
    |   +-- durchschnitt = berechneDurchschnitt(zahlen)
    |   |
    |   +-- Ausgabe: "Der Durchschnitt ist: " + durchschnitt
    |
    +-- Catch-Block (std::exception& e)
    |   |
    |   +-- Ausgabe Fehler: e.what()
    |   |
    |   +-- Rückgabe: 1
    |
    +-- Rückgabe: 0
|
Ende
*/

// array_durchschnitt_berechnung.cpp
#include <iostream>
#include <vector>
#include <stdexcept>

double berechneDurchschnitt(const std::vector<int> &zahlen)
{
    if (zahlen.empty())
    {
        throw std::runtime_error("Das Array ist leer.");
    }

    double summe = 0.0;
    for (int zahl : zahlen)
    {
        summe += zahl;
    }

    return summe / zahlen.size();
}

void druckeArray(const std::vector<int> &zahlen)
{
    std::cout << "Array-Elemente: ";
    for (int zahl : zahlen)
    {
        std::cout << zahl << " ";
    }
    std::cout << std::endl;
}

int main()
{
    try
    {
        std::vector<int> zahlen = {1, 2, 3, 4, 5};

        druckeArray(zahlen);

        double durchschnitt = berechneDurchschnitt(zahlen);

        std::cout << "Der Durchschnitt ist: " << durchschnitt << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Fehler: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}