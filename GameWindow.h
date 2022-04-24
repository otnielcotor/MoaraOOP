//---------------------------------------------------------------------------

#ifndef GameWindowH
#define GameWindowH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.StdCtrls.hpp>
#include "InformationForm.h"
#include "Game.h"
#include "EndGame.h"
#include "EndGame2.h"
#include <System.Win.ScktComp.hpp>
#include <string.h>
//---------------------------------------------------------------------------
class TGameForm : public TForm
{
__published:	// IDE-managed Components
	TImage *Tabla;
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TImage *Image5;
	TImage *Image6;
	TImage *Image7;
	TImage *Image8;
	TImage *Image9;
	TImage *Image10;
	TImage *Image11;
	TImage *Image12;
	TImage *Image13;
	TImage *Image14;
	TImage *Image15;
	TImage *Image16;
	TImage *Image17;
	TImage *Image18;
	TImage *Image19;
	TImage *Image20;
	TImage *Image21;
	TImage *Image22;
	TImage *Image23;
	TImage *Image24;
	TLabel *LabelSize1;
	TLabel *LabelSize2;
	TServerSocket *ServerSocket1;
	TClientSocket *ClientSocket1;
	TLabel *LabelRound;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
	void __fastcall Image9Click(TObject *Sender);
	void __fastcall Image11Click(TObject *Sender);
	void __fastcall Image12Click(TObject *Sender);
	void __fastcall Image17Click(TObject *Sender);
	void __fastcall Image15Click(TObject *Sender);
	void __fastcall Image19Click(TObject *Sender);
	void __fastcall Image8Click(TObject *Sender);
	void __fastcall Image16Click(TObject *Sender);
	void __fastcall Image24Click(TObject *Sender);
	void __fastcall Image21Click(TObject *Sender);
	void __fastcall Image14Click(TObject *Sender);
	void __fastcall Image5Click(TObject *Sender);
	void __fastcall Image23Click(TObject *Sender);
	void __fastcall Image22Click(TObject *Sender);
	void __fastcall Image20Click(TObject *Sender);
	void __fastcall Image10Click(TObject *Sender);
	void __fastcall Image18Click(TObject *Sender);
	void __fastcall Image13Click(TObject *Sender);
	void __fastcall Image7Click(TObject *Sender);
	void __fastcall Image6Click(TObject *Sender);
	void __fastcall Image4Click(TObject *Sender);
	void __fastcall btnStartClick(TObject *Sender);
	void __fastcall ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ServerSocket1ClientRead(TObject *Sender, TCustomWinSocket *Socket);





private:	// User declarations
int mcircle=1;
int mlinie=1;
int mcoloana=1;
int icircle;
int ilinie;
int icoloana;
int mindex;
bool Send=false;    // de sters
bool moara=false;
public:		// User declarations
Game *joc;
TImage *img[3][3][3];
TLabel *label[3][3][3];
TPngImage *Player1;
TPngImage *Player2;
TPngImage * Blank;
void afisare_piesa(TImage* img,int circle,int linie, int coloana);
void afisare_tabla();
void load();
void mutare(int circle,int linie,int coloana);
void Enabled();
void DisableAll();
void EnableZero();
void EnablePieces();
void Moara(int circle,int linie,int coloana);
AnsiString info(int index,int circle,int linie,int coloana,int mindex, int mcircle,int mlinie, int mcoloana);
void btnAction(int circle,int linie,int coloana);
__fastcall TGameForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGameForm *GameForm;
//---------------------------------------------------------------------------
#endif
