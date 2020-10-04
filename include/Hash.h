#ifndef HASH_H
#define HASH_H

#include "No.h"
#include "lista.h"

//#include "Multiplicacao.h"

class Hash
{
    public:
        Hash(int tamanho);
        virtual ~Hash();
        virtual int hashFunction(int chave, int m) = 0;
        int getTamanho();

        lista create(int m);

        No insere(int chave, int data);
        No lookup(int chave, int data);
        void destroy();

        int numColisoes = 0;

    private:
        int m;
        lista *tabela[];
};

#endif // HASH_H
