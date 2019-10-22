#include "List.h"
#include <cstddef>

template<typename T>
class Stack
{
  protected:
     List<T> c;
  public:
     const List<T>& Stack_list()
     {
	     return c;
     }
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
	     c = other.Stack_list();
	     return *this;
     }

};
template<typename T>
bool operator==(const Stack<T>& a, const Stack<T>& b)
{
	return a.Stack_list() == b.Stack_list();
}
template<typename T>
bool operator!=(const Stack<T>& a, const Stack<T>& b)
{
	return a.Stack_list() != b.Stack_list();
}
