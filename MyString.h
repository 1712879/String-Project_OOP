#ifndef __MyString_H__
#define __MyString_H__

#include<iostream>
using namespace std;
#pragma once

class MyString
{
public:
	typedef int size_type;
	static const size_type INITIAL_CAPACITY = 15;
	static const size_type MAX_SIZE = 4294967294;
	static const size_type npos = -1;
	//constructor 
	MyString(); 
	MyString(const MyString& Copystr);
	MyString(const MyString& Substr, size_type pos, size_type leng);
	MyString(const char* s);
	MyString(const char* s, size_type leng);
	MyString(size_type n, char c);
	MyString(size_type n, size_type c);
	template <class InputIterator>
	MyString(InputIterator first, InputIterator last){
		size = last - first;
		capacity = INITIAL_CAPACITY;
		while (size + 1 > capacity)
		{
			capacity += INITIAL_CAPACITY + 1;
		}
		str = new char[capacity];
		size_type i = 0;
		for (;first != last; i++, ++first)
		{
			*(str + i) = *first;
		}
		*(this->str + size) = '\0';
	}

	//operator:
	MyString& operator= (const MyString& Objstr);
	MyString& operator= (const char* s);
	MyString& operator= (char c);	

	friend	MyString operator+ (const MyString& lhs, const MyString& rhs);
	friend  MyString operator+ (const MyString& lhs, const char* rhs);
	friend  MyString operator+ (const char* lhs, const MyString& rhs);
	friend  MyString operator+ (const MyString& lhs, char rhs);
	friend  MyString operator+ (char lhs, const MyString& rhs);

	MyString& operator+= (const MyString& str);
	MyString& operator+= (const char* s);
	MyString& operator+=(const char c);

	friend bool operator== (const MyString& lhs, const MyString& rhs);
	friend bool operator== (const char*   lhs, const MyString& rhs);
	friend bool operator== (const MyString& lhs, const char*   rhs);
	friend bool operator!= (const MyString& lhs, const MyString& rhs);

	friend bool operator!= (const char*   lhs, const MyString& rhs);
	friend bool operator!= (const MyString& lhs, const char*   rhs);

	friend bool operator<  (const MyString& lhs, const MyString& rhs);
	friend bool operator<  (const char*   lhs, const MyString& rhs);
	friend bool operator<  (const MyString& lhs, const char*   rhs);

	friend bool operator<= (const MyString& lhs, const MyString& rhs);
	friend bool operator<= (const char*   lhs, const MyString& rhs);
	friend bool operator<= (const MyString& lhs, const char*   rhs);
	
	friend bool operator>  (const MyString& lhs, const MyString& rhs);
	friend bool operator>  (const char*   lhs, const MyString& rhs);
	friend bool operator>  (const MyString& lhs, const char*   rhs);
	
	friend bool operator>= (const MyString& lhs, const MyString& rhs);
	friend bool operator>= (const char*   lhs, const MyString& rhs);
	friend bool operator>= (const MyString& lhs, const char*   rhs);

	char& operator[] (size_type pos);
	const char& operator[] (size_type pos) const;

	//destructor:
	~MyString();

	//Iterator:
	typedef char* iterator;
	typedef const char* const_iterator;
	typedef reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	//begin() & end()
	iterator begin(){
		return str;
	}
	iterator end(){
		return (str + strlen(str));
	}
	//rbegin() & rend()
	reverse_iterator rbegin(){
		return reverse_iterator(end());
	}
	reverse_iterator rend(){
		return reverse_iterator(begin());
	}

	//cbegin() & cend()
	const_iterator cbegin() {
		return const_iterator(this->begin());
	}
	const_iterator cend() {
		return const_iterator(this->end());
	}

	//crbegin() & crend()
	const_reverse_iterator crbegin(){
		return const_reverse_iterator(this->rbegin());
	}
	const_reverse_iterator crend(){
		return const_reverse_iterator(this->rend());
	}
	//Capacity:
	size_type getSize() const;
	size_type getLength() const;
	size_type max_size() const;
	void resize(size_type n);
	void resize(size_type n, char c);
	size_type getCapacity() const;
	void reserve(size_type n);
	void clear();
	bool empty() const;
	void shrink_to_fit();
	//Element access:
	char& at(size_type pos);
	const char& at(size_type pos) const;
	char& back();
	const char& back() const;
	char& front();
	const char& front() const;
	//Modifiers:
	void push_back(char c);
	void swap(MyString& str);
	void pop_back();

	MyString& append(const MyString& str);
	MyString&append(const MyString& substr, size_type subpos, size_type sublen);
	MyString&append(const char* s);
	MyString&append(const char* s, size_type n);
	MyString&append(size_type n, char c);
	template <class InputIterator>
	MyString& append(InputIterator first, InputIterator last){
		MyString t(first, last);
		return append(t);
	}

	MyString& assign(const MyString& str);
	MyString& assign(const MyString& str, size_type subpos, size_type sublen);
	MyString& assign(const char* s);
	MyString& assign(const char* s, size_type n);
	MyString& assign(size_type n, char c);
	MyString& assign(size_type n, int c);
	template <class InputIterator>
	MyString& assign(InputIterator first, InputIterator last){
		size_type len = last - first;
		size_type last_size = size;
		reserve(len);
		size_type i = 0;
		while (first != last)
		{
			*(this->str + i) = *first;
			first++; i++;
		}
		*(this->str + len) = '\0';
		return *this;
	}

	MyString& insert(size_type pos, const MyString& str);
	MyString& insert(size_type pos, const MyString& str, size_type subpos, size_type sublen);
	MyString& insert(size_type pos, const char* s);
	MyString& insert(size_type pos, const char* s, size_type n);
	MyString& insert(size_type pos, size_type n, char c);
	void insert(iterator p, size_type n, char c){
		reserve(size + n);
		size_type i = 0;
		while (i < n)
		{
			*(p + i) = c;
			i++;
		}
		*(p + n) = '\0';
	}
	iterator insert(iterator p, char c){
		reserve(size + 1);
		char* t = new char[this->end() - p + 1];
		size_type i = 0;
		while (p + i != this->end())
		{
			*(t + i) = *(p + i);
			i++;
		}
		*(t + i) = '\0';
		*p = c;
		i = 0;
		while (*(t + i) != '\0')
		{
			*(p + 1 + i) = *(t + i);
			i++;
		}
		*(p + 1 + i) = '\0';
		delete[] t;
		return p;
	}
	template <class InputIterator>
	void insert(iterator p, InputIterator first, InputIterator last){
		size_type len = last - first;
		reserve(len + size);
		size_type i = 0;
		char* t = new char[this->end() - p + 1];
		while (p + i != this->end())
		{
			*(t + i) = *(p + i);
			i++;
		}
		*(t + i) = '\0';
		i = 0;
		while (first != last)
		{
			*(p + i) = *first;
			++first; i++;
		}
		i = 0;
		while (*(t + i) != '\0')
		{
			*(p + len + i) = *(t + i);
			i++;
		}
		*(p + len + i) = '\0';
		delete[] t;
	}

	MyString& erase(size_type pos, size_type len);
	iterator erase(iterator p){
		if (p < begin() || p == end())
		{
			return p;
		}
		size_type i = 0;
		while (*(p + i + 1) != '\0')
		{
			*(p + i) = *(p + 1 + i);
			i++;
		}
		size--;
		*(p + i) = '\0';
	}
	iterator erase(iterator first, iterator last){
		if (first < begin())
		{
			first = begin();
		}
		else if (last > end())
		{
			last = end();
		}
		size_type len = last - first;
		size_type i = 0; iterator p = first, q = last;
		while (*(q + i) != '\0')
		{
			*(p + i) = *(q + i);
			i++;
		}
		*(p + i) = '\0';
		size -= len;
		return p;
	}

	MyString& replace(size_type pos, size_type len, const MyString& str);
	MyString& replace(size_type pos, size_type len, const MyString& str,
		size_type subpos, size_type sublen);
	MyString& replace(size_type pos, size_type len, const char* s);
	MyString& replace(size_type pos, size_type len, const char* s, size_type n);
	MyString& replace(size_type pos, size_type len, size_type n, char c);

	MyString& replace(iterator i1, iterator i2, const MyString& str){
		MyString t;
		for (MyString::iterator it = begin(); it != i1; it++)
		{
			t += *it;
		}
		t.append(str);
		t.append(i2);
		*this = t;
		return *this;
	}
	MyString& replace(iterator i1, iterator i2, const char* s){
		MyString t(s);
		return replace(i1, i2, t);
	}
	MyString& replace(iterator i1, iterator i2, const char* s, size_type n){
		MyString t(s, n);
		return replace(i1, i2, t);
	}
	MyString& replace(iterator i1, iterator i2, size_type n, char c){
		MyString t(n, c);
		return replace(i1, i2, t);
	}
	template <class InputIterator>
	MyString& replace(iterator i1, iterator i2,
		InputIterator first, InputIterator last){
		MyString t(first, last);
		return replace(i1, i2, t);
	}
	//MyString operations:
	const char* c_str() const;
	const char* data() const;
	size_type copy(char* s, size_type len, size_type pos) const;

	size_type find(const MyString& str, size_type pos = 0) const;
	size_type find(const char* s, size_type pos = 0) const;
	size_type find(const char* s, size_type pos, size_type n) const;
	size_type find(char c, size_type pos = 0) const;

	size_type rfind(const MyString& str, size_type pos = npos) const;
	size_type rfind(const char* s, size_type pos = npos) const;
	size_type rfind(const char* s, size_type pos, size_type n) const;
	size_type rfind(char c, size_type pos = npos) const;

	size_type find_first_of(const MyString& str, size_type pos = 0) const;
	size_type find_first_of(const char* s, size_type pos = 0) const;
	size_type find_first_of(const char* s, size_type pos, size_type n) const;
	size_type find_first_of(char c, size_type pos = 0) const;

	size_type find_last_of(const MyString& str, size_type pos = npos) const;
	size_type find_last_of(const char* s, size_type pos = npos) const;
	size_type find_last_of(const char* s, size_type pos, size_type n) const;
	size_type find_last_of(char c, size_type pos = npos) const;

	size_type find_first_not_of(const MyString& str, size_type pos = 0) const;
	size_type find_first_not_of(const char* s, size_type pos = 0) const;
	size_type find_first_not_of(const char* s, size_type pos, size_type n) const;
	size_type find_first_not_of(char c, size_type pos = 0) const;

	size_type find_last_not_of(const MyString& str, size_type pos = npos) const;
	size_type find_last_not_of(const char* s, size_type pos = npos) const;
	size_type find_last_not_of(const char* s, size_type pos, size_type n) const;
	size_type find_last_not_of(char c, size_type pos = npos) const;

	MyString substr(size_type pos, size_type len) const;
	MyString substr(size_type pos) const;

	int compare(const MyString& str) const;
	int compare(size_type poMyStrings, size_type len, const MyString& str) const;
	int compare(size_type pos, size_type len, const MyString& str,
		size_type subpos, size_type sublen) const;
	int compare(const char* s) const;
	int compare(size_type pos, size_type len, const char* s) const;
	int compare(size_type pos, size_type len, const char* s, size_type n) const;
	//Non-member function overloads:
	friend void swap(MyString& x, MyString& y);

	friend istream& operator>> (istream& is, MyString& str);
	friend ostream& operator<< (ostream& os, const MyString& str);

	friend istream& getline(istream& is, MyString& str, char delim);
	friend istream& getline(istream& is, MyString& str);

	char* getMyString();

private:
	char* str;
	size_type size, capacity;
};



#endif