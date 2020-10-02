#include "Hash.h"
#include "Divisao.h"


Divisao::hashFunction(int chave, int m)
{
    return chave % m;
}
