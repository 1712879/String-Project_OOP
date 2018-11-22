#include "MyString.h"


MyString::MyString()
{
	this->str = new char[1];
	strcpy(str, "");
}

MyString::MyString(const MyString& Copystr){
	this->str = new char[strlen(Copystr.str) + 1];
	strcpy(str, Copystr.str);
}

MyString::MyString(const MyString& Substr, int pos, int leng){
	this->str = new char[leng + 1];
	for (int i = 0; i < leng; i++)
	{
		this->str[i] = Substr.str[pos + i];
	}
	this->str[leng] = '\0';
}

MyString::MyString(const char* s){
	this->str = new char[strlen(s) + 1];
	strcpy(str, s);
}

MyString::MyString(const char* s, int leng){
	this->str = new char[leng + 1];
	strncpy(this->str, s, leng);
	this->str[leng] = '\0';
}

MyString::MyString(int n, char c){
	this->str = new char[n + 1];
	memset(this->str, c, n);
	this->str[n] = '\0';
}

MyString::MyString(int n, int c){
	this->str = new char[n + 1];
	memset(this->str, (char)c, n);
	this->str[n] = '\0';
}

template <class InputIterator>
MyString::MyString(InputIterator first, InputIterator last){

}

//operator=
MyString &MyString::operator= (const MyString& Objstr){
	if (this->str) {
		delete this->str;
		this->str = NULL;
	}

	if (Objstr.str) {
		this->str = new char[strlen(Objstr.str) + 1];
		strcpy(this->str, Objstr.str);
	}
	return *this;
}

MyString &MyString::operator= (const char* s){
	if (this->str) {
		delete this->str;
		this->str = NULL;
	}

	this->str = new char[strlen(s) + 1];
	strcpy(this->str, s);
	return *this;
}

MyString &MyString::operator= (char c){
	if (this->str) {
		delete this->str;
		this->str = NULL;
	}

	this->str = new char[2];
	memset(this->str, c, 1);
	this->str[1] = '\0';
	return *this;
}

MyString &MyString::operator+=(const char c){
	char* s = new char[this->size() + 2];
	strncpy(s, this->str, this->size());
	s[this->size()] = c;
	s[this->size() + 1] = '\0';
	this->str = new char[strlen(s) + 1];
	strcpy(this->str, s);
	delete[] s;
	return *this;
}

char* MyString::getMyString(){
	return this->str;
}

//destructor
MyString::~MyString()
{
	if (this->str)
	{
		delete this->str;
		this->str = NULL;
	}
}

typedef unsigned int size_type;
size_type MyString::size() const{
	return strlen(this->str);
}

size_type MyString::length() const{
	return strlen(this->str);
}

/*size_type MyString::max_size() const{
	
}*/

void MyString::resize(size_t n){
	if (n < this->size())
	{
		strncpy(this->str, this->str, n);
		this->str[n] = '\0';
	}
}

void MyString::resize(size_t n, char c){
	if (n > this->size())
	{
		char* s = new char[n + 1];
		strncpy(s, this->str, this->size());
		for (int i = this->size(); i < n; i++)
		{
			s[i] = c;
		}
		s[n] = '\0';
		this->str = new char[n + 1];
		strcpy(this->str, s);
		delete[] s;
	}
	else if (n < this->size())
	{
		MyString::resize(n);
	}

}

size_type MyString::capacity() const{
	return strlen(this->str) + 1;
}

void MyString::reserve(size_t n){
	if (this->capacity() >= n)
	{
		return;
	}
	char* temp = this->str;
	this->str = new char[n];
	strcpy(this->str, temp);
	delete[] temp;
}

void MyString::clear(){
	delete[] this->str;
	this->str = new char[1];
	this->str[0] = '\0';
}

bool MyString::empty() const{
	if (*this->str == '\0' && this->size() == 0)
	{
		return true;
	}
	return false;
}

void MyString::shrink_to_fit(){
	if ((this->capacity() - this->size()) > 1)
	{
		return;
	}
}