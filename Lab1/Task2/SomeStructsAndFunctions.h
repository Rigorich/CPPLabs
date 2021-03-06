//---------------------------------------------------------------------------

#ifndef SomeStructsAndFunctionsH
#define SomeStructsAndFunctionsH
//---------------------------------------------------------------------------

extern const int ScreenWidth;
extern const int ScreenHeight;
#define ForAllPixels for(int x = 0; x < ScreenWidth; x++) for(int y = 0; y < ScreenHeight; y++)
		   /*
template <class U, class V>
U min(const U & a, const V & b){
	if(a > b) return b;
	return a;
}
template <class U, class V>
U max(const U & a, const V & b){
	if(a < b) return b;
	return a;
}         */
template <class T>
void swap(T & a, T & b){
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

double sqr(double x){
	return x*x;
}

double Div(long long a, long long b){
	if(!a || !b) return 0.0;
	return (double)a / b;
}

#define PI acos(-1)


struct Dot{
	int x;
	int y;
	Dot(){
		x = 0;
		y = 0;
	}
	Dot(int xCoord, int yCoord){
		x = xCoord;
		y = yCoord;
	}
	Dot(const TPoint & a){
		x = a.x;
		y = a.y;
	}
	operator TPoint() const {
		TPoint tmp;
		tmp.x = x;
		tmp.y = y;
		return tmp;
	}
	Dot & operator = (const TPoint & pnt)
	{
		x = pnt.x;
		y = pnt.y;
		return *this;
	}
};

extern Dot FuncCentre;

void DrawFuncCentre(TCanvas* canvas){
	canvas->MoveTo(FuncCentre.x, FuncCentre.y);
	canvas->Pen->Width = 7;
	canvas->Pen->Color = clWhite;
	canvas->LineTo(FuncCentre.x, FuncCentre.y);
	canvas->Pen->Width = 5;
	canvas->Pen->Color = clBlack;
	canvas->LineTo(FuncCentre.x, FuncCentre.y);
	canvas->Pen->Width = 3;
	canvas->Pen->Color = clWhite;
	canvas->LineTo(FuncCentre.x, FuncCentre.y);
}

double Distance(const Dot & a, const Dot & b){
	return sqrtl(sqr(a.x-b.x)+sqr(a.y-b.y));
}

TPoint Normalize(TPoint Pos){
	Pos.x = max(Pos.x, 0);
	Pos.x = min(Pos.x, ScreenWidth);
	Pos.y = max(Pos.y, 0);
	Pos.y = min(Pos.y, ScreenHeight);
	return Pos;
}

Dot Normalize(Dot Pos){
	Pos.x = max(Pos.x, 0);
	Pos.x = min(Pos.x, ScreenWidth);
	Pos.y = max(Pos.y, 0);
	Pos.y = min(Pos.y, ScreenHeight);
	return Pos;
}


struct MyColor{
	unsigned char R = 255, G = 255, B = 255;
	bool Clear = true;

	operator TColor() const {
		if (!Clear)
			return (TColor)(RGB(R,G,B));
		return (TColor)(RGB(255,255,255));
	}
	MyColor & operator = (const TColor & clr)
	{
		R = GetRValue(clr);
		G = GetGValue(clr);
		B = GetBValue(clr);
		Clear = false;
		return *this;
	}
	MyColor(){
		this->R = 255;
		this->G = 255;
		this->B = 255;
		this->Clear = true;
	}
	MyColor(int R, int G, int B){
		this->R = max(0, min(255, R));
		this->G = max(0, min(255, G));
		this->B = max(0, min(255, B));
		this->Clear = false;
	}
	MyColor(const TColor & clr){
		R = GetRValue(clr);
		G = GetGValue(clr);
		B = GetBValue(clr);
		Clear = false;
	}
	bool operator == (const MyColor & clr){
		if(R != clr.R) return false;
		if(G != clr.G) return false;
		if(B != clr.B) return false;
		if(Clear != clr.Clear) return false;
        return true;
	}
} const clTrans;

MyColor clRand(){
	srand(rand()+time(0));
	return MyColor(rand()%256, rand()%256, rand()%256);
}


template <class T>
struct PixelMap{
	T** Pixel;
	PixelMap() {
		Pixel = new T* [ScreenWidth];
		for(int i = 0; i < ScreenWidth; i++)
			Pixel[i] = new T[ScreenHeight];
	}
	~PixelMap() {
		for(int i = 0; i < ScreenWidth; i++)
			delete Pixel[i];
		delete Pixel;
	}

	T*& operator [] (const int i) {
		return Pixel[i];
    }
};


#endif
