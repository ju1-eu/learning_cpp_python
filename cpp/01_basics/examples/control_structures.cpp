/*
Algorithmus:
1. Initialisiere einen Zufallszahlengenerator
2. Wiederhole, bis der Benutzer das Programm beenden möchte:
   a. Zeige ein Menü mit Optionen (Zahlenraten, Primzahlprüfung, Fibonacci-Reihe, Beenden)
   b. Lese die Benutzerwahl ein
   c. Führe basierend auf der Wahl die entsprechende Aktion aus:
      - Zahlenraten: Generiere Zufallszahl, lasse Benutzer raten
      - Primzahlprüfung: Prüfe, ob eingegebene Zahl prim ist
      - Fibonacci-Reihe: Generiere Fibonacci-Reihe bis zum eingegebenen Wert
      - Beenden: Beende das Programm
   d. Frage, ob der Benutzer weiterspielen möchte

Struktogramm (textuell):

Zahlenspiel-Programm
├─ Initialisiere Zufallszahlengenerator
├─ Wiederhole
│  ├─ Zeige Menü
│  ├─ Lese Benutzerwahl
│  ├─ Fallunterscheidung: Benutzerwahl
│  │  ├─ Fall: Zahlenraten
│  │  │  ├─ Generiere Zufallszahl
│  │  │  ├─ Wiederhole
│  │  │  │  ├─ Lese Benutzertipp
│  │  │  │  ├─ Vergleiche Tipp mit Zufallszahl
│  │  │  │  └─ Gib Hinweis (zu hoch/zu niedrig)
│  │  │  └─ Bis Zahl erraten
│  │  ├─ Fall: Primzahlprüfung
│  │  │  ├─ Lese Zahl ein
│  │  │  ├─ Prüfe auf Primzahl
│  │  │  └─ Gib Ergebnis aus
│  │  ├─ Fall: Fibonacci-Reihe
│  │  │  ├─ Lese Anzahl ein
│  │  │  ├─ Generiere Fibonacci-Reihe
│  │  │  └─ Gib Reihe aus
│  │  └─ Fall: Beenden
│  │     └─ Setze Programmende-Flag
│  ├─ Frage nach Weiterspielen
└─ Bis Benutzer nicht weiterspielen möchte
*/
// control_structures.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

bool istPrimzahl(int zahl)
{
    if (zahl <= 1)
        return false;
    for (int i = 2; i * i <= zahl; ++i)
    {
        if (zahl % i == 0)
            return false;
    }
    return true;
}

void fibonacciReihe(int n)
{
    int a = 0, b = 1;
    for (int i = 0; i < n; ++i)
    {
        std::cout << a << " ";
        int temp = a;
        a = b;
        b = temp + b;
    }
    std::cout << std::endl;
}

int main()
{
    srand(time(0));
    bool weiterspielen = true;

    do
    {
        std::cout << "\nZahlenspiel-Menü:\n"
                  << "1. Zahlenraten\n"
                  << "2. Primzahlprüfung\n"
                  << "3. Fibonacci-Reihe\n"
                  << "4. Beenden\n"
                  << "Ihre Wahl: ";

        int wahl;
        std::cin >> wahl;

        switch (wahl)
        {
        case 1:
        {
            int zufallszahl = rand() % 100 + 1;
            int tipp, versuche = 0;
            std::cout << "Ich habe mir eine Zahl zwischen 1 und 100 ausgedacht.\n";
            do
            {
                std::cout << "Ihr Tipp: ";
                std::cin >> tipp;
                versuche++;
                if (tipp < zufallszahl)
                    std::cout << "Zu niedrig!\n";
                else if (tipp > zufallszahl)
                    std::cout << "Zu hoch!\n";
                else
                    std::cout << "Richtig! Sie haben " << versuche << " Versuche gebraucht.\n";
            } while (tipp != zufallszahl);
            break;
        }
        case 2:
        {
            int zahl;
            std::cout << "Geben Sie eine Zahl ein: ";
            std::cin >> zahl;
            if (istPrimzahl(zahl))
                std::cout << zahl << " ist eine Primzahl.\n";
            else
                std::cout << zahl << " ist keine Primzahl.\n";
            break;
        }
        case 3:
        {
            int n;
            std::cout << "Wie viele Fibonacci-Zahlen möchten Sie sehen? ";
            std::cin >> n;
            fibonacciReihe(n);
            break;
        }
        case 4:
            weiterspielen = false;
            std::cout << "Auf Wiedersehen!\n";
            break;
        default:
            std::cout << "Ungültige Eingabe!\n";
        }

        if (weiterspielen)
        {
            char antwort;
            std::cout << "Möchten Sie weiterspielen? (j/n): ";
            std::cin >> antwort;
            weiterspielen = (antwort == 'j' || antwort == 'J');
        }
    } while (weiterspielen);

    return 0;
}