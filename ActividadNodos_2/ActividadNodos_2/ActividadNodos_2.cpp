#include <iostream>

using namespace std;

struct Nodo {
    float estatura;
    Nodo* siguiente;
};

void PromedioFueraDelIntervalo(Nodo *cabecera, float *promedio);

int main()
{
    Nodo* cabecera = NULL;
    float estatura = 0.0;
    float promedio = 0.0;
    bool bandera = true;

    do
    {
        cout << "Ingresa estatura" << endl;
        cin >> estatura;
        if (estatura == 0.0f) { bandera = false;}
        Nodo* nuevoNodo = new Nodo{ estatura, NULL };

        if (cabecera == NULL) 
        {
            cabecera = nuevoNodo;
        }
        else
        {
            Nodo* tmp = cabecera;
            while (tmp->siguiente != NULL) //Recorremos la lista hasta llegar a la ultima posicion
            {
                tmp = tmp->siguiente;
            }
            tmp->siguiente = nuevoNodo; // Una vez estemos en la ultima posicion agregamos el nuevo Nodo.
        }
    } while (bandera);

    PromedioFueraDelIntervalo(cabecera, &promedio);

    cout << "El promedio de estatura fuera del intervalo cerrado [1.75 - 1.92] es: " << promedio << endl;
    return 0;
}

void PromedioFueraDelIntervalo(Nodo* cabecera, float* promedio) 
{
    int contador = 0;
    float acumuladora = 0.0;

    while(cabecera->siguiente != NULL)
    {
        if (cabecera->estatura < 1.75 || cabecera->estatura > 1.92) 
        {
            contador++;
            acumuladora += cabecera->estatura;
        }
        cabecera = cabecera->siguiente;
    }
    *promedio = acumuladora / contador;
}
