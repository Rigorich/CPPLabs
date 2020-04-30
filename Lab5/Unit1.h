//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonAdd;
	TButton *ButtonDel;
	TButton *ButtonMake;
	TListBox *ListBox;
	TListBox *ListBoxPos;
	TListBox *ListBoxNeg;
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonDelClick(TObject *Sender);
	void __fastcall ButtonMakeClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
