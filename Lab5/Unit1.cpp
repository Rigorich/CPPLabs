//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "CList.h"
#include "CQueue.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

Queue<int> in;
List<int> a, b;

void Redraw()
{
	Form1->ListBox->Clear();
	Form1->ListBoxPos->Clear();
	Form1->ListBoxNeg->Clear();

	for(auto it = in.begin(); it != in.end(); ++it)
		Form1->ListBox->Items->Add(IntToStr(in[it]));
	for(auto it = a.begin(); it != a.end(); ++it)
		Form1->ListBoxNeg->Items->Add(IntToStr(a[it]));
	for(auto it = b.begin(); it != b.end(); ++it)
		Form1->ListBoxPos->Items->Add(IntToStr(b[it]));
}

void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
	// Random number in range [-42; 42] \ {0}
	in.push_back(((rand()%2)*(-2)+1) * (1+rand()%42));
	Redraw();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDelClick(TObject *Sender)
{
	if(in.begin() != in.end())
		in.pop_front();
    Redraw();
}
//---------------------------------------------------------------------------

bool rule (const int & x) {
	return x < 0;
}

void __fastcall TForm1::ButtonMakeClick(TObject *Sender)
{
	a.clear();
	b.clear();
	in.split(a, b, rule);
	Redraw();
}
//---------------------------------------------------------------------------

