#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "Item.h"
#include "Lista.h"

using namespace std;



// Container para emcapsular os itens da lista e criar ligação entre eles

// Classe que representa a lista em sí



int main(int argc, char *argv[]) {
    
    Lista<Animal> stLista;
    
    Animal temp_1;
    sprintf(temp_1.cNome, "%s", "Insert Vaca teste");
    sprintf(temp_1.cGroup, "%s", "Mamifero");
    temp_1.nCodigo = -1;
    //stLista.insert(temp_1, 0);

    for (int i = 0; i < stLista.getSize(); i++) {
        printf("%dº Animal; Nome: %s\n", i,  stLista.get(i).cNome);
    }
    
    // printf("Press a key\n");
    // system("read r");
    // system("clear");

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


    printf("%s %d\n", "Quantidade total ", stLista.getSize());
    for (int i = 0; i < stLista.getSize(); i++) {
        printf("%dº Animal; Nome: %s\n", i,  stLista.get(i).cNome);
    }
    //stLista.clear();

    return 0;
}

