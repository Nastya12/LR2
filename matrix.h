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
    Matrix(); // по умолчанию
    Matrix(int n,int m); //с параметрами
    Matrix(const Matrix &martixToCopy); //конструктор копии
    ~Matrix();

    void clear();
    Matrix operator+ (const Matrix &right);
    Matrix operator+= (const Matrix &right);
    Matrix operator- (const Matrix &rigth);
    Matrix operator* (const Matrix &right);
    Matrix &operator= (const Matrix &right);
    int getN();
    int getM();
    void generation(int n, int m);
    void output(int n, int m);
    void input(int n, int m);
    Matrix multiplicationBy (int num);
protected:
private:
    int n_,m_;
    Data **matrix_;
};

#endif // MATRIX_H
