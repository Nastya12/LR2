#include <iostream>
#include <stdlib.h>
#include "matrix.h"

using namespace std;

int main()
{
    srand(time(NULL));
    int k,a,num;
    Matrix A,B;
    int n1, m1, n2, m2, i1, i2, i3,i4, i5, i6, i7, i8;
    cout<<" !  Matrix  !\n\n\a";
    cout<<"Input a number of matrix: n= ";
    cin>>k;
    Matrix *array;
    for (int i=0; i<k; i++)
        array=new Matrix [k];
    cout<<"# Matrix "<<endl;
    cout<<"\n Menu: \n";
    cout<<" 1 -> Enter "<<k<<" matrixs. \n";
    cout<<" 2 -> To generate "<<k<<" matrixs. \n";
    cout<<" 3 -> addition two matrixs. \n";
    cout<<" 4 -> subtraction two matrixs. \n";
    cout<<" 5 -> multuplication two matrix. \n";
    cout<<" 6 -> multuplication by const. \n";
    cout<<" 7 -> construct a square matrix. \n";
    cout<<" 0 -> exit. \n\n";
    cout<<"action=";
    cin>>a;
    if (a>=0)
        switch (a)
        {
        case 1:
        {
            for(int i=0; i<k; i++)
            {
                cout<<"enter size nxm\n";
                cout<<"n= ";
                cin>>n1;
                cout<<"m= ";
                cin>>m1;
                array[i].input(n1,m1);
                array[i].output(n1,m1);
            }
        }
        break;
        case 2:
        {
            for(int i=0; i<k; i++)
            {
                cout<<"enter size nxm\n";
                cout<<"n= ";
                cin>>n2;
                cout<<"m= ";
                cin>>m2;
                array[i].generation(n2,m2);
                array[i].output(n2,m2);
            }
        }
        break;
        case 3:
        {
            cout<<"\nWhat matrix is add?";
            cout<<"\nEnter numbers";
            cin>>i1;
            cout<<"and";
            cin>>i2;
            cout<<"\n Matrix #"<<i1<<" and "<<i2<<endl;
            cout<<"\nresult addition:\n";
            cout<<array[i1-1]+array[i2-1];


        }
        break;
        case 4:
        {
            cout<<"\nEnter numbers matrix ";
            cin>>i3;
            cout<<" and ";
            cin>>i4;
            cout<<" \nMatrix #"<<i3<<" and "<<i4<<endl;
            cout<<"\nresult subtraction:\n";
            cout<<array[i3-1]-array[i4-1];
        }
        break;
        case 5:
        {
            cout<<"What matrix is myltiply?";
            cout<<"\nEnter numbers matrix";
            cin>>i5;
            cout<<"and";
            cin>>i6;
            cout<<"\n Matrix #"<<i5<<" and "<<i6<<endl;
            cout<<"\nresult multiplication:\n";
            cout<<array[i5-1]*array[i6-1];
        }
        break;
        case 6:
        {
            cout<<"\nEnter number matrix";
            cin>>i7;
            cout<<"\n Matrix #"<<i7<<endl;
            cout<<"\n input any number: ";
            cin>>num;
            cout<<array[i7-1].multiplicationBy(array[i7-1],num);
        }break;
        case 7:
        {
            cout<<"\nEnter number matrix";
            cin>>i8;
            cout<<"\n Matrix #"<<i8<<endl;
            cout<<"result:\n";
            cout<<array[i8-1]*array[i8-1];
        }
        case 0:
            break;
        default:
            cout<<"error: incorrect action\n";
        }

    while (a);
    delete [] array;
    return 0;
}
