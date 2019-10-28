#include "List.h"
#include <cstddef>
template<typename T>
class Queue
{
  protected:
     List<T> c;
  public:
     List<T>& Queue_list()
     {
	     return c;
     }
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
	     c = other.Queue_list();
	     return *this;
     }
};
template<typename T>
bool operator==(const Queue<T>& a, const Queue<T>& b)
{
	return a.Queue_list() == b.Queue_list();
}
template<typename T>
bool operator!=(const Queue<T>& a, const Queue<T>& b)
{
	return a.Queue_list() != b.Queue_list();
}
