#include <iostream>
#include "time.h"
#include "include/Hash.h"
#include "include/lista.h"
#include "include/Divisao.h"
#include "include/Multiplicacao.h"
#include <vector>
using namespace std;

#define DIVISAO 0
#define MULTIPLICACAO 1
#define RAIZ 2

void CriandoChavesAleatorios(int Vetor[], int n)
{
    srand(time(NULL));
    cout << "VETOR DE DADOS" << endl;
    for(int i = 0; i< n; i++){
        Vetor[i] = rand() % 1000;
        cout << Vetor[i] << endl;
    }
}

int main(int arc, char* argv[])
{
  int n = 50;
  int m, m1 = 32, m2 = 43, m3 = 50, m4 = 100;
  int Data[n];

  CriandoChavesAleatorios(Data, n);

  for(int i = 0; i < 4; i++)
  {
    if(i == 0) m = m1;
    else if(i == 1) m = m2;
    else if(i == 2) m = m3;
    else if(i == 3) m = m4;
    cout << endl << "m = " << m << endl;
    Hash *tabelaDiv = new Hash(m);
    //tabelaDiv->create(m, n, DIVISAO, Data);
    //tabelaDiv->create(m, n, MULTIPLICACAO, Data);
    tabelaDiv->create(m, n, RAIZ, Data);
    tabelaDiv->destroy();
  }

}
