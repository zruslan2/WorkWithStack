#pragma once
#include "Library.h"

template<typename type> 
class Stack {
private:
	type *els;
	size_t length;
	size_t buf_size;
public:
	Stack();
	Stack(type* mass, int n);
	Stack(const Stack& obj);

	type& top();
	void push(type e);
	void pop();
	size_t size();
	bool empty();		
	
	~Stack();
};


