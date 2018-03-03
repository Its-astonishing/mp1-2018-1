#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class matrix
{
private:
    int** array;
    int size;
public:
    matrix(int n)
    {
        size = n;
        array = new int*[size];
        for (int i = 0; i < size; i++)
            array[i] = new int[size];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                array[i][j] = 0;
    }
    matrix(matrix& mtr)
    {
        size = mtr.size;
        array = new int*[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = new int[size];
        }
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                array[i][j] = mtr.array[i][j];
    }
    ~matrix()
    {
        for (int i = 0; i < size; i++)
            delete[] array[i];
        delete[] array;
    }
    void setSize(int n)
    {
        matrix a(size); 
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                a.array[i][j] = array[i][j];
        for (int i = 0; i < size; i++)
            delete[] array[i];
        delete[] array;
        size = n;
        array = new int*[size];
        for (int i = 0; i < size; i++)
            array[i] = new int[size];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (i >= a.size || j >= a.size)
                    array[i][j] = 0;
                else
                    array[i][j] = a.array[i][j];
    }
    void setElem(int i, int j, int elem)
    {
        array[i][j] = elem;
    }
    int getSize()
    {
        return size;
    }
    int getElem(int i, int j)
    {
        return array[i][j];
    }
    bool isDiagDominate()
    {
        int tmp = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j) continue;
                tmp += array[i][j];
            }
            if (abs(array[i][i]) < abs(tmp))
                return 0;
            tmp = 0;
        }
        return 1;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                cout << setw(3) << array[i][j] << " ";
            cout << endl;
        }

    }
    matrix& operator=(const matrix& mtr)
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                array[i][j] = mtr.array[i][j];
            return *this;
    }
    matrix& operator+=(const matrix& mtr)
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                array[i][j] += mtr.array[i][j];
        return *this;
    }
    matrix operator+(const matrix& mtr)
    {
        return *this += mtr;
      
    }
    matrix& operator-=(const matrix& mtr)
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                array[i][j] = array[i][j] - mtr.array[i][j];
        return *this;
    }
    matrix operator-(const matrix& mtr)
    {
        return *this -= mtr;
    }
    matrix operator*(int a)
    {
        matrix c(size);
        for (int i = 0; i < c.size; i++)
            for (int j = 0; j < c.size; j++)
                c.array[i][j] = array[i][j] * a;
        return c;
    }
    matrix& operator*=(const int a)
    {
        return *this *= a;
    }
};

int main()
{
    int size;
    cout << "Size of matrix (from 2 to 8):" << endl;
    cin >> size;
    if (size > 1 && size < 8)
    {
        matrix A(size); 
        matrix B(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                A.setElem(i, j, rand() % 10 + 1);
                B.setElem(i, j, rand() % 10 + 1);
            }
        };
        cout << "Matrix A:" << endl;
        A.print();
        cout << endl;
        cout << "Matrix B:" << endl;
        B.print();
        cout << endl;
        cout << "A+B:" << endl; (A + B).print(); cout << endl;
        cout << "A-B:" << endl; (A - B).print(); cout << endl;
        cout << "A*3:" << endl; (A * 3).print(); cout << endl;
        cout << "Size of matrix: " << A.getSize() << endl;
        cout << "Element number (2,2): " << A.getElem(1, 1) << endl;;
        if (A.isDiagDominate())
            cout << "Matrix A isn't diagonally dominant\n";
        else
            cout << "Matrix A is diagonally dominant\n";
        cout << "Set new A matrix size: ";
        cin >> size;
        if (size >= 1 && size < 8) 
        {
            A.setSize(size);
            A.print();
            system("pause");
        }
    }
    return 0;
}
