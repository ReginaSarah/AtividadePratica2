#include <iostream>
#include "time.h"
#include "Hash.h"
#include "lista.h"
#include "Divisao.h"
#include "Multiplicacao.h"
using namespace std;

void CriandoChavesAleatorios(int Vetor[], int n){
    srand(time(NULL));
    for(int i = 0; i< n; i++){
        Vetor[i] = rand() % 100;
    }
}

void imprime(int Vetor[], int n)
{
    cout << "Vetor" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << Vetor[i] << endl;
    }
    cout << endl;
}

int main(int arc, char* argv[])
{
	int tam = 2;
	Divisao *tabelaDiv;
	lista tabela[tam] = tabelaDiv->create(tam);

    No auxInsere;
    for(int i = 0; i < tam; i++)
    {
        int Chaves[tam], Data[tam];
        CriandoChavesAleatorios(Chaves, tam);
        CriandoChavesAleatorios(Data, tam);

        imprime(Chaves, tam);
        imprime(Data, tam);

        auxInsere = tabelaDiv->insere(Chaves[i], Data[i]);
        cout << tabelaDiv->numColisoes << endl;
    }

    tabela[tam].~lista();

}
