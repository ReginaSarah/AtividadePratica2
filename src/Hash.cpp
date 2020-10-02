#include <iostream>
#include "Hash.h"

#include "Hash.h"
#include <math.h>
#include "lista.h"


#define DIVISAO 0
#define MULTIPLICACAO 1
using namespace std;



Hash::Hash(int tamanho)
{
    //ctor
    this->m = tamanho;

}

Hash::~Hash()
{
    cout << "entre aqui caralho" << endl;
}

int Hash::getTamanho()
{
    this->m;
}

void Hash::create(int m)
{
    lista tabela[m];
}

No Hash::insere(int chave, int data)
{

    int indice = hashFunction(chave, m);
    if(tabela[indice].busca(data))
    {
        numColisoes++;
        return *tabela[indice].get(indice).getProx();
    }

    tabela[indice].set(indice, data);
    return *tabela[indice].get(indice).getProx();
}

No Hash::lookup(int chave, int data)
{
    int indice = hashFunction(chave, m);

    for (int i = 0; i < m; i++)
    {
        if (tabela[i].get(indice).getInfo() == data)
            return *tabela[i].get(indice).getProx();
    }
    return *tabela[indice].get(indice).getProx();
}

void Hash::destroy()
{
    /*for(int i = 0; i < m; i++)
    {
        tabela[i].~lista();
    }*/
}

