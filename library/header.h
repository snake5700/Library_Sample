#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctype.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

struct book{
    string autore;
    string titolo;
    string isbn;
    int n_copies;
};

book create(); // Crea un libro nuovo.

typedef vector<book> library;

void add(library&, book); // Aggiunge un libro alla libreria, se questo non è presente.
void remove(library&, string); // Rimuove un libro dalla libreria, se questo è presente.
void print(const library&); // Stampa la libreria.

library createEmpty(); // Crea un vettore vuoto.
library searchInLibrary(const library&, string); // Cerca all'interno della libreria tutti i libri di un autore.
library readFromFile(string);
library readFromStream(istream&);

bool searchInList(const library&, book); // Controlla se il libro è già presente nella libreria.
bool goodStream(istream&);

void menu(); // Funzione ausiliaria.

#endif