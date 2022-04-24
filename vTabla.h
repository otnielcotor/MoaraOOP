//---------------------------------------------------------------------------

#ifndef vTablaH
#define vTablaH
#include "Piesa.h"
#include "GameWindow.h"
#define size 3
#define INNER 1
#define MIDDLE 2
#define OUTTER 3
class vTabla
{ int inner[size][size];
  int middle[size][size];
  int outter[size][size];
  public:
  vTabla();
  void set(int circle,int linie,int col,int a);
  int get(int circle,int linie,int col);
  bool empty(int circle, int linie, int col);
	//afisare
  void afisare(TButton *b,int circle,int linie, int coloana);
};
//---------------------------------------------------------------------------
#endif
