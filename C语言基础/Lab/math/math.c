#include "math.h"

//¶¯Ì¬¿â
__declspec(deprecated) int Mult(int a, int b)
{
    return a*b;
}
//¶¯Ì¬¿â
__declspec(dllexport) int Add(int a, int b)
{
    return a + b;
}