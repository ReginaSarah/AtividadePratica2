#include <iostream>
#include <time.h>
#include "../include/Hash.h"
#include <math.h>
#include "../include/lista.h"

using namespace std;

#define DIVISAO 0
#define MULTIPLICACAO 1
#define RAIZ 2

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


int Hash::hashFunctionDivisao(int chave, int m)
{
    return chave % m;
}

int Hash::hashFunctionMultiplicacao(int chave, int m)
{
    float A, aux, num;
    int inteiro, key;

    A = (sqrt(5)-1) / 2;

    modf(chave*A, &num);
    num = (chave*A) - num;
    aux = m*num;
    modf(aux, &num);
    
    return num;
}

int Hash::hashFunctionOctal(int chave, int m) {
    int i = 1;
    int a;
    int octal = 0; 

    if(chave <= 7) {
        octal = chave;
    }
    else{
        while(chave >= 8) {
            a = chave % 8;
            chave = chave / 8;
            octal = octal + a * i; //calculo do octal
            i *= 10; 
        }
        chave = chave % 8;
        octal = octal + chave * i; //mesmo calculo aqui
    }

    return octal % m;
}

int Hash::hashFunction(int m, int data, int tipoHash)
{
  switch (tipoHash)
  {
    case DIVISAO:
      return hashFunctionDivisao(data, m);
      break;
    case MULTIPLICACAO:
      return hashFunctionMultiplicacao(data, m);
      break;
    case RAIZ:
      return hashFunctionOctal(data, m);
      break;
  }
}

void Hash::create(int m, int tipoHash)
{
    No *auxInsere;
    auxInsere = new No();
    int Chaves[m], Data[m];

    for(int i = 0; i < m; i++)
    {
      lista *l = new lista();
      tabela.push_back(l);
    }
    CriandoChavesAleatorios(Data, m);
    for(int i = 0; i < m; i ++)
    {
      cout << "Data: " << Data[i] << endl;
      int chave = this->hashFunction(m, Data[i], tipoHash);
      cout << "Chave: " << chave << endl;
      *auxInsere = this->insere(chave, Data[i]);
    }
    Colisoes();
    this->imprime();
}



No Hash::insere(int chave, int data)
{
    if(tabela[chave]->busca(data))
    {
        //numColisoes++;
        return tabela[chave]->get(chave);
    }
    
    tabela[chave]->insereFinal(data);
    //No *p = new No();
    //p = tabela[chave]->getUltimo().getProx();
    //tabela[chave]->setUltimo(p);
    return tabela[chave]->get(chave);
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
    for(int i = 0; i < m; i++)
    {
        tabela[i]->~lista();
    }
}

void Hash::Colisoes()
{
  for(int i = 0; i < this->m; i++)
  {
    int n = tabela[i]->getSize();
    if(n >= 2)
    {
      numColisoes = numColisoes + n - 1;
    }
  }  
}

void Hash::imprime()
{
  for(int i = 0; i < m; i++)
  {
    for(int j = tabela[i]->getSize() - 1; j >= 0; j--)
    {
      cout << tabela[i]->get(j).getInfo() << " - ";
    }
    cout << endl;
  } 
  cout << "Colisões: " <<numColisoes << endl;
}
