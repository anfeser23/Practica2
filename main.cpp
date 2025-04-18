/* **************Práctica 2 Informática II Andrés Felipe Sepúlveda******************** */

#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

/* ******************* Declaración de funciones ************************* */

bool CompararArreglos(char [],char [],int,int);
long long int RetornarNumero(int [], int);
int RetornarCadena(long long int, int*);
int Estrellas(int (*ptr)[8]);
void ImpriArregloInt(int [], int);


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

                cout<<endl;

                break;

            }

        case 7: //Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos.  Eemplo: se recibe bananas debe mostrar bans.

            {   char letra;
                char arreglo [500];
                int longitud=0;
                char arregOriginal [500];

                cout<<endl<<"Ingresa una cadena de caracteres (puede contener numeros) y termine con ',': ";

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

                    for (int k=longitud-1;k>0+j;k--){

                        if (arregOriginal[j]==arreglo[k]){
                            arregOriginal[k]='\0';
                        }
                    }

                    cout<<arregOriginal[j];

                }

                break;

            }

        case 8: //Escriba un programa que reciba una cadena de caracteres y separe los números del resto de caracteres, generando una cadena que no tiene números y otra con los números que había en la cadena original.

            {   char letra;
                char arreglo [500];
                int longitud=0;
                char arregOriginal [500];
                char array [500];

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

                cout<<"."<<endl;
                cout<<"Texto: ";

                for (int j=0;j<longitud-1;j++){

                    if (arregOriginal[j]>=48 && arregOriginal[j]<=57){
                        array[j]=arregOriginal[j];
                        arregOriginal[j]='\0';
                    }

                    else{
                        array[j]='\0';
                    }

                    cout<<arregOriginal[j];

                }

                cout<<".  ";
                cout<<"Numero: ";

                for (int k=0;k<longitud;k++){

                    cout<<array[k];

                }

                cout<<"."<<endl;

                break;

            }

        case 9: //Escribir un programa que reciba un número n y lea una cadena de caracteres numéricos, el programa debe separar la cadena de caracteres en números de n cifras, sumarlos e imprimir el resultado. En caso de no poderse dividir exactamente en números de n cifras se colocan ceros a la izquierda del primer número.  Ejemplo: Si n=3 y se lee el arreglo 87512395 la suma seria 087+512+395=994.

            {   char letra;
                int arreglo [500];
                int array [500];
                int longitud=0, num;
                long long suma=0;
                //long long int numero;
                int cont1=0, cont2=1;
                int aux;

                cout<<endl<<"Ingrese un numero entero: ";
                cin>>num;

                cout<<endl<<"Ingresa una cadena de caracteres numericos y termine con ',': ";

                do{

                    cin>>letra;
                    arreglo[longitud]=letra;
                    longitud+=1;

                }

                while (letra!=',');

                cout<<endl<<"Original: "<<RetornarNumero(arreglo,longitud)<<"."<<endl;

                if ((longitud-1)%num==0){
                    aux=(longitud-1)/num;
                }
                else{
                    aux=((longitud-1)/num)+1;
                }

                for (int j=0;j<aux;j++){

                    long long int acumulado=0;
                    int cont3=num-1;

                    for (int i=longitud-2-(cont1*num);i>=longitud-1-(cont2*num);i--){

                        array[cont3]=arreglo[i];

                        cont3-=1;

                        //cout<<endl<<i<<" "<<arreglo[i];

                    }

                    acumulado=RetornarNumero(array,num+1);

                    //cout<<endl<<j<<" "<<acumulado<<endl;

                    suma=suma+acumulado;

                    cont1+=1;
                    cont2+=1;

                }


                cout<<"Suma: "<<suma<<endl;

                break;

            }

        case 10: //Escribir un programa que permita convertir un número en el sistema romano al sistema arábigo usado actualmente. A continuación se encuentran los caracteres usados en el sistema romano y su equivalente arábigo:M: 1000 D: 500 C: 100 L: 50 X: 10 V: 5 I: 1

            {   char letra;
                char arreglo [500];
                int longitud=0;
                int array [500];
                char romanos [7]={'M','D','C','L','X','V','I'};
                int numeros [7]={1000,500,100,50,10,5,1};
                int total=0;

                cout<<endl<<"Ingresa un numero en el sistema romano (caracteres en mayusculas) y termine con ',': ";

                do{

                    cin>>letra;
                    arreglo[longitud]=letra;
                    longitud+=1;

                }

                while (letra!=',');

                cout<<endl<<"El numero ingresado fue: ";

                for (int k=0;k<longitud-1;k++){

                    //arregOriginal[k]=arreglo[k];
                    cout<<arreglo[k];

                }

                for (int i=0;i<longitud-1;i++){

                    for (int j=0;j<7;j++){

                        if (arreglo[i]==romanos[j]){
                            array[i]=numeros[j];
                        }

                    }

                    //cout<<endl<<array[i];

                }

                for (int k=0;k<longitud-1;k++){

                    if (array[k]>=array[k+1]){
                        total=total+array[k];
                    }
                    else{
                        total=total-array[k];
                    }

                }

                total += array[longitud - 1];

                cout<<endl<<"Que corresponde a: "<<total<<"."<<endl;

                break;

            }

        case 11: //Escriba un programa que permita manejar las reservas de asientos en una sala de cine, los asientos de la sala de cine están organizados en 15 filas con 20 asientos cada una. El programa debe mostrar una representación de la sala que indique que asientos están disponibles y cuales se encuentran reservados. Además debe permitir realizar reservas o cancelaciones al ingresar la fila (letras A-O) y el número del asiento (números 1-20).

            {   char matriz [15][20];
                char reserva='+';
                char disponible='-';
                char array [15]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
                char asiento,silla;
                char letra;
                int numero;
                char arreglo [500];
                int opcion=1,posLetra=0,posNumero=0;

                for (int i=0;i<15;i++){

                    for (int j=0;j<20;j++){

                        matriz[i][j]=disponible;
                        //asiento=matriz[i][j];
                        //cout<<"  "<<asiento<<"   ";

                    }

                    //cout<<endl;

                }

                while (opcion!=0){

                    cout<<endl<<"Ingrese la opcion que desea: 1 para reservar, 2 para cancelar o 0 para terminar: ";
                    cin>>opcion;

                    switch(opcion){

                    case 0:
                    {
                        cout<<endl<<"Asi ha quedado su reserva"<<endl;
                        cout<<endl;

                        for (int i=0;i<15;i++){

                            for (int j=0;j<20;j++){

                                //matriz[i][j]=disponible;
                                asiento=matriz[i][j];
                                cout<<"  "<<asiento<<"   ";

                            }

                            cout<<endl;

                        }

                        cout<<endl<<"Gracias, hasta la proxima"<<endl;
                        break;
                    }

                    case 1:
                    {

                        cout<<endl<<"Asientos disponibles: ( - )"<<endl;
                        cout<<endl;

                        for (int i=0;i<15;i++){

                            for (int j=0;j<20;j++){

                                //matriz[i][j]=disponible;
                                asiento=matriz[i][j];
                                cout<<"  "<<asiento<<"   ";

                            }

                            cout<<endl;

                        }

                        cout<<endl<<"Ingrese el asiento que quiere reservar: Fila(A-O)Columna(1-20).  Termine con ',': ";
                        int longitud=0;

                        do{

                            cin>>silla;
                            arreglo[longitud]=silla;
                            longitud+=1;

                        }

                        while (silla!=',');

                        letra=arreglo[0];

                        int contador=0;

                        for (int j=48;j<=57;j++){

                            if (arreglo[1]==j){
                                numero=contador;
                                contador=0;
                                break;
                            }
                            else{
                                contador+=1;
                            }

                        }

                        for (int j=48;j<=57;j++){

                            if (arreglo[2]==j){
                                numero=(numero*10)+contador;
                                break;
                            }
                            else{
                                contador+=1;
                            }

                        }

                        for (int i=0;i<15;i++){

                            if (letra==array[i]){
                                posLetra=i;
                                break;
                            }

                        }

                        posNumero=numero-1;

                        matriz[posLetra][posNumero]=reserva;

                        break;


                    }

                    case 2:
                    {

                        cout<<endl<<"Asientos disponibles: ( - )"<<endl;
                        cout<<endl;

                        for (int i=0;i<15;i++){

                            for (int j=0;j<20;j++){

                                //matriz[i][j]=disponible;
                                asiento=matriz[i][j];
                                cout<<"  "<<asiento<<"   ";

                            }

                            cout<<endl;

                        }

                        cout<<endl<<"Ingrese el asiento que quiere cancelar: Fila(A-O)Columna(1-20).  Termine con ',': ";
                        int longitud=0;

                        do{

                            cin>>silla;
                            arreglo[longitud]=silla;
                            longitud+=1;

                        }

                        while (silla!=',');

                        letra=arreglo[0];

                        int contador=0;

                        for (int j=48;j<=57;j++){

                            if (arreglo[1]==j){
                                numero=contador;
                                contador=0;
                                break;
                            }
                            else{
                                contador+=1;
                            }

                        }

                        for (int j=48;j<=57;j++){

                            if (arreglo[2]==j){
                                numero=(numero*10)+contador;
                                break;
                            }
                            else{
                                contador+=1;
                            }

                        }

                        for (int i=0;i<15;i++){

                            if (letra==array[i]){
                                posLetra=i;
                                break;
                            }

                        }

                        posNumero=numero-1;

                        matriz[posLetra][posNumero]=disponible;

                        break;


                    }

                    default: cout<<"Ha ingresado una opcion incorrecta"<<endl;

                    }

                }

            break;

        }

        case 12: // Un cuadrado mágico es una matriz de números enteros sin repetir, en la que la suma de los números en cada columna, cada fila y cada diagonal principal tienen como resultado la misma constante. Escriba un programa que permita al usuario ingresar una matriz cuadrada, imprima la matriz y verifique si la matriz es un cuadrado mágico.

            {   int n;

                cout<<endl<<"Ingrese el orden de la matriz: ";
                cin>>n;

                char posicion;
                int arreglo[500];
                long long int numero=0;

                int matriz [n][n];

                for (int i=0;i<n;i++){

                    for (int j=0;j<n;j++){

                        int longitud=0;
                        cout<<endl<<"Ingrese la posicion "<<i<<","<<j<<" de la matriz y finalice con ',': ";

                        do{

                            cin>>posicion;

                            arreglo[longitud]=posicion;
                            longitud+=1;

                        }

                        while (posicion!=',');

                        numero=RetornarNumero(arreglo,longitud);

                        matriz[i][j]=numero;

                        if (i==n-1 && j==n-1){
                            break;
                        }

                    }

                }

                cout<<endl<<"La matriz ingresada es la siguiente"<<endl;
                cout<<endl;

                int l=0;

                for (int i=0;i<n;i++){

                    for (int j=0;j<n;j++){

                        l=matriz[i][j];
                        cout<<"  "<<l<<"   ";

                    }

                    cout<<endl;

                }

                int valor=0;
                bool validacion=false;

                for (int i=0;i<n;i++){

                    int suma=0;

                    for (int j=0;j<n;j++){

                        suma+=matriz[i][j];
                        //cout<<endl<<suma<<" con j="<<j;

                    }

                    if (i==0){
                        valor=suma;
                    }
                    else if (valor!=suma){
                        validacion=false;
                        break;
                    }
                    else if (valor==suma){
                        validacion=true;
                    }

                    //cout<<endl<<"Suma="<<suma<<" "<<"Validacion="<<validacion;

                }

                for (int i=0;i<n;i++){

                    int suma=0;

                    for (int j=0;j<n;j++){

                        suma+=matriz[j][i];
                        //cout<<endl<<suma<<" con i="<<i;


                    }

                    if (valor!=suma){
                        validacion=false;
                        break;
                    }
                    else if (valor==suma){
                        validacion=true;
                    }

                    //cout<<endl<<"Suma="<<suma<<" "<<"Validacion="<<validacion;

                }

                int suma=0;

                for (int i=0;i<n;i++){

                    for (int j=0;j<n;j++){

                        if (i==j){
                             suma+=matriz[i][j];
                        }

                        //cout<<endl<<suma<<" con "<<i<<"="<<j;

                    }

                }

                if (valor==suma){
                    validacion=true;
                }

                else{
                    validacion=false;
                }

                //cout<<endl<<"Suma="<<suma<<" "<<"Validacion="<<validacion;

                suma=0;

                for (int i=0;i<n;i++){

                    for (int j=n-1;j>=0;j--){

                        if ((i+j)==(n-1) ){
                            suma+=matriz[i][j];
                        }

                        //cout<<endl<<suma<<" con "<<i<<"="<<j;

                    }

                }

                if (valor==suma){
                    validacion=true;
                }

                else{
                    validacion=false;
                }

                //cout<<endl<<"Suma="<<suma<<" "<<"Validacion="<<validacion;

                if (validacion){
                    cout<<endl<<"La matriz ingresada representa una cuadro magico"<<endl;
                }
                else{
                    cout<<endl<<"La matriz ingresada no representa una cuadro magico"<<endl;
                }

                break;

            }

        case 13: //  Se tiene una fotografía digitalizada de una porción de la galaxia NGC 1300 que está ubicada a 61.000.000 de años luz del planeta Tierra. La representación digital de la imagen está constituida por una matriz de números enteros; en la cual, cada uno representa la cantidad de luz en ese punto de la imagen.  Elabore y pruebe una función que reciba un puntero a la matriz de enteros como argumento y que retorne el número de estrellas encontradas en la imagen. Ignore las posibles estrellas que puedan existir en los bordes de la matriz.

            {   int matriz[6][8]={{0,3,4,0,0,0,6,8},{5,13,6,0,0,0,2,3},{2,6,2,7,3,0,10,0},{0,0,4,15,4,1,6,0},{0,0,7,12,6,9,10,4},{5,0,6,10,6,4,8,0}};

                int (*ptr)[8]=matriz;

                int estrellas=0;

                estrellas=Estrellas(ptr);

                cout<<endl<<"El numero de estrellas encontrado fue: "<<estrellas<<endl;

                break;

            }

        case 14: //Elabore un programa que llene una matriz 5x5 con los números del 1 al 25 y la imprima, luego imprima la matriz rotada 90, 180 y 270 grados.

            {   int matriz[5][5];
                int matriz90[5][5];
                int matriz180[5][5];
                int matriz270[5][5];
                //int aleatorio=0;
                int contador=1;

                //srand(time(0));

                cout<<endl<<"Matriz original"<<endl;
                cout<<endl;

                for (int i=0;i<5;i++){

                    for (int j=0;j<5;j++){

                        //aleatorio=1+rand()%26;
                        matriz[i][j]=contador;

                        if (contador<10){
                            cout<<"  "<<contador<<"  ";
                        }
                        else{
                            cout<<" "<<contador<<"  ";
                        }

                        contador+=1;

                    }

                    cout<<endl;

                }

                cout<<endl<<"Matriz rotada 90 grados"<<endl;
                cout<<endl;

                for (int i=0;i<5;i++){

                    int cont=4;

                    for (int j=0;j<5;j++){

                        matriz90[i][j]=matriz[cont][i];
                        contador=matriz90[i][j];
                        cont-=1;

                        if (contador<10){
                            cout<<"  "<<contador<<"  ";
                        }
                        else{
                            cout<<" "<<contador<<"  ";
                        }

                    }

                    cout<<endl;
                }

                cout<<endl<<"Matriz rotada 180 grados"<<endl;
                cout<<endl;

                for (int i=0;i<5;i++){

                    int cont=4;

                    for (int j=0;j<5;j++){

                        matriz180[i][j]=matriz90[cont][i];
                        contador=matriz180[i][j];
                        cont-=1;

                        if (contador<10){
                            cout<<"  "<<contador<<"  ";
                        }
                        else{
                            cout<<" "<<contador<<"  ";
                        }

                    }

                    cout<<endl;
                }

                cout<<endl<<"Matriz rotada 270 grados"<<endl;
                cout<<endl;

                for (int i=0;i<5;i++){

                    int cont=4;

                    for (int j=0;j<5;j++){

                        matriz270[i][j]=matriz180[cont][i];
                        contador=matriz270[i][j];
                        cont-=1;

                        if (contador<10){
                            cout<<"  "<<contador<<"  ";
                        }
                        else{
                            cout<<" "<<contador<<"  ";
                        }

                    }

                    cout<<endl;
                }


                break;

            }

        case 15: //

            {   char letra;
                int arreglo[4];
                int arreglo1 [4];
                int arreglo2 [4];
                int resultado [4];
                int longitud=0;
                long long int numero=0;

                cout<<endl<<"********Ingrese los datos del primer rectangulo*********"<<endl;

                for (int i=0;i<4;i++){

                    int longitud=0;

                    if (i==0){
                        cout<<endl<<"Ingrese la posicion x del rectangulo y finalice con: ";
                    }
                    else if (i==1){
                        cout<<endl<<"Ingrese la posicion y del rectangulo y finalice con: ";
                    }
                    else if (i==2){
                        cout<<endl<<"Ingrese el ancho del rectangulo y finalice con: ";
                    }
                    else if (i==3){
                        cout<<endl<<"Ingrese el largo del rectangulo y finalice con: ";
                    }

                    do{

                        cin>>letra;

                        arreglo[longitud]=letra;
                        longitud+=1;

                    }

                    while (letra!=',');

                    numero=RetornarNumero(arreglo,longitud);

                    arreglo1[i]=numero;

                    if (i==4){
                        break;
                    }

                }

                cout<<endl<<"********Ingrese los datos del segundo rectangulo*********"<<endl;

                for (int i=0;i<4;i++){

                    int longitud=0;

                    if (i==0){
                        cout<<endl<<"Ingrese la posicion x del rectangulo y finalice con: ";
                    }
                    else if (i==1){
                        cout<<endl<<"Ingrese la posicion y del rectangulo y finalice con: ";
                    }
                    else if (i==2){
                        cout<<endl<<"Ingrese el ancho del rectangulo y finalice con: ";
                    }
                    else if (i==3){
                        cout<<endl<<"Ingrese el largo del rectangulo y finalice con: ";
                    }

                    do{

                        cin>>letra;

                        arreglo[longitud]=letra;
                        longitud+=1;

                    }

                    while (letra!=',');

                    numero=RetornarNumero(arreglo,longitud);

                    arreglo2[i]=numero;

                    if (i==4){
                        break;
                    }

                }

                cout<<endl<<"Datos del primer rectangulo: {";

                for (int j=0;j<4;j++){

                    if (j!=3){
                        cout<<arreglo1[j]<<",";
                    }
                    else{
                        cout<<arreglo1[j]<<"}."<<endl;
                    }

                }

                cout<<"Datos del segundo rectangulo: {";

                for (int j=0;j<4;j++){

                    if (j!=3){
                        cout<<arreglo2[j]<<",";
                    }
                    else{
                        cout<<arreglo2[j]<<"}."<<endl;
                    }

                }

                for (int k=0;k<4;k++){

                    if (k==0 || k==1){

                        if (arreglo1[k]>=arreglo2[k]){
                            resultado[k]=arreglo1[k];
                        }
                        else{
                            resultado[k]=arreglo2[k];
                        }

                    }

                    if (k==2){

                        if ((arreglo1[k-2]+arreglo1[k])>=(arreglo2[k-2]+arreglo2[k])){
                            resultado[k]=(arreglo2[k]+arreglo2[k-2])-resultado[k-2];
                        }
                        else{
                            resultado[k]=(arreglo1[k]+arreglo1[k-2])-resultado[k-2];
                        }

                    }

                    if (k==3){

                        if ((arreglo1[k-2]+arreglo1[k])>=(arreglo2[k-2]+arreglo2[k])){
                            resultado[k]=(arreglo2[k]+arreglo2[k-2])-resultado[k-2];
                        }
                        else{
                            resultado[k]=(arreglo1[k]+arreglo1[k-2])-resultado[k-2];
                        }

                    }

                }

                if (resultado[2]>0 && resultado[3]>0){

                    cout<<endl<<"Interseccion: {";

                    for (int i=0;i<4;i++){
                        if (i!=3){
                            cout<<resultado[i]<<",";
                        }
                        else{
                            cout<<resultado[i]<<"}."<<endl;
                        }
                    }
                }

                else{
                    cout<<endl<<"Los resctangulos ingresados no tienen interseccion."<<endl;
                }

                break;

            }

        case 16: //En una malla de 2x2, realizando únicamente movimientos hacia la derecha y hacia abajo hay 6 posibles caminos para llegar de la esquina superior izquierda a la inferior derecha.  Escriba un programa que reciba un numero n y calcule el número de caminos posibles en una cuadricula de nxn.  Nota: la salida del programa debe ser: Para una malla de 2x2 puntos hay 6 caminos.

            {

                int orden=0;
                long long int factorial1=1, factorial2=1;
                int caminos=0;

                cout<<endl<<"Ingrese un numero entero: ";
                cin>>orden;

                for (int i=1;i<=orden;++i){
                    factorial1=factorial1*i;
                }

                cout<<endl<<factorial1;

                for (int i=1;i<=(2*orden);++i){
                    factorial2=factorial2*i;
                }

                cout<<endl<<factorial2;

                caminos=(factorial2)/(factorial1*factorial1);

                cout<<endl<<"El numero de caminos para una malla de "<<orden<<"x"<<orden<<" puntos hay "<<caminos<<" caminos"<<endl;

                break;

            }

        case 17: //Dos números a y b (a != b) son amigables si la suma de los divisores de a (excluyéndose el mismo) es igual a b, y viceversa. Ej: los divisores de 220 son 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 y 110; y suman 284. Los divisores de 284 son 1, 2, 4, 71 y 142; y suman 220. Entonces 220 y 284 son amigables. Escribir un programa que reciba un número y halle la suma de todos los números amigables menores al número ingresado.

            {   int N,i;
                int acumulado=0;
                //bool validacion=false;

                cout<<endl<<"Ingrese un numero entero: ";
                cin>>N;

                for (int j=(N-1);j>=1;j--){

                    int divisores1=0;

                    //cout<<endl<<"divisor mayor: "<<j;

                    for (i=1;i<j;++i){

                        if (j%i==0){
                            divisores1=divisores1+i;
                        }

                    }

                    //cout<<endl<<"Divisores 1: "<<divisores1;

                    for (int k=1;k<N;k++){

                        int divisores2=0;

                        for (i=1;i<k;++i){

                            if (k%i==0){

                                divisores2=divisores2+i;

                                //cout<<endl<<"Divisores 2 con k"<<k<<"="<<divisores2;
                            }

                        }

                        if (divisores1==k && divisores2==j && j!=k){

                            acumulado=acumulado+j+k;

                        }

                        //cout<<endl<<"Acumulado"<<"["<<j<<"]["<<k<<"]"<<acumulado;

                    }

                }

                cout<<endl<<"El resultado de la suma es: "<<acumulado/2<<endl;

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

int Estrellas(int (*ptr)[8]){

    int estrellas=1;

    for (int i=1;i<5;i++){

        for (int j=1;j<7;j++){

            int validacion=0;

            validacion=ptr[i][j]+ptr[i][j-1]+ptr[i][j+1]+ptr[i-1][j]+ptr[i+1][j];

            if ((validacion/5)>6){
                estrellas+=1;
            }

            cout<<endl<<i<<" "<<j<<" "<<validacion<<" "<<estrellas;;

        }
    }

    return estrellas;
}

void ImpriArregloInt(int arreglo [], int longitud){

    for (int i=0;i<longitud;i++){

        cout<<arreglo[i];

    }

}
