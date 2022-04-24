//---------------------------------------------------------------------------

#ifndef EndGameH
#define EndGameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TEndForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Ok;
private:	// User declarations
public:		// User declarations
	__fastcall TEndForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TEndForm *EndForm;
//---------------------------------------------------------------------------
#endif
