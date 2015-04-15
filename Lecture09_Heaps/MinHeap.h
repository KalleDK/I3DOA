#include <vector>
#include <iostream>

using namespace std;

//==================================================
// CLASS MinHeap
//==================================================
template<typename T>
class MinHeap
{
public:

	MinHeap() {}

	MinHeap(const vector<T>& ar)
	{
		heap = ar;
		size_t start = parent(heap.size()-1);
		for (size_t i = start; i > 0; --i) {
			percolateDown(i);
		}
		percolateDown(0);
	}

	void print() const
	{
		for(auto it = heap.begin(); it != heap.end(); ++it)
			cout << *it << " ";
		cout << endl;
	}

	// PRE	: -
	// POST	: If the heap is a true heap, true is returned. 
	//		  Otherwise, false is returned
	bool isHeap() const
	{
		for(size_t i=0; i< (heap.size()-1)/2; i++)
		{
			if(smallest(i) != i) return false;
		}
		return true;
	}

	void insert(T item)
	{
		heap.push_back(item);
		percolateUp(heap.size()-1);
	}

	void remove()
	{
		swap(0, heap.size()-1);
		heap.pop_back();
		percolateDown(0);
	}
		

	bool isEmpty() const
	{
		return heap.size() == 0;
	}

	T peek() const
	{
		return heap[0];
	}

private:
	vector<T> heap;

	size_t right(size_t i) const
	{
		return (i+1)*2;
	}

	size_t left(size_t i) const
	{
		return (i*2)+1;
	}

	size_t parent(size_t i) const
	{
		return (i-1)/2;
	}

		

	// PRE	: 0 <= i < heap.size()
	// POST	: Returns the index of the smallest of element i and its two children
	size_t smallest(size_t i) const	// returns index of smallest of i and its parents
	{
		size_t small = i;
	
		if(	left(i)  < heap.size() && 
			heap[i]> heap[left(i)]) 
			small = left(i);
		
		if(	right(i) < heap.size() && 
			heap[i]> heap[right(i)] && 
			heap[right(i)]< heap[left(i)] ) 
			small = right(i);

		return small;
	}

	// PRE	: 0 <= {x, y} < heap.size()
	// POST	: Elements with indices x and y are swapped
	void swap(size_t x, size_t y) 
	{ 
		T temp = heap[x]; 
		heap[x]=heap[y]; 
		heap[y]=temp;
	}

	void percolateUp(size_t i)
	{
		if (i == 0)
			return;

		if (heap[i] < heap[parent(i)]) {
			swap(i, parent(i));
			percolateUp(parent(i));
		}
	}

	void percolateDown(size_t i)
	{
		size_t small = smallest(i);
		if (i != small) {
			swap(i, small);
			percolateDown(small);
		}
	}

	
};

