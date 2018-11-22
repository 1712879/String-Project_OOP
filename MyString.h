#ifndef __MyString_H__
#define __MyString_H__

#include<iostream>
#include<string.h>
using namespace std;
#pragma once
//template<typename T>
/*class iterator{
private:
	T* data;
public:
	iterator(){

	}
	iterator(T* data) {
		this->data = data;
	}

	T &operator*() {
		return *data;
	}

	iterator<T> &operator++() {
		data++;
		return *this;
	}

	bool operator==(const iterator<T> &a) {
		return data == a.data;
	}

	bool operator!=(const iterator<T> &a) {
		return data != a.data;
	}

};*/

class MyString
{
private:
	char* str;
public:
	//constructor 
	MyString(); // ham tao mac dinh
	MyString(const MyString& Copystr); // ham tao copy
	MyString(const MyString& Substr, int pos, int leng);
	MyString(const char* s);
	MyString(const char* s, int leng);
	MyString(int n, char c);
	MyString(int n, int c);
	template <class InputIterator>
	MyString(InputIterator first, InputIterator last);

	//operator=
	MyString& operator= (const MyString& Objstr);
	MyString& operator= (const char* s);
	MyString& operator= (char c);
	MyString& operator+=(const char c);

	//destructor
	~MyString();

	//Iterator
	//begin() & end()
	typedef char* iterator;
	iterator begin(){
		return this->str;
	}
	iterator end(){
		return (this->str + strlen(this->str));
	}

	//rbegin() & rend()
	typedef reverse_iterator<iterator> reverse_iterator;
	reverse_iterator rbegin(){
		return reverse_iterator(end());
	}

	reverse_iterator rend(){
		return reverse_iterator(begin());
	}

	//cbegin() & cend()
	typedef const char* const_iterator;
	const_iterator cbegin() {
		return const_iterator(this->begin());
	}

	const_iterator cend() {
		return const_iterator(this->end());
	}

	//crbegin() & crend()
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	const_reverse_iterator crbegin(){
		return const_reverse_iterator(this->rbegin());
	}

	const_reverse_iterator crend(){
		return const_reverse_iterator(this->rend());
	}


	typedef unsigned int size_type;
	size_type size() const;
	size_type length() const;
	/*size_type max_size() const;*/
	void resize(size_t n);
	void resize(size_t n, char c);
	size_type capacity() const;
	void reserve(size_t n);
	void clear();
	bool empty() const;
	void shrink_to_fit();

	char* getMyString();
};

#endif