#ifndef STACKVECTOR_H
#define STACKVECTOR_H


class StackVector
{
    public:
        StackVector(int x=0, int y=0);
        int getx();
        int gety();
        virtual ~StackVector();

    private:
        int a,b;
};

#endif // STACKVECTOR_H
