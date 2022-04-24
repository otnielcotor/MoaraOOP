//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GameWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGameForm *GameForm;
//---------------------------------------------------------------------------
void TGameForm::afisare_piesa(TImage* img,int circle,int linie, int coloana)
{
	if(joc->get(circle,linie,coloana)==0)
	 {img->Visible=true;
	 img->Picture->Assign(Blank);
	 img->Proportional=true;}
	 if(joc->get(circle,linie,coloana)==1)
	 {img->Visible=true;
	 img->Picture->Assign(Player1);
	 img->Proportional=true;
	 }
	 if(joc->get(circle,linie,coloana)==2)
	 {img->Visible=true;
	 img->Picture->Assign(Player2);
	 img->Proportional=true;
	 }
}
void TGameForm::afisare_tabla()
{
for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
	for(int c=0;c<3;c++)
	{if(l==1&&c==1)
	c=c+1;
	afisare_piesa(img[k][l][c],k,l, c);
	LabelRound->Caption=joc->getRound();}

   }
void TGameForm::load()
   {Player1= new TPngImage();
 Player2= new TPngImage() ;
   Blank= new TPngImage();
	Player1->LoadFromFile("P1.png");
	Player2->LoadFromFile("P2.png");
	Blank->LoadFromFile("Blank.png");};



void TGameForm::btnAction(int circle,int linie,int coloana)
{
if(ServerSocket1->Active==true)
	{if(moara==true)
	{
	 Moara(circle,linie,coloana); }
	 else
	 {mutare(circle,linie,coloana);  }	  }
  else
  if(ClientSocket1->Active==true)
  { if(moara==true)
	 Moara(circle,linie,coloana);
	 else
	 mutare(circle,linie,coloana);}
}




void TGameForm::mutare(int circle,int linie,int coloana)
{
   LabelSize1->Caption=joc->getPieces(1);
   LabelSize2->Caption=joc->getPieces(2);
if(joc->getRound()<18)
	{
	joc->set(circle,linie,coloana,joc->getRound()%2+1);
		joc->piesa_noua(joc->getRound()%2+1,circle,linie,coloana);
		joc->nextRound();
	  //	DisableAll();
	  //	EnableZero();
	if(ServerSocket1->Active==true)
			ServerSocket1->Socket->Connections[0]->SendText(info(joc->getIndex(),circle,linie,coloana,mindex,mcircle,mlinie,mcoloana));
		   else
			ClientSocket1->Socket->SendText(info(joc->getIndex(),circle,linie,coloana,mindex,mcircle,mlinie,mcoloana));
		}
		else
		{
	if(joc->getClick()==0)
		{
					joc->indexPiece(joc->getRound()%2+1,circle,linie,coloana);
					   ilinie=linie;
					 icoloana=coloana;
					 icircle=circle;

	   }
	else

	if(joc->getPiesa(joc->getIndex(),joc->getRound()%2+1)->Move(circle,linie,coloana)==true)
		{ joc->set(joc->getPiesa(joc->getIndex(),joc->getRound()%2+1)->getCircle(),joc->getPiesa(joc->getIndex(),joc->getRound()%2+1)->getLinie(),joc->getPiesa(joc->getIndex(),joc->getRound()%2+1)->getColoana(),0);
			   joc->getPiesa(joc->getIndex(),joc->getRound()%2+1)->setCircle(circle);
			  joc->getPiesa(joc->getIndex(),joc->getRound()%2+1)->setLinie(linie);
			  joc->getPiesa(joc->getIndex(),joc->getRound()%2+1)->setColoana(coloana);
				 joc->set(circle,linie,coloana,joc->getRound()%2+1);
				 ilinie=linie;
				 icoloana=coloana;
				 icircle=circle;
				 if(joc->checkMoara(joc->getPiesa(joc->getIndex(),joc->getRound()%2+1))==true)
		 { if(InfoForm->ShowModal()==mrOk)
			{ moara=true;
			//  EnablePieces();
			  }        }
		   else{
			if(ServerSocket1->Active==true)
			ServerSocket1->Socket->Connections[0]->SendText(info(joc->getIndex(),circle,linie,coloana,mindex,mcircle,mlinie,mcoloana));
		   else
			ClientSocket1->Socket->SendText(info(joc->getIndex(),circle,linie,coloana,mindex,mcircle,mlinie,mcoloana));}
			  }
			   else
					{if(ServerSocket1->Active==true)
		  ServerSocket1->Socket->Connections[0]->SendText(info(joc->getIndex(),icircle,ilinie,icoloana,mindex,mcircle,mlinie,mcoloana));
		   else
			ClientSocket1->Socket->SendText(info(joc->getIndex(),icircle,ilinie,icoloana,mindex,mcircle,mlinie,mcoloana));}




			joc->nextClick();
            joc->refresh();
							   }
	afisare_tabla();}



void TGameForm::Moara(int circle,int linie,int coloana)
{    int i=joc->getIndex();
			 joc->indexPiece(joc->getRound()%2+1,circle,linie,coloana);
			 joc->killPiece(joc->getIndex(),joc->getRound()%2+1);
			 joc->set(circle,linie,coloana,0);
			 if(joc->getcheck(joc->getRound()%2+1)==false && joc->getPieces(joc->getRound()%2+1))
             joc->transform(joc->getRound()%2+1);
			moara=false;
			mcircle=circle;
			mlinie=linie;
			mcoloana=coloana;
			mindex=joc->getIndex();
	afisare_tabla();
	if(joc->getPieces(joc->getRound()%2+1)==2)
		if(EndForm->ShowModal()==mrOk)
			 {
			 GameForm->Hide();}
	 if(ServerSocket1->Active==true)
		  ServerSocket1->Socket->Connections[0]->SendText(info(i,icircle,ilinie,icoloana,mindex,mcircle,mlinie,mcoloana));
		   else
			ClientSocket1->Socket->SendText(info(i,icircle,ilinie,icoloana,mindex,mcircle,mlinie,mcoloana));
 mcircle=1;
mlinie=1;
mcoloana=1;
mindex=10;

}

void TGameForm::Enabled()
{     DisableAll();
 for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
	for(int c=0;c<3;c++)
	 {   if((l==1&&c==1) )
		c=c+1;
		if(joc->get(k,l,c)==joc->getRound()%2+1)
				  { if(joc->getClick()==0){img[k][l][c]->Enabled=true;}
					else
					  {EnableZero();}
}  }  }
void TGameForm::DisableAll()
{for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
	for(int c=0;c<3;c++)
	{if((l==1&&c==1) )
		c=c+1;
	img[k][l][c]->Enabled=false;}}

void TGameForm::EnableZero()
{for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
	for(int c=0;c<3;c++)
	{if((l==1&&c==1) )
		c=c+1;
	   if(joc->get(k,l,c)==0 )
		img[k][l][c]->Enabled=true;}}

void TGameForm::EnablePieces()
{DisableAll();
for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
	for(int c=0;c<3;c++)
	{if((l==1&&c==1) )
		c=c+1;
	   if(joc->get(k,l,c)!=0 )
		img[k][l][c]->Enabled=true;}}


AnsiString TGameForm::info(int index,int circle,int linie,int coloana,int mindex,int mcircle,int mlinie, int mcoloana)
{
 if(mlinie==1 && mcoloana==1)
return IntToStr(index)+IntToStr(circle)+IntToStr(linie)+IntToStr(coloana)+"0"+IntToStr(mindex)+IntToStr(mcircle)+IntToStr(mlinie)+IntToStr(mcoloana);
else
return IntToStr(index)+IntToStr(circle)+IntToStr(linie)+IntToStr(coloana)+"1"+IntToStr(mindex)+IntToStr(mcircle)+IntToStr(mlinie)+IntToStr(mcoloana);
}
__fastcall TGameForm::TGameForm(TComponent* Owner)
	: TForm(Owner)
{

joc=new Game();
load();
img[0][0][0]=Image17;
img[0][0][1]=Image15;
img[0][0][2]=Image19;
img[0][1][0]=Image24;
img[0][1][2]=Image21;
img[0][2][0]=Image23;
img[0][2][1]=Image22;
img[0][2][2]=Image20;

img[1][0][0]=Image9;
img[1][0][1]=Image11;
img[1][0][2]=Image12;
img[1][1][0]=Image16;
img[1][1][2]=Image14;
img[1][2][0]=Image10;
img[1][2][1]=Image18;
img[1][2][2]=Image13;

img[2][0][0]=Image1;
img[2][0][1]=Image2;
img[2][0][2]=Image3;
img[2][1][0]=Image8;
img[2][1][2]=Image5;
img[2][2][0]=Image7;
img[2][2][1]=Image6;
img[2][2][2]=Image4;
afisare_tabla();

}
//---------------------------------------------------------------------------






void __fastcall TGameForm::Image1Click(TObject *Sender)
{    int circle=2;
	 int linie=0;
	 int coloana=0;
btnAction(circle,linie,coloana);

	 if(joc->getRound()>=18)
	 Enabled();


}
//---------------------------------------------------------------------------


void __fastcall TGameForm::Image2Click(TObject *Sender)
{    int circle=2;
	 int linie=0;
	 int coloana=1;
btnAction(circle,linie,coloana);

if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image3Click(TObject *Sender)
{
int circle=2;
	 int linie=0;
	 int coloana=2;
btnAction(circle,linie,coloana);

if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image9Click(TObject *Sender)
{
int circle=1;
	 int linie=0;
	 int coloana=0;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image11Click(TObject *Sender)
{
int circle=1;
	 int linie=0;
	 int coloana=1;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image12Click(TObject *Sender)
{
	int circle=1;
	 int linie=0;
	 int coloana=2;
btnAction(circle,linie,coloana);
 if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image17Click(TObject *Sender)
{
int circle=0;
	 int linie=0;
	 int coloana=0;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image15Click(TObject *Sender)
{
int circle=0;
	 int linie=0;
	 int coloana=1;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image19Click(TObject *Sender)
{
int circle=0;
	 int linie=0;
	 int coloana=2;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image8Click(TObject *Sender)
{
int circle=2;
	 int linie=1;
	 int coloana=0;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image16Click(TObject *Sender)
{
int circle=1;
	 int linie=1;
	 int coloana=0;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image24Click(TObject *Sender)
{
int circle=0;
	 int linie=1;
	 int coloana=0;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image21Click(TObject *Sender)
{
int circle=0;
	 int linie=1;
	 int coloana=2;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image14Click(TObject *Sender)
{
int circle=1;
	 int linie=1;
	 int coloana=2;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image5Click(TObject *Sender)
{
int circle=2;
	 int linie=1;
	 int coloana=2;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image23Click(TObject *Sender)
{
int circle=0;
	 int linie=2;
	 int coloana=0;
	 btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image22Click(TObject *Sender)
{
int circle=0;
	 int linie=2;
	 int coloana=1;
	btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image20Click(TObject *Sender)
{
int circle=0;
	 int linie=2;
	 int coloana=2;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image10Click(TObject *Sender)
{
int circle=1;
	 int linie=2;
	 int coloana=0;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image18Click(TObject *Sender)
{
int circle=1;
	 int linie=2;
	 int coloana=1;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image13Click(TObject *Sender)
{
int circle=1;
	 int linie=2;
	 int coloana=2;
btnAction(circle,linie,coloana);
 if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image7Click(TObject *Sender)
{
int circle=2;
	 int linie=2;
	 int coloana=0;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image6Click(TObject *Sender)
{
int circle=2;
	 int linie=2;
	 int coloana=1;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::Image4Click(TObject *Sender)
{
int circle=2;
	 int linie=2;
	 int coloana=2;
btnAction(circle,linie,coloana);
if(joc->getRound()>=18) Enabled();
}
//---------------------------------------------------------------------------

void __fastcall TGameForm::btnStartClick(TObject *Sender)
{
joc->refresh();
  afisare_tabla();
}
//---------------------------------------------------------------------------






void __fastcall TGameForm::ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket)

{
AnsiString message=Socket->ReceiveText();
AnsiString index=message[1];
AnsiString circle=message[2];
AnsiString linie=message[3];
AnsiString coloana=message[4];
AnsiString mindex=message[6];
AnsiString mcircle=message[7];
AnsiString mlinie=message[8];
AnsiString mcoloana=message[9];
	if(joc->getRound()>=18)
{
	joc->getPiesa(index.ToInt(),joc->getRound()%2+1)->setCircle(circle.ToInt());
	joc->getPiesa(index.ToInt(),joc->getRound()%2+1)->setLinie(linie.ToInt());
	joc->getPiesa(index.ToInt(),joc->getRound()%2+1)->setColoana(coloana.ToInt());
	joc->set(joc->getPiesa(index.ToInt(),joc->getRound()%2+1)->getCircle(),joc->getPiesa(index.ToInt(),joc->getRound()%2+1)->getLinie(),joc->getPiesa(index.ToInt(),joc->getRound()%2+1)->getColoana(),1);
	joc->setClick(0);
	 joc->nextRound();
	 EnablePieces();
		if(message[5]=='1')
		{joc->killPiece(mindex.ToInt(),joc->getRound()%2+1);joc->transform(joc->getRound()%2+1);
		if(joc->getPieces(joc->getRound()%2+1)==2)
			if(EndForm2->ShowModal()==mrOk)
				 {GameForm->Hide();}}

		}
else if(joc->getRound()<18)
{
		joc->piesa_noua(joc->getRound()%2+1,circle.ToInt(),linie.ToInt(),coloana.ToInt());

		joc->nextRound();
		 }

LabelRound->Caption=joc->getRound();
  joc->refresh();
afisare_tabla();
}
//---------------------------------------------------------------------------


void __fastcall TGameForm::ServerSocket1ClientRead(TObject *Sender, TCustomWinSocket *Socket)

{
AnsiString message=Socket->ReceiveText();
AnsiString index=message[1];
AnsiString circle=message[2];
AnsiString linie=message[3];
AnsiString coloana=message[4];
AnsiString mindex=message[6];
AnsiString mcircle=message[7];
AnsiString mlinie=message[8];
AnsiString mcoloana=message[9];
	if(joc->getRound()>=18)
	{
	joc->getPiesa(index.ToInt(),joc->getRound()%2+1)->setCircle(circle.ToInt());
	joc->getPiesa(index.ToInt(),joc->getRound()%2+1)->setLinie(linie.ToInt());
	joc->getPiesa(index.ToInt(),joc->getRound()%2+1)->setColoana(coloana.ToInt());
	joc->set(joc->getPiesa(index.ToInt(),joc->getRound()%2+1)->getCircle(),joc->getPiesa(index.ToInt(),joc->getRound()%2+1)->getLinie(),joc->getPiesa(index.ToInt(),joc->getRound()%2+1)->getColoana(),2);
	joc->setClick(0);
	 joc->nextRound();
	 EnablePieces();
		if(message[5]=='1')
		{joc->killPiece(mindex.ToInt(),joc->getRound()%2+1);joc->transform(joc->getRound()%2+1);
		if(joc->getPieces(joc->getRound()%2+1)==2)
			if(EndForm2->ShowModal()==mrOk)
				 {
					 GameForm->Hide();}}

	}
else if(joc->getRound()<18)
{
		joc->piesa_noua(joc->getRound()%2+1,circle.ToInt(),linie.ToInt(),coloana.ToInt());

		joc->nextRound();
		 }

LabelRound->Caption=joc->getRound();
  joc->refresh();
afisare_tabla();
}
//---------------------------------------------------------------------------

