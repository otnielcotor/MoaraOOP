//---------------------------------------------------------------------------

#ifndef GameH
#define GameH
#include "Basic.h"
#include "OnlyThree.h"
#define size 3
#define INNER 11
#define MIDDLE 22
#define OUTTER 33
class Game
{ int tabla[3][3][3];
Piesa *P1[9];
Piesa *P2[9];
int index;
bool check1=false;
bool check2=false;
int P1pieces=0;
int P2pieces=0;
int clicknr;
int round;
public:
	Game();
	void set(int circle,int linie,int col,int a);
	int get(int circle,int linie,int col);
	void refresh();
	 bool checkMoara(Piesa *p);
	void nextRound();
	void nextClick();
	int getClick();
	int getRound();
	void decreaseClick();
	void decreaseRound();
    void setRound(int a);
	void piesa_noua(int Player,int circle,int linie,int coloana);
	void indexPiece(int player,int circle,int linie,int coloana);
	int getIndex();
    void setIndex(int a);
	Piesa* getPiesa(int i,int player);
	void killPiece(int index,int player);
	void transform(int player);
	bool getcheck(int player);
	void setClick(int a);
    int getPieces(int player);

};




//---------------------------------------------------------------------------
#endif
