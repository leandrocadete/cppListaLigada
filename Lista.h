#ifndef LISTA_H

#include "Item.h"
#include <iostream>

using namespace std;

// Classe exemplo, poderia ser pessoa, produto, carro, etc
class Animal {
public:
    char cNome[50];
    char cGroup[46];
    int nCodigo;
};

template <class T>
class Lista {
    int size;
    Item<T> *ptrPrimeiro; // Ponteiro para montar a lista
    Item<T> *ptrUlt;      // Ponteiro para montar a lista

public:
    Lista() {
        this->ptrPrimeiro = NULL;
        this->ptrUlt = NULL;
        this->size = 0;
    }

    void add(T item) {
        if (this->ptrPrimeiro == NULL) { // Será o primeiro
            this->ptrPrimeiro = this->ptrUlt = new Item<T>;
        } else { // Será o último
            this->ptrUlt = this->ptrUlt->ptrProximo = new Item<T>;
        }
        this->ptrUlt->ptrProximo = NULL; // O último aponta para NULL
        // copiar o conteúdo de animal para ptrUltimo
        Item<T> nItem;
        nItem.item = item;
        memcpy(this->ptrUlt, &nItem, sizeof(Item<T>));
        this->size++; // size
    }
    T get(int pos) {
        if (pos >= size || pos < 0) {
            cerr << "Out of range\n";
            Item<T> *ptrWork = new Item<T>;
            return ptrWork->item;
        }
        Item<T> *ptrWork;
        int i;
        for (ptrWork = this->ptrPrimeiro, i = 0; i < pos; ptrWork = ptrWork->ptrProximo, i++);
        return ptrWork->item;
    }
    bool insert(T item, int pos) {
        if ((pos >= size && size > 0) || pos < 0) {
            cerr << "Insert erro. Invalid index\n";
            return false;
        }
        if(this->ptrPrimeiro == NULL) {
            this->ptrPrimeiro = this->ptrUlt = new Item<T>;
        }
        // pega o index desejado
        Item<T> *ptrWork;
        int i;
        if(pos == 0) {
            ptrWork = this->ptrPrimeiro;
        } else {
            for (ptrWork = this->ptrPrimeiro, i = 0; i < pos-1; ptrWork = ptrWork->ptrProximo, i++);
        }

        if(size == 0) {
            ptrWork->item = item;
            ptrWork->ptrProximo = NULL;    
        } else {
            Item<T> *newItem = new Item<T>();
            newItem->item = item;

            Item<T>* backup = ptrWork->ptrProximo;
            if(pos>0) {
                printf("Nome $$$ %s $$$\n", ((Animal)ptrWork->item).cNome);
                ptrWork->ptrProximo = newItem;
                newItem->ptrProximo = backup; 
            } else {
                printf("Nome ### %s ###\n", ((Animal)ptrWork->item).cNome);
                newItem->ptrProximo = ptrWork;
                this->ptrPrimeiro = newItem;
            }
        }
        this->size++;
        return true;
    }
    bool remove(int pos) {
        if(pos >= size || pos < 0) {
            cerr << "Invalid index\n";
            return false;
        }
        Item<T> *ptrWork;
        int i;
        if(pos == 0) {
            this->ptrPrimeiro = this->ptrPrimeiro->ptrProximo;
        } else {
            for (ptrWork = this->ptrPrimeiro, i = 0; i < pos-1; ptrWork = ptrWork->ptrProximo, i++);
            ptrWork->ptrProximo = ptrWork->ptrProximo->ptrProximo;
        }
        this->size--;
    }
    void clear() {
        Item<T> *ptrWork; int i = 0;
        Item<T> *ptrTemp;

        for(ptrWork = this->ptrPrimeiro, ptrTemp = ptrWork, i = 0; i < size; ptrTemp = ptrWork, ptrWork = ptrTemp->ptrProximo, i++) {
            if(i != 0) {
                //printf("Delete Index: %d, \t %s\n", i, ((Animal) ptrTemp->item).cNome);
                delete ptrTemp;
            }
        }
        this->ptrPrimeiro = NULL;
        delete this->ptrUlt;
    }
    int getSize() { return this->size; }
    bool isEmpty() { return this->size == 0; }
};



#endif