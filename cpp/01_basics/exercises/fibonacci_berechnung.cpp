/*
Übung 3 : Fibonacci - Zahlen

Algorithmus: Berechnung und Ausgabe der ersten N Fibonacci-Zahlen

1. Funktion berechneFibonacci(anzahl):
   a. Initialisiere einen leeren Vektor 'fibonacciZahlen'
   b. Setze a = 0, b = 1
   c. Wiederhole 'anzahl' mal:
      i.   Füge a zum Vektor 'fibonacciZahlen' hinzu
      ii.  Berechne temp = a + b
      iii. Setze a = b
      iv.  Setze b = temp
   d. Gib den Vektor 'fibonacciZahlen' zurück

2. Hauptprogramm:
   a. Definiere Konstante ANZAHL_FIBONACCI = 10
   b. Gib eine Einleitung aus
   c. Rufe berechneFibonacci(ANZAHL_FIBONACCI) auf und speichere das Ergebnis in 'fibonacciFolge'
   d. Für jede Zahl in 'fibonacciFolge':
      i. Gib die Zahl aus, gefolgt von einem Leerzeichen
   e. Gib einen Zeilenumbruch aus

Struktogramm(textuell) :
Beginn
|
+-- Definiere Funktion berechneFibonacci(anzahl)
|   |
|   +-- Initialisiere leeren Vektor fibonacciZahlen
|   |
|   +-- Setze a = 0, b = 1
|   |
|   +-- Für i von 0 bis anzahl-1
|   |   |
|   |   +-- Füge a zu fibonacciZahlen hinzu
|   |   |
|   |   +-- temp = a + b
|   |   |
|   |   +-- a = b
|   |   |
|   |   +-- b = temp
|   |
|   +-- Gib fibonacciZahlen zurück
|
+-- In main()
    |
    +-- Setze ANZAHL_FIBONACCI = 10
    |
    +-- Gib Einleitung aus
    |
    +-- Rufe berechneFibonacci(ANZAHL_FIBONACCI) auf und speichere Ergebnis in fibonacciFolge
    |
    +-- Für jede Zahl in fibonacciFolge
    |   |
    |   +-- Gib Zahl aus
    |
    +-- Gib Zeilenumbruch aus
|
Ende
*/

// fibonacci_berechnung.cpp
#include <iostream>
#include <vector>

// Funktion zur Berechnung der Fibonacci-Zahlen
std::vector<int> berechneFibonacci(int anzahl)
{
    std::vector<int> fibonacciZahlen;
    int a = 0, b = 1, temp;

    for (int i = 0; i < anzahl; ++i)
    {
        fibonacciZahlen.push_back(a);
        temp = a + b;
        a = b;
        b = temp;
    }

    return fibonacciZahlen;
}

int main()
{
    const int ANZAHL_FIBONACCI = 10;

    std::cout << "Die ersten " << ANZAHL_FIBONACCI << " Fibonacci-Zahlen:" << std::endl;

    // Berechne Fibonacci-Zahlen
    std::vector<int> fibonacciFolge = berechneFibonacci(ANZAHL_FIBONACCI);

    // Gib Fibonacci-Zahlen aus
    for (int zahl : fibonacciFolge)
    {
        std::cout << zahl << " ";
    }

    std::cout << std::endl;
    return 0;
}