#include <iostream>

struct Carro
{
	int placa;
	int cedula;
	Carro* siguiente;
};

struct Multa
{
	int placa;
	int valor_multa;
	Multa* siguiente;
};

using namespace std;

void imprimir_carro(Carro* cab1);
void imprimir_multas(Multa* cab2);
float generar_factura(Carro* cab1, Multa* cab2, int cedula);

int main()
{
	int opc = 1;
	int cedula;
	float valorAPagar;

	struct Carro* cab1, * p = NULL, * nuevo;
	cab1 = NULL;

	struct Multa* cab2, * q = NULL, * nuevo2;
	cab2 = NULL;

	while (opc == 1)
	{
		nuevo = new (Carro);
		printf("\nSuministre una placa:");
		cin >> nuevo->placa;
		printf("\nSuministre una cedula:");
		cin >> nuevo->cedula;
		nuevo->siguiente = NULL;

		if (cab1 == NULL)
		{
			cab1 = nuevo;
			p = cab1;
		}
		else
		{
			p->siguiente = nuevo;
			p = nuevo;
		}
		printf("\n Desea continuar ? (1:SI, 2: NO) ? :");
		cin >> opc;
	}

	printf("\n La lista creada fue :\n");
	imprimir_carro(cab1);

	opc = 1;
	while (opc == 1)
	{
		nuevo2 = new (Multa);
		printf("\nSuministre una placa:");
		cin >> nuevo2->placa;
		printf("\nSuministre el valor de la multa:");
		cin >> nuevo2->valor_multa;
		nuevo2->siguiente = NULL;

		if (cab2 == NULL)
		{
			cab2 = nuevo2;
			q = cab2;
		}
		else
		{
			q->siguiente = nuevo2;
			q = nuevo2;
		}
		printf("\n Desea continuar ? (1:SI, 2: NO) ? :");
		cin >> opc;
	}

	imprimir_multas(cab2);

	printf("\n Ingrese la cedula del susodicho:");
	cin >> cedula;

	valorAPagar = generar_factura(cab1, cab2, cedula);
	cout << "El valor a pagar del susodicho con cedula: " << cedula << " por concepto de multa es: $" << valorAPagar << endl;

}

void imprimir_carro(Carro* cab)
{
	Carro* tmp = cab;
	while (tmp != NULL)
	{
		printf("  %d  ---> ", tmp->placa);
		printf("  %d  ---> ", tmp->cedula);
		tmp = tmp->siguiente;
	};
	printf("NULL  \n");
}

void imprimir_multas(Multa* cab2)
{
	Multa* tmp = cab2;

	while (tmp != NULL)
	{
		printf("  %d  ---> ", tmp->placa);
		printf("  %d  ---> ", tmp->valor_multa);
		tmp = tmp->siguiente;
	};
	printf("NULL  \n");
}

float generar_factura(Carro* cab1, Multa* cab2, int cedula)
{
	float valorAPagar = 0;
	Carro* p;
	Multa* q;

	if (cab1 == NULL)
	{
		cout << "No hay vehiculos" << endl;
	}
	else
	{
		if (cab2 == NULL)
		{
			cout << "La lista de multas esta vacia" << endl;
		}
		else
		{
			p = cab1;
			while (p != NULL)
			{
				if (p->cedula == cedula)
				{
					q = cab2;
					while (q != NULL)
					{
						if (p->placa == q->placa)
						{
							valorAPagar += q->valor_multa;
						}
						q = q->siguiente;
					}
				}
				p = p->siguiente;
			}
		}
	}
	return valorAPagar;
}
