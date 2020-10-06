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
        int hashFunctionDivisao(int chave, int m);
        int hashFunctionMultiplicacao(int chave, int m);
        int hashFunctionOctal(int chave, int m);
        int hashFunction(int m, int data, int tipoHash);
        int getTamanho();

        void CriandoChavesAleatorios(int Vetor[], int n);

        void create(int m, int tipoHash);
        void Colisoes();
        No insere(int chave, int data);
        No lookup(int indice, int data);
        void destroy();
        void imprime();
        int numColisoes = 0;

    private:
        int m;
        vector<lista*> tabela;
};

#endif // HASH_H
