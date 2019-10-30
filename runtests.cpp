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

	StringList a;
	StringList b;

	a.push_front("A");
	Assert(a.front() == "A", "front == A");
	a.push_front("B");
	Assert(a.front() == "B", "front == B");
	a.pop_front();
	Assert(a.front() == "A", "front == A");
	a.push_front("Z");
	Assert(a.front() == "Z", "front == Z");

	b = a;
	Assert(a == b, "a == b");
	Assert(b.front() == "Z", "b.front == Z");
	b.pop_front();
	Assert(b.front() == "A", "b.front == A");
	b.pop_front();
	Assert(b.empty() == true, "b is empty");
	Assert(a.empty() == false, "a is NOT empty");

	/*-----------------------*/
	b.push_back("N");
	b.push_back("Y");
	Assert(b.front() == "N", "push_back, front == N");
	Assert(b.back() == "Y", "push_back, back == Y");
	Assert(b.size() == 2, "b.size()");
	b.clear();
	Assert(b.empty() == true, "b.clear()");
	a.clear();
	a.push_front("P");
	a.push_front("P");
	a.push_front("P");
	Assert(a.size() == 3, "a.size()");
	a.unique();
	Assert(a.size() == 1, "a.unique()");
	a.push_front("H");
	a.reverse();
	Assert(a.front() == "P", "a.reverse()");

	// TODO: check all methods on StringList...

	StringStack c;
	c.push("A");
	c.push("B");
	Assert(c.top() == "B", "B is at top");
	c.pop();
	Assert(c.empty() == false, "c is not empty");
	c.pop();
	Assert(c.empty() == true, "c is empty");
	c.push("N");
	c.push("Y");
	Assert(c.top() == "Y", "top == Y");
//	Assert(c.size() == 2, "c.size()");
	StringStack ss;
	ss = c;
	Assert(c == ss, "string stack ==");
	//Assert(ss.top() == "Y", "string stack == front");
	ss.pop();
	ss.pop();
	Assert(ss.empty(), "pop, empty for string stack");
	Assert(c != ss, "!= stack");
	// TODO: check all methods on StringStack...

	IntList ia;
	ia.push_front(5);
	ia.push_front(6);
	Assert(ia.front() == 6, "front is 6");

	// TODO: check all methods on IntList...

	IntStack ic;
	ic.push(6);
	ic.push(5);
	Assert(ic.top() == 5, "top is 5");
	IntStack hs;
	hs = ic;
	Assert(ic == hs, "stack ==");
	Assert(hs.top() == 5, "stack == front");
	hs.pop();
	hs.pop();
	Assert(hs.empty(), "pop, empty for stack");
	Assert(ic != hs, "!= stack");
	// TODO: check all methods on IntStack...
	
	StringQueue sq;
	sq.push("B");
	sq.push("C");
	Assert(sq.front() == "B", "front is B");
	sq.pop();
	Assert(sq.front() == "C", "front is C after pop");
	
	IntQueue iq;
	iq.push(3);
	iq.push(7);
	IntQueue is;
	is = iq;
//	Assert(is == iq, "== operator");
	Assert(iq.front() == 3, "front is 3 intqueue");
	Assert(iq.back() == 7, "back is 7 intqueue");
	iq.pop();
	Assert(iq.front() == 7, "front is 7 after pop");
	
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	Assert(sq.front() == "C", "front is C after pop");
	
	return 0;
}


