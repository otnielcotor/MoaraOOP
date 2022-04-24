//---------------------------------------------------------------------------

#ifndef StartWindowH
#define StartWindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ScktComp.hpp>
//---------------------------------------------------------------------------
class TStartForm : public TForm
{
__published:	// IDE-managed Components
	TButton *btnPickServer;
	TButton *btnPickClient;
	TLabel *Label1;
	void __fastcall btnPickServerClick(TObject *Sender);
	void __fastcall btnPickClientClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TStartForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStartForm *StartForm;
//---------------------------------------------------------------------------
#endif
