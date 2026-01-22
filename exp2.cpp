#include<iostream>
using namespace std;

int main() {
    int r1 , r2, c1, c2;

        cout<<"Enter number of rows in matrix 1 : ";
        cin>>r1;

        cout<<"Enter number of columns in matrix 1 : ";
        cin>>c1;

        int A[r1][c1];

        cout<<"Enter elements in matrix 1 : ";
        for(int i = 0; i < r1; i++) {
            for(int j = 0; j < c1; j++) {
                cin>>A[i][j];
            }
        }
        
        
        cout<<"Enter number of rows in matrix 2 : ";
        cin>>r2;
        
        cout<<"Enter number of columns in matrix 2 : ";
        cin>>c2;
        
        int B[r2][c2];

        cout<<"Enter elements in matrix 2 : ";
        for(int i = 0; i < r2; i++) {
            for(int j = 0; j < c2; j++) {
                cin>>B[i][j];
            }
        }

    cout<<"---Choices---\n";
    cout<<"1.Display the matrix\n";
    cout<<"2.Transpose of matrix 1\n";
    cout<<"3.Transpose of matrix 2\n";
    cout<<"4.Addition\n";
    cout<<"5.Subtrction\n";
    cout<<"6.Multiplication\n";
    cout<<"7.Division\n";

    int ch;
    cout<<"Enter choice : ";
    cin>>ch;

    switch(ch) {

        case 1: 

        cout<<"Elements in matrix 1 : "<<endl;
        for(int i = 0; i < r1; i++) {
            for(int j = 0; j < c1; j++) {
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"Elements in matrix 2 : "<<endl;
        for(int i = 0; i < r2; i++) {
            for(int j = 0; j < c2; j++) {
                cout<<B[i][j]<<" ";
            }
            cout<<endl;
        }
        break;

        case 2:

        cout<<"Transpose of matrix 1 : "<<endl;
        for(int i = 0; i < c1; i++) {
            for(int j = 0; j < r1; j++) {
                cout<<A[j][i]<<" ";
            }
            cout<<endl;
        }
        break;

        case 3:

        cout<<"Transpose of matrix 2 : "<<endl;
        for(int i = 0; i < c2; i++) {
            for(int j = 0; j < r2; j++) {
                cout<<B[j][i]<<" ";
            }
            cout<<endl;
        }
        break;

        case 4:

        cout<<"Addition : "<<endl;
        if(r1==r2 && c1==c2) {
            int C[r1][r2];
            for(int i = 0; i < r1; i++) {
                for(int j = 0; j < c1; j++) {
                    C[i][j] = A[i][j] + B[i][j];
                }
            }

            cout<<"Addition of two matrices : "<<endl;
            for(int i = 0; i < r1; i++) {
                for(int j = 0; j <c1; j++) {
                    cout<<C[i][j]<<" ";
                }
                cout<<endl;
            }
        } else {
            cout<<"Matrices must have same size.";
        }
        break;

        case 5:

        cout<<"Subtraction : "<<endl;
        if(r1==r2 && c1==c2) {
            int C[r1][r2];
            for(int i = 0; i < r1; i++) {
                for(int j = 0; j < c1; j++) {
                    C[i][j] = A[i][j] - B[i][j];
                }
            }

            cout<<"Subtraction of two matrices : "<<endl;
            for(int i = 0; i < r1; i++) {
                for(int j = 0; j <c1; j++) {
                    cout<<C[i][j]<<" ";
                }
                cout<<endl;
            }
        } else {
            cout<<"Matrices must have same size.";
        }
        break;

        case 6: // Multiplication
            if(c1==r2) {
                int C[r1][c2];
                for(int i=0;i<r1;i++){
                    for(int j=0;j<c2;j++){
                        C[i][j]=0;
                        for(int k=0;k<c1;k++)
                            C[i][j]+=A[i][k]*B[k][j];
                    }
                }
                cout<<"Multiplication result stored in matrix C :"<<endl;
                for(int i=0;i<r1;i++){
                    for(int j=0;j<c2;j++)
                        cout<<C[i][j]<<" ";
                    cout<<endl;
                }
            } else {
                cout<<"Matrix multiplication not possible! Columns of matrix 1 must equal rows of matrix 2.";
            }
            break;

        case 7: // Division (element-wise)
            if(r1==r2 && c1==c2) {
                int C[r1][c1];
                for(int i=0;i<r1;i++){
                    for(int j=0;j<c1;j++){
                        if(B[i][j]==0){
                            cout<<"INF "; // cannot divide by zero
                            C[i][j] = 0; // store 0 in C to avoid garbage
                        } else {
                            C[i][j] = A[i][j]/B[i][j];
                        }
                    }
                }
                cout<<"Division result stored in matrix C :"<<endl;
                for(int i=0;i<r1;i++){
                    for(int j=0;j<c1;j++)
                        cout<<C[i][j]<<" ";
                    cout<<endl;
                }
            } else {
                cout<<"Matrices must be of same size for division!";
            }
            break;

        default:
            cout<<"Invalid choice!";
    }
    return 0;
}