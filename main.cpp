#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;


class Animal {
public:
    char cNome[21];
    char cGroup[21];
    int nCodigo;
    Animal *ptrProximo;
};

template <class T>

class Lista
{
    int size;

public:
    T *ptrPrimeiro; // Ponteiro para montar a lista
    T *ptrUlt;      // Ponteiro para montar a lista
    T stAnimal;     // para conter um animal

    Lista()
    {
        this->ptrPrimeiro = NULL;
        this->size = 0;
    }

    void add(T a)
    {
        if (this->ptrPrimeiro == NULL) // Será o primeiro
        {
            this->ptrPrimeiro = this->ptrUlt = new T;
        }
        else // Será o último
        {
            this->ptrUlt = this->ptrUlt->ptrProximo = new T;
        }
        this->ptrUlt->ptrProximo = NULL; // O último aponta para NULL
        // copiar o conteúdo de animal para ptrUltimo
        memcpy(this->ptrUlt, &a, sizeof(T));
        this->size++; // size
    }
    T get(int pos)
    {
        if (pos > size || pos < 0)
        {
            cout << "Out of range" << endl;
            Animal *ptrWork = new T;
            return *ptrWork;
        }
        Animal *ptrWork;
        int i;
        for (ptrWork = this->ptrPrimeiro, i = 0; i < pos; ptrWork = ptrWork->ptrProximo, i++)
        {
        }
        return *ptrWork;
    }
    int getSize() { return this->size; }
    bool isEmpty() { return this->size == 0; }
};


int main()
{
    Lista<Animal> stLIsta;
    int n = 0;
    do
    {
        Animal a;
        cout << "Entre com o nome de um animail" << endl;
        cin >> a.cNome;

        stLIsta.add(a);
        n++;
    } while (n < 4);
    cout << "Quantidade total " << stLIsta.getSize() << endl;
    cout << "Primeiro Animal: " << stLIsta.get(0).cNome << endl;
    cout << "Quarto Animal: " << stLIsta.get(3).cNome << endl;
    return 0;
}

