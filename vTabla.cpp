//---------------------------------------------------------------------------

#pragma hdrstop
#include "GameWindow.h"
#include "vTabla.h"
vTabla::vTabla()
{ for(int i=0;i<size;i++)
	for(int j=0;j<size;j++)
	{inner[i][j]=0;
	 middle[i][j]=0;
	 outter[i][j]=0;}
	 inner[1][1]=INNER;
	 middle[1][1]=MIDDLE;
	 outter[1][1]=OUTTER;
}
void vTabla::set(int circle,int linie,int col,int a)
{ switch(circle)
{     case INNER:
	  inner[linie][col]=a;break;
	  case MIDDLE:
	  middle[linie][col]=a;break;
	  case OUTTER:
	  outter[linie][col]=a;break;
		   }
			 }
int vTabla::get(int circle,int linie, int col)
{     switch(circle)
{     case INNER:
	  return inner[linie][col];break;
	  case MIDDLE:
	  return middle[linie][col];break;
	  case OUTTER:
	  return outter[linie][col];break;   }
      return 0;//warning daca nu pun un return
}
bool vTabla::empty(int circle,int linie, int col)
{   switch(circle)
{     case INNER:
	  if(inner[linie][col]!=0)
	  return true;break;
	  case MIDDLE:
	  if(middle[linie][col]!=0)
	  return true;break;
	  case OUTTER:
	  if(outter[linie][col]!=0)
	  return true;break;   }
	  return false;
}
void vTabla::afisare(TButton* b,int circle,int linie, int coloana)
{           switch(circle)
{     case INNER:
	  b->Caption=inner[linie][coloana];break;
	  case MIDDLE:
	  b->Caption=middle[linie][coloana];break;
	  case OUTTER:
	  b->Caption=outter[linie][coloana];break;}

}
//---------------------------------------------------------------------------
#pragma package(smart_init)
