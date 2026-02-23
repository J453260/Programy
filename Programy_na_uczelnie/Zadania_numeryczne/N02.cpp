#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <chrono>
using namespace std;

vector<double> pelna_macierz(int N)
{
    double h = 2.0/(N-1);
    vector<vector<double>> A(N, vector<double>(N,0)), Q, R;
    vector<double> b(N);

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

    for(int i=0; i<N; i++) b[i]=cos(4.0*M_PI*i/N);

    Q = A;
    R.assign(N, vector<double>(N,0));
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

    vector<double> Qtb(N,0), x(N,0);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) Qtb[i]+=Q[j][i]*b[j];

    for(int i=N-1; i>=0; i--)
    {
        double sum=Qtb[i];
        for(int j=i+1; j<N; j++) sum-=R[i][j]*x[j];
        x[i]=sum/R[i][i];
    }
    return x;
}

vector<double> sherman(int N)
{
    double h = 2.0/(N-1), a=1/(h*h), b=-2/(h*h);
    vector<double> lower(N-1,a), diag(N,b), upper(N-1,a), rhs(N);
    for(int i=0; i<N; i++) rhs[i]=cos(4.0*M_PI*i/N);

    auto tridiag_solve = [&](vector<double> l, vector<double> d, vector<double> u, vector<double> r)
    {
        int n=r.size();
        vector<double> cp(n-1), dp(n), x(n);
        cp[0]=u[0]/d[0];
        dp[0]=r[0]/d[0];
        for(int i=1; i<n; i++)
        {
            double den=d[i]-l[i-1]*cp[i-1];
            if(i<n-1) cp[i]=u[i]/den;
            dp[i]=(r[i]-l[i-1]*dp[i-1])/den;
        }
        x[n-1]=dp[n-1];
        for(int i=n-2; i>=0; i--) x[i]=dp[i]-cp[i]*x[i+1];
        return x;
    };

    vector<double> e(N,0);
    e[0]=1;
    e[N-1]=1;
    vector<double> x = tridiag_solve(lower, diag, upper, rhs);
    vector<double> z = tridiag_solve(lower, diag, upper, e);

    double factor=0;
    for(int i=0; i<N; i++) factor+=x[i]*e[i];
    double denom=1;
    for(int i=0; i<N; i++) denom+=z[i]*e[i];
    factor/=denom;
    for(int i=0; i<N; i++) x[i]-=factor*z[i];
    return x;
}

vector<double> gauss_seidel(int N,int max_iter=1000,double tol=1e-10)
{
    double h = 2.0/(N-1), a=1/(h*h), b=-2/(h*h);
    vector<double> u(N,0), rhs(N);
    for(int i=0; i<N; i++) rhs[i]=cos(4.0*M_PI*i/N);

    for(int iter=0; iter<max_iter; iter++)
    {
        vector<double> u_old = u;
        for(int i=0; i<N; i++)
        {
            double sum = 0;
            if(i>0) sum+=a*u[i-1];
            else sum+=a*u[N-1]; // cyklicznie
            if(i<N-1) sum+=a*u[i+1];
            else sum+=a*u[0];
            u[i] = (rhs[i]-sum)/b;
        }
        double err=0;
        for(int i=0; i<N; i++) err+=fabs(u[i]-u_old[i]);
        if(err<tol) break;
    }
    return u;
}

int main()
{
    int N = 500;
    cout << "Rozwiazywanie ukladu dla N = " << N << "\n\n";

    //Metoda 1
    auto t1 = chrono::high_resolution_clock::now();
    auto u1 = pelna_macierz(N);
    auto t2 = chrono::high_resolution_clock::now();

    //Metoda 2
    auto t3 = chrono::high_resolution_clock::now();
    auto u2 = sherman(N);
    auto t4 = chrono::high_resolution_clock::now();

    //Metoda 3
    auto t5 = chrono::high_resolution_clock::now();
    auto u3 = gauss_seidel(N);
    auto t6 = chrono::high_resolution_clock::now();

    cout << "Czasy wykonania:\n";
    cout << " 1) Pelna macierz:          "
         << chrono::duration<double, milli>(t2 - t1).count() << " ms\n";
    cout << " 2) Sherman:                "
         << chrono::duration<double, milli>(t4 - t3).count() << " ms\n";
    cout << " 3) Gauss_siedel:           "
         << chrono::duration<double, milli>(t6 - t5).count() << " ms\n\n";

    cout << "Fragment rozwiazania (pierwsze 5 wartosci):\n";
    for(int i = 0; i < min(5, N); i++)
        cout << "u[" << i+1 << "] = " << u2[i] << endl;

    return 0;
}

