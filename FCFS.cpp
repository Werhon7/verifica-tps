#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <assert.h>


using namespace std;

struct processo{

    int id, arrivo, durata, prio;


};

int main(){

    ifstream in("input.txt");
    int tempo=0;

    // Controllo se il file esiste e si apre correttamente
    if (!in.is_open()) {
        cout << "Errore nell'apertura del file!" << endl;
        return 1;
    }


    int n;
    in>>n;

    vector <processo> processi(n);

    for(int i=0; i<n; i++){
        in>>processi[i].id>>processi[i].arrivo>>processi[i].durata>>processi[i].prio;
    }

    tempo=processi[0].arrivo;

    for(int i=0; i<processi.size(); i++){
        cout<<processi[i].id<<" "<<tempo<<" "<<tempo+processi[i].durata<<"\n";
        tempo+=processi[i].durata;
    }



}

