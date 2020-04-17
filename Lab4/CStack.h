//---------------------------------------------------------------------------

#ifndef CStackH
#define CStackH

template <class T>
class Stack{
	struct Vertex{
		T value;
		Vertex* prev;
	};
	Vertex* CurVrt;

public:
	Stack(){
		CurVrt = nullptr;
	}
	Stack(const T & x){
		CurVrt = nullptr;
		Vertex* it = x.CurVrt;
		while(it != nullptr){
			this->push_back(it->value);
			it = it->prev;
		}
		this->reverse();
	}

	void push_back(const T & x){
		Vertex* tmp = new Vertex;
		if(!tmp){
            ShowMessage("Ошибка выделения памяти");
			throw 42;
		}
		tmp->value = x;
		tmp->prev = CurVrt;
		CurVrt = tmp;
	}
	T& back(){
		if(empty()) throw 42;
		return CurVrt->value;
	}
	T pop_back(){
		if(empty()) throw 42;
		T rtrn = back();
		Vertex* del = CurVrt;
		CurVrt = CurVrt->prev;
		delete del;
		return rtrn;
	}

	void reverse(){
		Vertex* last = nullptr;
		Vertex* it = CurVrt;
		while(it != nullptr){
			Vertex* next = it->prev;
			it->prev = last;
			last = it;
			it = next;
		}
		CurVrt = last;
	}

	bool empty(){
        return (CurVrt == nullptr);
	}
	void clear(){
		while(!empty())
			pop_back();
	}
	~Stack(){
		clear();
	}
};

//---------------------------------------------------------------------------
#endif
