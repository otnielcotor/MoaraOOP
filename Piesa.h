//---------------------------------------------------------------------------

#ifndef PiesaH
#define PiesaH
#include "Pozitie.h"
class Piesa: public Pozitie
{protected :
int Player;
public:
	Piesa(int circle,int linie,int coloana,int player);
  int getPlayer();
  int getCircle();
  int getLinie();
  int getColoana();
  void setCircle(int circle);
  void setLinie(int linie);
  void setColoana(int coloana);
  void setPlayer(int Player);
};
//---------------------------------------------------------------------------
#endif
