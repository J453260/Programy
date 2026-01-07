#ifndef TypZespolone
#define TypZespolone
#include <stdio.h>

struct Zespolone
{
    double Re; // Część rzeczywista
    double Im; // Część urojona
};
typedef struct Zespolone zesp;

zesp CzytajZ(FILE *wp);
int PiszZ(FILE *wp, zesp z);
zesp SprzezenieZ(zesp z);
double ModulZ(zesp z);
double FazaZ(zesp z);
zesp SumaZ(zesp z1, zesp z2);
zesp RoznicaZ(zesp z1, zesp z2);
zesp IloczynZ(zesp z1, zesp z2);
zesp IlorazZ(zesp z1, zesp z2);

#endif

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif // M_PI
