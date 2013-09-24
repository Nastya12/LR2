#include <iostream>
#include <stdlib.h>
#include "matrix.h"

using namespace std;

int main()
{
    srand(time(NULL));
    int k,a,num;
    int n1, m1, i1, i2;
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
    cout<<" 3 -> addition two matrices. \n";
    cout<<" 4 -> subtraction two matrices. \n";
    cout<<" 5 -> multuplication two matrix. \n";
    cout<<" 6 -> multuplication by const. \n";
    cout<<" 7 -> calculate a square matrix. \n";
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
                cin>>n1;
                cout<<"m= ";
                cin>>m1;
                array[i].generation(n1,m1);
                array[i].output(n1,m1);
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
            cin>>i1;
            cout<<" and ";
            cin>>i2;
            cout<<" \nMatrix #"<<i1<<" and "<<i2<<endl;
            cout<<"\nresult subtraction:\n";
            cout<<array[i1-1]-array[i2-1];
        }
        break;
        case 5:
        {
            cout<<"What matrix is myltiply?";
            cout<<"\nEnter numbers matrix";
            cin>>i1;
            cout<<"and";
            cin>>i2;
            cout<<"\n Matrix #"<<i1<<" and "<<i2<<endl;
            cout<<"\nresult multiplication:\n";
            cout<<array[i1-1]*array[i2-1];
        }
        break;
        case 6:
        {
            cout<<"\nEnter number matrix";
            cin>>i1;
            cout<<"\n Matrix #"<<i1<<endl;
            cout<<"\n input any number: ";
            cin>>num;
            cout<<array[i1-1].multiplicationBy(num);
        }break;
        case 7:
        {
            cout<<"\nEnter number matrix";
            cin>>i1;
            cout<<"\n Matrix #"<<i1<<endl;
            cout<<"result:\n";
            cout<<array[i1-1]*array[i1-1];
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
