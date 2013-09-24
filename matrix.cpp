#include "matrix.h"
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <iostream>

using namespace std;

Matrix::Matrix():
    n_(0),
    m_(0),
    matrix_(0)
{
}

Matrix::Matrix(int n, int m):
    n_(n),
    m_(m),
    matrix_(0)
{
    matrix_=new Data *[n_];
    for (int i=0; i<n_; i++)
    {
        matrix_[i]=0;
        matrix_[i]=new Data[m_];
    }
}

Matrix::Matrix(const Matrix &matrixToCopy)
{
    matrix_=new Data *[getN()];
    for (int i=0; i<getN(); i++)
    {
        matrix_[i]=0;
        matrix_[i]=new Data [getM()];
        for (int i=0; i<matrixToCopy.n_; i++)
        {
            for (int j=0; j<matrixToCopy.m_; j++)
                matrix_[i][j]=matrixToCopy.matrix_[i][j];
        }
    }
}

Matrix::~Matrix()
{
    clear();
}

void Matrix::clear()
{
    for(int i=0; i<n_; i++)
        delete matrix_[i];
    delete [] matrix_;
      matrix_=0;
}

ostream &operator<< (ostream &output, const Matrix &obj)
{
    for (int i=0; i<obj.n_; i++)
    {
        for (int j=0; j=obj.m_; j++)
            output<<obj.matrix_[i][j]<<" ";
        output<<endl;
    }
    output<<endl;
    return output;
}

istream &operator>> (istream &input, Matrix &obj)
{
    for (int i=0; i<obj.n_; i++)
        for (int j=0; j<obj.m_; j++)
            input>>obj.matrix_[i][j];
    return input;
}

Matrix Matrix::operator+ (const Matrix &right)
{
    if (n_!=right.n_ ||m_!=right.m_)
    {
        cout<<"different size.\n";
        exit(1);
    }
    Matrix result(n_,m_);
    for (int i=0; i<n_; i++)
        for (int j=0; i<m_; j++)
            result.matrix_[i][j]= matrix_[i][j]+right.matrix_[i][j];
    return result;
}

Matrix Matrix:: operator+= (const Matrix&right)
{
    if (n_ != right.n_ || m_ != right.m_)
    {
        cout<<" different size.\n ";
        exit(1);
    }
    for (int i = 0; i < n_; i++)
        for (int j = 0; j < m_; j++)
            matrix_[i][j] = matrix_[i][j] + right.matrix_[i][j];
    return *this;
}

Matrix Matrix::operator- (const Matrix &right)
{
    if (n_!=right.n_ ||m_!=right.m_)
    {
        cout<<"different size.\n";
        exit(1);
    }
    Matrix result(n_,m_);
    for (int i=0; i<n_; i++)
        for (int j=0; i<m_; j++)
            result.matrix_[i][j]= matrix_[i][j]-right.matrix_[i][j];
    return result;
}

Matrix Matrix::operator* (const Matrix &right)
{
    if (n_!=right.m_ ||m_!=right.n_)
    {
        cout<<"multiplication is not possible.\n";
        exit(1);
    }
    Matrix result(n_,m_);
    for (int k=0; k<n_; k++)
        for (int i=0; i<n_; i++)
            for (int j=0; j<m_; j++)
            {
                result.matrix_[i][j]=0;
                result.matrix_[i][j]+=matrix_[i][k]*right.matrix_[k][j];
            }
    return result;
}
Matrix &Matrix::operator= (const Matrix&right)
{
    if(&right != this)
    {
        clear();
        matrix_=new Data *[n_];
        for (int i=0; i<n_; ++i)
        {
            matrix_[i]=0;
            matrix_[i]=new Data[m_];
        }
        for (int i=0; i<n_ ; ++i )
            for (int j=0; i<m_ ; j++ )
                matrix_[i][j]=right.matrix_[i][j];
    }
    return *this;
}

void Matrix::generation(int n, int m)
{

    cout<<"matrix: \n";
    for (int i=0; i<getN(); i++)
    {
        for (int j=0; j<getM(); j++)
        {
            matrix_[i][j]=rand()%5;
        }
    }

}

void Matrix::output(int n, int m)
{
    for (int i=0; i<getN(); i++)
    {
        for (int j=0; j<getM(); j++)
        {
            cout<<matrix_[i][j]<<" ";
        }
        cout<<endl;
    }

}

void Matrix::input(int n, int m)
{
    for(int i=0; i<getN(); i++)
    {
        cout<<"line = "<<i+1<<endl;
        for (int j=0; j<getM(); j++)
        {
            cout<<matrix_[i][j];
        }
        cout<<endl;
    }
    cout<<"matrix: \n";

}

int Matrix::getN()
{
    return n_;
}

int Matrix::getM()
{
    return m_;
}


Matrix Matrix::multiplicationBy (int num)
{

    Matrix result(n_,m_);
    for (int i = 0; i < n_; i++)
        for (int j = 0; j < m_; j++)
            result.matrix_[i][j] =matrix_[i][j]*num;
    return result;
}
