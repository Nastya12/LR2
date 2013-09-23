#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>
#include <istream>

typedef int Data;

class Matrix
{
    friend std::ostream &operator<< (std::ostream &output, const Matrix &obj);
    friend std::istream &operator>> (std::istream &input, Matrix &obj);

public:
    Matrix(); // �� ���������
    Matrix(int n,int m); //� �����������
    Matrix(const Matrix &martixToCopy); //����������� �����
    ~Matrix();

    void clear();
    Matrix operator+ (const Matrix &right);
    Matrix operator+= (const Matrix &right);
    Matrix operator- (const Matrix &rigth);
    Matrix operator* (const Matrix &right);
    const Matrix &operator= (const Matrix &right);
    int getN();
    int getM();
    void setN(int n);
    void setM(int n);
    void generation(int &n, int &m);
    void output(int &n, int &m);
    void input(int n, int m);
    Matrix multiplicationBy (Matrix &A, int &num);
protected:
private:
    int n_,m_;
    Data **matrix_;
};
Matrix addition (Matrix &A, Matrix &B);
Matrix subtraction (Matrix &A, Matrix &B);
Matrix multiplication (Matrix &A, Matrix &B);


#endif // MATRIX_H
