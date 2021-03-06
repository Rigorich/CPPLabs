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

TBitmap* tmp = new TBitmap();

//---------------------------------------------------------------------------

double DegToRad(int x){
	return ((double)x)/180*acos(-1);
}

double dsin(int x){
	return sin(DegToRad(x));
}
double dcos(int x){
	return cos(DegToRad(x));
}

class MyRectangle{
	public:
		int xpos, ypos;
		int width, height;
		int angle;

		MyRectangle(int x, int y, int w, int h, int a = 0){
			xpos = x; ypos = y;
			width = w; height = h;
			angle = a;
		}
		MyRectangle(){
			MyRectangle(0,0,0,0,0);
		}

		void Show(){
			int tx, ty;
			tmp->Canvas->MoveTo(xpos,ypos);
			tx = xpos, ty = ypos;
			tx += round(width * dcos(angle)), ty -= round(width * dsin(angle));
			tmp->Canvas->LineTo(tx,ty);
			tx += round(height * dsin(angle)), ty += round(height * dcos(angle));
			tmp->Canvas->LineTo(tx,ty);
			tmp->Canvas->MoveTo(xpos,ypos);
            tx = xpos, ty = ypos;
			tx += round(height * dsin(angle)), ty += round(height * dcos(angle));
			tmp->Canvas->LineTo(tx,ty);
			tx += round(width * dcos(angle)), ty -= round(width * dsin(angle));
			tmp->Canvas->LineTo(tx,ty);
		}
		void Fill(){
			int tx = xpos, ty = ypos;
			tx += round(width * dcos(angle)), ty -= round(width * dsin(angle));
			tx += round(height * dsin(angle)), ty += round(height * dcos(angle));
			tmp->Canvas->FloodFill((xpos+tx)/2,(ypos+ty)/2,tmp->Canvas->Pixels[(xpos+tx)/2][(ypos+ty)/2],fsSurface);
		}
		void Move(int dx, int dy){
			xpos += dx;
			ypos += dy;
		}
};

class MyFlagman : public MyRectangle{

	public:
		int LineWidth = 10;
		int LeftHandAngle, RightHandAngle;
		MyRectangle TempFlag;
		int FlagWidth = 30, FlagHeight = 60;

		using MyRectangle::MyRectangle;

	private:
		void ShowFlag(int xbegin, int ybegin, int flagangle, bool reflect = false){
			TempFlag.width = FlagWidth;
			TempFlag.height = FlagHeight;
			TempFlag.xpos = xbegin - reflect * TempFlag.width*dcos(flagangle);
			TempFlag.ypos = ybegin + reflect * TempFlag.width*dsin(flagangle);
			TempFlag.angle = flagangle;
			tmp->Canvas->Pen->Color = clBlack;
			tmp->Canvas->Pen->Width = 3;
			TempFlag.Show();
			tmp->Canvas->Brush->Color = clRed;
			TempFlag.Fill();
		}
		void ShowHand(int xbegin, int ybegin, int handangle){
			tmp->Canvas->Pen->Color = clBlack;
			tmp->Canvas->Pen->Width = LineWidth;
			tmp->Canvas->MoveTo(xbegin, ybegin);
			tmp->Canvas->LineTo(tmp->Canvas->PenPos.x+height*dsin(handangle), tmp->Canvas->PenPos.y+height*dcos(handangle));
			tmp->Canvas->Pen->Width = LineWidth*2;
			tmp->Canvas->LineTo(tmp->Canvas->PenPos.x, tmp->Canvas->PenPos.y);
			tmp->Canvas->Pen->Width = LineWidth/2;
			tmp->Canvas->Pen->Color = clMaroon;
			tmp->Canvas->LineTo(tmp->Canvas->PenPos.x+(height/2+FlagHeight)*dsin(handangle), tmp->Canvas->PenPos.y+(height/2+FlagHeight)*dcos(handangle));
			tmp->Canvas->MoveTo(tmp->Canvas->PenPos.x-FlagHeight*dsin(handangle), tmp->Canvas->PenPos.y-FlagHeight*dcos(handangle));
		}
	public:
		void Show(){
			int r = width/3;

			ShowHand(xpos+width+LineWidth, ypos, RightHandAngle);
			ShowFlag(tmp->Canvas->PenPos.x, tmp->Canvas->PenPos.y, RightHandAngle, true);

			ShowHand(xpos-LineWidth, ypos, LeftHandAngle);
			ShowFlag(tmp->Canvas->PenPos.x, tmp->Canvas->PenPos.y, LeftHandAngle);

			tmp->Canvas->Brush->Color = clWhite;
			//����
			tmp->Canvas->Pen->Width = LineWidth;
			tmp->Canvas->Pen->Color = clBlack;
			MyRectangle::Show();
			//�����
			tmp->Canvas->Pen->Width = LineWidth*2;
			tmp->Canvas->MoveTo(xpos-LineWidth/2,ypos);
			tmp->Canvas->LineTo(xpos-LineWidth/2,ypos);
			tmp->Canvas->MoveTo(xpos+width+LineWidth/2,ypos);
			tmp->Canvas->LineTo(xpos+width+LineWidth/2,ypos);
			//������
			tmp->Canvas->Pen->Width = LineWidth;
			tmp->Canvas->Ellipse(xpos+width/2-r,ypos-r*2,xpos+width/2+r,ypos);
			//����
			tmp->Canvas->Pen->Width = LineWidth;
			tmp->Canvas->MoveTo(xpos+r,ypos+height);
			tmp->Canvas->LineTo(xpos+r,ypos+height+height-r);
			tmp->Canvas->MoveTo(xpos+width-r,ypos+height);
			tmp->Canvas->LineTo(xpos+width-r,ypos+height+height-r);
		}

} *Test = new MyFlagman(385, 400, 100, 200, 0);
//---------------------------------------------------------------------------

void Redraw()
{
	tmp->Width = 1920;
	tmp->Height = 1080;
	tmp->Canvas->Pen->Color = clWhite;
	tmp->Canvas->Brush->Color = clWhite;
	tmp->Canvas->Rectangle(0,0,1920,1080);

	Test->Show();

	Form1->Canvas->CopyRect(Rect(0,0,1920,1080), tmp->Canvas, Rect(0,0,1920,1080));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RightHandTrackBarChange(TObject *Sender)
{
	Test->RightHandAngle = 180 - (RightHandTrackBar->Position * (180/RightHandTrackBar->Max));
	Redraw();
}

void __fastcall TForm1::LeftHandTrackBarChange(TObject *Sender)
{
	Test->LeftHandAngle = 180 - (-LeftHandTrackBar->Position * (180/LeftHandTrackBar->Max));
	Redraw();
}

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	Timer1->Enabled = false;
	LeftHandTrackBar->Position = LeftHandTrackBar->Max;
	RightHandTrackBar->Position = RightHandTrackBar->Max;
	Redraw();
}

//---------------------------------------------------------------------------

