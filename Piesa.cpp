//---------------------------------------------------------------------------

#pragma hdrstop

#include "Piesa.h"
  Piesa::Piesa(int circle,int linie,int coloana,int player)
  {this->circle=circle;
  this->linie=linie;
  this->coloana=coloana;
  this->Player=player;
  }
 int Piesa::getPlayer()
 {return Player;
 }

   int Piesa::getCircle()
   {return circle;}

  int Piesa::getLinie()
  {return linie;}

	int Piesa::getColoana()
	{return coloana;}

	void Piesa::setCircle(int circle)
	{ this->circle=circle;
	}
  void Piesa::setLinie(int linie)
  {this->linie=linie;}

  void Piesa::setColoana(int coloana)
  {this->coloana=coloana;}

  void Piesa::setPlayer(int Player)
  {this->Player=Player;}

//---------------------------------------------------------------------------
#pragma package(smart_init)
