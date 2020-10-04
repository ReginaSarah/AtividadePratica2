#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include "No.h"
#include "lista.h"
#include <vector>

using namespace std;

//#include "Multiplicacao.h"

class Hash
{
    public:
        Hash(int tamanho);
        ~Hash();
        int hashFunction(int chave, int m);
        int getTamanho();

        void CriandoChavesAleatorios(int Vetor[], int n);

        void create(int m);
        
        No insere(int chave, int data);
        No lookup(int indice, int data);
        void destroy();

        int numColisoes = 0;

    private:
        int m;
        vector<lista*> tabela;
};

#endif // HASH_H
