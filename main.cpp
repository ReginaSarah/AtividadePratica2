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

void CriandoChavesAleatorios(int Vetor[], int n)
{
    srand(time(NULL));
    cout << "VETOR DE DADOS" << endl;
    for(int i = 0; i< n; i++)
    {
        Vetor[i] = rand() % 1000;
        cout << Vetor[i] << endl;
    }
}

void Imprime(vector<int> Data, int n)
{
  for(int i = 0; i < n; i++)
    {
      cout << Data[i] << endl;
    }
}

void Leitura(int* n, int* m, int* tipoHash, vector<int>* Data, int argv)
{
    ifstream entrada;
    //entrada.open(argv, ios::in);

    if(entrada.is_open())
    {
        string num;
        getline(entrada, num, ' ');
        *m = std::stoi(num);
        getline(entrada, num, ' ');
        *n = std::stoi(num);
        getline(entrada, num);
        *tipoHash = std::stoi(num);
        while(!entrada.eof())
        {
            string n;
            getline(entrada, n);
            //cout << n << endl;
            int a = stoi(n);
            Data->push_back(a);
        }
        entrada.close();
    }
    else
        cout << "Que pena, não consegui abrir o arquivo!" << endl;

}

int main(int arc, char* argv[])
{
  int n, m, tipoHash;
  vector<int> Data;

  if (arc != 2) {
    cout << "ERRO: Necessario os parametros: ./<program_name> <input_file>" << endl;
    return 1;
  }

  string program_name(argv[0]);
  string input_file_name(argv[1]);

  ifstream entrada;
  entrada.open(argv[1], ios::in);

    if(entrada.is_open())
    {
        string num;
        getline(entrada, num, ' ');
        m = std::stoi(num);
        getline(entrada, num, ' ');
        n = std::stoi(num);
        getline(entrada, num);
        tipoHash = std::stoi(num);
        while(!entrada.eof())
        {
            string n;
            getline(entrada, n);
            int a = stoi(n);
            Data.push_back(a);
        }
        entrada.close();
    }
    else
        cout << "Que pena, não consegui abrir o arquivo!" << endl;

    //Leitura(&n, &m, &tipoHash, &Data, argv[1]);

     int mm = m - 1;
    cout << endl << "m = " << m << endl;
    cout << endl << "n = " << n << endl;
    cout << endl << "Hash = " << tipoHash << endl;

    Hash *tabelaEncad = new Hash(m);
    tabelaEncad->create(m, mm, n, tipoHash, Data);
    tabelaEncad->destroy();

}
