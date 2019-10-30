#include "List.h"
#include <cstddef>

template<typename T>
class Stack
{
  protected:
     List<T> c;
  public:
     T& top()
     {
	     return c.front();
     }
     const T& top() const
     {
	     return c.front();
     }
     void push(const T& other)
     {
	     c.push_front(other);
     }
     void pop()
     {
	     c.pop_front();
     }
     size_t size() const
     {
	     return c.size();
     }
     bool empty() const
     {
	     return c.empty();
     }
     Stack<T>& operator=(const Stack<T>& other)
     {
	     c = other.c;
	     return *this;
     }
     template<typename M>
     friend bool operator==(const Stack<M>&, const Stack<M>&);
     template<typename M>
     friend bool operator==(const Stack<M>&, const Stack<M>&);
};
template<typename T>
bool operator==(const Stack<T>& a, const Stack<T>& b)
{
	if (a.size() != b.size())
		return false;
	auto aptr = a._front;
	auto bptr = b._front;
	for(;aptr!= 0; aptr = aptr->next)
	{
		if(aptr->value != bptr->value)
			return false;
		bptr = bptr->next;
	}
	return true;
	
}
template<typename T>
bool operator!=(const Stack<T>& a, const Stack<T>& b)
{
	if (a.size() != b.size())
		return true;
	auto aptr = a._front;
	auto bptr = b._front;
	for(;aptr!= 0; aptr = aptr->next)
	{
		if(aptr->value != bptr->value)
			return true;
		bptr = bptr->next;
	}
	return false;
	
}
