//---------------------------------------------------------------------------

#ifndef OnlyThreeH
#define OnlyThreeH
#include "Piesa.h"
class OnlyThree:public Piesa
{public:
	OnlyThree(int circle, int linie, int coloana,int player):Piesa(circle,linie,coloana,player){};
	bool Move(int circle,int linie,int coloana);
};
//---------------------------------------------------------------------------
#endif
