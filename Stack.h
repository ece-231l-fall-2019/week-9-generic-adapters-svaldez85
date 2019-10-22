#include "List.h"
#include <cstddef>

template<typename T>
Stack
{
  protected:
     List<T> c;
  public:
     T& top();
     const T& top() const;
     void push(const T&);
     void pop();
     size_t size() const;
     bool empty() const;
     Stack<T>& operator=(const Stack<T>&);
};

bool operator==(const Stack<T>&, const Stack<T>&);
bool operator!=(const Stack<T>&, const Stack<T>&);
