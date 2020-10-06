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

int main(int arc, char* argv[])
{
	int tam = 2;

  Hash *tabelaDiv = new Hash(tam);
  
  tabelaDiv->create(tam, DIVISAO);

  tabelaDiv->destroy();

}
