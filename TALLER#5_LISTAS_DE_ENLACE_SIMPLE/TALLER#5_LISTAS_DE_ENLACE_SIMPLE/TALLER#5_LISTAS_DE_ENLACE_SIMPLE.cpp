#include <iostream>
#include <string>

using namespace std;

struct Nodo 
{
	int numero;
	Nodo* siguiente;
};

struct Nodo2
{
	char letra;
	Nodo2* siguiente;
};

void imprimirLista(Nodo *cabecera);
void imprimirListaSalteada(Nodo *cabecera);
void clasificarLista(Nodo *cabecera);
int contarPalabras(Nodo2 *cabecera2);

int main()
{
    Nodo* cabecera = NULL, *nuevoNodo = NULL, *temporal = NULL;
	Nodo2* cabecera2 = NULL, *nuevoNodo2 = NULL, *temporal2 = NULL;
    int opcion = 1, cantidadPalabras = 0;
	string frase = "";

    while (opcion == 1) 
    {
		nuevoNodo = new (Nodo);
		printf("\nSuministre un numero:");
		cin >> nuevoNodo->numero;
		nuevoNodo->siguiente = NULL;

		if (cabecera == NULL)
		{
			cabecera = nuevoNodo;
			temporal = cabecera;
		}
		else
		{
			temporal->siguiente = nuevoNodo;
			temporal = nuevoNodo;
		}
		printf("\n Desea continuar ? (1:SI, 2: NO) ? :");
		cin >> opcion;
    }
	cin.ignore();
	printf("\nSuministre una frase:");
	getline(cin, frase);
	for (int i = 0; i < frase.length(); i++)
	{
		nuevoNodo2 = new (Nodo2);
		nuevoNodo2->letra = frase[i];
		nuevoNodo2->siguiente = NULL;
		if (cabecera2 == NULL) 
		{
			cabecera2 = nuevoNodo2;
			temporal2 = cabecera2;
		}
		else 
		{
			temporal2->siguiente = nuevoNodo2;
			temporal2 = nuevoNodo2;
		}
	}

	imprimirLista(cabecera);
	imprimirListaSalteada(cabecera);
	clasificarLista(cabecera);
	cantidadPalabras = contarPalabras(cabecera2);
	cout << "Cantidad de palabras : " << cantidadPalabras << endl;
}

void imprimirLista(Nodo* cabecera)
{
	Nodo* temp = cabecera;
	while (temp != NULL)
	{
		printf("  %d  ---> ", temp->numero);
		temp = temp->siguiente;
	};
	printf("NULL  \n");
}

void imprimirListaSalteada(Nodo* cabecera) 
{
	cout << "Ejercicio 1: Lista Procesada.\n Numeros Salteados: ";
	Nodo* temp = cabecera;
	while (temp != NULL)
	{	
		printf("  %d  ---> ", temp->numero);
		temp = (temp->siguiente)->siguiente;
	};
	printf("NULL  \n");
}

void clasificarLista(Nodo* cabecera) 
{
	Nodo* temp = cabecera, *cabecera_dos = NULL, *q = NULL, *nuevo = NULL;

	while (temp != NULL)
	{
		if (temp->numero % 2 == 0) 
		{
			nuevo = new (Nodo);
			nuevo->numero = temp->numero;
			nuevo->siguiente = NULL;
			if (cabecera_dos == NULL) 
			{
				cabecera_dos = nuevo;
				q = cabecera_dos;
			}
			else 
			{
				q->siguiente = nuevo;
				q = nuevo;
			}
		}
		temp = temp->siguiente;
	};

	cout << "Ejercicio 2: Lista Procesada.\n Numeros pares : ";
	imprimirLista(cabecera_dos);

	temp = cabecera;
	cout << "\n Numeros impares: ";
	while (temp != NULL)
	{
		if (temp->numero % 2 != 0) 
		{
			printf("  %d  ---> ", temp->numero);
		}
		temp = temp->siguiente;
	};
	printf("NULL  \n");
}

int contarPalabras(Nodo2* cabecera2) 
{
	Nodo2* temp = cabecera2;
	int contador = 0;

	if (temp != NULL) 
	{
		contador = 1;
		while (temp != NULL)
		{
			if (temp->letra == ' ')
			{
				contador++;
			}
			temp = temp->siguiente;
		}
	}
	return contador;
}


