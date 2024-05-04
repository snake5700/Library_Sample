#include "header.h"

/**************************************************************************************************************************************************/

// Mostra il menù delle possibili opzioni ( Rimuovere in seguito ).
void menu(){
    cout << "1: Lettura di un archivio di libri" << endl;
    cout << "2: Inserimento di un libro singolo" << endl;
    cout << "3: Stampa del catalogo" << endl;
    cout << "4: Ricerca per autore" << endl;
    cout << "5: Cancellazione di un libro" << endl;
    return;
}

// Create an empty magazine.
library createEmpty(){
    library b;
    return b;
}

/* Auxiliary function: Optimize the lecture of data per line. It returns a boolean value:
- False if runtime error is issue;
- True if all gone. */
bool goodStream(ifstream& ifs, book& b){
    string line="";
    if(!getline(ifs,line))
        return !(ifs.good());

    for(unsigned int i = 0; i < line.length(); i++){
        if(line[i] == ';')
            line[i] = ' ';
    }

    stringstream ss(line);
    ss >> b.autore;
    ss >> b.titolo;
    ss >> b.isbn;
    ss >> (int)b.n_copies;

    return true;
}

/* The function read from the specify stream and insert inside the magazine. It returns: 
- Magazine if all gone;
- Issue an exception if something went wrong */
library readFromStream(istream& i){
    if(!i)
        throw new runtime_error("Stream not found");
    library aux = createEmpty();
    book b;
    while(!goodStream(ifs, b))
        add(aux, b); // Call to ordered push.
    return aux;
}

/* Read from an archieve inside the system. It returns: 
- Magazine if all gone;
*/
library readFromFile(string name){
    ifstream ifs(name.c_str());
    return readFromStream(ifs);
}

// Auxiliary function: It swap two element. 
void swap(library l, int i, int j){
    book b = l.at(j); 
    l.at(j) = l.at(i);
    l.at(i) = b;
    return;
}

/****************************************************************************************************************************************************/

/* Manually insert a book inside the magazine. It returns: 
- book if all gone;
*/
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

/* Auxiliary function: It search a book inside the magazine. Returns:
- True if there is;
- False if there isn't*/
bool searchInList(const library& l, book b){
    int begin = 0;
    int end = (l.size()-1);
    int middle = 0;
    bool trovato = false;

    while((!trovato) && (begin <= end)){
        middle = ((begin + end)/2);
        if(l.at(middle).isbn == b.isbn)
            trovato = true;
        else{
            if(l.at(middle).isbn < b.isbn)
                begin = middle + 1;
            else
                end = middle - 1; 
        }   
    }
    return trovato;
}

// Ordered insert inside vect, maybe optimize the complexity.
void add(library& l, book b){
    if(searchInList(l, b))
       return;
    if((l.size() == 0) || (l.at(l.size()-1).isbn < b.isbn))
        l.push_back(b);
    for(unsigned int i = 0; i < l.size(); i++){
        if(l.at(i).isbn > b.isbn){
            l.push_back(b);
            for(unsigned int j = (l.size()-1); j > i; j--)
                swap(l, j, j-1);
        }
    }
    return;
}

/****************************************************************************************************************************************************/

// Print magazine.
void print(const library& l){
    if(l.empty())
        return;
    cout << "-------------------------------------------------------------" << endl;
    for(unsigned int i=0; i<l.size(); i++)
        cout << "Autore: " << l.at(i).autore << "\nTitolo: " << l.at(i).titolo << "\nIsbn: " << l.at(i).isbn << "\nCopie: " << l.at(i).n_copies << endl;
    cout << "-------------------------------------------------------------" << endl;
    return;
}

/***************************************************************************************************************************************************/

/* Used for construct a list of books written by a given author. It returns:
- List of books if all gone;
- Empty List if an empty list is given. */
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

/* Auxiliary function: It search an element inside the library for deleting. It returns:
- The position of element if all is gone;
- '-1' if the element isn't inside. */
int searchPos(const library &l, string isbn){ // Is this a code clone?
    int begin = 0;
    int end = (l.size() -1);
    int middle = 0;
    bool trovato = false;

    while((!trovato) && (begin <= end)){
        middle = ((begin + end)/2);
        if(l.at(middle).isbn == isbn)
            trovato = true;
        else{
            if(l.at(middle).isbn < isbn)
                begin = middle + 1;
            else
                end = middle - 1; 
        }   
    }
    return (trovato ? middle : -1); // Maybe find a better way to write it? 
}

/* Remove: It delete a book from a list.*/
void remove(library& l, string isbn){
    if(l.empty())
        return;
    int pos = searchPos(l, isbn);
    if(pos < 0)
        throw new range_error("Index out of bound");
    for(unsigned int i = pos; i < (l.size()-1); i++)
        swap(l, i, (i+1));
    l.pop_back();
    return;
}
