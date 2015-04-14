#include "MinHeap.h"

template<typename T>
class PriorityQueue
{
public:
	void push(T item)
	{
		q.insert(item);
	}
		
	T top() const
	{
		return q.peek();
	}

	void pop() const
	{
		q.remove();
	}

	bool isEmpty() const
	{
		return q.isEmpty();
	}

private:
	MinHeap<T> q;
