#include <iostream>

using namespace std;

struct Nodo {
	int numero;
	Nodo* siguiente;
};

void imprimirLista(Nodo* cabecera);
void ordernarDeManeraAscendente(Nodo *cabecera);
void eliminarNumero(Nodo *&cabecera, int z);
void anadirNumero(Nodo *&cabecera, int z);

int main()
{
	int opcion = 1, entradaDeDatos = 0;
	bool bandera = true;
	Nodo *cabecera = NULL, *temp = NULL, *nuevoNodo = NULL;

	while (bandera)
	{
		cout << "Ingresa una opcion valida: \n" << endl;
		cout << "1) Anadir Numeros A La Lista." << endl;
		cout << "2) Imprimir lista." << endl;
		cout << "3) Ordernar Lista De Manera Ascendente." << endl;
		cout << "4) Anadir Numero En Su Orden." << endl;
		cout << "5) Eliminar Un Numero." << endl;
		cout << "6) Salir." << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			while (opcion == 1)
			{
				cout << "Anade un numero" << endl;
				cin >> entradaDeDatos;
				nuevoNodo = new Nodo{ entradaDeDatos , NULL};

				if (cabecera == NULL)
				{
					cabecera = nuevoNodo;
					temp = cabecera;
				}
				else
				{
					temp->siguiente = nuevoNodo;
					temp = nuevoNodo;
				}
				printf("\nDesea continuar ? (1:SI, 2: NO) ? :");
				cin >> opcion;
			}
			cout << "\n" << endl;
			break;
		case 2:
			imprimirLista(cabecera);
			break;
		case 3:
			ordernarDeManeraAscendente(cabecera);
			break;
		case 4:
			cout << "Ingrese El Numero A Anadir" << endl;
			cin >> entradaDeDatos;
			anadirNumero(cabecera, entradaDeDatos);
			break;
		case 5:
			cout << "Ingrese El Numero A Eliminar" << endl;
			cin >> entradaDeDatos;
			eliminarNumero(cabecera, entradaDeDatos);
			break;
		case 6:
			cout << "!Adios!" << endl;
			bandera = false;
			break;
		default:
			cout << "\nOpcion Incorrecta, Intentelo Nuevamente.\n" << endl;
			break;
		}
	}
	return 0;
}

void imprimirLista(Nodo *cabecera)
{
	Nodo *tmp = cabecera;

	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			cout << tmp->numero << " --> ";
			tmp = tmp->siguiente;
		}
	}
	else 
	{
		cout << "La Lista Esta Vacia" << endl;
	}
}

void eliminarNumero(Nodo*& cabecera, int z) 
{
	Nodo* p = cabecera, *q = NULL;
	bool sw = false;

	if (p == NULL) 
	{
		cout << "La Lista esta vacia" << endl;
	}
	else 
	{
		while (p != NULL && sw == false) 
		{
			if (p->numero == z)
			{
				sw = true;
			}
			else 
			{
				q = p;
				p = p->siguiente;
			}
		}

		if (sw == false) 
		{
			cout << "El Numero Ingresado No Esta En La Lista" << endl;
		}
		else
		{
			if (q == NULL) 
			{
				cabecera = p->siguiente;
			}
			else 
			{
				q->siguiente = p->siguiente;
			}
		}
	}
}

void ordernarDeManeraAscendente(Nodo* cabecera) 
{
	if (cabecera == NULL) 
	{
		cout << "La lista esta vacia." << endl;
	}
	else 
	{
		Nodo* p = cabecera;
		Nodo* q = NULL;
		int temp = 0;

		while (p->siguiente != NULL) 
		{
			q = p->siguiente;
			while (q != NULL) 
			{
				if (p->numero > q->numero) 
				{
					temp = p->numero;
					p->numero = q->numero;
					q->numero = temp;
				}
				q = q->siguiente;
			}
			p = p->siguiente;
		}
	}
}

void anadirNumero(Nodo*& cabecera, int z) 
{
	Nodo* p = NULL, * q = NULL, *nuevoNodo = new Nodo();
	nuevoNodo->numero = z;
	nuevoNodo->siguiente = NULL;

	if (cabecera == NULL || z < cabecera->numero) 
	{
		nuevoNodo->siguiente = cabecera;
		cabecera = nuevoNodo;
	}
	else 
	{
		Nodo* p = cabecera;
		Nodo* q = p->siguiente;

		while (q != NULL && q->numero < z) 
		{
			p = q;
			q = q->siguiente;
		}
		p->siguiente = nuevoNodo;
		nuevoNodo->siguiente = q;
	}
}
