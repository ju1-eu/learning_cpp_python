# Lernmaterial zu C++ Basics

- [Lernmaterial zu C++ Basics](#lernmaterial-zu-c-basics)
  - [Zusammenfassung](#zusammenfassung)
  - [Notizen](#notizen)
  - [Beispiele](#beispiele)

## Zusammenfassung

1. **Syntax und Datentypen**
   - Grundlegende Syntax (Semikolons, Blöcke)
   - Primitive Datentypen (int, float, double, char, bool)
   - Variablendeklaration und -initialisierung
   - Konstanten (const)
   - Typenumwandlung (implizit und explizit)

2. **Kontrollstrukturen**
   - Verzweigungen (if-else, switch-case)
   - Schleifen (for, while, do-while)
   - Break und continue
   - Logische Operatoren (&&, ||, !)

3. **Funktionen**
   - Funktionsdeklaration und -definition
   - Parameter und Rückgabewerte
   - Überladung von Funktionen
   - Inline-Funktionen
   - Rekursion

4. **Grundlegende Datenstrukturen**
   - Arrays (eindimensional und mehrdimensional)
   - std::vector
   - std::string
   - Einführung in die STL (Standard Template Library)

## Notizen

1. **Syntax und Datentypen**
   - C++ ist eine case-sensitive Sprache
   - Jede Anweisung endet mit einem Semikolon
   - Codeblöcke werden durch geschweifte Klammern {} begrenzt
   - **Hauptdatentypen**:
        - int: Ganzzahlen (4 Bytes, $-2^{31} \text{ bis } 2^{31-1}$)
        - float: Gleitkommazahlen einfacher Genauigkeit (4 Bytes)
        - double: Gleitkommazahlen doppelter Genauigkeit (8 Bytes)
        - char: Einzelne Zeichen (1 Byte)
        - bool: Wahrheitswerte (true oder false)
   - Variablendeklaration: `Typ Name;`
   - Variableninitialisierung: `Typ Name = Wert;`
   - Konstanten mit 'const' deklarieren: `const int MAX_VALUE = 100`;
   - Implizite Typenumwandlung: `int zu float`
   - Explizite Typenumwandlung: `static_cast<neuer_typ>(variable)`

2. **Kontrollstrukturen**
   - if-else Syntax:

     ```c++
     if (Bedingung) {
         // Code
     } else if (Bedingung) {
         // Code
     } else {
         // Code
     }
     ```

   - switch-case Syntax:
  
     ```c++
     switch (variable) {
         case Wert1:
             // Code
             break;
         case Wert2:
             // Code
             break;
         default:
             // Code
     }
     ```

   - for-Schleife: for (Initialisierung; Bedingung; Inkrementierung) { }
   - while-Schleife: while (Bedingung) { }
   - do-while-Schleife: do { } while (Bedingung);
   - break: Beendet die aktuelle Schleife oder switch-Anweisung
   - continue: Springt zum nächsten Schleifendurchlauf
   - Logische Operatoren: && (und), || (oder), ! (nicht)

3. **Funktionen**
   - Funktionsdeklaration: Rückgabetyp Funktionsname(Parameter);
   - Funktionsdefinition:

     ```c++
     Rückgabetyp Funktionsname(Parameter) {
         // Funktionskörper
         return Wert;
     }
     ```

   - Void-Funktionen haben keinen Rückgabewert
   - Parameterübergabe: by value, by reference (&), by pointer (*)
   - Überladung: Mehrere Funktionen mit gleichem Namen, aber unterschiedlichen Parametern
   - Inline-Funktionen: inline vor der Funktionsdeklaration für kleine, häufig verwendete Funktionen
   - Rekursion: Funktion ruft sich selbst auf

4. **Grundlegende Datenstrukturen**

    ```c++
    - Arrays: Typ Name[Größe];
    - Mehrdimensionale Arrays: Typ Name[Größe1][Größe2];
    - std::vector: Dynamisches Array aus der STL
        #include <vector>
        std::vector<Typ> Name;
    - std::string: String-Klasse aus der STL
        #include <string>
        std::string Name;
    - STL: Sammlung von Containerklassen, Algorithmen und Funktoren
    ```

## Beispiele

1. **Variablen und Datentypen**:

    ```cpp
    #include <iostream>

    int main() {
        int age = 25;
        double height = 1.75;
        char grade = 'A';
        bool isStudent = true;

        std::cout << "Age: " << age << std::endl;
        std::cout << "Height: " << height << " m" << std::endl;
        std::cout << "Grade: " << grade << std::endl;
        std::cout << "Is student: " << (isStudent ? "Yes" : "No") << std::endl;

        return 0;
    }
    ```

2. **Kontrollstrukturen**:

    ```cpp
    #include <iostream>

    int main() {
        int number;
        std::cout << "Enter a number: ";
        std::cin >> number;

        if (number > 0) {
            std::cout << "Positive number" << std::endl;
        } else if (number < 0) {
            std::cout << "Negative number" << std::endl;
        } else {
            std::cout << "Zero" << std::endl;
        }

        for (int i = 1; i <= 5; i++) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        return 0;
    }
    ```

3. **Funktionen**:

    ```cpp
    #include <iostream>

    int add(int a, int b) {
        return a + b;
    }

    void printMessage(std::string message) {
        std::cout << message << std::endl;
    }

    int main() {
        int result = add(5, 3);
        std::cout << "5 + 3 = " << result << std::endl;

        printMessage("Hello, C++!");

        return 0;
    }
    ```

4. **Datenstrukturen**:

    ```cpp
    #include <iostream>
    #include <vector>
    #include <string>

    int main() {
        int arr[3] = {1, 2, 3};
        std::vector<int> vec = {4, 5, 6};
        std::string str = "C++ Basics";

        std::cout << "Array: ";
        for (int i = 0; i < 3; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Vector: ";
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        std::cout << "String: " << str << std::endl;

        return 0;
    }
    ```
