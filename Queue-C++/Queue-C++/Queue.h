#pragma

#include <iostream>
#include <deque>

using namespace std;

template<class T,class Container = deque<T>>
class Queue
{
public:
	void Push(const T& x)
	{
		_con.push_back(x);
	}

	void Pop()
	{
		_con.pop_front();
	}

	bool Empty()
	{
		return _con.empty();
	}

	size_t Size()
	{
		return _con.size();
	}

	T& Front()
	{
		return _con.front();
	}
private:
	Container _con;
};

void TestQueue()
{
	Queue<int>q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);

	cout << q.Size() << endl;
	while (!q.Empty())
	{
		cout << q.Front() << " ";
		q.Pop();
	}
	cout << endl;
}