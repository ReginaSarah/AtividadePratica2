#ifndef LISTA_H
#define LISTA_H

#include "No.h"

class lista
{
    public:
        lista();
        virtual ~lista();
        bool busca(int val);        /// retorna true caso val esteja na lista e false caso contrario
        No get(int k);             /// retorna o valor do k-�simo elemento
        void set(int k, int val);   /// altera o valor do k-�simo elemento
        void insereInicio(int val); /// insere um novo No contendo val no in�cio da lista
        void insereFinal(int val);  /// insere um novo No contendo val no final da lista
        void removeInicio();        /// remove o primeiro No da lista
        void removeFinal();         /// remove o �ltimo No da lista

    private:
        No *primeiro;  /// ponteiro para o primeiro No da lista
        No *ultimo;    /// ponteiro para o ultimo No da lista
        int n;         /// numero de nos na lista

    protected:

};

#endif // LISTA_H
