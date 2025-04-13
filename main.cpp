/* **************Práctica 2 Informática II Andrés Felipe Sepúlveda******************** */

#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>


int main()
{
    int numeral=1;

    while(numeral!=0) {

        cout<<endl<<"Ingrese el numero de ejercicio o 0 para terminar: ";
        cin>>numeral;

        switch(numeral) {

        case 0: cout<<endl<<"Gracias!!";
            numeral=0;
            break;

        case 1: //Se necesita un programa que permita determinar la mínima combinación de billetes y monedas para una cantidad de dinero determinada. Los billetes en circulación son de $50.000, $20.000, $10.000, $5.000, $2.000 y $1.000, y las monedas son de $500, $200, $100 y $50. Hacer un programa que entregue el número de billetes y monedas de cada denominación para completar la cantidad deseada. Si por medio de los billetes y monedas disponibles no se puede lograr la cantidad deseada, el sistema deberá decir lo que resta para lograrla. Use arreglos y ciclos para realizar el programa.

            {   int dinero,cantidad;

                cout<<endl<<"Ingrese el monto de dinero: ";
                cin>>dinero;
                cout<<endl;

                int arreglo [10]={50000,20000,10000,5000,2000,1000,500,200,100,50};
                cantidad=0;

                for (int i=0;i<10;i++){

                    if (dinero/arreglo[i]>=1){
                        cantidad=dinero/arreglo[i];
                        dinero=dinero%arreglo[i];
                        cout<<arreglo[i]<<": "<<cantidad<<endl;
                        cantidad=0;
                    }
                    else{
                        cout<<arreglo[i]<<": "<<cantidad<<endl;
                    }

                }

                cout<<"Faltante: "<<dinero<<endl;

                break;

            }

        case 2: //Elabore un programa que genere un arreglo de 200 letras mayúsculas aleatorias, imprima este arreglo y luego imprima cuantas veces se repite cada letra en el arreglo.

            {   char letra;
                int contador=0;
                char* arreglo= new char[200];

                cout<<endl<<"Arreglo: ";

                srand(time(0));

                for (int i=0;i<200;i++){


                    letra = 'A'+rand()%26;
                    arreglo[i]=letra;

                    cout<<arreglo[i];

                }

                cout<<endl<<"\n";

                for (char j=65;j<=90;j++){

                    for (int k=0;k<200;k++){

                        if (arreglo[k]==j){
                            contador+=1;
                        }

                    }

                    cout<<j<<": "<<contador<<endl;
                    contador=0;

                }

                delete [] arreglo;

                break;

            }










        default: cout<<"Ha ingresado una opcion incorrecta"<<endl;

        }

    }


    return 0;
}
