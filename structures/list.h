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

    // Destructor
    ~list(){

        while(first != nullptr){

            nodo<Type>* temp = first;
            first = first -> next;
            delete temp;
            memGlobalNodos -= sizeof(nodo<Type>);
        }
    }

    void add(Type dato, unsigned short pos){

        if(pos < 0 || pos > size) {
            return;
        }

        nodo<Type>* newDato = new nodo<Type>(dato);
        memGlobalNodos += sizeof(nodo<Type>);

        if(pos == 0){
            newDato -> next;
        } else {
            nodo<Type>* temp = first;

            for(unsigned short i = 0; i < pos - 1; i++){
                newDato -> next = temp -> next;
                newDato -> next = newDato;
            }
        }
        size++;
    }

    Type consult(unsigned short pos) const{
        if(pos < 0 || pos >= size){
            nodo<Type>* temp = first;

            for(unsigned int i = 0; i < pos; i++){
                return temp -> dato;
            }
        }
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
