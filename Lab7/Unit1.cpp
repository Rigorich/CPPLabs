// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "CHash.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

class TestHash : public Hash<int> {
	static int HashInt(const int & x) {
		return x;
	}

public:
	TestHash(int tableSize) : Hash(tableSize, HashInt) {
	}

	void Show(TMemo* Mem) {
		Mem->Lines->Clear();
		for (int i = 0; i < TableSize; i++) {
			AnsiString s;
			s += IntToStr(i) + ": ";
			for (auto it = Table[i].begin(); it != Table[i].end(); ++it)
				s += IntToStr(Table[i][it]) + " | ";
			Mem->Lines->Add(s);
		}
	}

	void Randomize() {
		for (int i = rand() % 13; i < 42; i++)
			insert(99 - rand() % 199);
	}

	int FindMax() {
		int maxind = -1, maxval;
		for (int i = 0; i < TableSize; i++)
			for (auto it = Table[i].begin(); it != Table[i].end(); ++it)
				if (maxind == -1 || Table[i][it] > maxval) {
					maxind = i;
					maxval = Table[i][it];
				}
		return maxind;
	}
};

TestHash* a;

void __fastcall TForm1::FormCreate(TObject *Sender) {
	a = new TestHash(StrToInt(EditHash->Text));
	a->Show(Memo1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonClearClick(TObject *Sender) {
	delete a;
	try {
		int HS = StrToInt(EditHash->Text);
		if (HS < 1)
			throw;
		a = new TestHash(HS);
	}
	catch (...) {
		ShowMessage("FATAL: Wrong hash table size");
		Application->Terminate();
	}
	a->Show(Memo1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonRandomizeClick(TObject *Sender) {
	a->Randomize();
	a->Show(Memo1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonFindMaxClick(TObject *Sender) {
	ShowMessage("Max number is in " + IntToStr(a->FindMax()) + "th array");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAddClick(TObject *Sender) {
	try {
		a->insert(StrToInt(EditNumber->Text));
	}
	catch (...) {
		ShowMessage("Wrong number");
	}
	a->Show(Memo1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteClick(TObject *Sender) {
	try {
		a->erase(StrToInt(EditNumber->Text));
	}
	catch (...) {
		ShowMessage("Wrong number");
	}
	a->Show(Memo1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonFindClick(TObject *Sender) {
	try {
		if (a->contain(StrToInt(EditNumber->Text)))
			ShowMessage("True, there is " + EditNumber->Text);
		else
			ShowMessage("False, there is no " + EditNumber->Text);
	}
	catch (...) {
		ShowMessage("Wrong number");
	}
}
// ---------------------------------------------------------------------------
