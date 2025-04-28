#pragma once

#include <iostream>
#include <vector>
#include <algorithm>  // per std::swap

//racchiudo tutto in un namespace di nome sortlibrary in modo tale da evitare conflitti di nome con altri file o librerie
namespace SortLibrary {

//Algoritmo Bubble Sort
template<typename T>  //rendo la funzione generica
void BubbleSort(std::vector<T>& v) //passo vettore v per riferimento
{
    bool swapped; //serve per controllare se sono stati effettuati scambi durante un ciclo
    const unsigned int n = v.size();   //salvo lunghezza vettore in una variabile locale
    for (unsigned int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (unsigned int j = 0; j < n - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Se non ci sono stati scambi, il vettore è già ordinato
    }
}

//Funzione di heapify
template<typename T>
void heapify(std::vector<T>& v, int n, int i)
{
    int largest = i;       //assume che la radice(i) sia la più grande
    int left = 2 * i + 1;  //Calcola l'indice del figlio sinistro
    int right = 2 * i + 2; //Calcola l'indice del figlio destro
    
	//Se il figlio sinistro esiste ed è maggiore del padre,aggiorno largest
    if (left < n && v[left] > v[largest])
        largest = left;
    
	//Se il figlio destro esiste ed è maggiore del massimo attuale, aggiorno largest
	
    if (right < n && v[right] > v[largest])
        largest = right;
    
	//Se largest è cambiato (quindi un figlio era più grande del padre)

    if (largest != i) {
        std::swap(v[i], v[largest]);  //Scambio il padre con il figlio maggiore
        heapify(v, n, largest);     //Chiamo ricorsivamente heapify sul sottoalbero modificato
    }
}

//Algoritmo Heap Sort
template<typename T>
void HeapSort(std::vector<T>& v)
{
    int n = v.size();   //Salvo la dimensione del vettore
    
	//Costruzione del max-heap (partendo dall'ultimo nodo genitore fino alla radice)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);
    //Estrazione degli elementi uno a uno dal heap
	
    for (int i = n - 1; i > 0; i--) {
        std::swap(v[0], v[i]);  //Sposto la radice corrente (il massimo) alla fine del vettore
        heapify(v, i, 0);      //Richiamo heapify sulla parte rimanente (escludendo l'elemento appena messo a posto)
    }
}

}









