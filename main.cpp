#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>


#include "Lista.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    Lista<Animal> stLista;

    for (int i = 1; i < argc; i++) {
        Animal a;
        char *d = strchr(argv[i], '-');
        string nome_grupo(argv[i]);
        int traco = nome_grupo.find('-');

        string nome = nome_grupo.substr(0, traco);
        string grupo = nome_grupo.substr(traco);

        sprintf(a.cNome, "%s", nome.c_str());
        sprintf(a.cGroup, "%s", grupo.c_str());
        a.nCodigo = i + 1;
        stLista.add(a);
    }

    Item<Animal> ai;
    Animal an;
    sprintf(an.cNome, "%s", "Vaca");
    sprintf(an.cGroup, "%s", "Mamifero");
    an.nCodigo = 98;

    ai.item = an;
    stLista.insert(an, 0);


    stLista.remove(5);


    printf("%s %d\n", "Quantidade total ", stLista.getSize());
    for (int i = 0; i < stLista.getSize(); i++) {
        printf("%dº Animal; Nome: %s\n", i,  stLista.get(i).cNome);
    }
    //stLista.clear();

    return 0;
}

