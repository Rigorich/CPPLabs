//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *EditRes;
	TButton *Button1;
	TEdit *EditA;
	TEdit *EditB;
	TEdit *EditC;
	TEdit *EditD;
	TEdit *EditE;
	TEdit *EditRPN;
	TButton *Button8;
	TPaintBox *ErrorInVar;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
