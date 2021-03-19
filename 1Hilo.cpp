#include <stdio.h>
#include <iostream>
#include <math.h>
#include <chrono> // librerias
using namespace std;

const long numero = 1000000; //numero maximo al que se quiere llegar
long long array1 [numero];
long long array2 [numero]; // se duplica en 2 arrays

void Potencia(long long inicio, long long fin) // Funcion que calcula la potencia
{
    for (int a=inicio;a<fin;a+=1){
        array2[a]=pow(array1[a],2); //se calcula al cuadrado
    }
}


int main() //Funcion principal
{
    using namespace std::literals::chrono_literals;
    auto start = chrono::high_resolution_clock::now();
    
    //int c;
    
    for (int i=0;i<numero;i+=1){ //Se llena el array
        //c = rand() %100;
        //array1[i]=c;
        array1[i]=i;
    }

    Potencia(0,numero); //Se aplica la funcion de potencia a los nuemros del array
    
    /*
    for(int l=0;l < numero;l+=1){ //Se llena el segundo array con los resultados y se imprime
        cout<<array2[l]<<' ';
    }
    */

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start; 
    cout << duration.count() << ""; //se imprime la duracion del programa

    return 1; //termina el programa
}

