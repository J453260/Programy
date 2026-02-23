#include <iostream>
#include <vector>
#include <random>
#include <cmath>
using namespace std;

vector<double> losowyWektor(int n)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(-1.0, 1.0);

    vector<double> x(n);
    double norma = 0.0;

    for (int i = 0; i < n; ++i)
    {
        x[i] = dist(gen);
        norma += x[i] * x[i];
    }

    norma = sqrt(norma);
    for (int i = 0; i < n; ++i)
        x[i] /= norma;

    return x;
}

struct Macierz
{
    int n;
    double h2inv;
    vector<double> diag;

    Macierz(int N) : n(N), diag(N)
    {
        double h = 20.0 / (N - 1);
        h2inv = 1.0 / (h * h);

        for (int i = 0; i < N; ++i)
        {
            double x = i * h - 10.0;
            diag[i] = -2.0 * h2inv + x * x;
        }
    }
};

double norma(const vector<double>& x)
{
    double s = 0.0;
    for (double v : x) s += v * v;
    return sqrt(s);
}

double iloczynSkalarny(const vector<double>& a,
                       const vector<double>& b)
{
    double s = 0.0;
    for (int i = 0; i < a.size(); ++i)
        s += a[i] * b[i];
    return s;
}

vector<double> mnozenieMacierzy(const Macierz& A,
                                const vector<double>& x)
{
    int n = A.n;
    vector<double> y(n, 0.0);

    y[0] = A.diag[0] * x[0] + A.h2inv * x[1];
    for (int i = 1; i < n - 1; ++i)
        y[i] = A.h2inv * x[i - 1] + A.diag[i] * x[i] + A.h2inv * x[i + 1];
    y[n - 1] = A.h2inv * x[n - 2] + A.diag[n - 1] * x[n - 1];

    return y;
}

void ortogonalizuj(vector<double>& x,
                   const vector<vector<double>>& poprzednie)
{
    for (const auto& v : poprzednie)
    {
        double p = iloczynSkalarny(x, v);
        for (int i = 0; i < x.size(); ++i)
            x[i] -= p * v[i];
    }
    double nrm = norma(x);
    for (double& xi : x) xi /= nrm;
}

vector<double> rozwiazTridiagonalna(const Macierz& A, double przesuniecie,
                                    const vector<double>& b)
{
    int n = A.n;
    vector<double> a(n - 1, A.h2inv),
           c(n - 1, A.h2inv),
           d(n), rhs = b;

    for (int i = 0; i < n; ++i)
        d[i] = A.diag[i] - przesuniecie;

    for (int i = 1; i < n; ++i)
    {
        double m = a[i - 1] / d[i - 1];
        d[i] -= m * c[i - 1];
        rhs[i] -= m * rhs[i - 1];
    }

    vector<double> x(n);
    x[n - 1] = rhs[n - 1] / d[n - 1];
    for (int i = n - 2; i >= 0; --i)
        x[i] = (rhs[i] - c[i] * x[i + 1]) / d[i];

    return x;
}

void najwiekszeWartosci(const Macierz& A, int ile,
                        vector<double>& lambdy,
                        vector<vector<double>>& wektory)
{
    for (int k = 0; k < ile; ++k)
    {
        vector<double> x = losowyWektor(A.n);
        ortogonalizuj(x, wektory);

        double lambda = 0.0;

        for (int it = 0; it < 2000; ++it)
        {
            vector<double> y = mnozenieMacierzy(A, x);
            ortogonalizuj(y, wektory);

            double nrm = norma(y);
            for (int i = 0; i < A.n; ++i)
                x[i] = y[i] / nrm;

            vector<double> Ax = mnozenieMacierzy(A, x);
            lambda = iloczynSkalarny(x, Ax);
        }

        lambdy.push_back(lambda);
        wektory.push_back(x);
    }
}

void najmniejszeWartosci(const Macierz& A, int ile, vector<double>& lambdy, vector<vector<double>>& wektory)
{
    for (int k = 0; k < ile; ++k)
    {
        vector<double> x = losowyWektor(A.n);
        ortogonalizuj(x, wektory);

        double lambda = 0.0;

        for (int it = 0; it < 300; ++it)
        {
            vector<double> y = rozwiazTridiagonalna(A, 0.0, x);
            ortogonalizuj(y, wektory);

            double nrm = norma(y);
            for (int i = 0; i < A.n; ++i)
                x[i] = y[i] / nrm;

            vector<double> Ax = mnozenieMacierzy(A, x);
            lambda = iloczynSkalarny(x, Ax);
        }

        lambdy.push_back(lambda);
        wektory.push_back(x);
    }
}

vector<vector<double>> zbieznoscPotegowa(const Macierz& A, int ile, int maxIter)
{
    vector<vector<double>> residua_all;

    for (int k = 0; k < ile; ++k)
    {
        vector<double> x = losowyWektor(A.n);
        vector<double> residua_iter;

        for (int it = 0; it < maxIter; ++it)
        {
            vector<double> y = mnozenieMacierzy(A, x);
            double nrm = norma(y);
            for (int i = 0; i < A.n; ++i)
                x[i] = y[i] / nrm;

            vector<double> Ax = mnozenieMacierzy(A, x);
            double lambda = iloczynSkalarny(x, Ax);

            double res = 0.0;
            for (int i = 0; i < A.n; ++i)
                res += (Ax[i] - lambda * x[i]) * (Ax[i] - lambda * x[i]);
            residua_iter.push_back(sqrt(res));

            if (sqrt(res) < 1e-10) break;
        }
        residua_all.push_back(residua_iter);
    }
    return residua_all;
}

vector<vector<double>> zbieznoscRayleigha(const Macierz& A, int ile, int maxIter)
{
    vector<vector<double>> residua_all;

    for (int k = 0; k < ile; ++k)
    {
        vector<double> x = losowyWektor(A.n);
        vector<double> residua_iter;

        for (int it = 0; it < maxIter; ++it)
        {
            vector<double> y = rozwiazTridiagonalna(A, 0.0, x);
            double nrm = norma(y);
            for (int i = 0; i < A.n; ++i)
                x[i] = y[i] / nrm;

            vector<double> Ax = mnozenieMacierzy(A, x);
            double lambda = iloczynSkalarny(x, Ax);

            double res = 0.0;
            for (int i = 0; i < A.n; ++i)
                res += (Ax[i] - lambda * x[i]) * (Ax[i] - lambda * x[i]);
            residua_iter.push_back(sqrt(res));

            if (sqrt(res) < 1e-10) break;
        }
        residua_all.push_back(residua_iter);
    }
    return residua_all;
}

int main()
{
    int N = 800;
    Macierz A(N);

    vector<double> lambdaMax, lambdaMin;
    vector<vector<double>> wektoryMax, wektoryMin;

    najwiekszeWartosci(A, 2, lambdaMax, wektoryMax);
    najmniejszeWartosci(A, 4, lambdaMin, wektoryMin);

    /**
    cout << "2 Najwieksze (modol): "<<endl;
    for (double l : lambdaMax) cout << abs(l) << endl;

    cout << endl << "4 Najmniejsze (modol): "<<endl;
    for (double l : lambdaMin) cout << abs(l) << endl;

    cout<<endl;
    */


    cout << "2 Najwieksze i wektory wlasne (pierwsze 10 elementow):\n";
    for (int i = 0; i < lambdaMax.size(); ++i)
    {
        cout << "Wartosc wlasna[" << i+1 << "] = " << lambdaMax[i] << "\nWektor wlasny: ";
        for (int j = 0; j < min(10, N); ++j)
            cout << wektoryMax[i][j] << ", ";
        cout << "...\n\n";
    }

    cout << "4 Najmniejsze i wektory wlasne (pierwsze 10 elementow):\n";
    for (int i = 0; i < lambdaMin.size(); ++i)
    {
        cout << "Wartosc wlasna[" << i+1 << "] = " << lambdaMin[i] << "\nWektor wlasny: ";
        for (int j = 0; j < min(10, N); ++j)
            cout << wektoryMin[i][j] << ", ";
        cout << "...\n\n";
    }

    auto residuaPotegowa = zbieznoscPotegowa(A, 2, 2000);
    auto residuaRayleigha = zbieznoscRayleigha(A, 4, 300);
    cout << "Zbieznosc metody potegowej (pierwsza najwieksza): " << endl;
    for (double r : residuaPotegowa[0]) cout << r << endl;
    cout << "\nZbieznosc metody Rayleigha (pierwsza najmniejsza): " << endl;
    for (double r : residuaRayleigha[0]) cout << r << endl;
}
