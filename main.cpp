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
    //Animal *ptrProximo;
};

// Container para emcapsular os itens da lista e criar ligação entre eles
template <class TItem>
class Item {
public:
    Item* ptrProximo;
    TItem item;
};
// Classe que representa a lista em sí
template <class T>
class Lista {
    int size;
    Item<T> *ptrPrimeiro; // Ponteiro para montar a lista
    Item<T> *ptrUlt;      // Ponteiro para montar a lista
    Item<T> stItem;     // para conter um item

public:
    Lista() {
        this->ptrPrimeiro = NULL;
        this->size = 0;
    }

    void add(T item) {
        if (this->ptrPrimeiro == NULL) { // Será o primeiro
            this->ptrPrimeiro = this->ptrUlt = new Item<T>;
        }
        else { // Será o último
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
        if (pos > size || pos < 0) {
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
        if (pos > size || pos < 0) {
            cerr << "Invalid index" << endl;
        }

        return true;
    }
    int getSize() { return this->size; }
    bool isEmpty() { return this->size == 0; }
};



int main(int argc, char *argv[]) {
    
    Lista<Item<Animal>> stLista;
    
    for (int i = 1; i < argc; i++) {
        Item<Animal> itemAnimal;
        Animal a;
        sprintf(a.cNome, "Nome: %s", argv[i]);
        sprintf(a.cGroup, "%d", i +1);
        itemAnimal.item = a;
        a.nCodigo = i + 1;
        stLista.add(itemAnimal);
    }

    cout << "Quantidade total " << stLista.getSize() << endl;
    for (int i = 0; i < stLista.getSize(); i++) {
        printf("%dº Animal; Nome: %s\n", i,  stLista.get(i).item.cNome);
    }

    return 0;
}

