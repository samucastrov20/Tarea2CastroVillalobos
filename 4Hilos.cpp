#include <stdio.h>
#include <iostream>
#include <math.h>
#include <thread>
#include <pthread.h>
#include <chrono> // bibliotecas usadas
using namespace std;

const long long numero = 1000000;
long long array1 [numero]; //no se pudo definir la longitud del array con una variable
long long array2 [numero]; // se crean 2 arrays del mismo largo

void Potencia(long long inicio, long long fin) //Funcion para calcular potencias
{
    for (int a=inicio;a<fin;a++){
        array2[a]=pow(array1[a],2); //Se calculan los numeros al cuadrado
    }
}

int main(){ //Funcion principal
    using namespace std::literals::chrono_literals;
    auto start = chrono::high_resolution_clock::now(); //se inicia el tiempo de ejecución

    thread Hilos[4]; // se cran los cuatro hilos
    int limites[]={0,numero/4,numero/2,numero*3/4,numero}; //se definen los limiy¿tes del rango de cada hilo
    int c;

    for (int i=0;i<numero;i+=1){ //Se llena el primer array con los numeros iniciales
        array1[i]=i;
        //c = rand() %100;
        //array1[i]=c;
    }

    for (int j=0;j < 4;j+=1){ //Se calcula su potencia usando la funcion
        Hilos[j]=thread(Potencia,limites[j],limites[j+1]);
    }

    for (int k=0;k < 4;k+=1){ // Se corre el comando join para que los hilos corran adecuadamente
        Hilos[k].join();
    }
    /*
    for(int l=0;l < numero;l+=1){ //Se llena el segundo array y se imprimen los resultados
        cout<<array2[l]<<' ';
    }
    */
   
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start; 
    cout << duration.count() << ""; //Se imprime el tiempo de ejecucion

    return 1; // finaliza la función
}
