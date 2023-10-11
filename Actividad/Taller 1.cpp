#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){
	
	int cantidadDeEquipos , puntos, opcion = 0, codigoEquipo, totalPuntos;		
	string nombreDeEquipo;
	int DIMA[20][12]; 
    string equipos[20];
	
	while(opcion != 9)
	{		
		system("cls");
		cout<<"\n				MENU PRINCIPAL ";
		cout<<"\n\n\n";
		cout<<"			1. Leer matriz. \n"; // main               
		cout<<"			2. Imprimir matriz. \n"; // main                
		cout<<"			3. Equipos ganadores en octubre. \n"; // si no       
		cout<<"			4. Imprimir codigo de equipos que ganaron todos los partidos del primer semestre. \n"; //si no            
		cout<<"			5. Imprimir codigo de equipo con mayor partidos ganados en el año. \n"; // si no
		cout<<"			6. Imprimir codigo de equipo que perdieron en el mes de octubre. \n"; //si no por referencia
		cout<<"			7. Imprimir codigo de equipos con mayor porcentaje de partidos perdidos en el año. \n";	 //si no
		cout<<"			8. ¿Algun equipo empato en el segundo semestre? \n"; //si si	
		cout<<"			9. Salir. \n\n"; //si si							
		cout<<"\n		Digite la opcion de su preferencia: ";
		cin>>opcion;
		
		switch(opcion) {
			
			case 1: 
			cout << "Ingrese la cantidad de equipos a registrar no mayor de 20" << endl;
			cin >> cantidadDeEquipos;				 
				if(cantidadDeEquipos > 0 && cantidadDeEquipos < 20)
				{
					for(int i = 0; i < cantidadDeEquipos; i++)
					{
						cout << "Ingrese el nombre del equipo numero " << (i+1) << ": ";
					    cin >> 	nombreDeEquipo;
					    equipos[i] = nombreDeEquipo;
					    for(int j = 0; j < 12; j++)
						{
					    	cout << "Ingrese los puntos del equipo " << equipos[i] << " del mes " << (j+1) << " : ";
					    	cin >> puntos;
					    	puntosDelEquipo[i][j] = puntos;
					    }
					}
					
				} 
				else 
				{
					cout << "Numero de equipos incorrecto";
				}
				system("pause");
			break;
			
			case 2:  
				if(cantidadDeEquipos > 0)
				{
					for(int i = 0; i < cantidadDeEquipos ;i++) 
					{
						cout << "Puntos del equipos : " << equipos[i] << endl;			
					for(int j = 0; j < 12; j++) 
					{
						cout << "Puntos en el mes " << (j+1) << " : " << puntosDelEquipo[i][j] << endl;
					}
				
   					}
				} 
				else 
				{
					cout << "La lista esta vacia";
				}				
				system("pause");
			break;
			
			case 3:  
				if(cantidadDeEquipos > 0)
				{
					cout << "Ingrese el codigo del equipo a buscar: ";
					cin >> codigoEquipo;
					if(codigoEquipo > 0 && cantidadDeEquipos > 0)
					{
						for(int j = 0; j < 12; j++)
						{
							totalPuntos += puntosDelEquipo[(codigoEquipo - 1)][j];
						}
						cout << "El equipo " << equipos[(codigoEquipo - 1)] << " gano : " << totalPuntos << " puntos" << endl;
						totalPuntos = 0;
					}
					else
					{
						cout << "Codigo incorrecto";
					}
				} 
				else 
				{
					cout << "La lista esta vacia";
				}
				system("pause");
			break;
			
			case 4:
				if(cantidadDeEquipos > 0)
				{
					for(int i = 0; i < cantidadDeEquipos; i++)
					{
					  	if(puntosDelEquipo[i][6] == 0)
					   	{
					   	   cout << "El equipo " << equipos[i] << " no consiguio puntos en el mes de Julio.";
					   	}					
					}			
				} 
				else
				{
					cout << "Codigo incorrecto";
				} 
				system("pause");
			break;
			
			case 5:  
				system("cls");
				printf("\n !!! Adios !!!\n");
			break;
			
			default:
				printf("\n                        ==============================");
				printf("\n                        ! **** Opcion Invalida ***** !") ;
				printf("\n                        ==============================");
				system("pause");
		}
	}
	return 0;
}

