//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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

#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int MaxWardCapacity = 4;

struct Record {
	AnsiString Name;
	AnsiString Sex;
	int Age;
	AnsiString Diagnosis;
	int Ward;
};

vector<Record> Database;

AnsiString FormatPatient(int i, AnsiString delta1, AnsiString delta2, AnsiString delta3, AnsiString delta4){
	return Database[i].Name + delta1 +
			Database[i].Sex + delta2 +
			IntToStr(Database[i].Age) + delta3 +
			Database[i].Diagnosis + delta4 +
			Database[i].Ward;
}
AnsiString FormatPatient(int i, AnsiString delta){
	return FormatPatient(i, delta, delta, delta, delta);
}

bool compWard(int a, int b){
	if(Database[a].Ward != Database[b].Ward)
		return Database[a].Ward < Database[b].Ward;
	return Database[a].Name < Database[b].Name;
}
bool compDiagnosis(int a, int b){
	if(Database[a].Diagnosis != Database[b].Diagnosis)
		return Database[a].Diagnosis < Database[b].Diagnosis;
	if(Database[a].Ward != Database[b].Ward)
		return Database[a].Ward < Database[b].Ward;
	return Database[a].Name < Database[b].Name;
}
bool compName(int a, int b){
	if(Database[a].Name != Database[b].Name)
		return Database[a].Name < Database[b].Name;
	return Database[a].Ward < Database[b].Ward;
}

vector<int> ListInds;

void ReWrite(){
	ListInds.clear();
	if(Form1->RadioButtonList->ItemIndex == 0)
		for(int i = 0; i < Database.size(); i++)
			if(Database[i].Ward != 0)
				ListInds.push_back(i);
	if(Form1->RadioButtonList->ItemIndex == 1)
		for(int i = 0; i < Database.size(); i++)
			if(Database[i].Ward == 0)
				ListInds.push_back(i);
	switch(Form1->ComboBoxSearch->ItemIndex){
		case 0:
			sort(ListInds.begin(), ListInds.end(), compWard);
			break;
		case 1:
			sort(ListInds.begin(), ListInds.end(), compDiagnosis);
			break;
		case 2:
			sort(ListInds.begin(), ListInds.end(), compName);
			break;
	}

	Form1->ListBox->Clear();
	Form1->ListBox->TabWidth = 111;
	for(int i = 0; i < ListInds.size(); i++)
	if(Form1->EditSearch->Text.Trim().Length() == 0 ||
		Database[ListInds[i]].Name.LowerCase().Pos(Form1->EditSearch->Text.Trim().LowerCase()) != 0 ||
		Database[ListInds[i]].Diagnosis.LowerCase().Pos(Form1->EditSearch->Text.Trim().LowerCase()) != 0 ||
		IntToStr(Database[ListInds[i]].Ward).Pos(Form1->EditSearch->Text.Trim().LowerCase()) != 0)
			Form1->ListBox->Items->Add(FormatPatient(ListInds[i], (AnsiString)(char)9 + " | ", " | ", " | ", (AnsiString)(char)9 + " | "));
}

const char delta = '|';
const char lend = '\n';

void __fastcall TForm1::ButtonSaveDialogClick(TObject *Sender)
{
	if (SaveDialog->Execute()) {
		ofstream fout(SaveDialog->FileName.c_str());
		if(!fout){
			ShowMessage("Файл не найден");
			return;
		}
		for(int i = 0; i < Database.size(); i++) {
			fout << delta << FormatPatient(i, delta) << delta << lend;
		}
		fout.close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOpenDialogClick(TObject *Sender)
{
	if (OpenDialog->Execute()) {
		ifstream fin(OpenDialog->FileName.c_str());
		if(!fin){
			ShowMessage("Файл не найден");
			return;
		}
		Database.clear();
		while(true) {
			Record tmp;
			AnsiString str = "";
			char sym = 0;

			bool stop = false;

			while(sym != lend){

				if(fin.eof()) {
					fin.close();
					stop = true;
					break;
				}

				sym = fin.get();
				str += sym;
			}

			if(stop) break;

			int p = 2, i = 2;

			while(str[i] != delta) i++;
			tmp.Name = str.SubString(p, i - p);
			i++;
			p = i;

			while(str[i] != delta) i++;
			tmp.Sex = str.SubString(p, i - p);
			i++;
			p = i;

			while(str[i] != delta) i++;
			tmp.Age = StrToInt(str.SubString(p, i - p));
			i++;
			p = i;

			while(str[i] != delta) i++;
			tmp.Diagnosis = str.SubString(p, i - p);
			i++;
			p = i;

			while(str[i] != delta) i++;
			tmp.Ward = StrToInt(str.SubString(p, i - p));
			i++;
			p = i;

			Database.push_back(tmp);

		}
		ButtonFlushListClick(Sender);
        Form1->RadioButtonList->ItemIndex = 0;
		RadioButtonListClick(Sender);
	}
}
//---------------------------------------------------------------------------

const AnsiString SexM = "Муж";
const AnsiString SexW = "Жен";

Record getRecord(){
	Record tmp;

	tmp.Name = Form1->EditName->Text.Trim();
	if(tmp.Name.Length() == 0){
		ShowMessage("Введите имя пациента");
		throw 0;
	}

	if(Form1->RadioGroupSex->ItemIndex == 0) tmp.Sex = SexM;
	else if(Form1->RadioGroupSex->ItemIndex == 1) tmp.Sex = SexW;
	else {
		ShowMessage("Выберите пол пациента");
		throw 0;
	}

	try {
		tmp.Age = StrToInt(Form1->EditAge->Text);
		if(tmp.Age < 18) throw 0;
		if(tmp.Age > 150) throw 0;
	} catch (...) {
		ShowMessage("Введите возраст пациента");
		throw 0;
	}

	tmp.Diagnosis = Form1->EditDiagnosis->Text.Trim();
	if(tmp.Diagnosis.Length() == 0){
		ShowMessage("Введите диагноз пациента");
		throw 0;
	}

	try {
		tmp.Ward = StrToInt(Form1->EditWard->Text);
	} catch (...) {
		ShowMessage("Введите номер палаты или 0");
		throw 0;
	}

	return tmp;
}

void __fastcall TForm1::ButtonSaveChangesClick(TObject *Sender)
{
	if(CheckBoxAddPatient->Checked) {
		Record tmp;
		bool OK = true;
        try {
			tmp = getRecord();
			try {
				Form1->RadioButtonList->ItemIndex = 0;
        		if(tmp.Ward == 0) {
        			int OkWard = 0;
        			map<int, int> s;
        			for(int i = 0; i < Database.size(); i++)
        				s[Database[i].Ward] += 1;
        			for(int i = 0; i < Database.size(); i++)
        				if(s[Database[i].Ward] < MaxWardCapacity)
        				if(Database[i].Sex == tmp.Sex)
        				if(Database[i].Diagnosis == tmp.Diagnosis)
        					OkWard = Database[i].Ward;
        			if(OkWard){
        				tmp.Ward = OkWard;
        				ShowMessage("Пациент добавлен в палату " + IntToStr(OkWard));
        			} else {
        				for(int i = 0; i < Database.size(); i++)
        					if(s[Database[i].Ward] < MaxWardCapacity)
        					if(Database[i].Sex == tmp.Sex)
								OkWard = Database[i].Ward;
        				if(OkWard){
        					tmp.Ward = OkWard;
        					ShowMessage("В палате " + IntToStr(OkWard) + " пациенты с разными диагнозами");
        				} else {
        					tmp.Ward = 0;
        					Form1->RadioButtonList->ItemIndex = 1;
        					ShowMessage("Не удалось разместить пациента");
        				}
        			}
        		} else {
			        map<int, int> s;
        			for(int i = 0; i < Database.size(); i++)
        				s[Database[i].Ward] += 1;
        			if(s[tmp.Ward] == MaxWardCapacity)
        				throw (AnsiString)"Палата переполнена";
        			for(int i = 0; i < Database.size(); i++)
        				if(Database[i].Ward == tmp.Ward && Database[i].Sex != tmp.Sex)
        					throw (AnsiString)"Разнополые пациенты в одной палате";
        		}
			} catch (AnsiString err) {
				ShowMessage(err);
				throw 0;
			}
		} catch(...) {
			OK = false;
		}
		if(OK){
			Database.push_back(tmp);
			RadioButtonListClick(Sender);
			CheckBoxAddPatientClick(Sender);
		}
	} else {
		if(ListBox->ItemIndex != -1){
			int p = ListBox->ItemIndex;
			Record tmp;
			bool OK = true;
			try {
				tmp = getRecord();
				try {
					if(tmp.Ward == 0) {
						int OkWard = 0;
						map<int, int> s;
						for(int i = 0; i < Database.size(); i++)
							if(ListInds[p] != i)
								s[Database[i].Ward] += 1;
						for(int i = 0; i < Database.size(); i++)
							if(ListInds[p] != i)
							if(s[Database[i].Ward] < MaxWardCapacity)
							if(Database[i].Sex == tmp.Sex)
							if(Database[i].Diagnosis == tmp.Diagnosis)
								OkWard = Database[i].Ward;
						if(OkWard){
							tmp.Ward = OkWard;
							ShowMessage("Пациент добавлен в палату " + IntToStr(OkWard));
						} else {
							for(int i = 0; i < Database.size(); i++)
								if(ListInds[p] != i)
								if(s[Database[i].Ward] < MaxWardCapacity)
								if(Database[i].Sex == tmp.Sex)
									OkWard = Database[i].Ward;
							if(OkWard){
								tmp.Ward = OkWard;
								ShowMessage("В палате " + IntToStr(OkWard) + " пациенты с разными диагнозами");
							} else {
								tmp.Ward = 0;
								ShowMessage("Не удалось разместить пациента");
                                throw 0;
							}
						}
					} else {
						map<int, int> s;
						for(int i = 0; i < Database.size(); i++)
							if(ListInds[p] != i)
								s[Database[i].Ward] += 1;
						if(s[tmp.Ward] == MaxWardCapacity)
							throw (AnsiString)"Палата переполнена";
						for(int i = 0; i < Database.size(); i++)
							if(ListInds[p] != i)
							if(Database[i].Ward == tmp.Ward && Database[i].Sex != tmp.Sex)
								throw (AnsiString)"Разнополые пациенты в одной палате";
					}
				} catch (AnsiString err) {
					ShowMessage(err);
					throw 0;
				}
			} catch(...) {
				OK = false;
			}
			if(OK){
				Database[ListInds[p]] = tmp;
				Form1->RadioButtonList->ItemIndex = 0;
				RadioButtonListClick(Sender);
				CheckBoxAddPatient->Checked = true;
			}
		}
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSearchClick(TObject *Sender)
{
	ReWrite();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonFlushListClick(TObject *Sender)
{
	EditSearch->Text = "";
	ReWrite();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBoxAddPatientClick(TObject *Sender)
{
	ListBox->ItemIndex = -1;
	EditName->Text = "";
	RadioGroupSex->ItemIndex = -1;
	EditAge->Text = "";
	EditDiagnosis->Text = "";
	EditWard->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButtonListClick(TObject *Sender)
{
	ReWrite();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteClick(TObject *Sender)
{
	if(ListBox->ItemIndex != -1){
		Database.erase(Database.begin() + ListInds[ListBox->ItemIndex]);
		RadioButtonListClick(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBoxClick(TObject *Sender)
{
	if(ListBox->ItemIndex != -1){
		int p = ListBox->ItemIndex;
		int i = ListInds[p];
		CheckBoxAddPatient->Checked = false;
		EditName->Text = Database[i].Name;
		if(Database[i].Sex == SexM)
			RadioGroupSex->ItemIndex = 0;
		else if(Database[i].Sex == SexW)
			RadioGroupSex->ItemIndex = 1;
		else
			RadioGroupSex->ItemIndex = -1;
		EditAge->Text = IntToStr(Database[i].Age);
		EditDiagnosis->Text = Database[i].Diagnosis;
		EditWard->Text = IntToStr(Database[i].Ward);
		RadioButtonListClick(Sender);
		ListBox->ItemIndex = p;
	}
}
//---------------------------------------------------------------------------

