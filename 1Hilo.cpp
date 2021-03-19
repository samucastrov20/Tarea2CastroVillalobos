#include <stdio.h>
#include <iostream>
#include <math.h>
#include <chrono>
using namespace std;

const long numero = 1000000;
long long array1 [numero];
long long array2 [numero];

void Potencia(long long inicio, long long fin)
{
    for (int a=inicio;a<fin;a+=1){
        array2[a]=pow(array1[a],2);
    }
}


int main()
{
    using namespace std::literals::chrono_literals;
    auto start = chrono::high_resolution_clock::now();
    
    //int c;
    
    for (int i=0;i<numero;i+=1){
        //c = rand() %100;
        //array1[i]=c;
        array1[i]=i;
    }

    Potencia(0,numero);
    
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

