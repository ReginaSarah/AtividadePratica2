#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <utility>
#include <tuple>
#include <iomanip>
#include <stdlib.h>
#include "time.h"
#include "include/Hash.h"
//#include "include/lista.h"
//#include "include/Divisao.h"
//#include "include/Multiplicacao.h"
#include <vector>

using namespace std;

string Linear = "Sondagem Linear";
string Dupla = "Sondagem Dupla";

void Leitura(ifstream* entrada, int* n, int* m, int* tipoHash, vector<int>* Data)
{
    if(entrada->is_open())
    {
        string num;
        getline(*entrada, num, ' ');
        *m = std::stoi(num);
        getline(*entrada, num, ' ');
        *n = std::stoi(num);
        getline(*entrada, num);
        *tipoHash = std::stoi(num);
        while(!entrada->eof())
        {
            string n;
            getline(*entrada, n);
            //cout << n << endl;
            int a = stoi(n);
            Data->push_back(a);
        }
        entrada->close();
    }
    else
        cout << "Que pena, não consegui abrir o arquivo!" << endl;

}

int main(int arc, char* argv[])
{
  int n, m, tipoHash;
  int mm = 47;
  vector<int> Data;

  if (arc != 2) {
    cout << "ERRO: Necessario os parametros: ./<program_name> <input_file>" << endl;
    return 1;
  }

  string program_name(argv[0]);
  string input_file_name(argv[1]);

  ifstream entrada;
  entrada.open(argv[1], ios::in);

  Leitura(&entrada, &n, &m, &tipoHash, &Data);

  cout << endl << "m = " << m << endl;
  cout << endl << "n = " << n << endl;
  if(tipoHash == 0) cout << endl << Linear << endl;
  else if(tipoHash == 1) cout << endl << Dupla << endl;

  Hash *tabelaEnd = new Hash(m);
  tabelaEnd->create(m, mm, n, tipoHash, Data);
  tabelaEnd->destroy();

}
