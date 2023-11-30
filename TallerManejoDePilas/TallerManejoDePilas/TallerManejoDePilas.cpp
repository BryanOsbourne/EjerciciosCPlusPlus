#include <iostream>

using namespace std;

struct Nodo
{
    char letra;
    Nodo* siguiente;
};

void imprimirPila(Nodo *pila);
bool determinarSiEspalindrome(Nodo *pila);

int main()
{
    int opc = 1;
    string palabra = "";
    Nodo* cabecera = NULL, * nuevoNodo = NULL, * temp = NULL;

    while (opc == 1)
    {
        cout << "Escriba Una Palabra" << endl;
        cin >> palabra;
        for (char letra : palabra)
        {
            nuevoNodo = new Nodo{ letra, NULL };
            if (cabecera == NULL)
            {
                cabecera = nuevoNodo;
            }
            else
            {
                temp = cabecera;
                while (temp->siguiente != NULL)
                {
                    temp = temp->siguiente;
                }
                temp->siguiente = nuevoNodo;
            }
        }
    }
    determinarSiEspalindrome(cabecera) ? cout << "La Palabra Es Palindrome" << endl : cout << "La Palabra No Es Palindrome" << endl;
    return 0;
}

bool determinarSiEspalindrome(Nodo *pila) 
{
    Nodo* temp = pila, *aux1 = NULL, *aux2 = NULL;

    if (pila == NULL) 
    {
        cout << "Pila Vacia" << endl;
    }
    else 
    {
        while (!temp.empty_p()) 
        {
            *aux1 = temp.pop();
        }
    }
}


