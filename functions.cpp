#include "header.h"

/**************************************************************************************************************************************************/

void menu(){
    cout << "1: Inserire un libro" << endl;
    cout << "2: Stampa libreria" << endl;
    cout << "3: Ricerca di un libro" << endl;
    cout << "4: Rimozione di un libro" << endl;
    return;
}

library createEmpty(){
    vector<book> b;
    return b;
}

/****************************************************************************************************************************************************/

book create(){
    book b;
    cout << "Autore: ";
    cin >> b.autore;
    cout << "Titolo: ";
    cin >> b.titolo;
    cout << "Isbn: ";
    cin >> b.isbn;
    cout << "Copie in magazzino: ";
    cin >> b.n_copies;
    return b;
}

// Rendere più efficiente.
bool searchInList(const library& l, book b){
    bool trovato = false;
    int i = 0;

    while((!trovato) && (i < l.size())){
        if((l.at(i).isbn == b.isbn))
            trovato = true;
        i++;
    }
    return trovato;
}

void add(library& l, book b){
    if(searchInList(l, b))
       return;
    l.push_back(b);
    return;
}

/****************************************************************************************************************************************************/

void print(const library& l){
    if(l.empty())
        return;
    cout << "-------------------------------------------------------------" << endl;
    for(unsigned int i=0; i<l.size(); i++){
        cout << "Autore: " << l.at(i).autore << "\n Titolo: " << l.at(i).titolo << "\n Isbn: " << l.at(i).isbn << "Copie: " << l.at(i).n_copies << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
    return;
}

/***************************************************************************************************************************************************/

// searchInLibrary serve per individuare più libri appartenenti ad un dato autore. Valore di ritorno atteso: Lista di libri library (Libreria, library)
library searchInLibrary(const library& l, string author){
    if(l.empty())
        return createEmpty();
    library aux = createEmpty();

    for(unsigned int i = 0; i < l.size(); i++){
        if(l.at(i).autore == author)
            aux.push_back(l.at(i));
    }

    return aux;
}

/***************************************************************************************************************************************************/

// Funzione ausialiaria! swap serve per scambiare l'elemento davanti con l'elemento attuale.
void swap(library l, int i, int j){
    book b = l.at(j); 
    l.at(j) = l.at(i);
    l.at(i) = b;
    return;
}

// Funzione ausiliria! searchPos serve per individuare la posizione del libro da cancellare. Risultato atteso: (Posizione, Intero) --> Rendere più efficiente.
int searchPos(const library &l, string isbn){
    int i, tmp;
    tmp = -1;
    bool trovato = false;

    i = 0;
    while((!trovato) && (i < l.size())){
        if(l.at(i).isbn == isbn){
            tmp = i;
            trovato = true;
        }
        i++;    
    }

    return tmp;
}

/* Remove serve per rimuovere un libro dalla libreria. Opera secondotre casi:
- Libreria vuota: Non fa nulla;
- Elem in ultima posizione: Rimuove direttamente;
- Elem in prima o posizione mediana: Porta l'elemento in ultima posizione dopo opera come caso soprastante.*/
void remove(library& l, string isbn){
    if(l.empty())
        return;
    int pos = searchPos(l, isbn);
    if(pos < 0)
        throw new range_error("Index out of bound"); // Eccezione?
    for(unsigned int i = pos; i < (l.size()-1); i++)
        swap(l, i, (i+1));
    l.pop_back();
    return;
}
