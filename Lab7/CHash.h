// ---------------------------------------------------------------------------

#include "CList.h"

#ifndef CHashH
#define CHashH

template<class T>
class Hash {
protected:
	int TableSize;
	List<T> *Table;

	int(*HashFunc)(const T & x);

	int GetHash(const T & x) {
		return ((HashFunc(x) % TableSize) + TableSize) % TableSize;
	}

public:
	Hash(int tableSize, int(*hashFunc)(const T&)) {
		HashFunc = hashFunc;
		TableSize = tableSize;
		Table = new List<T>[TableSize];
		if (!Table)
			throw;
	}

	void clear() {
		for (int i = 0; i < TableSize; i++)
			Table[i].clear();
	}

	~Hash() {
		clear();
		delete[]Table;
	}

	void insert(const T & x) {
		int index = GetHash(x);
		Table[index].push_back(x);
	}

	void erase(const T & x) {
		int index = GetHash(x);
		for (auto it = Table[index].begin(); it != Table[index].end(); ++it)
			if (x == Table[index][it]) {
				Table[index].erase(it);
				return;
			}
	}

	bool contain(const T & x) {
		int index = GetHash(x);
		for (auto it = Table[index].begin(); it != Table[index].end(); ++it)
			if (x == Table[index][it])
				return true;
		return false;
	}
};

// ---------------------------------------------------------------------------
#endif
