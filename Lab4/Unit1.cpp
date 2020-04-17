//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "CStack.h"
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

const AnsiString vars = "abcde";
const AnsiString opers = "(+-*/)";

int OperPrior(char x){
	switch(x){
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '/':
		case '*':
			return 2;
		default:
			throw 42;
	}
}

double StringToFloat(AnsiString s){
	if(s.IsEmpty()) return 0.0;
	for(int i = 1; i <= s.Length(); i++)
		if(s[i] == '.')
			s[i] = ',';

	double t;
	bool OK = TryStrToFloat(s, t);
	if(!OK){
		t = 0;
		Form1->ErrorInVar->Canvas->Brush->Color = clRed;
		Form1->ErrorInVar->Canvas->FloodFill(1,1,clRed,fsBorder);
		// По неизвестной мне причине любая из следующих двух строк кода вызывает необрабатываемую ошибку
		//ShowMessage("Неверное значение переменной");
		//throw 42;
	}
	return t;
}

double GetVarValue(char x){
	double t = 0;
	switch(x){
		case 'a':
			t = StringToFloat(Form1->EditA->Text);
			break;
		case 'b':
			t = StringToFloat(Form1->EditB->Text);
			break;
		case 'c':
			t = StringToFloat(Form1->EditC->Text);
			break;
		case 'd':
			t = StringToFloat(Form1->EditD->Text);
			break;
		case 'e':
			t = StringToFloat(Form1->EditE->Text);
			break;
		default:
			throw 42;
	}
	return t;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	try{
		ErrorInVar->Canvas->Brush->Color = clBtnFace;
		ErrorInVar->Canvas->FloodFill(1,1,clBtnFace,fsBorder);

		AnsiString str = "(" + Edit1->Text + ")";
		for(int i = 1; i <= str.Length(); i++)
		if(str[i] == ' '){
			str.Delete(i, 1);
			i--;
		}
		for(int i = 1; i <= str.Length(); i++)
		if((vars+opers).Pos(str[i]) == 0)
			throw 42;

		Stack<char> ex;
		Stack<char> st;
		for(int i = 1; i <= str.Length(); i++){
			if(vars.Pos(str[i]) != 0)
				ex.push_back(str[i]);
			if(opers.Pos(str[i]) != 0){
				switch(str[i]){
					case '(':
						st.push_back('(');
						break;
					case ')':
						while(st.back() != '(')
							ex.push_back(st.pop_back());
						st.pop_back();
						break;
					default:
						while(OperPrior(str[i]) <= OperPrior(st.back()))
							ex.push_back(st.pop_back());
						st.push_back(str[i]);
				}
			}
		}
		if(!st.empty()) throw 42;

		AnsiString RPN;
		ex.reverse();
		Stack<char> tmp(ex);
		while(!tmp.empty())
			RPN += tmp.pop_back();
		EditRPN->Text = RPN;

		Stack<double> s;

		while(!ex.empty()){
			if(vars.Pos(ex.back()) != 0)
				s.push_back(GetVarValue(ex.back()));
			if(opers.Pos(ex.back()) != 0){
				double t2 = s.pop_back();
				double t1 = s.pop_back();
				switch(ex.back()){
					case '+':
						s.push_back(t1 + t2);
						break;
					case '-':
						s.push_back(t1 - t2);
						break;
					case '/':
						s.push_back(t1 / t2);
						break;
					case '*':
						s.push_back(t1 * t2);
						break;
					default:
						throw 42;
				}
			}
			ex.pop_back();
		}

		if(s.empty()) throw 42;
		EditRes->Text = FloatToStr(s.pop_back());
		if(!s.empty()) throw 42;

	} catch(...) {
		EditRes->Text = "Результат вычисления";
		EditRPN->Text = "Обратная польская запись";
		ShowMessage("Неверное выражение");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Edit1->Text = "a/(b*(c+d))-e";
	EditA->Text = "8.5";
	EditB->Text = "0.3";
	EditC->Text = "2.4";
	EditD->Text = "7.9";
	EditE->Text = "1.6";
    Button1Click(Sender);
	ShowMessage("Ответ: 1.151");
}
//---------------------------------------------------------------------------
