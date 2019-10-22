#include "List.h"
#include <cstddef>
template<typename T>
Queue
{
  protected:
     List<T> c;
  public:
     T& front();
     T& back();
     const T& front() const;
     const T& back() const;
     void push(const T&);
     void pop();
     size_t size() const;
     bool empty() const;
     Queue<T>& operator=(const Queue<T>&);
};

bool operator==(const Queue<T>&, const Queue<T>&);
bool operator!=(const Queue<T>&, const Queue<T>&);
