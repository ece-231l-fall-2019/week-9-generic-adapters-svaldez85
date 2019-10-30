#include "List.h"
#include <cstddef>
template<typename T>
class Queue
{
  protected:
     List<T> c;
  public:
     T& front()
     {
	     return c.front();
     }
     T& back()
     {
	     return c.back();
     }
     const T& front() const
     {
	     return c.front();
     }
     const T& back() const
     {
	     return c.back();
     }
     void push(const T& other)
     {
	     c.push_back(other);
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
     Queue<T>& operator=(const Queue<T>& other)
     {
	     c = other.c;
	     return *this;
     }
     template<typename M>
     friend bool operator==(const Queue<M>&, const Queue<M>&);
     template<typename M>
     friend bool operator!=(const Queue<M>&, const Queue<M>&);
     
};
template<typename T>
bool operator==(const Queue<T>& a, const Queue<T>& b)
{
	auto alist = a.c;
	auto blist = b.c;
	return alist == blist;
}
template<typename T>
bool operator!=(const Queue<T>& a, const Queue<T>& b)
{
	auto alist = a.c;
	auto blist = b.c;
	return alist != blist;
}
