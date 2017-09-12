#include "StackVector.h"

StackVector::StackVector(int x, int y)
{
    a=x;
    b=y;
}

StackVector::~StackVector()
{
    //dtor
}

int StackVector::getx(){
    return a;
}

int StackVector::gety(){
    return b;
}
