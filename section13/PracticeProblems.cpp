//
// Created by Dmitry Petukhov on 26/01/2020.
//

#include <iostream>
#include <complex>

using namespace std;

int Index(int r, int c, int numberOfColumns);

typedef int (*ArithmeticFcn)(int, int);

int Add(int x, int y);
int Sub(int x, int y);
int Mul(int x, int y);
int Div(int x, int y);
int Mod(int x, int y);
int Pow(int x, int y);

ArithmeticFcn GetArithmeticFcn(char op);

int main()
{
    /*
     * Problem 1:
     *
     * How would you write a 2D array
     * using only a 1D array.
     * What extra functions might
     * you need to accomplish this?
     */
//
//    const int MAX = 3;
//
//    int array[MAX*MAX];
//
//    for (int r = 0; r < MAX; r++)
//    {
//        for (int c = 0; c < MAX; c++)
//        {
//            array[Index(r,c, MAX)] = Index(r, c, MAX);
//            cout << "r = " << r << ", c = " << c << endl;
//            cout << "array[" << Index(r,c,MAX) << "] = " << array[Index(r, c, MAX)] << endl;
//        }
//    }

    /*
     * Problem 2:
     *
     * Write a mini calculator program
     * that takes in a character ('+','-','*','/')
     * and 2 integers and outputs the result.
     * Use function pointers for this.
     *
     */

    int x1 = 0;
    int x2 = 0;

    char op;

    cout << "Please input the two operands with a space between: ";
    cin >> x1 >> x2;

    cout << "Please enter the operation ('+','-','*','/','%','^'): ";
    cin >> op;

    ArithmeticFcn opFcn = GetArithmeticFcn(op);

    cout << x1 << " " << op << " " << x2 << " = " << opFcn(x1,x2) << endl;

    return 0;
}

int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}

int Mod(int x, int y)
{
    return x % y;
}
int Pow(int x, int y)
{
    return pow(x,y);
}

ArithmeticFcn GetArithmeticFcn(char op)
{
    switch (op)
    {
        case '+': return Add;
        case '-': return Sub;
        case '*': return Mul;
        case '/': return Div;
        case '%': return Mod;
        case '^': return Pow;
        default: return Add;
    }
}



int Index(int r, int c, int numberOfColumns)
{
    return c + numberOfColumns * r;
}