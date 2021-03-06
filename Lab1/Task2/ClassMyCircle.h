//---------------------------------------------------------------------------
#ifndef ClassMyCircleH
#define ClassMyCircleH
//---------------------------------------------------------------------------

#include "ClassMyFigure.h"

#include <math.h>

class MyCircle : public MyFigure {
	public:
		int R;
		Dot Centre;

		void Draw(TCanvas* canvas) override
		{
			canvas->Pen->Width = BorderWidth;
			canvas->Pen->Color = Border;
			canvas->Brush->Color = Inside;
			canvas->Ellipse(Centre.x-R, Centre.y-R, Centre.x+R, Centre.y+R);

			canvas->MoveTo(Centre.x, Centre.y);
			canvas->Pen->Width = 5;
			canvas->Pen->Color = clBlack;
			canvas->LineTo(Centre.x, Centre.y);
			canvas->Pen->Width = 3;
			canvas->Pen->Color = clRed;
			canvas->LineTo(Centre.x, Centre.y);
		}
		void Move(int dx, int dy) override
		{
			Centre.x += dx;
			Centre.y += dy;
		}
		void Rotate(int angle) override
		{
			double a = Div(angle,180)*PI;
			int x = Centre.x, y = Centre.y,
				x0 = FuncCentre.x, y0 = FuncCentre.y;
			Centre.x = x0 + (x - x0) * cos(a) - (y - y0) * sin(a);
			Centre.y = y0 + (y - y0) * cos(a) + (x - x0) * sin(a);
		}
		void Scale(int percentage) override
		{
			double scl = (double)percentage / 100;
			R = (int)round(R * scl);
			Centre.x = FuncCentre.x + (int)round((Centre.x-FuncCentre.x) * scl),
			Centre.y = FuncCentre.y + (int)round((Centre.y-FuncCentre.y) * scl);
		}

		Dot GetMassCentre() override
		{
			return Centre;
		}
		void SetMassCentre(Dot where) override
		{
			Move(where.x - Centre.x, where.y - Centre.y);
		}

		int GetArea() override
		{
			return PI*R*R;
		}
		int GetPerimeter() override
		{
			return 2*PI*R;
		}

		MyFigure* CreateCopy() override
		{
			MyFigure* p = new MyCircle(*this);
            return p;
		}

		MyCircle(const MyCircle & base){
			R = base.R;
			Centre = base.Centre;
			Border = base.Border;
			Inside = base.Inside;
			BorderWidth = base.BorderWidth;
		}
		MyCircle(int width, MyColor border, MyColor inside){
			BorderWidth = width;
			Border = border;
			Inside = inside;
		}
		MyCircle(int width, MyColor border): MyCircle(width, border, clTrans) { }
		MyCircle(int width): MyCircle(width, MyColor(clBlack), clTrans) { }
		MyCircle(): MyCircle(2, MyColor(clBlack), clTrans) { }
};

//---------------------------------------------------------------------------

#endif