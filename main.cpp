#include <iostream>
#include "time.h"
#include "include/Hash.h"
#include "include/lista.h"
#include "include/Divisao.h"
#include "include/Multiplicacao.h"
#include <vector>
using namespace std;

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
  
  Hash *tabelaDiv;
  
  tabelaDiv->create(tam);


}
