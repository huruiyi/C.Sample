#include "math.h"

//��̬��
__declspec(deprecated) int Mult(int a, int b)
{
    return a*b;
}
//��̬��
__declspec(dllexport) int Add(int a, int b)
{
    return a + b;
}