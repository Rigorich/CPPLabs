//---------------------------------------------------------------------------
#ifndef ClassMyPolygonH
#define ClassMyPolygonH

//---------------------------------------------------------------------------

#include <vector>
#include <math.h>
using std::vector;

class MyPolygon : public MyFigure {
	private:
		Dot MassCentre;
		int Area = 0;
		int Perimeter = 0;

		void GetFigureMap(){

			double tmpPerimeter = 0.0;
			for (int i = 0; i < Vrts.size(); i++)
				tmpPerimeter += Distance( Vrts[fori(i)] , Vrts[fori(i+1)] );
			Perimeter = round(tmpPerimeter);

			PixelMap<int> tmp;
			ForAllPixels {
				tmp[x][y] = 0;
			}

			int MinY = Vrts[0].y;
			for(int i = 0; i < Vrts.size(); i++)
				MinY = min(MinY, Vrts[i].y);
			for(int i = 0; i < Vrts.size(); i++) {
				Dot D1 = Vrts[fori(i)], D2 = Vrts[fori(i+1)];
				int add = (D1.x < D2.x) ? 1 : -1;
				if(add == -1){
					swap(D1, D2);
				}
				for(int x = max(0, D1.x); x < min(ScreenWidth, D2.x); x++)
				if(D1.x != D2.x) {
					int MaxY = D1.y + (D2.y-D1.y) * Div(x-D1.x, D2.x-D1.x);
					for(int y = max(0, MinY); y < min(ScreenHeight, MaxY); y++){
						tmp[x][y] += add;
					}
				}
			}

			long long SummX = 0, SummY = 0;
			Area = 0;
			ForAllPixels {
				if(tmp[x][y]){
					Area++;
					SummX += x;
					SummY += y;
				}
			}

			MassCentre.x = round(Div(SummX, Area));
			MassCentre.y = round(Div(SummY, Area));
		}

		int fori(int i){
			while(i < 0){
				i += Vrts.size();
			}
			while(i >= Vrts.size()){
				i -= Vrts.size();
			}
			return i;
		}

	public:
		vector<Dot> Vrts;

		void Draw(TCanvas* canvas) override
		{
			GetFigureMap();

			canvas->Pen->Width = BorderWidth;
			canvas->Pen->Color = Border;
			if(Inside == clTrans){
				canvas->MoveTo(Vrts[fori(-1)].x, Vrts[fori(-1)].y);
				for(int i = 0; i < Vrts.size(); i++)
					canvas->LineTo(Vrts[i].x, Vrts[i].y);
			} else {
				vector<TPoint> temp;
				for(int i = 0; i < Vrts.size(); i++)
					temp.push_back(Vrts[i]);
				canvas->Brush->Color = Inside;
				canvas->Polygon(&(temp[0]), temp.size() - 1);
			}

			if(MassCentre.x && MassCentre.y){
				canvas->MoveTo(MassCentre.x, MassCentre.y);
				canvas->Pen->Width = 5;
				canvas->Pen->Color = clBlack;
				canvas->LineTo(MassCentre.x, MassCentre.y);
				canvas->Pen->Width = 3;
				canvas->Pen->Color = clRed;
				canvas->LineTo(MassCentre.x, MassCentre.y);
			}
		}
		void Move(int dx, int dy) override
		{
			for(int i = 0; i < Vrts.size(); i++)
				Vrts[i] = Dot(Vrts[i].x + dx, Vrts[i].y + dy);
		}
		void Rotate(int angle) override
		{
			double a = Div(angle,180)*PI;
			for(int i = 0; i < Vrts.size(); i++){
				int x = Vrts[i].x, y = Vrts[i].y,
					x0 = FuncCentre.x, y0 = FuncCentre.y;
				Vrts[i].x = x0 + (x - x0) * cos(a) - (y - y0) * sin(a);
				Vrts[i].y = y0 + (y - y0) * cos(a) + (x - x0) * sin(a);
			}
		}
		void Scale(int percentage) override
		{
			double scl = (double)percentage / 100;
			for(int i = 0; i < Vrts.size(); i++)
				Vrts[i].x = FuncCentre.x + (int)round((Vrts[i].x-FuncCentre.x) * scl),
				Vrts[i].y = FuncCentre.y + (int)round((Vrts[i].y-FuncCentre.y) * scl);
		}

		Dot GetMassCentre() override
		{
			return MassCentre;
		}
		void SetMassCentre(Dot where) override
		{
			Move(where.x - MassCentre.x, where.y - MassCentre.y);
			MassCentre = where;
		}

		int GetArea() override
		{
			return Area;
		}
		int GetPerimeter() override
		{
			return Perimeter;
		}

		MyFigure* CreateCopy() override
		{
			MyFigure* p = new MyPolygon(*this);
            return p;
		}

		MyPolygon(const MyPolygon & base){
			Vrts = base.Vrts;
			Border = base.Border;
			Inside = base.Inside;
			BorderWidth = base.BorderWidth;
		}
		MyPolygon(int width, MyColor border, MyColor inside){
			BorderWidth = width;
			Border = border;
			Inside = inside;
		}
		MyPolygon(int width, MyColor border): MyPolygon(width, border, clTrans) { }
		MyPolygon(int width): MyPolygon(width, MyColor(clBlack), clTrans) { }
		MyPolygon(): MyPolygon(2, MyColor(clBlack), clTrans) { }
};

//---------------------------------------------------------------------------
#endif
