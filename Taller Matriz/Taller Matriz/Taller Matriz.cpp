#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void equiposGanadoresEnOctubre(int dima[20][12], string equipos[], int cantidadDeEquipos);
void todosLosPartidosGanadosEnElPrimerSemestre(int dima[20][12], string equipos[], int cantidadDeEquipos);
void equipoConMasPartidosGanadosEnElAnnio(int dima[20][12], string equipos[], int cantidadDeEquipos);
void cantidadEquiposQuePerdieronEnOctubre(int dima[20][12], string equipos[], int cantidadDeEquipos, int *cantEquiposPerdidos);
void equipoConMayorPorcentajeDePartidosPerdidosEnElAnnio(int dima[20][12], string equipos[], int cantidadDeEquipos);
bool determinarSiEquipoEmpatoEnSegundoSemestre(int dima[20][12], int cantidadDeEquipos);

int main() {

	int cantidadDeEquipos = 0, puntos = 0, opcion = 0, totalPuntos = 0, cantEquiposPerdieronOctubre;
	int DIMA[20][12];
	string EQUIPOS[20];
	string nombreDeEquipo;

	while (opcion != 9)
	{
		system("cls");
		cout << "\n				MENU PRINCIPAL ";
		cout << "\n\n\n";
		cout << "			1. Leer matriz. \n"; // main               
		cout << "			2. Imprimir matriz. \n"; // main                
		cout << "			3. Equipos ganadores en octubre. \n"; // si no       
		cout << "			4. Imprimir codigo de equipos que ganaron todos los partidos del primer semestre. \n"; //si no            
		cout << "			5. Imprimir codigo de equipo con mayor partidos ganados en el annio. \n"; // si no
		cout << "			6. Imprimir numero de equipos que perdieron en el mes de octubre. \n"; //si no por referencia
		cout << "			7. Imprimir codigo de equipo con mayor porcentaje de partidos perdidos en el annio. \n";	 //si no
		cout << "			8. ¿Algun equipo empato en el segundo semestre? \n"; //si si	
		cout << "			9. Salir. \n\n";							
		cout << "\n		Digite la opcion de su preferencia: ";
		cin >> opcion;

		switch (opcion) {

		case 1:
			cout << "Ingrese la cantidad de equipos a registrar no mayor de 20 : ";
			cin >> cantidadDeEquipos;
			if (cantidadDeEquipos > 0 && cantidadDeEquipos < 20)
			{
				for (int i = 0; i < cantidadDeEquipos; i++)
				{
					cout << "Ingrese el nombre del equipo numero " << (i + 1) << ": ";
					cin >> nombreDeEquipo;
					EQUIPOS[i] = nombreDeEquipo;
					for (int j = 0; j < 12; j++)
					{
						cout << "Ingrese los puntos del equipo " << EQUIPOS[i] << " del mes " << (j + 1) << " : ";
						cin >> puntos;
						DIMA[i][j] = puntos;
					}
				}
			}
			else
			{
				cout << "Numero de equipos incorrecto" << endl;
			}
			system("pause");
			break;

		case 2:
			if (cantidadDeEquipos > 0)
			{
				for (int i = 0; i < cantidadDeEquipos;i++)
				{
					cout << "Puntos del equipos : " << EQUIPOS[i] << endl;
					for (int j = 0; j < 12; j++)
					{
						cout << "Puntos en el mes " << (j + 1) << " : " << DIMA[i][j] << endl;
					}
				}
			}
			else
			{
				cout << "La lista esta vacia" << endl;
			}
			system("pause");
			break;

		case 3:
			if (cantidadDeEquipos > 0)
			{
				equiposGanadoresEnOctubre(DIMA, EQUIPOS, cantidadDeEquipos);
			}
			else
			{
				cout << "La lista esta vacia" << endl;
			}
			system("pause");
			break;

		case 4:
			if (cantidadDeEquipos > 0)
			{
				todosLosPartidosGanadosEnElPrimerSemestre(DIMA, EQUIPOS, cantidadDeEquipos);
			}
			else
			{
				cout << "La lista esta vacia" << endl;
			}
			system("pause");
			break;

		case 5:
			if (cantidadDeEquipos > 0)
			{
				equipoConMasPartidosGanadosEnElAnnio(DIMA, EQUIPOS, cantidadDeEquipos);
			}
			else
			{
				cout << "La lista esta vacia" << endl;
			}
			system("pause");
			break;

		case 6:
			if (cantidadDeEquipos > 0)
			{
				cantidadEquiposQuePerdieronEnOctubre(DIMA, EQUIPOS, cantidadDeEquipos, &cantEquiposPerdieronOctubre);
				cout << cantEquiposPerdieronOctubre << " Equipos perdieron en el mes de octubre " << endl;
			}
			else
			{
				cout << "La lista esta vacia" << endl;
			}
			system("pause");
			break;

		case 7:
			if (cantidadDeEquipos > 0)
			{
				equipoConMayorPorcentajeDePartidosPerdidosEnElAnnio(DIMA, EQUIPOS, cantidadDeEquipos);
			}
			else
			{
				cout << "La lista esta vacia" << endl;
			}
			system("pause");
			break;

		case 8:
			if (cantidadDeEquipos > 0)
			{
				determinarSiEquipoEmpatoEnSegundoSemestre(DIMA, cantidadDeEquipos) ? cout << "Se encontraron empatados"<< endl : cout << "No hubo empatados" << endl;
			}
			else
			{
				cout << "La lista esta vacia" << endl;
			}
			system("pause");
			break;

		case 9:
			printf("\n !!! Adios !!!\n");
			break;

		default:
			printf("\n                        ==============================");
			printf("\n                        ! **** Opcion Invalida ***** !");
			printf("\n                        ==============================");
			system("pause");
		}
	}
	return 0;
}

void equiposGanadoresEnOctubre(int dima[20][12], string equipos[], int cantidadDeEquipos) {
	for (int i = 0; i < cantidadDeEquipos; i++) {
		if (dima[i][9] == 3) {
			cout << "El equipo " << equipos[i] << " gano el partido en el mes de octubre" << endl;
		}
	}
}

void todosLosPartidosGanadosEnElPrimerSemestre(int dima[20][12], string equipos[], int cantidadDeEquipos) {
	int numeroDeEquiposGanados = 0;
	for (int i = 0; i < cantidadDeEquipos; i++) {
		for (int j = 0; j <= 6; j++) {
			if (dima[i][j] == 3) {
				numeroDeEquiposGanados++;
				if (j == 5 && numeroDeEquiposGanados == 6) {
					cout << "El equipo " << equipos[i] << " gano todos los partidos del primer semestre" << endl;
				}
			}
		}
		numeroDeEquiposGanados = 0;
	}
}

void equipoConMasPartidosGanadosEnElAnnio(int dima[20][12], string equipos[], int cantidadDeEquipos) {
	int cantidadDePartidosGanados = 0, temp = 0, posicionEquipoConMasPartidosGanados;
	for (int i = 0; i < cantidadDeEquipos; i++) {
		for (int j = 0; j < 12; j++) {
			if (dima[i][j] == 3) {
				cantidadDePartidosGanados++;
			}
		}
		if (cantidadDePartidosGanados > temp) {
			temp = cantidadDePartidosGanados;
			posicionEquipoConMasPartidosGanados = i;
		}
		cantidadDePartidosGanados = 0;
	}
	cout << "El equipo con mas partidos ganados en el año es: " << equipos[posicionEquipoConMasPartidosGanados] << endl;
}

void cantidadEquiposQuePerdieronEnOctubre(int dima[20][12], string equipos[], int cantidadDeEquipos, int *cantEquiposPerdidos) {
	int contAux = 0;
	for (int i = 0; i < cantidadDeEquipos; i++) {	
		if (dima[i][9] == 0) {
			contAux++;
		}	
	}
	*cantEquiposPerdidos = contAux;
}

void equipoConMayorPorcentajeDePartidosPerdidosEnElAnnio(int dima[20][12], string equipos[], int cantidadDeEquipos) {
	int totalPartidos = cantidadDeEquipos * 6;// Es lo mismo que (cantidadDeEquipos * 12) / 2 por lo que cada partido involucra 2 equipos
	float maxPorcentajePerdido = 0.0, auxPorc = 0.0;
	int posEquipo = 0;
	for (int i = 0; i < cantidadDeEquipos; i++) {
		for (int j = 0; j < 12; j++) {
			if (dima[i][j] == 0) {
				auxPorc++;
			}
		}
		if ((auxPorc / totalPartidos) > maxPorcentajePerdido) {
			maxPorcentajePerdido = (auxPorc / totalPartidos);
			posEquipo = i;
			auxPorc = 0;
		}
	}
	cout << "El equipo con mayor procentaje de partidos perdidos en el año es: " << equipos[posEquipo] << " Con un " << (maxPorcentajePerdido*100) << "% de partidos perdidos" << endl;
}

bool determinarSiEquipoEmpatoEnSegundoSemestre(int dima[20][12], int cantidadDeEquipos) {
	int aux = 0;
	bool seEncontraronEmpatados = false;
	for (int i = 1; i < cantidadDeEquipos; i++, aux++) {
		for (int j = 6; j < 12; j++) {
			if (dima[aux][j] == dima[i][j]) {
				seEncontraronEmpatados = true;
			}
		}
	}
	return seEncontraronEmpatados;
}

