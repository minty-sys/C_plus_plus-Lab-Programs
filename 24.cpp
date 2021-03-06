//WAP to show sum of matrix using operator overloading as a member function as well as subtraction,
// multiplication of operator overloading using friend function.

#include <iostream>
using namespace std;
class matrix
{
    int A[2][2], sum[2][2], i, j;

public:
    void in()
    {
        cout << "Enter matrix element" << endl;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
                cin >> A[i][j];
        }
    }
    
    void out()
    {
        cout << "Matrix elements are" << endl;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
                cout << A[i][j] << " ";
            cout << endl;
        }
    }
    
    void operator+(matrix obj)
    {
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
                sum[i][j] = A[i][j] + obj.A[i][j];
        }

        for (int i = 0; i < 2; i++)
        {

            for (int j = 0; j < 2; j++)
            {

                // Print the sum of matrix
                cout << sum[i][j] << ' ';
            }
            cout << endl;
        }
    }
    friend void operator -(matrix,matrix);
    friend void operator *(matrix,matrix);
};
void operator-(matrix obj1, matrix obj2)
{
    int i, j, sub[2][2];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            sub[i][j] = obj1.A[i][j] - obj2.A[i][j];
        }
    }
    for (int i = 0; i < 2; i++)
    {

        for (int j = 0; j < 2; j++)
        {

            // Print the difference of matrix
            cout << sub[i][j] << ' ';
        }
        cout << endl;
    }
}
void operator*(matrix obj1, matrix obj2)
{
    int i, j, mul[2][2];
    cout << "MULTIPLICATION of matrix is :" << endl;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {

                mul[i][j] = mul[i][j] + (obj1.A[i][j] * obj2.A[i][j]);
            }
        }
        cout << "\n";
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << mul[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    matrix m1, m2;
    m1.in();
    m1.out();
    m2.in();
    m2.out();
    cout << "Sum of matrix is: " << endl;
    cout << endl;

    m1 + m2;
    cout << "Difference of matrix is: " << endl;
    cout << endl;

    m1 - m2;
    m1 *m2;

    return 0;
}

/*
OUTPUT:
Enter matrix elements 
1
2
3
4
Matrix elements are 
1 2 
3 4 
Enter matrix elements 
7
8
9
6
Matrix elements are
7 8
9 6
Sum of matrix is:
8 10
12 10
Difference of matrix is:
-6 -6
-6 -2
MULTIPLICATION of matrix is :
14 32
54 48
*/
