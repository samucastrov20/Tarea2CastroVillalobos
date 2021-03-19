#include <stdio.h>
#include <iostream>
#include <math.h>
#include <thread>
#include <pthread.h>
#include <chrono>
using namespace std;

const long long numero = 1000000;
long long array1 [numero]; //no se pudo definir la longitud del array con una variable
long long array2 [numero];

void Potencia(long long inicio, long long fin)
{
    for (int a=inicio;a<fin;a++){
        array2[a]=pow(array1[a],2);
    }
}

int main(){
    using namespace std::literals::chrono_literals;
    auto start = chrono::high_resolution_clock::now();

    thread Hilos[4];
    int limites[]={0,numero/4,numero/2,numero*3/4,numero};
    int c;

    for (int i=0;i<numero;i+=1){
        array1[i]=i;
        //c = rand() %100;
        //array1[i]=c;
    }

    for (int j=0;j < 4;j+=1){
        Hilos[j]=thread(Potencia,limites[j],limites[j+1]);
    }

    for (int k=0;k < 4;k+=1){
        Hilos[k].join();
    }
    /*
    for(int l=0;l < numero;l+=1){
        cout<<array2[l]<<' ';
    }
    */
   
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start; 
    cout << duration.count() << "";

    return 1;
}