#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#include <string>

#if 1
#include "List.h"
typedef List<std::string> StringList;
typedef List<int> IntList;
#include "Stack.h"
typedef Stack<std::string> StringStack;
typedef Stack<int> IntStack;
#include"Queue.h"
typedef Queue<std::string> StringQueue;
typedef Queue<int> IntQueue;
#else
#include <list>
typedef std::list<std::string> StringList;
typedef std::list<int> IntList;
#include <stack>
typedef std::stack<std::string> StringStack;
typedef std::stack<int> IntStack;
#include <queue>
typedef std::queue<std::string> StringQueue;
typedef std::queue<int> IntQueue;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	// TODO:
	// Write more tests to fully test your classes.


	//STRINGLIST TESTS
	StringList a;
	StringList b;
	std::cout << "STRINGLIST TESTS" << std::endl;
	a.push_front("A");
	Assert(a.front() == "A", "front()");
	a.push_front("B");
	Assert(a.front() == "B", "push_front");
	a.pop_front();
	Assert(a.front() == "A", "pop_front");
	a.push_front("Z");
	Assert(a.front() == "Z", "push_front");

	b = a;
	Assert(a == b, "==, = operators");
	Assert(b.front() == "Z", "=, front()");
	b.pop_back();
	Assert(b.back() == "Z", "pop_back, back()");
	b.pop_front();
	Assert(b.empty() == true, "b is empty");
	Assert(a.empty() == false, "a is NOT empty");

	b.push_back("N");
	b.push_back("Y");
	Assert(b.front() == "N", "push_back");
	Assert(b.back() == "Y", "push_back, back()");
	Assert(b.size() == 2, "size()");
	b.clear();
	Assert(b.empty() == true, "clear()");
	a.clear();
	
	a.push_front("P");
	a.push_front("P");
	a.push_front("P");
	Assert(a.size() == 3, "size()");
	a.unique();
	Assert(a.size() == 1, "unique()");
	a.push_front("H");
	a.reverse();
	Assert(a.front() == "P", "reverse()");

	b.push_back("N");
	b.push_back("Y");
	Assert(b.front() == "N", "push_back, front == N");
	Assert(b.back() == "Y", "push_back, back == Y");
	Assert(b.size() == 2, "b.size()");
	b.clear();
	Assert(b.empty() == true, "b.clear()");
	
	// INTLIST TESTS
	IntList ila;
	IntList ilb;

	std::cout << "INTLIST TESTS" << std::endl;
	ila.push_front(8);
	Assert(ila.front() == 8, "front()");
	ila.push_front(5);
	Assert(ila.front() == 5, "push_front");
	ila.pop_front();
	Assert(ila.front() == 8, "pop_front()");
	ila.push_front(3);
	Assert(ila.front() == 3, "push_front");

	ilb = ila;
	Assert(ila == ilb, "ila == ilb");
	Assert(ilb.front() == 3, "ilb.front == 3");
	ilb.pop_front();
	Assert(ilb.front() == 8, "ilb.front == 8");
	ilb.pop_front();
	Assert(ilb.empty() == true, "ilb is empty");
	Assert(ila.empty() == false, "ila is NOT empty");
	
	ilb.push_back(4);
	ilb.push_back(3);
	Assert(ilb.front() == 4, "push_back, front == 4");
	Assert(ilb.back() == 3, "push_back, back == 3");
	Assert(ilb.size() == 2, "ilb.size()");
	ilb.clear();
	Assert(ilb.empty() == true, "ilb.clear()");
	ila.clear();
	
	ila.push_front(1);
	ila.push_front(1);
	ila.push_front(1);
	Assert(ila.size() == 3, "ila.size()");
	ila.unique();
	Assert(ila.size() == 1, "ila.unique()");
	ila.push_front(2);
	ila.reverse();
	Assert(ila.front() == 1, "ila.reverse()");

	//STRINGSTACK TESTS
	StringStack c;
	
	std::cout << "STRINGSTACK TESTS" << std::endl;
	c.push("A");
	c.push("B");
	Assert(c.top() == "B", "B is at top");
	c.pop();
	Assert(c.empty() == false, "c is not empty");
	c.pop();
	Assert(c.empty(), "c is empty");
	c.push("N");
	c.push("Y");
	Assert(c.top() == "Y", "top == Y");
	Assert(c.size() == 2, "c.size()");
	StringStack ss;
	ss = c;
	Assert(c == ss, "string stack ==");
	Assert(ss.top() == "Y", "string stack == front");
	ss.pop();
	ss.pop();
	Assert(ss.empty(), "pop, empty for string stack");
	Assert(c != ss, "!= stack");
	
	//INTSTACK TESTS
	IntStack ic;

	std::cout << "INTSTACK TESTS" << std::endl;
	ic.push(6);
	ic.push(5);
	Assert(ic.top() == 5, "top()");
	IntStack hs;
	hs = ic;
	Assert(ic == hs, "stack == and =");
	Assert(hs.top() == 5, "stack == front");
	hs.pop();
	hs.pop();
	Assert(hs.empty(), "empty(), pop()");
	Assert(ic != hs, "!= stack");
	Assert(ic.size() == 2, "stack size");
	//STRINGQUEUE TESTS
	StringQueue sq;

	std::cout << "STRINGQUEUE TESTS" << std::endl;
	sq.push("B");
	sq.push("C");
	Assert(sq.front() == "B", "front(), push()");
	sq.pop();
	Assert(sq.front() == "C", "front() after pop");
	sq.push("H");
	Assert(sq.back() == "H", "back()");
	Assert(sq.size() == 2, "size()");
	StringQueue qt;
	qt = sq;	
	Assert(sq == qt, "==, = operator");
	qt.pop();
	Assert(sq != qt, "!= operator");
	qt.pop();
	Assert(qt.empty(), "empty()");

	//INTQUEUE TESTS
	IntQueue iq;

	std::cout << "INTQUEUE TESTS" << std::endl;
	iq.push(3);
	iq.push(7);
	
	IntQueue is;
	is = iq;
	Assert(is == iq, "==, = operator");
	Assert(iq.front() == 3, "front(), push()");
	Assert(iq.back() == 7, "back()");
	iq.pop();
	Assert(iq.front() == 7, "front() after pop");
	Assert(is != iq, "!= operator");
	iq.pop();
	Assert(iq.empty(), "empty()");
	Assert(is.size() == 2, "size()");
	
	return 0;
}


