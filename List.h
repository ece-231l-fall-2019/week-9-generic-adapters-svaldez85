#ifndef __EE231_List_h__
#define __EE231_List_h__

#include <cstddef>
/*
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
		clear();
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
};*/
template<typename T>
class List
{
	private:
	size_t _size;
	typedef struct llist {
		T value;
		struct llist *next;
		struct llist *prev;
	} llist;

	llist *_back;
	llist *_front;

	public:

	// default constructor
	void reccopy(const llist *ptr)
	{
		if (ptr)
		{
			reccopy(ptr->next);
			push_front(ptr->value);
		}
	}
	
	// default constructor
	List()
	{
		_front = nullptr;
		_back = nullptr;
		_size = 0;
	}
	// copy constructor
	List(const List& other)
	{
		_front = nullptr;
		_back = nullptr;
		_size = 0;
		reccopy(other._front);
	}
	~List()
	{
		clear();
	}
	
	// copy operator
	List& operator=(const List<T>& other)
	{
		clear();
		llist* ptr = other._front;
		while(ptr != nullptr)
		{
			push_back(ptr->value);
			ptr = ptr->next;
		}
		this->_size = other._size;
		return *this;
	}

	T& front()
	{
		return _front->value;
	}
	
	T& back()
	{
		return _back->value;
	}
	void push_front(const T& value)
	{
		llist *newItem = new llist; // Valgrind doesn't like this line
		newItem->value = value;
		newItem->next = _front;
		newItem->prev = nullptr;
		if(_front)
			_front->prev = newItem;
		
		if(_back == nullptr)
			_back = newItem;
		_front = newItem;
		_size++;
	}

	void push_back(const T& value)
	{	
		llist *newItem = new llist; //Valgrind doesn't like this line
		newItem->value = value;
		newItem->next = nullptr;
		newItem->prev = _back;
		
		if(_back)
			_back->next = newItem;
		if(_front == nullptr)
			_front = newItem;
		_back = newItem;
		_size++;
	}

	bool empty() const
	{
		return (_front == nullptr)&&(_back == nullptr);
	}

	size_t size() const
	{
		return _size;
	}

	void clear()
	{
		while (!empty())
		{
			pop_front();
		}
		//_size = 0;
	}

	void pop_front()
	{
		llist* ptr = _front;
		_front = _front->next;
		if(_front)
			_front->prev = nullptr;
		else
			_back = nullptr;
		delete ptr;
		_size--;
	}
	void pop_back()
	{
		llist* ptr = _back;
		_back = _back->prev;
		if(_back)
		{
			_back->next = nullptr;
		}
		else
			_front = nullptr;
		delete ptr;
		_size--;
	}

	void reverse()
	{
		if(size() <= 1)
			return;
		for(llist* ptr = _front; ptr != 0; ptr = ptr->prev)
		{
			llist* tmp = ptr->next;
			ptr->next = ptr->prev;
			ptr->prev = tmp;
			//delete tmp;
		}
		llist* tmp2 = _back;
		_back = _front;
		_front = tmp2;
	}

	void unique()
	{
		for(llist* ptr = _front; ptr != 0; ptr=ptr->next)
		{
			while((ptr->next != 0)&&(ptr->value==ptr->next->value))
			{
				_size--;
				llist* saveptr = ptr->next;
				ptr->next = saveptr->next;
				if(saveptr->next != 0)
					saveptr->next->prev = ptr;
				else
					_back = ptr;
				delete saveptr;
			}
		}
	}

	template<typename M>
	friend bool operator==(const List<M>&, const List<M>&);
	template<typename M>
	friend bool operator!=(const List<M>&, const List<M>&);
};

template<typename T>
bool operator==(const List<T>& a, const List<T>& b)
{
	if(a.size() != b.size())
		return false;

	auto aptr = a._front;
	auto bptr = b._front;

	for(; aptr != nullptr && bptr != nullptr; aptr=aptr->next, bptr=bptr->next)
	{
		if(aptr->value != bptr->value)
			return false;
	}

	return true;
}

template<typename T>
bool operator!=(const List<T>& a, const List<T>& b)
{
	if(a.size() != b.size())
		return true;

	auto aptr = a._front;
	auto bptr = b._front;

	for(; aptr != nullptr && bptr != nullptr; aptr=aptr->next, bptr=bptr->next)
	{
		if(aptr->value != bptr->value)
			return true;
	}

	return false;
}


#endif // __EE231_List_h__
