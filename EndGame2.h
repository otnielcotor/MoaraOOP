//---------------------------------------------------------------------------

#ifndef EndGame2H
#define EndGame2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TEndForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Button1;
private:	// User declarations
public:		// User declarations
	__fastcall TEndForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEndForm2 *EndForm2;
//---------------------------------------------------------------------------
#endif
