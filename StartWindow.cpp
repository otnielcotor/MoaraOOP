//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StartWindow.h"
#include "GameWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStartForm *StartForm;
//---------------------------------------------------------------------------
__fastcall TStartForm::TStartForm(TComponent* Owner)
	: TForm(Owner) {
}
//---------------------------------------------------------------------------

void __fastcall TStartForm::btnPickServerClick(TObject *Sender)
{
GameForm->ServerSocket1->Active=true;
GameForm->Caption="Server";
GameForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TStartForm::btnPickClientClick(TObject *Sender)
{
GameForm->ClientSocket1->Address="127.0.0.1";
GameForm->ClientSocket1->Active=true;
GameForm->Caption="Client";
GameForm->Show();

}
//---------------------------------------------------------------------------

