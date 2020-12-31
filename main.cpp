#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

// Classe exemplo, poderia ser pessoa, produto, carro, etc
class Animal {
public:
    char cNome[50];
    char cGroup[46];
    int nCodigo;
};

// Container para emcapsular os itens da lista e criar ligação entre eles
template <class TItem>
class Item {
public:
    Item() {}
    ~Item() { cout << "Destructor Item" << endl; }
    Item* ptrProximo;
    TItem item;
};
// Classe que representa a lista em sí
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
            cerr << "Out of range" << endl;
            Item<T> *ptrWork = new Item<T>;
            return ptrWork->item;
        }
        Item<T> *ptrWork;
        int i;
        for (ptrWork = this->ptrPrimeiro, i = 0; i < pos; ptrWork = ptrWork->ptrProximo, i++);
        return ptrWork->item;
    }
    bool insert(T item, int pos) {
        if (pos >= size || pos < 0) {
            cerr << "Invalid index" << endl;
            return false;
        }
        // pega o index desejado
        Item<T> *ptrWork;
        int i;
        if(pos == 0) {
            ptrWork = this->ptrPrimeiro;
        } else {
            for (ptrWork = this->ptrPrimeiro, i = 0; i < pos-1; ptrWork = ptrWork->ptrProximo, i++);
        }

        Item<T> *newItem = new Item<T>();
        newItem->item = item;

        Item<T>* backup = ptrWork->ptrProximo;
        ptrWork->ptrProximo = newItem;
        newItem->ptrProximo = backup; 
        this->size++;
        return true;
    }
    bool remove(int pos) {
        if(pos >= size || pos < 0) {
            cerr << "Invalid index" << endl;
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
        // TODO
        // cout << "Clear" << endl;
        Item<T> *ptrWork; int i = 0;
        Item<T> *ptrTemp;

        for(ptrWork = this->ptrPrimeiro, ptrTemp = ptrWork, i = 0; i < size; ptrTemp = ptrWork, ptrWork = ptrTemp->ptrProximo, i++) {
            // if(ptrWork != NULL) {
            //     printf("Index: %d, \t %s\n", i, ((Animal) ptrWork->item).cNome);
            // } else {
            //     printf("NUll pointer");
            // }
            if(i != 0) {
                printf("Delete Index: %d, \t %s\n", i, ((Animal) ptrTemp->item).cNome);
                delete ptrTemp;

            }
        }
        //printf("First Index: %d, \t %s\n", 0, ((Animal) this->ptrUlt->item).cNome);
        //delete this->ptrPrimeiro;
        delete this->ptrUlt;
    }
    int getSize() { return this->size; }
    bool isEmpty() { return this->size == 0; }
};



int main(int argc, char *argv[]) {
    
    Lista<Animal> stLista;
    
    for (int i = 1; i < argc; i++) {
        Animal a;
        sprintf(a.cNome, "Nome: %s", argv[i]);
        sprintf(a.cGroup, "%d", i +1);
        a.nCodigo = i + 1;
        stLista.add(a);
    }

    Item<Animal> ai;
    Animal an;
    sprintf(an.cNome, "Nome: %s", "Inserção teste");
    an.nCodigo = 98;

    ai.item = an;
    stLista.insert(an, 0);


    stLista.remove(6);


    cout << "Quantidade total " << stLista.getSize() << endl;
    for (int i = 0; i < stLista.getSize(); i++) {
        printf("%dº Animal; Nome: %s\n", i,  stLista.get(i).cNome);
    }
    stLista.clear();

    return 0;
}

