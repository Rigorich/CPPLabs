// ---------------------------------------------------------------------------

#ifndef CListH
#define CListH

template<class T>
class List {
protected:
	struct Vertex {
		T value;
		Vertex* prev;
		Vertex* next;

		Vertex() {
			prev = nullptr;
			next = nullptr;
		}
	};

	Vertex* Base;

public:
	List() {
		Base = new Vertex;
		if (!Base)
			throw 42;
		Base->prev = Base;
		Base->next = Base;
	}

	struct iterator {
		Vertex* ptr;

		iterator(Vertex* x) {
			ptr = x;
		}

		iterator() {
			ptr = nullptr;
		}

		iterator & operator++() {
			(*this) = iterator(this->ptr->next);
			return *this;
		}

		iterator & operator--() {
			(*this) = iterator(this->ptr->prev);
			return *this;
		}

		bool operator == (const iterator & it) const {
			return this->ptr == it.ptr;
		}

		bool operator != (const iterator & it) const {
			return this->ptr != it.ptr;
		}

	};

	void clear() {
		while (begin() != end())
			pop_back();
	}

	~List() {
		clear();
		delete Base;
	}

	void push_after(const iterator & it, const T & x) {
		Vertex* tmp = new Vertex();
		if (!tmp)
			throw 42;
		tmp->prev = it.ptr;
		tmp->value = x;
		tmp->next = it.ptr->next;
		it.ptr->next->prev = tmp;
		it.ptr->next = tmp;
	}

	void push_back(const T & x) {
		push_after(Base->prev, x);
	}

	void push_front(const T & x) {
		push_after(Base, x);
	}

	T erase(const iterator & it) {
		if (it == end())
			throw 42;
		it.ptr->next->prev = it.ptr->prev;
		it.ptr->prev->next = it.ptr->next;
		T rtrn = it.ptr->value;
		delete it.ptr;
		return rtrn;
	}

	T pop_back() {
		return erase(Base->prev);
	}

	T pop_front() {
		return erase(Base->next);
	}

	T & back() {
		return Base->prev->value;
	}

	T & front() {
		return Base->next->value;
	}

	iterator begin() {
		return Base->next;
	}

	iterator last() {
		return Base->prev;
	}

	iterator end() {
		return Base;
	}

	T & operator[](const iterator & it) {
		return it.ptr->value;
	}
};

// ---------------------------------------------------------------------------
#endif
