#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctype.h>
#include <iostream>
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

void createEmpty(library&); // Crea un vettore vuoto.
void add(library&, book); // Aggiunge un libro alla libreria, se questo non è presente.
void remove(library&, string); // Rimuove un libro dalla libreria, se questo è presente.
void print(const library&); // Stampa la libreria.


library searchInLibrary(const library&, string); // Cerca all'interno della libreria tutti i libri di un autore.

bool searchInList(const library&, book); // Controlla se il libro è già presente nella libreria.


void menu(); // Funzione ausiliaria.

#endif