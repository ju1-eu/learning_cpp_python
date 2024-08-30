/*
Übung 5: Einfaches Adressbuch

Algorithmus:
1. Struktur für Kontakt definieren
2. Vektor für Kontakte erstellen
3. Schleife für Benutzerinteraktion:
   a. Menü anzeigen
   b. Benutzereingabe verarbeiten
   c. Gewählte Aktion ausführen (Hinzufügen, Anzeigen, Beenden)

Struktogramm (textuell):
Beginn
|
+-- Struktur: Kontakt
|   |
|   +-- name: string
|   +-- telefon: string
|
+-- Funktion: kontaktHinzufuegen(adressbuch)
|   |
|   +-- Erstelle neuerKontakt
|   |
|   +-- Ausgabe: "Name: "
|   +-- Eingabe: neuerKontakt.name (mit getline)
|   |
|   +-- Ausgabe: "Telefon: "
|   +-- Eingabe: neuerKontakt.telefon (mit getline)
|   |
|   +-- Füge neuerKontakt zu adressbuch hinzu
|
+-- Funktion: kontakteAnzeigen(adressbuch)
|   |
|   +-- Für jeden kontakt in adressbuch
|   |   |
|   |   +-- Ausgabe: "Name: " + kontakt.name + ", Telefon: " + kontakt.telefon
|
+-- Hauptprogramm: main()
    |
    +-- Erstelle leeren vector<Kontakt> adressbuch
    |
    +-- Wiederhole
    |   |
    |   +-- Ausgabe: Menü (1. Hinzufügen, 2. Anzeigen, 3. Beenden)
    |   +-- Eingabe: auswahl
    |   |
    |   +-- Switch (auswahl)
    |   |   |
    |   |   +-- Fall 1:
    |   |   |   |
    |   |   |   +-- Rufe kontaktHinzufuegen(adressbuch) auf
    |   |   |
    |   |   +-- Fall 2:
    |   |   |   |
    |   |   |   +-- Rufe kontakteAnzeigen(adressbuch) auf
    |   |   |
    |   |   +-- Fall 3:
    |   |   |   |
    |   |   |   +-- Ausgabe: "Programm wird beendet."
    |   |   |
    |   |   +-- Standard:
    |   |       |
    |   |       +-- Ausgabe: "Ungültige Auswahl."
    |   |
    +-- Bis auswahl == 3
    |
    +-- Rückgabe: 0
|
Ende
*/
// adressbuch_vector_string.cpp
#include <iostream>
#include <vector>
#include <string>

struct Kontakt
{
    std::string name;
    std::string telefon;
};

void kontaktHinzufuegen(std::vector<Kontakt> &adressbuch)
{
    Kontakt neuerKontakt;
    std::cout << "Name: ";
    std::cin.ignore();
    std::getline(std::cin, neuerKontakt.name);
    std::cout << "Telefon: ";
    std::getline(std::cin, neuerKontakt.telefon);
    adressbuch.push_back(neuerKontakt);
}

void kontakteAnzeigen(const std::vector<Kontakt> &adressbuch)
{
    for (const auto &kontakt : adressbuch)
    {
        std::cout << "Name: " << kontakt.name << ", Telefon: " << kontakt.telefon << std::endl;
    }
}

int main()
{
    std::vector<Kontakt> adressbuch;
    int auswahl;

    do
    {
        std::cout << "\n1. Kontakt hinzufügen\n2. Kontakte anzeigen\n3. Beenden\nAuswahl: ";
        std::cin >> auswahl;

        switch (auswahl)
        {
        case 1:
            kontaktHinzufuegen(adressbuch);
            break;
        case 2:
            kontakteAnzeigen(adressbuch);
            break;
        case 3:
            std::cout << "Programm wird beendet." << std::endl;
            break;
        default:
            std::cout << "Ungültige Auswahl." << std::endl;
        }
    } while (auswahl != 3);

    return 0;
}
