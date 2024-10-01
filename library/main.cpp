#include "header.h"


int main(){
   
    library l,aux;
    book b;

    string isbn="", author="", file="";
    int opt = 0;
    
    l = createEmpty();
    aux = createEmpty();

    do{
        try{
            menu();
            cin >> opt;
            switch(opt){
                case 1: cout << "Inserimento automatico dei libri --> File: ";
                        cin >> file;
                        l = readFromFile(file);
                        break;
                case 2: cout << "Inserimento manuale di un libro" << endl;
                        b = create();
                        add(l,b);
                        break;
                case 3: cout << "Stampa della libreria:" << endl;
                        print(l);
                        break;
                case 4: cout << "Ricerca dei libri scritti da un particolare autore: ";
                        cin >> author;
                        aux = searchInLibrary(l, author);
                        cout << "Ecco cosa ho trovato:" << endl;
                        print(aux);
                        break;
                case 5: cout << "Cancellazione tramite isbn:" << endl;
                        cin >> isbn;
                        remove(l,isbn);
                        print(l);
                default: break;
            }
        }catch(exception& ex){
            cerr << ex.what() << endl;
        }
    }while(opt != 4); // Forse un piccolo cambiamneto? Mh.

    return 0;
}