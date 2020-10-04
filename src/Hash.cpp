#include <iostream>
#include <time.h>
#include "../include/Hash.h"
#include <math.h>
#include "../include/lista.h"


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

}

int Hash::getTamanho()
{
   return this->m;
}

void Hash::CriandoChavesAleatorios(int Vetor[], int n)
{
    srand(time(NULL));
    for(int i = 0; i< n; i++){
        Vetor[i] = rand() % 100;
    }
}


int Hash::hashFunction(int chave, int m)
{
    return chave % m;
}


void Hash::create(int m)
{
    No *auxInsere;
    auxInsere = new No();
    int Chaves[m], Data[m];

    for(int i = 0; i < m; i++)
    {
      cout << "oi" << endl;
      lista *l = new lista();
      tabela.push_back(l);
    }/*
    for(int i = 0; i < m; i ++)
    {
      CriandoChavesAleatorios(Data, m);
      int chave = this->hashFunction(Data[i], m);
      *auxInsere = this->insere(chave, Data[i]);
      cout << DIVISAO << endl;
    }*/

}

No Hash::insere(int chave, int data)
{
    if(tabela[chave]->busca(data))
    {
        numColisoes++;
        return *tabela[chave]->get(chave).getProx();
    }
    tabela[chave]->set(chave, data);
    return *tabela[chave]->get(chave).getProx();
}

No Hash::lookup(int indice, int data)
{
    for (int i = 0; i < m; i++)
    {
        if (tabela[i]->get(indice).getInfo() == data)
            return *tabela[i]->get(indice).getProx();
    }
    return *tabela[indice]->get(indice).getProx();
}

void Hash::destroy()
{
    /*for(int i = 0; i < m; i++)
    {
        tabela[i].~lista();
    }*/
}

