#include <iostream>
#include <string>

using namespace std;

struct Nodo
{
    char letra;
    Nodo* siguiente;
};

int contarVocalesYConsonantes(Nodo* cabecera, int& vocales);

int main()
{
    int vocales = 0;
    int consonantes = 0;
    Nodo* cabecera = NULL;
    string nombre = "BRAYAN";

    for (char letra : nombre)
    {
        Nodo* nuevoNodo = new Nodo{ letra, NULL };
        if (cabecera == NULL)
        {
            cabecera = nuevoNodo;
        }
        else
        {
            Nodo* temp = cabecera;
            while (temp->siguiente != NULL)
            {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    consonantes = contarVocalesYConsonantes(cabecera, vocales);

    cout << "El nombre '" << nombre << "' tiene " << vocales << " vocales y " << consonantes << " consonantes." << endl;

    return 0;
}

int contarVocalesYConsonantes(Nodo* cabecera, int& vocales)
{
    int consTmp = 0;
    while (cabecera != NULL)
    {
        char letra = cabecera->letra;

        if (letra >= 'A' && letra <= 'Z')
        {
            if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
            {
                vocales++;
            }
            else
            {
                consTmp++;
            }
        }
        cabecera = cabecera->siguiente;
    }
    return consTmp;
}
