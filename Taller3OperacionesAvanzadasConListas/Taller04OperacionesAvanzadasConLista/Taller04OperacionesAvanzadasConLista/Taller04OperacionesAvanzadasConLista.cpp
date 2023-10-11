#include <iostream>

struct Nodo
{
    int numero;
    Nodo* siguiente;
};

using namespace std;

void clasificarNumeros(Nodo *cabecera);
float calcularPromedio(Nodo *cabecera);
void imprimirNodo(Nodo *cabecera);

int main()
{
    int opc = 1;
    float pro = 0;
    Nodo *cabecera, *q= NULL, *nuevoNodo;
    cabecera = NULL;

    while (opc == 1) 
    {
        nuevoNodo = new (Nodo);
        cout << "Ingrese un numero: " << endl;
        cin >> nuevoNodo->numero;
        nuevoNodo->siguiente = NULL;

        if (cabecera == NULL) 
        {
            cabecera = nuevoNodo;
            q = cabecera;
        }
        else 
        {
            q->siguiente = nuevoNodo;
            q = nuevoNodo;
        }
        printf("\nDesea continuar ? (1:SI, 2: NO) ? :");
        cin >> opc;
    }

    cout << "Lista: ";
    imprimirNodo(cabecera);

    pro = calcularPromedio(cabecera);

    cout << "El promedio es: " << pro << endl;
    clasificarNumeros(cabecera);
}

float calcularPromedio(Nodo* cabecera)
{
    Nodo* temp;
    float promedio = 0; 
    int cont = 0;

    if (cabecera == NULL) 
    {
        cout << "La lista esta vacia" << endl;
    }
    else 
    {
        temp = cabecera;
        while (temp != NULL) 
        {
            promedio += temp->numero;
            cont++;
            temp = temp->siguiente;
        }
    }
    promedio = promedio / cont;
    return promedio;
}

void imprimirNodo(Nodo* cabecera) 
{
    Nodo* tmp = cabecera;

    while (tmp != NULL)
    {
        printf("  %d  ---> ", tmp->numero);
        tmp = tmp->siguiente;
    };
    printf("NULL  \n\n");
}

void clasificarNumeros(Nodo* cabecera) 
{
    Nodo* temp, *cabecera2 = NULL, *cabecera3 = NULL, *nuevoNodo = NULL, *q = NULL, *p = NULL;
    float promedio;

    if (cabecera == NULL)
    {
        cout << "La lista esta vacia" << endl;
    }
    else
    {
        promedio = calcularPromedio(cabecera);
        temp = cabecera;
        while (temp != NULL)
        {
            nuevoNodo = new (Nodo);
            nuevoNodo->numero = temp->numero;
            nuevoNodo->siguiente = NULL;
            if (temp->numero < promedio) 
            {
                if (cabecera2 == NULL) 
                {
                    cabecera2 = nuevoNodo;
                    q = cabecera2;
                }
                else 
                {
                    q->siguiente = nuevoNodo;
                    q = nuevoNodo;
                }
            }
            else if (temp->numero >= promedio)
            {
                if (cabecera3 == NULL)
                {
                    cabecera3 = nuevoNodo;
                    p = cabecera3;
                }
                else
                {
                    p->siguiente = nuevoNodo;
                    p = nuevoNodo;
                }
            }
            temp = temp->siguiente;
        }
    }
    cout << "Numeros inferiores al promedio: ";
    imprimirNodo(cabecera2);
    cout << "Numeros superiores o iguales a promedio: ";
    imprimirNodo(cabecera3);
}

