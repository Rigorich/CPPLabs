//---------------------------------------------------------------------------
#ifndef ClassMyFigureH
#define ClassMyFigureH
//---------------------------------------------------------------------------

#include "SomeStructsAndFunctions.h"

class MyFigure{

	public:

		MyColor Border;
		MyColor Inside;
		int BorderWidth;

		virtual void Draw(TCanvas* canvas) = 0;
		virtual Dot GetMassCentre() = 0;
		virtual void SetMassCentre(Dot where) = 0;
		virtual int GetArea() = 0;
		virtual int GetPerimeter() = 0;
		virtual void Move(int dx, int dy) = 0;
		virtual void Rotate(int angle) = 0;
		virtual void Scale(int percentage) = 0;
		virtual MyFigure* CreateCopy() = 0;
        //virtual ~MyFigure() = 0;

};


#endif
