//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("StartWindow.cpp", StartForm);
USEFORM("EndGame.cpp", EndForm);
USEFORM("GameWindow.cpp", GameForm);
USEFORM("InformationForm.cpp", InfoForm);
USEFORM("EndGame2.cpp", EndForm2);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TStartForm), &StartForm);
		Application->CreateForm(__classid(TGameForm), &GameForm);
		Application->CreateForm(__classid(TInfoForm), &InfoForm);
		Application->CreateForm(__classid(TEndForm), &EndForm);
		Application->CreateForm(__classid(TEndForm2), &EndForm2);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
