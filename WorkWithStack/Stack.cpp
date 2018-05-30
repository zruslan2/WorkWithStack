#include "Stack.h"

template <typename type>
Stack<type>::Stack() 
{
	buf_size = 0;
	length = 0;
	els = nullptr;
}
template <typename type>
Stack<type>::Stack(type* mass, int n) 
{
	this->length = n;
	els = new type[this->length];
	this->buf_size = this->length;
	for (int i = 0; i < length; i++)
		this->els[i] = mass[i];
}

template<typename type>
Stack<type>::Stack(const Stack& obj) 
{
	this->length = obj.length;
	this->buf_size = obj.buf_size;
	this->els = new type[length];
	for (int i = 0; i < length; i++)
		els[i] = obj.els[i];
}

template<typename type>
type& Stack<type>::top() 
{
	return els[length - 1];
}

template<typename type>
size_t Stack<type>::size() 
{
	return length;
}

template<typename type>
bool Stack<type>::empty() 
{
	return (size() == 0);
}

template <typename type>
void Stack<type>::pop() 
{
	length--;
}

template <typename type>
Stack<type>::~Stack() 
{
	delete[] els;
	els = nullptr; 
}

template <typename type>
void Stack<type>::push(type e) 
{
	if (buf_size == 0) {
		buf_size = 2;
		els = new type[buf_size];
	}
	else if (buf_size <= length) {
		buf_size *= 2;
		type *tmp = new type[buf_size];
		for (int i = 0; i < length; i++)
			tmp[i] = els[i];
		delete[] els;
		els = tmp;
	}
	els[length++] = e;
}