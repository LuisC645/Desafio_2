#ifndef LIST_H
#define LIST_H

#include "nodo.h"

extern unsigned long memGlobalNodos;

template<typename Type>
class list{

private:
    nodo<Type>* first;
    unsigned int size;

public:

    // Constructor
    list(): first(nullptr), size(0) {}

    ~list(){

        while(first != nullptr){

            nodo<Type>* temp = first;
            first = first->getNext();

            delete temp;
            memGlobalNodos -= sizeof(nodo<Type>);
        }
    }

    void add(Type dato, unsigned short pos) {

        if(pos > size) return;

        nodo<Type>* newDato = new nodo<Type>(dato);

        memGlobalNodos += sizeof(nodo<Type>);

        if(pos == 0) {

            newDato->setNext(first);
            first = newDato;

        } else {

            nodo<Type>* temp = first;

            for(unsigned short i=0; i<pos-1; i++) {
                temp = temp->getNext();
            }

            newDato->setNext(temp->getNext());
            temp->setNext(newDato);
        }

        size++;
    }

    Type consult(unsigned short pos) const {

        if(pos >= size) {
            return Type();
        }

        nodo<Type>* temp = first;

        for(unsigned short i = 0; i < pos; i++) {
            temp = temp->getNext();
        }

        return temp->getDato();
    }

    // Sobrecarga op[]
    Type operator[](unsigned short pos) const {
        return consult(pos);
    }

    void replace(Type nuevoDato, unsigned short pos) {

        if(pos >= size) {
            return;
        }

        nodo<Type>* temp = first;

        for(unsigned short i = 0; i < pos; i++) {
            temp = temp->getNext();
        }

        temp->setDato(nuevoDato);
    }

    unsigned int getSize() const {
        return size;
    }

    // Reiniciar memoria global nodos
    static void resetMem() {
        memGlobalNodos = 0;
    }
};

#endif // LIST_H
