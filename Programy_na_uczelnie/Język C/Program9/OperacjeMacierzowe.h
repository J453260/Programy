#ifndef OperacjeMacierzowe
#define OperacjeMacierzowe

int CzytajMacierz(FILE *wp, char *nazwa, int n, double M[n][n]);
int WypiszMacierz(FILE *wp, char *nazwa, int n, double M[n][n]);
int CzytajWektor(FILE *wp, char *nazwa, int n, double V[n]);
int WypiszWektor(FILE *wp, char *nazwa, int n, double V[n]);
int CzytajLiczbe(FILE *wp, char *nazwa, double *c);
int WypiszLiczbe(FILE *wp, char *nazwa, double c);
void TransponujMacierz(int n, double M[n][n], double MT[n][n]);
void DodajMacierze(int n, double A[n][n], double B[n][n], double C[n][n]);
void OdejmijMacierze(int n, double A[n][n], double B[n][n], double C[n][n]);
void MnozLiczbaMacierz(int n, double c, double A[n][n], double B[n][n]);
void MnozMacierzWektor(int n, double A[n][n], double V[n], double W[n]);
void MnozMacierze(int n, double A[n][n], double B[n][n], double C[n][n]);

#endif
