//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SomeStructsAndFunctions.h"
#include "ClassMyFigure.h"
#include "ClassMyPolygon.h"
#include "ClassMyCircle.h"
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

Dot FuncCentre(ScreenWidth/2, ScreenHeight/2);
MyCircle TmpCircle;
MyFigure *TmpFigure, *CurFigure;
MyPolygon TmpPolygon;

#include <vector>
#include <math.h>
using std::vector;

const int ScreenWidth = 750;
const int ScreenHeight = 750;
#define ForAllPixels for(int x = 0; x < ScreenWidth; x++) for(int y = 0; y < ScreenHeight; y++)

vector<MyFigure*> AllFigures;

TBitmap* tmpBitmap = new TBitmap();

void FullRedraw()
{
	tmpBitmap->Canvas->Pen->Color = clWhite;
	tmpBitmap->Canvas->Brush->Color = clWhite;
	tmpBitmap->Canvas->Rectangle(0,0,ScreenWidth,ScreenHeight);

 	for(int i = 0; i < AllFigures.size(); i++)
		AllFigures[i]->Draw(tmpBitmap->Canvas);

	DrawFuncCentre(tmpBitmap->Canvas);

	Form1->PaintBox1->Canvas->CopyRect(Rect(0,0,ScreenWidth,ScreenHeight), tmpBitmap->Canvas, Rect(0,0,ScreenWidth,ScreenHeight));
}

void __fastcall TForm1::OnceUponTimer(TObject *Sender)
{
	OnceUpon->Enabled = false;
	tmpBitmap->Width = ScreenWidth;
	tmpBitmap->Height = ScreenHeight;
	FullRedraw();
}

void SetCurInfo()
{
	if(CurFigure) {
		Form1->LabelP->Caption = "Периметр = " + IntToStr(CurFigure->GetPerimeter()) + " пикс.";
		Form1->LabelS->Caption = "Площадь = " + IntToStr(CurFigure->GetArea()) + " пикс.";
		Form1->EditMassPosX->Text = IntToStr(CurFigure->GetMassCentre().x);
		Form1->EditMassPosY->Text = IntToStr(CurFigure->GetMassCentre().y);
	} else {
		Form1->LabelP->Caption = "Периметр = 0 пикс.";
		Form1->LabelS->Caption = "Площадь = 0 пикс.";
		Form1->EditMassPosX->Text = "0";
		Form1->EditMassPosY->Text = "0";
	}

	Form1->EditScale->Text = "100";
	Form1->EditRotate->Text = "0";
}

void SetCurFigure(int index)
{
	if(index < 0 || AllFigures.size() <= index) {
		CurFigure = nullptr;
	} else {
		AllFigures.push_back(AllFigures[index]);
		AllFigures.erase(AllFigures.begin() + index);
		CurFigure = AllFigures[AllFigures.size()-1];
	}

	FullRedraw();
	SetCurInfo();
}

//---------------------------------------------------------------------------

MyColor CurBorderColor = clBlack;
MyColor CurInsideColor = clTrans;

void __fastcall TForm1::BothColorChange(TObject *Sender)
{
	CurBorderColor = MyColor(StrToInt(BorderColorR->Text),StrToInt(BorderColorG->Text),StrToInt(BorderColorB->Text));

	if(InsideTrans->Checked) {
		CurInsideColor = MyColor(StrToInt(InsideColorR->Text),StrToInt(InsideColorG->Text),StrToInt(InsideColorB->Text));
	} else {
		CurInsideColor = clTrans;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonClearClick(TObject *Sender)
{
	/*
	BorderColorR->Text = "0";
	BorderColorG->Text = "0";
	BorderColorB->Text = "0";
	CurBorderColor = clBlack;
	InsideColorR->Text = "0";
	InsideColorG->Text = "0";
	InsideColorB->Text = "0";
    InsideTrans->Checked = false;
	CurInsideColor = clTrans;
    */
	/*
	Form1->PaintBox1->Canvas->Pen->Color = clWhite;
	Form1->PaintBox1->Canvas->Brush->Color = clWhite;
	Form1->PaintBox1->Canvas->Rectangle(0,0,ScreenWidth,ScreenHeight);
	*/
	ActionListChange(Sender);
	for(int i = 0; i < AllFigures.size(); i++)
		delete AllFigures[i];
	AllFigures.clear();
	CurFigure = nullptr;
	SetCurInfo();
	FuncCentre = Dot(ScreenWidth/2, ScreenHeight/2);
	FullRedraw();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PaintBox1Click(TObject *Sender)
{
	if(ActionList->Text == "Многоугольник"){
		PaintBox1->Canvas->Pen->Color = CurBorderColor;
		PaintBox1->Canvas->Pen->Width = StrToInt(BorderWidthEdit->Text);
		TPoint Pos = Normalize(PaintBox1->ScreenToClient(Mouse->CursorPos));
		if(TmpPolygon.Vrts.size() > 0 && Distance(Dot(Pos.x,Pos.y), TmpPolygon.Vrts[0]) < 10)
		{
			Timer30FPS->Enabled = false;
			PaintBox1->Canvas->LineTo(TmpPolygon.Vrts[0].x, TmpPolygon.Vrts[0].y);
			TmpPolygon.Border = CurBorderColor;
			TmpPolygon.Inside = CurInsideColor;
			TmpPolygon.BorderWidth = StrToInt(BorderWidthEdit->Text);
			MyFigure* p = new MyPolygon(TmpPolygon);
			AllFigures.push_back(p);
			SetCurFigure(AllFigures.size()-1);
			ActionListChange(Sender);
			return;
		}
		TmpPolygon.Vrts.push_back({Pos.x,Pos.y});
		if(TmpPolygon.Vrts.size() == 1)
		{
			tmpBitmap->Canvas->CopyRect(Rect(0,0,ScreenWidth,ScreenHeight), PaintBox1->Canvas, Rect(0,0,ScreenWidth,ScreenHeight));
			Timer30FPS->Enabled = true;
		}
	}
	if(ActionList->Text == "Круг"){
		TPoint Pos = Normalize(PaintBox1->ScreenToClient(Mouse->CursorPos));
		if(TmpCircle.Centre.x == -1) {
			TmpCircle.Centre = Pos;

			tmpBitmap->Canvas->CopyRect(Rect(0,0,ScreenWidth,ScreenHeight), PaintBox1->Canvas, Rect(0,0,ScreenWidth,ScreenHeight));
			Timer30FPS->Enabled = true;
		} else {
			Timer30FPS->Enabled = false;
			TmpCircle.R = Distance(TmpCircle.Centre, Pos);

			TmpCircle.Border = CurBorderColor;
			TmpCircle.Inside = CurInsideColor;
			TmpCircle.BorderWidth = StrToInt(BorderWidthEdit->Text);

			MyFigure* p = new MyCircle(TmpCircle);
			AllFigures.push_back(p);
			SetCurFigure(AllFigures.size()-1);
			ActionListChange(Sender);
		}
	}
	if(ActionList->Text == "Случайная фигура")
	{
		MyPolygon Test(rand()%5, clRand(), clRand());
		for(int i = 0; i < 3+rand()%10; i++)
			Test.Vrts.push_back(Dot(rand()%ScreenWidth, rand()%ScreenHeight));
		MyPolygon* p = new MyPolygon(Test);
		AllFigures.push_back(p);
		SetCurFigure(AllFigures.size()-1);
	}
	if(ActionList->Text == "Изменение опорной точки")
	{
		TPoint Pos = Normalize(PaintBox1->ScreenToClient(Mouse->CursorPos));
		FuncCentre = Pos;
		FullRedraw();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PaintBox1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if(ActionList->Text == "Плавноугольник")
	{
		TPoint Pos = Normalize(PaintBox1->ScreenToClient(Mouse->CursorPos));
		TmpPolygon.Vrts.clear();
		TmpPolygon.Vrts.push_back({Pos.x,Pos.y});

		TmpPolygon.Border = CurBorderColor;
		TmpPolygon.Inside = CurInsideColor;
        TmpPolygon.BorderWidth = StrToInt(BorderWidthEdit->Text);

		PaintBox1->Canvas->Pen->Width = StrToInt(BorderWidthEdit->Text);
		PaintBox1->Canvas->Pen->Color = CurBorderColor;
		PaintBox1->Canvas->MoveTo(Pos.x, Pos.y);

		Timer30FPS->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer30FPSTimer(TObject *Sender)
{
	if(ActionList->Text == "Плавноугольник")
	{
		TPoint Pos = Normalize(PaintBox1->ScreenToClient(Mouse->CursorPos));
		if(Distance(TmpPolygon.Vrts[TmpPolygon.Vrts.size()-1], Pos) > 4.2)
		{
			TmpPolygon.Vrts.push_back({Pos.x,Pos.y});
			PaintBox1->Canvas->Pen->Color = CurBorderColor;
			PaintBox1->Canvas->Pen->Width = StrToInt(BorderWidthEdit->Text);
			PaintBox1->Canvas->LineTo(Pos.x, Pos.y);
		}
	}
	if(ActionList->Text == "Многоугольник")
	{
		PaintBox1->Canvas->CopyRect(Rect(0,0,ScreenWidth,ScreenHeight), tmpBitmap->Canvas, Rect(0,0,ScreenWidth,ScreenHeight));

		PaintBox1->Canvas->Pen->Color = CurBorderColor;
		PaintBox1->Canvas->Pen->Width = StrToInt(BorderWidthEdit->Text);
		PaintBox1->Canvas->MoveTo(TmpPolygon.Vrts[0].x, TmpPolygon.Vrts[0].y);
		for(int i = 1; i < TmpPolygon.Vrts.size(); i++)
			PaintBox1->Canvas->LineTo(TmpPolygon.Vrts[i].x, TmpPolygon.Vrts[i].y);
		TPoint Pos = Normalize(PaintBox1->ScreenToClient(Mouse->CursorPos));
		PaintBox1->Canvas->LineTo(Pos.x, Pos.y);

		PaintBox1->Canvas->MoveTo(TmpPolygon.Vrts[0].x, TmpPolygon.Vrts[0].y);
		PaintBox1->Canvas->Pen->Width = 7+StrToInt(BorderWidthEdit->Text);
		PaintBox1->Canvas->LineTo(TmpPolygon.Vrts[0].x, TmpPolygon.Vrts[0].y);
		PaintBox1->Canvas->Pen->Width = StrToInt(BorderWidthEdit->Text);
	}
	if(ActionList->Text == "Круг")
	{
		TmpCircle.Border = CurBorderColor;
		TmpCircle.Inside = CurInsideColor;
		TmpCircle.BorderWidth = StrToInt(BorderWidthEdit->Text);

		TPoint Pos = Normalize(PaintBox1->ScreenToClient(Mouse->CursorPos));
		TmpCircle.R = Distance(TmpCircle.Centre, Pos);

		PaintBox1->Canvas->CopyRect(Rect(0,0,ScreenWidth,ScreenHeight), tmpBitmap->Canvas, Rect(0,0,ScreenWidth,ScreenHeight));
		TmpCircle.Draw(PaintBox1->Canvas);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PaintBox1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if(ActionList->Text == "Плавноугольник")
	{
		Timer30FPS->Enabled = false;
		PaintBox1->Canvas->LineTo(TmpPolygon.Vrts[0].x, TmpPolygon.Vrts[0].y);
		TmpPolygon.Border = CurBorderColor;
		TmpPolygon.Inside = CurInsideColor;
		TmpPolygon.BorderWidth = StrToInt(BorderWidthEdit->Text);
		MyFigure* p = new MyPolygon(TmpPolygon);
		AllFigures.push_back(p);
		SetCurFigure(AllFigures.size()-1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonChangeClick(TObject *Sender)
{
	if(CurFigure)
	{
		TBitmap* baseBitmap = new TBitmap();
		baseBitmap->Width = ScreenWidth;
		baseBitmap->Height = ScreenHeight;

		baseBitmap->Canvas->Pen->Color = clWhite;
		baseBitmap->Canvas->Brush->Color = clWhite;
		baseBitmap->Canvas->Rectangle(0,0,ScreenWidth,ScreenHeight);
		for(int i = 0; i < AllFigures.size(); i++)
			if(CurFigure != AllFigures[i])
				AllFigures[i]->Draw(baseBitmap->Canvas);

		CurFigure->SetMassCentre({StrToInt(EditMassPosX->Text), StrToInt(EditMassPosY->Text)});

		int NewScale = StrToInt(EditScale->Text);
		int NewRotate = StrToInt(EditRotate->Text);

		TmpFigure = CurFigure;
		CurFigure = TmpFigure->CreateCopy();
		int CurScale = 100;
		while (CurScale != NewScale)
		{
			CurScale += ((CurScale < NewScale) ? 1 : -1);

			if(CurFigure) delete CurFigure;
			CurFigure = TmpFigure->CreateCopy();

			CurFigure->Scale(CurScale);

			tmpBitmap->Canvas->CopyRect(Rect(0,0,ScreenWidth,ScreenHeight), baseBitmap->Canvas, Rect(0,0,ScreenWidth,ScreenHeight));
			CurFigure->Draw(tmpBitmap->Canvas);
			DrawFuncCentre(tmpBitmap->Canvas);
			Form1->PaintBox1->Canvas->CopyRect(Rect(0,0,ScreenWidth,ScreenHeight), tmpBitmap->Canvas, Rect(0,0,ScreenWidth,ScreenHeight));

		}
		delete TmpFigure;

		TmpFigure = CurFigure;
		CurFigure = TmpFigure->CreateCopy();
		int CurRotate = 0;
		while (CurRotate != NewRotate)
		{
			CurRotate += ((CurRotate < NewRotate) ? 1 : -1);

			if(CurFigure) delete CurFigure;
			CurFigure = TmpFigure->CreateCopy();

			CurFigure->Rotate(CurRotate);

			tmpBitmap->Canvas->CopyRect(Rect(0,0,ScreenWidth,ScreenHeight), baseBitmap->Canvas, Rect(0,0,ScreenWidth,ScreenHeight));
			CurFigure->Draw(tmpBitmap->Canvas);
			DrawFuncCentre(tmpBitmap->Canvas);
			Form1->PaintBox1->Canvas->CopyRect(Rect(0,0,ScreenWidth,ScreenHeight), tmpBitmap->Canvas, Rect(0,0,ScreenWidth,ScreenHeight));
		}
		delete TmpFigure;

		delete baseBitmap;
	}
	FullRedraw();
	SetCurInfo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ActionListChange(TObject *Sender)
{
	Timer30FPS->Enabled = false;
	TmpPolygon.Vrts.clear();
	TmpPolygon.Border = clBlack;
	TmpPolygon.Inside = clTrans;
	TmpCircle.Centre = Dot(-1,-1);
	TmpCircle.R = 0;
	PaintBox1->Canvas->Pen->Width = 1;
	PaintBox1->Canvas->Pen->Color = clBlack;
	FullRedraw();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(CurFigure){
		int delta = (Shift.Contains(ssShift) ? 10 : 1);
		switch(Key){
			case VK_UP:
				CurFigure->Move(0,-delta);
				break;
			case VK_DOWN:
				CurFigure->Move(0,delta);
				break;
			case VK_LEFT:
				CurFigure->Move(-delta,0);
				break;
			case VK_RIGHT:
				CurFigure->Move(delta,0);
				break;
		}
		FullRedraw();
		SetCurInfo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonChangeCurClick(TObject *Sender)
{
	SetCurFigure(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int index;
	for(index = 0; index < AllFigures.size(); index++)
		if(AllFigures[index] == CurFigure)
			break;
	if(index < AllFigures.size()){
        delete AllFigures[index];
		AllFigures.erase(AllFigures.begin() + index);
	}
	if(index == AllFigures.size()) index--;
	SetCurFigure(index);
}
//---------------------------------------------------------------------------

