#include <iostream>
#include <cstdlib>
#include "../include/lista.h"


using namespace std;

lista::lista()
{
    cout << "Criando objeto listaaEncad" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

lista::~lista()
{
    cout << "Destruindo objeto ListaEncad" << endl;
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

No lista::getPrimeiro()
{
  return *primeiro;
}

No lista::getUltimo()
{
  return *ultimo;
}

void lista::setPrimeiro(No* p)
{
  primeiro = p;
}

void lista::setUltimo(No* p)
{
  ultimo = p;
}


bool lista::busca(int val)
{
    No *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

/*No lista::getAnterior(int data)
{
  No *p = primeiro;
  No *aux;
  int i = 0;
  while(i < k)
  {
      i++;
      aux = p->getProx();
      p = p->getProx();
  }
  if(p == NULL)
  {
      cout << "O ERRO: Indice invalido!" << endl;
  }
  else
      return *aux;
}*/

int lista:: getSize()
{
  return this->n;
}

No lista::get(int k)
{
    No *p = primeiro;
    No *aux;
    int i = 0;
    while(i < k && p->getProx() != NULL)
    {
        i++;
        p = p->getProx();
    }
    if(p == NULL)
    {
        cout << "O ERRO: Indice invalido!" << endl;
    }
    else
        return *p;
}

void lista::set(int val)
{
    No *p = primeiro;
    int i = 0;
    while(i < this->getSize() && p != NULL)
    {
        i++;
        this->setUltimo(p);
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
    {
      p->setInfo(val);
    }
        
}


void lista::insereInicio(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(primeiro);

    primeiro = p;

    n++;
    if(n == 1) ultimo = p;
}

void lista::insereFinal(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);

    if(ultimo != NULL) 
    {
      ultimo->setProx(p);
      cout << "Inseriu certo" << endl;
    }
    ultimo = p;

    n++;
    if(n == 1) primeiro = p;
}

void lista::removeInicio()
{
    No* p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;

        n--;
        if(n == 0) ultimo = NULL;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

void lista::removeFinal()
{
    No* p;
    if(ultimo != NULL)
    {
        if(primeiro == ultimo)
        {
            primeiro = NULL;
            p = NULL;
        }
        else
        {
            p = primeiro;
            while(p->getProx() != ultimo)
                p = p->getProx();
            p->setProx(NULL);
        }
        delete ultimo;
        ultimo = p;
        n--;
    }
    else
        cout << "ERRO: listaa vazia!" << endl;
}
