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
    int cont=0;

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

    while(!processi.empty()){
        for(int i=0; i<processi.size(); i++){
            if (processi[i].arrivo>tempo)
                break;
            cont++;

        }

        auto it=max_element(processi.begin(),processi.begin()+cont,[] (const processo &a, const processo &b){
            
            if (a.prio==b.prio)
            {
                if (a.durata==b.durata)
                {
                    return a.arrivo<b.arrivo;
                }

                return a.durata>b.durata;
                
            }
            
            
            return a.prio>b.prio;
        });


        cout<<(*it).id<<" "<<tempo<<" "<<tempo+(*it).durata<<endl;
        tempo+=(*it).durata;
        processi.erase(it);
        cont=0;
    
    
    
    }






}

