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

        void create(int m);

        No insere(int chave, int data);
        No lookup(int chave, int data);
        void destroy();

    private:
        lista tabela[];
        int m;
};

#endif // HASH_H
