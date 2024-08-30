/*

*/
// data_structures.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void manipulateArray()
{
    int arr[] = {5, 2, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sortieren
    std::sort(arr, arr + size);
    std::cout << "Sortiertes Array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Suchen
    int target = 8;
    auto it = std::find(arr, arr + size, target);
    if (it != arr + size)
    {
        std::cout << target << " gefunden an Position " << (it - arr) << std::endl;
    }
    else
    {
        std::cout << target << " nicht gefunden" << std::endl;
    }

    // Umkehren
    std::reverse(arr, arr + size);
    std::cout << "Umgekehrtes Array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void manipulateVector()
{
    std::vector<int> vec = {5, 2, 8, 1, 9};

    // Hinzufügen von Elementen
    vec.push_back(7);

    // Entfernen von Elementen
    vec.erase(vec.begin() + 2);

    // Ausgabe des Vektors
    std::cout << "Vektor: ";
    for (int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void manipulateString()
{
    std::string str = "Hallo, Welt!";

    // Länge des Strings
    std::cout << "Länge: " << str.length() << std::endl;

    // Teilstring extrahieren
    std::cout << "Teilstring: " << str.substr(0, 5) << std::endl;

    // String umkehren
    std::reverse(str.begin(), str.end());
    std::cout << "Umgekehrter String: " << str << std::endl;
}

int main()
{
    manipulateArray();
    manipulateVector();
    manipulateString();
    return 0;
}