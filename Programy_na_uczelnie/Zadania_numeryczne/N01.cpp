#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <iomanip>

using namespace std;

vector<double> rozwiazanie(int N)
{
    vector<double> u(N, 1.0);
    return u;
}

vector<double> pelne_macierze(int N)
{
    double h = 2.0 / (N - 1);

    vector<vector<double>> A(N, vector<double>(N, 0.0));
    vector<double> b(N, 0.0);

    A[0][0] = 1.0; b[0] = 1.0;
    A[N-1][N-1] = 1.0; b[N-1] = 1.0;

    for(int i = 1; i < N-1; i++)
    {
        A[i][i-1] = 1.0 / (h*h);
        A[i][i]   = -2.0 / (h*h);
        A[i][i+1] = 1.0 / (h*h);
        b[i] = 0.0;
    }

    for(int i = 0; i < N; i++)
    {
        int maxRow = i;
        for(int k = i+1; k < N; k++)
            if(abs(A[k][i]) > abs(A[maxRow][i]))
            {
                maxRow = k;
            }
        swap(A[i], A[maxRow]);
        swap(b[i], b[maxRow]);

        for(int k = i+1; k < N; k++)
        {
            double factor = A[k][i] / A[i][i];
            for(int j = i; j < N; j++)
            {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    vector<double> x(N);
    for(int i = N-1; i >= 0; i--)
    {
        x[i] = b[i];
        for(int j = i+1; j < N; j++)
            x[i] -= A[i][j]*x[j];
        x[i] /= A[i][i];
    }

    return x;
}

vector<double> qr(int N)
{
    double h = 2.0/(N-1);
    vector<vector<double>> A(N, vector<double>(N,0));
    vector<double> b(N), x(N);

    A[0][0]=-2/(h*h);
    A[0][1]=1/(h*h);
    A[0][N-1]=1/(h*h);
    for(int i=1; i<N-1; i++)
    {
        A[i][i-1]=1/(h*h);
        A[i][i]=-2/(h*h);
        A[i][i+1]=1/(h*h);
    }
    A[N-1][0]=1/(h*h);
    A[N-1][N-2]=1/(h*h);
    A[N-1][N-1]=-2/(h*h);
    for(int i=0; i<N; i++) b[i]=cos((4.0*M_PI*i)/N);

    vector<vector<double>> Q=A,R(N,vector<double>(N,0));
    for(int j=0; j<N; j++)
    {
        double norm=0;
        for(int i=0; i<N; i++) norm+=Q[i][j]*Q[i][j];
        norm=sqrt(norm);
        R[j][j]=norm;
        for(int i=0; i<N; i++) Q[i][j]/=norm;
        for(int k=j+1; k<N; k++)
        {
            double dot=0;
            for(int i=0; i<N; i++) dot+=Q[i][j]*Q[i][k];
            R[j][k]=dot;
            for(int i=0; i<N; i++) Q[i][k]-=dot*Q[i][j];
        }
    }

    vector<double> Qtb(N,0);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) Qtb[i]+=Q[j][i]*b[j];

    // Back substitution
    for(int i=N-1; i>=0; i--)
    {
        double sum=Qtb[i];
        for(int j=i+1; j<N; j++) sum-=R[i][j]*x[j];
        x[i]=sum/R[i][i];
    }

    return x;
}

int main()
{
    int N = 500;
    cout << "Rozwiazywanie ukladu dla N = " << N << "\n\n";

    //Metoda 1
    auto t1 = chrono::high_resolution_clock::now();
    auto u1 = rozwiazanie(N);
    auto t2 = chrono::high_resolution_clock::now();

    //Metoda 2
    auto t3 = chrono::high_resolution_clock::now();
    auto u2 = pelne_macierze(N);
    auto t4 = chrono::high_resolution_clock::now();

    //Metoda 3
    auto t5 = chrono::high_resolution_clock::now();
    auto u3 = qr(N);
    auto t6 = chrono::high_resolution_clock::now();

    cout << "Czasy wykonania:\n";
    cout << " 1) Analitycznie:          "
         << chrono::duration<double, milli>(t2 - t1).count() << " ms\n";
    cout << " 2) Macierz pelna (LU):    "
         << chrono::duration<double, milli>(t4 - t3).count() << " ms\n";
    cout << " 3) QR:                    "
         << chrono::duration<double, milli>(t6 - t5).count() << " ms\n\n";

    cout << "Fragment rozwiazania (pierwsze 5 wartosci):\n";
    for(int i = 0; i < min(5, N); i++)
        cout << "u[" << i+1 << "] = " << u2[i] << endl;

    return 0;
}
