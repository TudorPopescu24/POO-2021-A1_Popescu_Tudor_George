class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) {
		int* e1_int = static_cast<int*>(e1);
		int* e2_int = static_cast<int*>(e2);
		return *e1_int - *e2_int;
	}
};

template<class T>
class ArrayIterator
{
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
	T* Element;
public:
	ArrayIterator(int Value) {
		Current = Value;
	}
	ArrayIterator& operator++ () {
		Current++;
	}
	ArrayIterator& operator-- () {
		Current--;
	}
	bool operator= (ArrayIterator<T>& ArrIt) {
		Current = ArrIt.Current;
		return true;
	}
	bool operator!=(ArrayIterator<T>& ArrIt) {
		if (Current != ArrIt.Current) return true;
		return false;
	}
	T* GetElement() {
		return Element;
	}
};

template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista

public:
	Array() {
		Capacity = 0;
		Size = 0;
		List = nullptr;
	}
	~Array() {
		delete[] List;
	}
	Array(int capacity) {
		if (capacity < 0)
			throw "Error: Capacity cannot be smaller then 0. [Array(int capacity) constructor]";
		Capacity = capacity;
		Size = 0;
		List = new T * [capacity];
		for (int i = 0; i < capacity; i++)
			List[i] = new T;
	}
	Array(const Array<T>& otherArray) {
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		List = new T * [Capacity];
		for (int i = 0; i < otherArray.Capacity; i++) {
			List[i] = new T;
			*List[i] = otherArray[i];
		}
	}

	// arunca exceptie daca index este out of range
	T& operator[] (int index) {
		if (index < 0 || index > Size)
			throw "Error: index is out of range. [Operator[]]";
		return *(List[index]);
	}

	// adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& operator+=(const T& newElem) {
		if (Size == Capacity)
			Capacity = Capacity * 2;
		*(List[Size++]) = newElem;
		return *this;
	}

	// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const T& newElem) {
		if (index < 0 || index > Size)
			throw "Error: index is out of range. [Insert(int index, const T& newElem) method]";
		for (int i = Capacity - 1; i > index; i--)
			*List[i] = *List[i - 1];

		*List[index] = newElem;

		if (Size == Capacity)
			Capacity = Capacity * 2;
	}

	// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray) {
		if (index < 0 || index > Size)
			throw "Error: index out of bounds. [3]";
	}

	// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index) {
		if (index < 0 || index > Size)
			throw "Error: index is out of range. [Delete(int index) method]";
		for (int i = index; i < Size - 1; i++)
			*List[i] = *List[i + 1];
		Size--;
	}

	bool operator=(const Array<T>& otherArray) {
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		for (int i = 0; i < Capacity; i++)
			*List[i] = *otherArray.List[i];
		return true;
	}

	// sorteaza folosind comparatia intre elementele din T
	void Sort() {
		T aux;
		for (int i = 0; i< Size - 1; i++)
			for (int j = 0; j < Size - i - 1; j++) {
				if (*List[j] > *List[j + 1]) {
					aux = *List[j];
					*List[j] = *List[j + 1];
					*List[j + 1] = aux;
				}
			}
	}

	// sorteaza folosind o functie de comparatie
	void Sort(int(*compare)(const T&, const T&)) {
		if (compare == nullptr)
			throw "Error: Invalid compare function. [Sort(int(*compare)(const T&, const T&)) method]";
		T aux;
		for (int i = 0; i < Size - 1; i++)
			for (int j = 0; j < Size - i - 1; j++) {
				if (compare(*List[j], *List[j + 1]) > 0) {
					aux = *List[j];
					*List[j] = *List[j + 1];
					*List[j + 1] = aux;
				}
			}
	}

	// sorteaza folosind un obiect de comparatie
	void Sort(Compare* comparator) {
		if (comparator == nullptr)
			throw "Error: Invalid compare function. [Sort(int(*compare)(const T&, const T&)) method]";
		T aux;
		for (int i = 0; i < Size - 1; i++)
			for (int j = 0; j < Size - i - 1; j++) {
				if (compare(*List[j], *List[j + 1]) > 0) {
					aux = *List[j];
					*List[j] = *List[j + 1];
					*List[j + 1] = aux;
				}
			}
	}

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator

	int Find(const T& elem); // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

	int GetSize();
	int GetCapacity();

	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();
};