//---------------------------------------------------------------------------

#ifndef InformationFormH
#define InformationFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TInfoForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *InfoLabel;
	TButton *Ok;
private:	// User declarations
public:		// User declarations
	__fastcall TInfoForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInfoForm *InfoForm;
//---------------------------------------------------------------------------
#endif
