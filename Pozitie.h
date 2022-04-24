//---------------------------------------------------------------------------

#ifndef PozitieH
#define PozitieH
//---------------------------------------------------------------------------
 class Pozitie
{protected:
	int circle;
	int linie;
	int coloana;
public:
   virtual bool Move(int circle,int linie,int coloana)=0;
};
#endif
