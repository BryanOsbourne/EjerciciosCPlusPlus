#include <iostream>

using namespace std;

struct Cliente
{
	int cedula;
	int saldo;
	Cliente* siguiente;
};

void imprimirLista(Cliente *cabecera);
void eliminarCliente(Cliente *cabecera, int cedula);

int main()
{
	Cliente* cabecera = NULL, * nuevoNodo = NULL, * temporal = NULL;
	int opcion = 1, cedula;

	while (opcion == 1)
	{
		nuevoNodo = new (Cliente);
		printf("\nSuministre la cedula del cliente:");
		cin >> nuevoNodo->cedula;
		printf("\nSuministre el saldo del cliente:");
		cin >> nuevoNodo->saldo;
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
	printf("\n Ingresa la cedula del cliente: ");
	cin >> cedula;
	eliminarCliente(cabecera, cedula);
	imprimirLista(cabecera);
}

void imprimirLista(Cliente* cabecera)
{
	Cliente* temp = cabecera;
	while (temp != NULL)
	{
		printf("  %d  ---> ", temp->cedula);
		temp = temp->siguiente;
	};
	printf("NULL  \n");
}

void eliminarCliente(Cliente* cabecera, int cedula) 
{
	bool sw;
	Cliente* p, * q, * r;

	if (cabecera == NULL) 
	{
		cout << "No hay datos en la lista" << endl;
	}
	else
	{
		if (cabecera->siguiente == NULL) 
		{
			// FLUJO DE LISTA CON UN SOLO CLIENTE
			if (cabecera->cedula == cedula) 
			{
				if (cabecera->saldo == 0) 
				{
					//FREE NODE 
					cabecera = NULL;
					cout << "Cliente retirado" << endl;
				}
				else 
				{
					if (cabecera->saldo < 0) 
					{
						cout << "El cliente con cedula: " << cabecera->cedula 
							<< " tiene un saldo a favor de: " 
							<< cabecera->saldo << endl;
						//FREE NODE 
						cabecera = NULL;
					}
					else 
					{
						cout << "El cliente con cedula: " << cabecera->cedula
							<< " no se puede eliminar, tiene un saldo pendiente de: "
							<< cabecera->saldo << endl;
					}
				}
			}
			else 
			{
				cout << "El cliente no existe" << endl;
			}
		}
		else 
		{
			sw = false;
			p = cabecera;
			q = cabecera;
			r = p->siguiente;

			while (sw == false && p != NULL) 
			{
				if (p->cedula == cedula) 
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
				cout << "Cliente invalido rectifique" << endl;
			}
			else 
			{
				if (p = cabecera) 
				{
					if (p->saldo == 0) 
					{
						cabecera = cabecera->siguiente;
						p->siguiente = NULL;
						//FREE NODE
						cout << "Cliente eliminado" << endl;
					}
					else 
					{
						if (p->saldo < 0)
						{
							cabecera = cabecera->siguiente;
							p->siguiente = NULL;
							//FREE NODE
							cout << "El cliente con cedula: " << cabecera->cedula
								<< " tiene un saldo a favor de: "
								<< cabecera->saldo << endl;
						}
					}

					r = p->siguiente;
					q->siguiente = NULL;
					p->siguiente = NULL;
					//FREE NODE
					cout << "Cliente retirado" << endl;
				}
			}
		}
	}
}

