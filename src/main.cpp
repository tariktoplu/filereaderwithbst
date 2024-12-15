#include "../include/LinkedList.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
void processFile(LinkedList *list)
{
    ifstream inputFile("agaclar.txt");
    string line;

    if (!inputFile.is_open())
    {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }

    while (getline(inputFile, line))
    {
        // Her satırı bir BST'ye ekle
        BST *tree = new BST();

        // Karakterleri doğrudan işleme
        for (auto it = line.begin(); it != line.end(); ++it)
        {
            char ch = *it; // Iterator ile karakteri al
            tree->Add(ch); // Her karakteri BST'ye ekle
        }
        list->addNode(*tree);

        delete tree;
    }

    inputFile.close();
}

int main()
{
    LinkedList *list = new LinkedList();
    processFile(list);

    short int index = 0;
    short int startIndex = 0;

    while (true)
    {
        system("cls");
        list->bagliListeYaz(startIndex);

        list->isaretYaz(index, startIndex);

        list->agacYaz(index);
        cout << "\nSecim.......: ";
        char secim = cin.get();

        if (secim == 'x' || secim == 'X')
        {
            break; // Programdan çık
        }
        else if (secim == 'a' || secim == 'A')
        {
            if (index > 0)
            {
                index -= 1;

                if (index < startIndex)
                {
                    startIndex -= 10;
                    if (startIndex < 0)
                        startIndex = 0;
                }
            }
        }
        else if (secim == 'd' || secim == 'D')
        {
            if (index < list->Size() - 1)
            {
                index += 1;

                if (index >= startIndex + 10)
                {
                    startIndex += 10;
                    if (startIndex >= list->Size())
                        startIndex = list->Size() - 10;
                }
            }
        }
        else if (secim == 'S' || secim == 's')
        {

            if (list->Size() == 1)
            {
                list->removeAt(index);
                cout << "Tüm Liste Silindi";
                break;
            }

            list->removeAt(index);
            if (index == list->Size())
            {
                index -= 1;
            }

            if (index < startIndex && startIndex > 0)
            {
                startIndex -= 10;

                if (index >= list->Size() && list->Size() > 0)
                {
                    index = list->Size() - 1;
                }
            }
        }
        else if (secim == 'w' || secim == 'W')
        {                                             // Aynalama işlemini yap
            BST *tree = list->getNodeAt(index)->tree; // Seçilen düğümün ağacını al
            tree->mirror();                           // Ağacı aynala
        }
    }
    delete list;
    return 0;
}