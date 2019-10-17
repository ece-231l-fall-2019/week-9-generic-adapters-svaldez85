# ECE 231 Week 9 Lab Assignment

This assignment will build upon the StringList class we developed in week 8. There are two abstract
data types, stacks and queues, which can be built using your StringList class.  A "stack" data type
is a set which implements a last in, first out (LIFO) paradigm. Meaning, the most recent thing added
to the set (the last item) is the first thing to be removed from the set. A "queue" data type is a
set which implements a first in, first out (FIFO) paradigm. This means that the first the inserted
into the set (the oldest item) is the first item removed from the set.  These two classes have
interfaces which are described in the C++ standard that are similiar to, but slightly different than,
the interface on our StringList class. So we will write adapter classes which adapt our StringList
class to a Queue and a Stack.


## Part 1: Convert the StringList class to a generic/templated List class

All of the container classes we have written so far have been designed to hold a specific data type.
But with C++ templates we are able to design classes that can hold *any* datatype, assuming they
meet some basic set of requirements.

For this step, I want you to convert your StringList class from the previous assignment to a generic,
templated class which can hold *any* datatype. I will go over this in class, but basically I want you
to make this conversion:

```
class StringList
{
private:
  typedef struct llist {
     std::string str;
     llist *next;
     llist *prev;
  } llist;
 ... etc.
public:
  void push_back(const std::string& str);
  void push_front(const std::string& str);
  std::string& back();
  std::string& front();
  ... etc.
  };
```
To the following:
```
template<typename T>
class List
{
private:
  typedef struct llist {
     T value;
     llist *next;
     llist *prev;
  } llist;
 ... etc.
public:

  List();
  List(const List<T>&);
  List(const std::initializer_list&);
  
  void push_back(const T& value);
  void push_front(const T& value);
  T& back();
  T& front();
  const T& back() const;
  const T& front() const;
  ... etc.
  };
```
I supplied the code for my single linked list StringList implementation converted to a generic List type
but it will be easier to convert your already implemented double linked list StringList class to a
generic templated version instead of modifying my code. With a templated class, all methods MUST be implemented
in the header file. You cannot put templated methods into a .cpp file!

I will go over the [std::initializer_list](https://en.cppreference.com/w/cpp/utility/initializer_list) constructor in class.

## Part 2: Implement generic Stack and Queue classes.

The [Stack](https://en.cppreference.com/w/cpp/container/stack)
and [Queue](https://en.cppreference.com/w/cpp/container/queue) classes are just simple adapter classes that
put a different functional interface on top of an underlying container class, in this case your List class.
You will need to create and implement the following classes. The Queue class:
```
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
```
And the Stack class:
```
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
```
## Part 3: Unit tests

Write unit tests for your three classes. The unit tests must test all methods in each class and must test
with the container holding two different data types. The tests I have started out with have tests for
the containers holding `std::string` and `int` data types.

## Deliverables

The following source files:

    1. List.h
    1. Queue.h
    1. Stack.h
    1. runtests.cpp

Your `runtests.cpp` must have at least 50(?) addiontal tests to tests all of the functions and methods on the 3 classes.
