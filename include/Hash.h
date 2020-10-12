#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

//#include "No.h"
//#include "lista.h"
#include <vector>

using namespace std;

#define LINEAR 0
#define DUPLA 1
#define INFINITO -1
//#include "Multiplicacao.h"

class Hash
{
    public:
        Hash(int tamanho);
        ~Hash();
        int hashFunction(int m, int mm, int* i, int data, int tipoHash);
        int SondagemLinear(int chave, int m, int *i);
        int SondagemDupla(int chave, int m, int mm, int* i);
        int auxSondagemDupla(int chave, int m);

        int getTamanho();
        bool Cheia(int m);

        void create(int m, int mm, int n, int tipoHash, vector<int> Data);

        int insere(int chave, int data);
        int lookup(int indice, int data);
        void destroy();
        void imprime();
        int numColisoes = 0;

    private:
        int m;
        vector<int> tabela;
};

#endif // HASH_H
