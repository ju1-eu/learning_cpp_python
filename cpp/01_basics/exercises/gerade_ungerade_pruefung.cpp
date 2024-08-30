/*
Übung 2: Prüfung auf gerade oder ungerade Zahl

Algorithmus:
1. Zahl einlesen
2. Prüfen, ob Zahl durch 2 teilbar ist
3. Ergebnis ausgeben

Struktogramm (textuell):
Beginn
|
+-- Wiederhole
    |
    +-- Eingabe: Zahl
    |
    +-- Solange Eingabe ungültig
    |   |
    |   +-- Fehlermeldung ausgeben
    |   +-- Eingabepuffer leeren
    |   +-- Neue Eingabe anfordern
    |
    +-- Wenn (Zahl % 2 == 0)
    |   |
    |   +-- Ausgabe: "Gerade"
    |   |
    |   Sonst
    |   |
    |   +-- Ausgabe: "Ungerade"
    |
    +-- Frage nach weiterer Prüfung
    |
+-- Bis Benutzer nicht weitermachen möchte
|
Ende
*/

// gerade_ungerade_pruefung.cpp
#include <iostream>
#include <limits>

bool istGerade(int zahl)
{
    return zahl % 2 == 0;
}

void pruefeZahl(int zahl)
{
    if (istGerade(zahl))
    {
        std::cout << zahl << " ist gerade." << std::endl;
    }
    else
    {
        std::cout << zahl << " ist ungerade." << std::endl;
    }
}

int main()
{
    int zahl;
    char weitermachen;

    do
    {
        std::cout << "Geben Sie eine ganze Zahl ein: ";
        while (!(std::cin >> zahl))
        {
            std::cout << "Ungültige Eingabe. Bitte geben Sie eine ganze Zahl ein: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        pruefeZahl(zahl);

        std::cout << "Möchten Sie eine weitere Zahl prüfen? (j/n): ";
        std::cin >> weitermachen;
    } while (weitermachen == 'j' || weitermachen == 'J');

    return 0;
}