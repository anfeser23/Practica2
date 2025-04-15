/* **************Práctica 2 Informática II Andrés Felipe Sepúlveda******************** */

#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

/* ******************* Declaración de funciones ************************* */

bool CompararArreglos(char [],char [],int,int);
long long int RetornarNumero(int [], int);
int RetornarCadena(long long int, int*);


/* ******************************** main ******************************** */


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

        case 3: //Haga una función que compare 2 cadenas de caracteres y retorno un valor lógico verdadero si son iguales y falso en caso contrario, no olvide también tener en cuenta la longitud de las cadenas. Escriba un programa de prueba.

            {   char letra;
                char arreglo1 [500];
                char arreglo2 [500];
                int longitud1=0, longitud2=0;
                bool ban=false;

                cout<<endl<<"Ingresa la primera cadena de caracteres y termine con ',': ";

                do{

                    cin>>letra;
                    arreglo1[longitud1]=letra;
                    longitud1+=1;

                }

                while (letra!=',');

                longitud1=longitud1-1;

                cout<<endl<<"Ingresa la segunda cadena de caracteres y termine con ',': ";

                do{

                    cin>>letra;
                    arreglo2[longitud2]=letra;
                    longitud2+=1;

                }

                while (letra!=',');

                 longitud2=longitud2-1;

                ban=CompararArreglos(arreglo1,arreglo2,longitud1,longitud2);

                if (ban==true){
                    cout<<endl<<"Las dos cadenas son iguales"<<endl;
                }
                else{
                    cout<<endl<<"Las dos cadenas no son iguales"<<endl;
                }

                break;

            }

        case 4: //Haga una función que reciba una cadena de caracteres numéricos, la convierta a un número entero y retorne dicho número. Escriba un programa de prueba. Ejemplo: si recibe la cadena “123”, debe retornar un int con valor 123.

            {   char letra;
                int arreglo [500];
                int longitud=0;
                long long int numero=0;

                cout<<endl<<"Ingresa una cadena de caracteres numericos y termine con ',': ";

                do{

                    cin>>letra;
                    arreglo[longitud]=letra;
                    longitud+=1;

                }

                while (letra!=',');

                numero=RetornarNumero(arreglo,longitud);

                cout<<endl<<numero<<endl;

                break;

            }

        case 5: //Haga una función que reciba un numero entero (int) y lo convierta a cadena de caracteres. Use parámetros por referencia para retornar la cadena. Escriba un programa de prueba.  Ejemplo: si recibe un int con valor 123, la cadena que se retorne debe ser “123”.

            {   long long int numero;
                int longitud;

                int * arreglo =new int [500];
                int* ptr=arreglo;

                for (int i=0;i<500;i++){

                    arreglo[i]=9;

                }

                cout<<endl<<"Ingrese un numero: ";
                cin>>numero;

                longitud=RetornarCadena(numero,ptr);

                for (int i=0;i<longitud;i++){

                    cout<<arreglo[i];

                }

                cout<<endl;

                delete [] arreglo;

                break;

            }

        case 6: //Escriba un programa que reciba una cadena de caracteres y cambie las letras minúsculas por mayúsculas, los demás caracteres no deben ser alterados.

            {   char letra;
                char arreglo [500];
                int longitud=0;
                char arregOriginal [500];

                cout<<endl<<"Ingresa una cadena de caracteres y termine con ',': ";

                do{

                    cin>>letra;
                    arreglo[longitud]=letra;
                    longitud+=1;

                }

                while (letra!=',');

                cout<<endl<<"Original: ";

                for (int k=0;k<longitud-1;k++){

                    arregOriginal[k]=arreglo[k];
                    cout<<arreglo[k];

                }

                cout<<".  "<<"En mayusculas: ";

                for (int i=0;i<longitud-1;i++){

                    for (int j=97;j<=122;j++){

                        if (arreglo[i]==j){
                            arreglo[i]=j-32;
                            break;
                        }
                    }

                    cout<<arreglo[i];

                }

                break;

            }

        case 7: //Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos.  Eemplo: se recibe bananas debe mostrar bans.

            {   char letra;
                char arreglo [500];
                int longitud=0;
                char arregOriginal [500];

                cout<<endl<<"Ingresa una cadena de caracteres y termine con ',': ";

                do{

                    cin>>letra;
                    arreglo[longitud]=letra;
                    longitud+=1;

                }

                while (letra!=',');

                cout<<endl<<"Original: ";

                for (int i=0;i<longitud-1;i++){

                    arregOriginal[i]=arreglo[i];
                    cout<<arregOriginal[i];

                }

                cout<<".  "<<"Sin repetirlos: ";

                for (int j=0;j<longitud-1;j++){

                    //int contador=0;

                    for (int k=longitud-1;k>0+j;k--){

                        if (arregOriginal[j]==arreglo[k]){
                            arregOriginal[k]='\0';
                            //contador+=1;
                        }

                        /*if (arregOriginal[j]==arreglo[k] && contador>=1){
                            arregOriginal[j]=arreglo[j+1];
                            break;
                        }

                        else{
                            arregOriginal[j]=arreglo[j];
                        }*/

                    }

                    cout<<arregOriginal[j];

                }

                break;

            }





        default: cout<<"Ha ingresado una opcion incorrecta"<<endl;

        }

    }


    return 0;
}

/* ********************************** Funciones ******************************************* */


bool CompararArreglos(char arreglo1 [],char arreglo2 [],int longitud1, int longitud2){

    bool bandera=true;

    if (longitud1!=longitud2){
        bandera=false;
        return bandera;
    }

    else{

        for (int i=0;i<longitud1;i++){

            if (arreglo1[i]==arreglo2[i]){
                bandera=true;
            }
            else{
                bandera=false;
                break;
            }
        }

        return bandera;

    }

}

long long int RetornarNumero(int arreglo [], int longitud){

    long long int numero;

    for (int j=0;j<longitud-1;j++){

        int contador=0;

        for (int k=48;k<=57;k++){

            if (arreglo[j]==k){
                arreglo[j]=contador;
                break;
            }
            else{
                contador+=1;
            }

        }

    }

    for (int i=0;i<longitud-1;i++){

        if (i==0){
            numero=arreglo[0];
        }
        else{
            numero=(numero*10)+arreglo[i];
        }

    }

    return numero;

}

int RetornarCadena(long long int numero, int* ptr){

    int caracter;
    int longitud=1,aux;

    aux=numero;

    while (aux/10>=1){

        aux=aux/10;
        longitud+=1;

    }

    cout<<endl;

    for (int i=longitud-1;i>=0;i--){

        if (numero/10>=1){

            caracter=numero%10;
            numero=numero/10;
            ptr[i]=caracter;

        }

        else{

            caracter=numero;
            ptr[i]=caracter;

        }

    }

    return longitud;
}
