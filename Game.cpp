//---------------------------------------------------------------------------

#pragma hdrstop

#include "Game.h"
Game::Game()
{for(int k=0;k<size;k++)
for(int i=0;i<size;i++)
	for(int j=0;j<size;j++)
	{tabla[k][i][j]=0;}
	 tabla[0][1][1]=INNER;
	 tabla[1][1][1]=MIDDLE;
	 tabla[2][1][1]=OUTTER;
round=0;
clicknr=0;
index=0;}

void Game::set(int circle,int linie,int col,int a)
{	tabla[circle][linie][col]=a;	 }

int Game::get(int circle,int linie, int col)
{     return tabla[circle][linie][col];
}

void Game::refresh()
{for(int k=0;k<size;k++)
for(int i=0;i<size;i++)
	for(int j=0;j<size;j++)
	{tabla[k][i][j]=0;}

for(int i=0;i<P1pieces;i++)
{tabla[P1[i]->getCircle()][P1[i]->getLinie()][P1[i]->getColoana()]=P1[i]->getPlayer();
}

 for(int i=0;i<P2pieces;i++)
 {  tabla[P2[i]->getCircle()][P2[i]->getLinie()][P2[i]->getColoana()]=P2[i]->getPlayer();
 }

 }
 bool Game::checkMoara(Piesa *p)
 {int ok1=0,ok2=0,ok3=0;
 for(int i=0;i<3;i++)
	if(tabla[i][p->getLinie()][p->getColoana()]==p->getPlayer()&& ((p->getLinie()==0 && p->getColoana()==1)||(p->getLinie()==1 && p->getColoana()==2)||(p->getLinie()==1 && p->getColoana()==0)||(p->getLinie()==2 && p->getColoana()==1)) )
		   ok1++;
   for(int i=0;i<3;i++)
	 {if(tabla[p->getCircle()][p->getLinie()][i]==p->getPlayer())
	 ok2++;
	 if(tabla[p->getCircle()][i][p->getColoana()]==p->getPlayer())
	 ok3++;
		}
		if(ok1==3 ||ok2==3||ok3==3)
		return true ;
		else
		return false;
}
void Game::piesa_noua(int Player,int circle,int linie,int coloana)
{  Basic *p=new Basic(circle,linie,coloana,Player);
if(Player==1)
 P1[P1pieces++]=p;
else if(Player==2)
  P2[P2pieces++]=p;
set(circle,linie,coloana,Player);
}

void Game::nextRound()
{round++;
}
void Game::nextClick()
{clicknr++;
if(clicknr%2==0)
	{clicknr=0;
	round++;}

}
int Game::getClick()
{return clicknr;}

int Game::getRound(){
return round;}

int Game::getPieces(int player)
{ if(player==1)
return P1pieces;
else
return P2pieces; }

void Game::setClick(int a)
{clicknr=a;}

void Game::indexPiece(int player,int circle,int linie,int coloana)
{int i;
   if(player==1)
	{for(i=0;i<P1pieces;i++)
	if(P1[i]->getCircle()==circle && P1[i]->getLinie()==linie && P1[i]->getColoana()==coloana )
		{index=i;break;}
	}
	else
	{for( i=0;i<P2pieces;i++)
	 if(P2[i]->getCircle()==circle && P2[i]->getLinie()==linie && P2[i]->getColoana()==coloana)
		 {index=i;break;}

} }
int Game::getIndex()
{return index;}

Piesa* Game::getPiesa(int i,int player)
{if(player==1)
	return P1[i];
	else
	return P2[i];
	}
void Game::decreaseClick()
{clicknr--;}
void Game::decreaseRound()
{round--;}
void Game::killPiece(int index,int Player)
	{ if(Player==1)
	{for(int i=index;i<P1pieces-1;i++)
		  P1[i]=P1[i+1];
	P1pieces--;
	}
	else
	{for(int i=index;i<P2pieces-1;i++)
		  P2[i]=P2[i+1];
	P2pieces--;
	}
	}
void Game::transform(int player)
{if(player==1)
for(int i=0;i<3;i++)
{Piesa *b=new OnlyThree(P1[i]->getCircle(),P1[i]->getLinie(),P1[i]->getColoana(),player);
P1[i]=b;}
else
 for(int i=0;i<3;i++)
{Piesa *b=new OnlyThree(P2[i]->getCircle(),P2[i]->getLinie(),P2[i]->getColoana(),player);      //!!! asa sau OnlyThree?
P2[i]=b;}
}

	bool Game::getcheck(int player)
	{if(player==1)
	return check1;
	else
	return check2;
	}
void Game::setIndex(int a)
{index=a;}
void Game::setRound(int a)
{round=a;}
//---------------------------------------------------------------------------
#pragma package(smart_init)
