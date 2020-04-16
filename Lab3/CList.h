//---------------------------------------------------------------------------

#ifndef CListH
#define CListH

template <class T>
class List {
	struct Vertex {
		T value;
		Vertex* prev;
		Vertex* next;

		Vertex(){
			prev = nullptr;
			next = nullptr;
		}
	};

	Vertex* Base;
	int Size = 0;

public:
	List(){
		Size = 0;
		Base = new Vertex;
		if(!Base) throw 42;
		Base->prev = Base;
		Base->next = Base;
	}
	struct iterator {
		Vertex* ptr;

		iterator(Vertex* x){
			ptr = x;
		}
		iterator(){
			ptr = nullptr;
		}

		iterator & operator ++(){
			(*this) = iterator(this->ptr->next);
			return *this;
		}

		bool operator == (const iterator & it) const {
            return this->ptr == it.ptr;
		}
		bool operator != (const iterator & it) const {
			return this->ptr != it.ptr;
		}
	};

	void clear(){
		while(begin() != end())
			pop_back();
	}
	~List(){
        clear();
        delete Base;
	}

	void push_after(const iterator & it, const T & x){
		Vertex* tmp = new Vertex();
		if(!tmp) throw 42;
		tmp->prev = it.ptr;
		tmp->value = x;
		tmp->next = it.ptr->next;
		it.ptr->next->prev = tmp;
		it.ptr->next = tmp;
		Size++;
	}
	void push_back(const T & x){
		push_after(Base->prev, x);
	}
	void push_front(const T & x){
		push_after(Base, x);
	}
	void erase(const iterator & it){
		if(it == end()) return;
		it.ptr->next->prev = it.ptr->prev;
		it.ptr->prev->next = it.ptr->next;
		delete it.ptr;
		Size--;
	}
	void pop_back(){
		erase(Base->prev);
	}
	void pop_front(){
		erase(Base->next);
	}

	iterator begin(){
		return Base->next;
	}
	iterator end(){
		return Base;
	}
	T & operator [] (const iterator & it) {
		return it.ptr->value;
	}

	int size(){
		return Size;
	}
};

//---------------------------------------------------------------------------
#endif
