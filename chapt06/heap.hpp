#ifndef __HEAP__HPP
#define __HEAP__HPP

template <typename T>
class Heap {
public:
	Heap(T v[],int size);
	void remove();
private:
	void max_heapify(int i);
	int size;
	T * data;
};

#endif
