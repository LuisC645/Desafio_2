#ifndef NODO_H
#define NODO_H

template <class Type>

class nodo {

private:
    Type dato;
    nodo<Type>* next;

public:
    nodo(const Type& d) : dato(d), next(nullptr) {}

    const Type& getDato() const {
        return dato;
    }

    nodo<Type>* getNext() const {
        return next;
    }
    void setNext(nodo<Type>* n) {
        next = n;
    }
    void setDato(const Type& d) {
        dato = d;
    }


};

#endif // NODO_H
