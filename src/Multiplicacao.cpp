#include "../include/Hash.h"
#include "../include/Multiplicacao.h"
#include <math.h>


int Multiplicacao::hashFunction(int chave, int m)
{
    float A, aux, num;
    int inteiro, key;

    A = (sqrt(5)-1) / 2;

    modf(chave*A, &num);
    num = (chave*A) - num;
    aux = m*num;
    modf(aux, &num);
    
    return num;
}
