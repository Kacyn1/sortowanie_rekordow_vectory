#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

struct gracze{
        string imie, nazwisko;
        int miejsce;
};

class poz{
            vector <struct gracze> spis;
            ifstream plik1;
            ofstream plik2;
       
public:
        poz();
        ~poz();
                
        void wprowadz();
        void posortuj();             
};

	poz::poz(){
		plik1.open("p1.txt");
    	plik2.open("p2.txt");
}

int compare(const void *a, const void *b){
		return ( (*(gracze*)a).miejsce - (*(gracze*)b).miejsce );
	}

void poz::wprowadz(){
	struct gracze wprowadzani;
	while(!plik1.eof()){
		plik1>>wprowadzani.imie>>wprowadzani.nazwisko>>wprowadzani.miejsce;	
		spis.push_back(wprowadzani);
	}
	
}

void poz::posortuj(){
	qsort(&spis[0], spis.size(), sizeof(gracze),compare);
		plik2<<"["<<endl;
			for(vector<struct gracze>::iterator it = spis.begin(); it != spis.end(); ++it){
        			plik2<<"{\"miejsce\":\""<<it->miejsce<<"\", \"imie\":\""<<it->imie<<"\", \"nazwisko\":\""<<it->nazwisko<<"\"},"<<endl;
    }
    	plik2<<"]";
			
}

poz::~poz(){
    plik1.close();
    plik2.close();
}


int main(int argc, char** argv) {
        poz p1;
        p1.wprowadz();
        p1.posortuj();
    return 0;
}
