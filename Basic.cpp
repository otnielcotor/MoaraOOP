//---------------------------------------------------------------------------

#pragma hdrstop

#include "Basic.h"
#include <math.h>

bool Basic::Move(int circle,int linie,int coloana)
{if((abs(this->circle-circle)==1 && (((linie==this->linie && linie==1)&& (coloana==this->coloana && coloana==2))||((linie==this->linie&& linie==2) && (coloana==this->coloana && coloana==1)) ||((linie==this->linie && linie==0) && (coloana==this->coloana && coloana==1)) ||((linie==this->linie && linie==1) && (coloana==this->coloana && coloana==0)))))
return true;
else
if(this->circle==circle)
	{if((abs(this->linie-linie) && this->coloana==coloana) || (abs(this->coloana-coloana)==1 && this->linie==linie) )
	return true;  }
	else if(abs(this->circle-circle)==1 && this->linie==linie && this->coloana==coloana)
	return true;

return false;
};
//---------------------------------------------------------------------------
#pragma package(smart_init)
