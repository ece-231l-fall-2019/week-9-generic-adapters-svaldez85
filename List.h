#ifndef __EE231_List_h__
#define __EE231_List_h__

#include <cstddef>

template<typename T>
class List
{
	private:

	typedef struct llist {
		T val;
		struct llist *next;
	} llist;

	llist *_data;
	size_t _size;

	// private recursive copy so elements
	// end up in the same order.
	void reccopy(const llist *ptr)
	{
		if (ptr)
		{
			reccopy(ptr->next);
			push_front(ptr->val);
		}
	}

	public:
	
	// default constructor
	List()
	{
		_data = 0;
		_size = 0;
	}

	// copy constructor
	List(const List& other)
	{
		_data = 0;
		_size = 0;
		reccopy(other._data);
	}

	// destructor
	~List()
	{
		clear();
	}

	// copy operator
	List& operator=(const List& other)
	{
		reccopy(other._data);
		return *this;
	}

	void clear()
	{
		while(!empty())
			pop_front();
	}

	T& front()
	{
		return _data->val;
	}

	const T& front() const
	{
		return _data->val;
	}

	void push_front(const T& val)
	{
		llist *newItem = new llist;
		newItem->val = val;
		newItem->next = _data;
		_data = newItem;
		_size++;
	}

	void pop_front()
	{
		llist *front = _data;
		if (front)
		{
			_data = front->next;
			delete front;
			_size--;
		}
	}

	bool empty() const
	{
		return _data == 0;
	}

	size_t size() const
	{
		return _size;
	}
};

#endif // __EE231_List_h__
