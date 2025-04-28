#include <cmath>
#include <iostream>
#include <numeric> //libreria per usare ad esempio std::iota(riempire vettori con valori consecutivi)
#include <sstream> //libreria per operazioni di conversione dati in stringhe
#include <chrono>  //libreria per misurare il tempo

#include "SortingAlgorithm.hpp"
using namespace std;

template<typename T>  //definisco funzione generica per qualsiasi T
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString; //creo oggetto per costruire stringa
    toString << "[ ";
    for (const T& e: v)        //ciclo che scorre ogni elemento del vettore e lo aggiunge alla stringa
        toString << e << " ";
    toString << "]";

    return toString.str();   //restituisco stringa che rappresenta vettore
}

int main(int argc, char *argv[])   //accetto argomenti da linea di comando(argv è argument vector)
{
    cout << "argc: " << argc << endl;
    for (int a = 0; a < argc; a++)   //ciclo che stampa ogni argomento passato
        cout << argv[a] << " ";
    cout << endl;

    size_t m = 100;   //inizializzo a 100 il valore predefinito
    if (argc > 1)
    {
        istringstream convert(argv[1]);
        convert >> m;
        cout << "use value: "  << m << endl;
    }
    else
        cerr << "use default value: "  << m << endl;
    
	//creo le 3 tipologie di vettori che userò per fare il test
	
	
    vector<int> v1(m);      //creo vettore di dimensione m
    std::iota(v1.begin(), v1.end(), -4);  //riempio il vettore con valori consecutivi a partire da -4

    srand(2);   //imposto seme
    vector<double> v2(m);
    for (size_t i = 0; i < m; i++)  //riempio il vettore con numeri casuali normalizzati tra 0 e 1
        v2[i] = rand() / ((double)RAND_MAX);

    vector<int> v3(m, 0);  //creo vettore di interi di dimensione m inizializzato a 0
    for (size_t i = floor(m * 0.5) + 1; i < m; i++)  //riempio metà del vettore casualmente
        v3[i] = rand() % 1000;  //ad ogni iterazione,assegna un numero casuale intero da 0 a 999 alla posizione i del vettore v3
    //copio la prima metà del vettore v1 in v3.
    copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin());
    
	//stampo tempo corrente
    const auto today_time = std::chrono::system_clock::now();
    std::cout << "Tempo trascorso dal 1 gennaio 1970: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(
                     today_time.time_since_epoch()).count() << endl;

    unsigned int num_experiment = 1000; //Numero di volte che ogni test verrà ripetuto per calcolare la media.
    
	//ora devo misurare quanto tempo impiega il bubble sort a ordinare il vettore v1(facendo molti eseperimenti)
    
	double time_elapsed_bubble_v1 = 0.0; //inizializzo il tempo
	//ripeto il test molte volte e calcolo la media del tempo
    for (unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);  //creo copia di v1
		//registro il tempo di inizio usando steady clock che è piu preciso
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);  //eseguo bubble sort sul vettore v
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now(); //salvo il tempo dopo l'ordinamento
		//calcolo quanto è trascorso usando gli opportuni comandi della libreria chrono e inserisco dentro la variabile
        time_elapsed_bubble_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v1 /= num_experiment; //ottengo tempo medio
    cout << "Bubble Sort - v1: " << time_elapsed_bubble_v1 << " Microsecondi" << endl;
    
	//stesso procedimento per altri 2 vettori
	
    double time_elapsed_bubble_v2 = 0.0;
    for (unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v2 /= num_experiment;
    cout << "Bubble Sort - v2: " << time_elapsed_bubble_v2 << " Microsecondi" << endl;

    double time_elapsed_bubble_v3 = 0.0;
    for (unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v3 /= num_experiment;
    cout << "Bubble Sort - v3: " << time_elapsed_bubble_v3 << " Microsecondi" << endl;
    
	//Stessi ragionameti per heap sort
	
    double time_elapsed_heap_v1 = 0.0;
    for (unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v1 /= num_experiment;
    cout << "Heap Sort - v1: " << time_elapsed_heap_v1 << " Microsecondi" << endl;

    double time_elapsed_heap_v2 = 0.0;
    for (unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v2 /= num_experiment;
    cout << "Heap Sort - v2: " << time_elapsed_heap_v2 << " Microsecondi" << endl;

    double time_elapsed_heap_v3 = 0.0;
    for (unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v3 /= num_experiment;
    cout << "Heap Sort - v3: " << time_elapsed_heap_v3 << " Microsecondi" << endl;

    return 0;
}







