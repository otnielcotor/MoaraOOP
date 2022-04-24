//---------------------------------------------------------------------------

#ifndef BasicH
#define BasicH
#include "Piesa.h"
class Basic:public Piesa
{public:
Basic(int circle, int linie, int coloana,int player):Piesa(circle,linie,coloana,player){};
bool Move(int circle,int linie,int coloana);

};
//---------------------------------------------------------------------------
#endif
