//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TTreeView *TreeView1;
	TStringGrid *StringGrid1;
	TButton *ButtonAdd;
	TButton *ButtonClear;
	TButton *ButtonDelete;
	TEdit *EditKey;
	TEdit *EditValue;
	TButton *ButtonMove;
	TEdit *EditDelKey;
	TButton *ButtonNew;
	TButton *ButtonRandom;
	TStringGrid *StringGridLevels;
	TMemo *Memo1;
	TRadioGroup *RadioGroup1;
	TButton *ButtonFind;
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonClearClick(TObject *Sender);
	void __fastcall ButtonMoveClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonNewClick(TObject *Sender);
	void __fastcall ButtonRandomClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall ButtonFindClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
