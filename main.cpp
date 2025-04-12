/* **************Práctica 2 Informática II Andrés Felipe Sepúlveda******************** */

#include <iostream>
using namespace std;
//#include <cstdlib>
//#include <ctime>

int main()
{
    unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};

    cout<<endl<<b<<endl;
    cout<<b+2<<endl;
    cout<<*(b+2)<<endl;
    cout<<*(b+2)+1<<endl;
    cout<<*((b+2)+1)<<endl;
    cout<<b[3][1];
    cout<<*b;


    int numeral=1;

    while(numeral!=0) {

        cout<<endl<<"Ingrese el numero de ejercicio o 0 para terminar: ";
        cin>>numeral;

        switch(numeral) {

        case 0: cout<<endl<<"Gracias!!";
            numeral=0;
            break;

        //case 1: //Escribe un programa que pida dos números A y B e imprime en pantalla el residuo de la división A/B.








        default: cout<<"Ha ingresado una opcion incorrecta"<<endl;

        }

    }


    return 0;
}

