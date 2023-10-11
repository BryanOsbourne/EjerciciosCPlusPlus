#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int res, m1, m2;
using namespace std ;

int sumar (int a, int b);       //si-si
void restar (int a, int b);     //si-no, globales
int multiplicar ();             //no-si, globales
void dividir();                 //no-no, globales
void factorial(int a, int *f);  //si-no, referencia
float raizc();                  //no-si

int main()
{

	int opc = 0, num, num3, fac;
	float num1, num2, y;
	double raiz, resp;
	while (opc != 7 )
	{	system("cls");
		cout<<"\n				MENU PRINCIPAL ";
		cout<<"\n\n\n";
		cout<<"			1. Suma dos numeros \n";                  
		cout<<"			2. Resta de dos numero \n";                 
		cout<<"			3. Multiplicacion de dos numeros \n";       
		cout<<"			4. Divicion de dos numeros \n";             
		cout<<"			5. Factorial de un numero \n";              
		cout<<"			6. Raiz cuadrada de un numero\n";
		cout<<"			7. Salir\n\n";
		cout<<"\n			Digite la opcion que desee: ";
		cin>>opc;

	switch (opc)
	{

	case 1:  
		system("cls");
		cout<<"Ingrese el primer numero ";
		cin>>num;
		cout<<"Ingrese el segundo numero ";
		cin>>num3;
        resp=sumar (num, num3);			
		cout<<"la suma de " << num << "+" << num3 << ":" << resp << endl;
		system("pause");
		break;

	case 2:
		system("cls");
		cout<<"Ingrese el primer numero ";
		cin>>num;
		cout<<"Ingrese el segundo numero ";
		cin>>num3;
        restar (num,num3);		
		cout<<"la resta de " << num << "-" << num3 << ":" << res << endl;
		system("pause");
		break;

	case 3:
		system("cls");
		cout<<"Ingrese el primer numero ";
		cin>>m1;
		cout<<"ingrese el segundo numero ";
		cin>>m2;		
		cout<<"la multiplicacion de " << m1 << "x" << m2 << ":" << multiplicar () << endl;
		system("pause");
		break;
	case 4:
		system("cls");
		cout<<"Ingrese el primer numero ";
		cin>>m1;
		cout<<"Ingrese el segundo numero ";
		cin>>m2;
		if(m2==0){
			cout<<"escriba un numero mayor a 0 " << endl;
		}else{
			dividir();
			cout<<"la division es : " << res << endl;
		}
		system("pause");
		break;

	case 5:		
		system("cls");
		cout<<"digite el factorial: ";
		cin>>num1;
		if(num1>0){
			factorial (num1, &fac);
			cout<<"el factorial es: " << fac << endl;
			}else if(num1==0){
				cout<<"el factorial de 0 es " << 1 << endl;
			}else{
				cout<<"No se permite numero negativo!! " << endl;
			}
		system("pause");
		break;

    case 6:		
		system("cls");

		cout<<"Ingrese la raiz ";
		cin>>m1;
		if(m1<0){
			cout<<"escriba un numero mayor a 0";
		}else{
			y=raizc();
			cout<<"la raiz cuadrada de " << m1 << " es " << y << endl;
		}
		system("pause");
		break;
		
	case 7:  
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
		system("pause");
} 

int sumar (int a, int b){
	int x;
	x=a+b;
	return(x);
}
void restar (int a, int b){
	res=a-b;
}
int multiplicar (){
	
	return(m1*m2);
}
void dividir(){
	res=m1/m2;
}
void factorial(int a, int *f){
	int i;
	*f=1;
	for(i=1;i<=a;i++){
		*f=(*f)*i;
	}
}
float raizc(){
	return(sqrt(m1));
}
