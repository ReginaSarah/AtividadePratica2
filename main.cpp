#include <iostream>
#include "time.h"
#include "Hash.h"
#include "Divisao.h"
#include "Multiplicacao.h"
using namespace std;

void CriandoChavesAleatorios(int Vetor[], int n){
    srand(time(NULL));
    for(int i = 0; i< n; i++){
        Vetor[i] = rand() % 100;
    }
}

int main(int arc, char* argv[])
{
	int tam = 5;
	Divisao *tabelaDiv;
	tabelaDiv->create(tam);

}
