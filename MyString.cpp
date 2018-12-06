#include "MyString.h"
typedef int size_type;
static const size_type npos = -1;

//---default constructor
MyString::MyString()
{
	size = 0; capacity = INITIAL_CAPACITY;
	str = new char[INITIAL_CAPACITY];
	*str = '\0';
}
//---copy constructor
MyString::MyString(const MyString& Copystr)
{
	size = Copystr.size; capacity = Copystr.capacity;
	str = new char[Copystr.capacity];
	memcpy(str, Copystr.str, Copystr.size + 1);
}
//---substring constructor
MyString::MyString(const MyString& Substr, size_type pos, size_type leng)
{
	size = leng;
	capacity = INITIAL_CAPACITY;
	while (leng + 1 > capacity)
	{
		capacity += INITIAL_CAPACITY + 1;
	}
	str = new char[capacity];
	for (int i = 0; i < leng; i++)
	{
		str[i] = Substr.str[pos + i];
	}
	str[leng] = '\0';
}
//--- from c-Mystring
MyString::MyString(const char* s){
	size = strlen(s);
	capacity = INITIAL_CAPACITY;
	while (size + 1 > capacity)
	{
		capacity += INITIAL_CAPACITY + 1;
	}
	str = new char[capacity];
	memcpy(str, s, size + 1);
}
//---from buffer
MyString::MyString(const char* s, size_type leng){
	size = leng;  capacity = INITIAL_CAPACITY;
	while (leng + 1 > capacity)
	{
		capacity += INITIAL_CAPACITY + 1;
	}
	str = new char[capacity];
	memcpy(str, s, leng);
	str[leng] = '\0';
}
//---fill constructor
MyString::MyString(size_type n, char c){
	size = n; capacity = INITIAL_CAPACITY;
	while (n + 1 > capacity)
	{
		capacity += INITIAL_CAPACITY + 1;
	}
	str = new char[capacity];
	memset(str, c, n);
	str[n] = '\0';
}
//---range constructor
MyString::MyString(size_type n, size_type c){
	size = n; capacity = INITIAL_CAPACITY;
	while (n + 1 > capacity)
	{
		capacity += INITIAL_CAPACITY + 1;
	}
	str = new char[capacity];
	memset(str, (char)c, n);
	str[n] = '\0';
}
//---operator=
MyString &MyString::operator= (const MyString& Objstr){
	reserve(Objstr.size);
	memcpy(str, Objstr.str, Objstr.size + 1);
	return *this;
}
MyString &MyString::operator= (const char* s){
	
	reserve(strlen(s));
	memcpy(str, s, strlen(s) + 1);
	return *this;
}
MyString &MyString::operator= (char c){
	size = 1;
	*str = c; str[1] = '\0';
	return *this;
}
//---operator+
MyString operator+ (const MyString& lhs, const MyString& rhs){
	MyString t;
	t = lhs; t += rhs;
	return t;
}
MyString operator+ (const MyString& lhs, const char* rhs){
	MyString t;
	t = lhs; t += rhs;
	return t;
}
MyString operator+ (const char* lhs, const MyString& rhs){
	MyString t;
	t = lhs; t += rhs;
	return t;
}
MyString operator+ (const MyString& lhs, char rhs){
	MyString t;
	t = lhs; t += rhs;
	return t;
}
MyString operator+ (char lhs, const MyString& rhs){
	MyString t;
	t = lhs; t += rhs;
	return t;
}
//---operator+=
MyString &MyString::operator+= (const MyString& str){
	reserve(size+ str.size);
	strcat(this->str, str.str);
	return *this;
}
MyString& MyString::operator+= (const char* s){
	reserve(size + strlen(s));
	strcat(str, s);
	return *this;
}
MyString &MyString::operator+=(const char c){
	reserve(size + 1);
	str[size - 1] = c; str[size] = '\0';
	return *this;
}
//------Relational operators------
//---operator==
bool operator== (const MyString& lhs, const MyString& rhs){
	if (lhs.compare(rhs) == 0) { return true; }
	else { return false; }
}
bool operator== (const char*   lhs, const MyString& rhs){
	if (rhs.compare(lhs) == 0){ return true; }
	else { return false; }
}
bool operator== (const MyString& lhs, const char*   rhs){
	if (lhs.compare(rhs) == 0){ return true; }
	else { return false; }
}
//---operator!=
bool operator!= (const MyString& lhs, const MyString& rhs){
	if (lhs == rhs) { return false; }
	else { return true; }
}
bool operator!= (const char*   lhs, const MyString& rhs){
	if (lhs == rhs){ return false; }
	else { return true; }
}
bool operator!= (const MyString& lhs, const char*   rhs){
	if (lhs == rhs){ return false; }
	else{ return true; }
}
//---operator<
bool operator<  (const MyString& lhs, const MyString& rhs){
	if (lhs.compare(rhs) < 0){ return true; }
	else{ return false; }
}
bool operator<  (const char*   lhs, const MyString& rhs){
	if (rhs.compare(lhs) > 0) // dao nguoc so sanh(thay vi < chuyen sang >)
	{ return true; }
	else
	{return false;}
}
bool operator<  (const MyString& lhs, const char*   rhs){
	if (lhs.compare(rhs) < 0){ return true; }
	else{ return false; }
}
//---operator<=
bool operator<= (const MyString& lhs, const MyString& rhs){
	if (lhs.compare(rhs) <= 0){ return true; }
	else{ return false; }
}
bool operator<= (const char*   lhs, const MyString& rhs){
	// dao nguoc so sanh(thay vi <= chuyen sang >=)
	if (rhs.compare(rhs) >= 0){ return true; }
	else{ return false; }
}
bool operator<= (const MyString& lhs, const char*   rhs){
	if (lhs.compare(rhs) <= 0){ return true; }
	else{ return false; }
}
//---operator>
bool operator>  (const MyString& lhs, const MyString& rhs){
	if (lhs.compare(rhs) > 0){ return true; }
	else{ return false; }
}
bool operator>  (const char*   lhs, const MyString& rhs){
	if (rhs.compare(lhs) < 0){ return true; }
	else{ return false; }
}
bool operator>  (const MyString& lhs, const char*   rhs){
	if (lhs.compare(rhs) > 0){ return true; }
	else{ return false; }
}
//---operator>=
bool operator>= (const MyString& lhs, const MyString& rhs){
	if (lhs.compare(rhs) >= 0){ return true; }
	else{ return false; }
}
bool operator>= (const char* lhs, const MyString& rhs){
	if (rhs.compare(lhs) <= 0){ return true; }
	else{ return false; }
}
bool operator>= (const MyString& lhs, const char*   rhs){
	if (lhs.compare(rhs) >= 0){ return true; }
	else{ return false; }
}
//---operator[]
char &MyString::operator[](size_type pos){
	return *(str + pos);
}
const char &MyString::operator[] (size_type pos) const{
	return operator[](pos);
}

char* MyString::getMyString(){
	return str;
}

//----String destructor
MyString::~MyString()
{
	if (str)
	{
		size = 0; capacity = 0;
		delete[] str;
		str = NULL;
	}
}
//----size of Mystring
size_type MyString::getSize() const{
	return size;
}
//----length of Mystring
size_type MyString::getLength() const{
	return size;
}
//-----maxsize of Mystring
size_type MyString::max_size() const{
	return MAX_SIZE;
}
//----resize Mystring
void MyString::resize(size_type n){
	if (n < size)
	{
		reserve(n);
		memcpy(str, str, n + 1);
		*(str + n) = NULL;
	}
}
void MyString::resize(size_type n, char c){
	if (n > size)
	{
		int i = size;
		reserve(n);
		while (i < n)
		{
			*(str + i) = c;
			i++;
		}
		*(str + n) = NULL;
	}
	else if (n < size)
	{
		reserve(n);
		memcpy(str, str, n + 1);
		*(str + n) = NULL;
	}

}
//----capacity Mystring
size_type MyString::getCapacity() const{
	return capacity;
}
//----reserve
void MyString::reserve(size_type n){
	if (capacity > n)
	{
		size = n;
		return;
	}
	size = n; capacity = INITIAL_CAPACITY;
	while (n + 1 > capacity)
	{
		capacity += INITIAL_CAPACITY + 1;
	}
	char* t = new char[size + 1];
	memcpy(t, str, size + 1);
	delete[] str;
	str = new char[capacity];
	memcpy(str, t, n + 1);
	delete[] t;
}
//---- clear Mystring
void MyString::clear(){
	size = 0; capacity = INITIAL_CAPACITY;
	*str = '\0';
}
//----empty
bool MyString::empty() const{
	return size == 0 ? true : false;
}
//----shrink to fit
void MyString::shrink_to_fit(){
	char* t = new char[size + 1];
	memcpy(t, str, size + 1);
	delete[] str;
	str = new char[size + 1];
	memcpy(str, t, size + 1);
	capacity = size;
	delete[] t;
}
//----Get character in Mystring
char&  MyString::at(size_type pos){
	if (pos < size){ return *(str + pos); }
	else{ cout << "ERROR!!!" << endl; }
}
const char&  MyString::at(size_type pos) const{
	return this->at(pos);
}
//----Access last character
char&  MyString::back(){
	return str[size - 1];
}
const char&  MyString::back() const{
	return this->back();
}
//----Access first character
char& MyString::front(){
	return *str;
}
const char& MyString::front() const{
	return this->front();
}
//----Append to Mystring
MyString& MyString::append(const MyString& str){
	size_type last_capacity = capacity;
	size_type last_size = size;
	reserve(size + str.size);
	memcpy(this->str + last_size, str.str, str.size + 1);
	return *this;
}
MyString& MyString::append(const MyString& substr, size_type subpos, size_type sublen){
	MyString t(substr, subpos, sublen);
	return append(t);
}
MyString& MyString::append(const char* s){
	MyString t(s);
	return append(t);
}
MyString& MyString::append(const char* s, size_type n){
	MyString t(s, n);
	return append(t);
}
MyString& MyString::append(size_type n, char c){
	MyString t(n, c);
	return append(t);
}
//----Append character to Mystring
void MyString::push_back(char c){
	reserve(size + 1);
	str[size - 1] = c;
	str[size] = '\0';
}	
//----Assign content to Mystring
MyString& MyString::assign(const MyString& str){
	size_type last_capacity = capacity;
	size_type last_size = size;
	reserve(str.size);
	memcpy(this->str, str.str, str.size + 1);
	return *this;
}
MyString& MyString::assign(const MyString& str, size_type subpos, size_type sublen){
	MyString t(str, subpos, sublen);
	return assign(t);
}
MyString& MyString::assign(const char* s){
	MyString t(s);
	return assign(t);
}
MyString& MyString::assign(const char* s, size_type n){
	MyString t(s, n);
	return assign(t);
}
MyString& MyString::assign(size_type n, char c){
	MyString t(n, c);
	return assign(t);
}
MyString& MyString::assign(size_type n, int c){
	MyString t(n, c);
	return assign(t);
}
//----Insert into Mystring
MyString& MyString::insert(size_type pos, const MyString& str){
	reserve(size + str.size);
	MyString t = this->str + pos;
	memcpy(this->str + pos, str.str, str.size + 1);
	size = strlen(this->str);
	append(t);
	return *this;
}
MyString& MyString::insert(size_type pos, const MyString& str, size_type subpos, size_type sublen){
	MyString t(str, subpos, sublen);
	return insert(pos, t);
}
MyString& MyString::insert(size_type pos, const char* s){
	MyString t(s);
	return insert(pos, t);
}
MyString& MyString::insert(size_type pos, const char* s, size_type n){
	MyString t(s, n);
	return insert(pos, t);	
}
MyString& MyString::insert(size_type pos, size_type n, char c){
	MyString t(n, c);
	return insert(pos, t);
}
//-----Erase characters from Mystring
MyString& MyString::erase(size_type pos, size_type len){
	if (pos >= size){ return *this; }
	if (pos == 0 && len == -1){ clear(); }
	else if (pos + len > size)
	{
		*(str + pos) = '\0';
		size = pos + 1;
	}
	else{
		size_type i = 0;
		while (*(str + pos + len + i) != '\0')
		{
			*(str + pos + i) = *(str + pos + len + i);
			i++;
		}
		size -= len;
		*(str + size) = '\0';
	}
	return *this;
}
//----Replace portion of Mystring
MyString& MyString::replace(size_type pos, size_type len, const MyString& str){
	if (pos < 0 || pos > size){ return *this; }
	reserve(size + str.size - len);
	MyString t = this->str + pos + len;
	memcpy(this->str + pos, str.str, str.size + 1);
	size = strlen(this->str);
	append(t);
	return *this;
}
MyString& MyString::replace(size_type pos, size_type len, const MyString& str,
	size_type subpos, size_type sublen){
	MyString t(str, subpos, sublen);
	return replace(pos, len, t);
}
MyString& MyString::replace(size_type pos, size_type len, const char* s){
	if (pos < 0 || pos > size){ return *this; }
	reserve(size + strlen(s) - len);
	MyString t = this->str + pos + len;
	memcpy(this->str + pos, s, strlen(s) + 1);
	size = strlen(this->str);
	append(t);
	return *this;
}
MyString& MyString::replace(size_type pos, size_type len, const char* s, size_type n){
	MyString t(s, n);
	return replace(pos, len, t);
}
MyString& MyString::replace(size_type pos, size_type len, size_type n, char c){
	MyString t(n, c);
	return replace(pos, len, t);
}
//----Swap Mystring values
void MyString::swap(MyString& str){
	char* s = this->str;
	this->str = str.str;
	str.str = s;

	size_type t = size;
	size = str.size;
	str.size = t;

	t = capacity;
	capacity = str.capacity;
	str.capacity = t;
}
//----Delete last character
void MyString::pop_back(){
	reserve(size - 1);
	*(str + size) = '\0';
}
//----Get C Mystring equivalent
const char* MyString::c_str() const{
	return str;
}
//----Get Mystring data 
const char* MyString::data() const{
	return str;
}
//----Copy sequence of characters from Mystring
size_type MyString::copy(char* s, size_type len, size_type pos) const{
	if (pos > size)
	{
		return 0;
	}
	if (len + pos > size)
	{
		size_type i = 0;
		while (*(str + pos + i) != '\0')
		{
			*(s + i) = *(str + pos + i);
			i++;
		}
		return size - pos;
	}
	else
	{
		for (size_type i = 0; i < len; i++)
		{
			*(s + i) = *(str + pos + i);
		}
	}
	return len;
}
//----Find content in Mystring
size_type MyString::find(const MyString& str, size_type pos) const{
	for (size_type i = 0; this->str[i] != '\0'; i++)
	{
		size_type k = 0;
		for (size_type j = i; this->str[j] == str.str[k] && str.str[k] != '\0'; j++, k++)
		{
			if (k + 1 == str.size)
			{
				return i;
			}

		}
	}
	return npos;
}
size_type MyString::find(const char* s, size_type pos) const{
	MyString t(s);
	return find(t);
}
size_type MyString::find(const char* s, size_type pos, size_type n) const{
	for (size_type i = pos; this->str[i] != '\0'; i++)
	{
		size_type k = 0;
		for (size_type j = i; this->str[j] == s[k] && s[k] != '\0'; j++, k++)
		{
			if (k + 1 == n)
			{
				return i;
			}

		}
	}
	return npos;
}
size_type MyString::find(char c, size_type pos) const{
	if (pos > size)
	{
		return npos;
	}
	else
	{
		for (size_type i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == c)
			{
				return i;
			}
		}
		return npos;
	}
}
//----Find last occurrence of content in Mystring
size_type MyString::rfind(const MyString& str, size_type pos) const{
	size_type Id = npos;
	for (size_type i = 0; this->str[i] != '\0'; i++)
	{
		size_type k = 0;
		for (size_type j = i; this->str[j] == str.str[k] && str.str[k] != '\0'; j++, k++)
		{
			if (k + 1 == str.size)
			{
				Id = i;
			}
		}
	}
	if (Id != npos)
	{
		return Id;
	}
	return npos;
}
size_type MyString::rfind(const char* s, size_type pos) const{
	MyString t(s);
	return rfind(t);
}
size_type MyString::rfind(const char* s, size_type pos, size_type n) const{
	size_type Id = npos;
	for (size_type i = pos; this->str[i] != '\0'; i++)
	{
		size_type k = 0;
		for (size_type j = i; this->str[j] == s[k] && s[k] != '\0'; j++, k++)
		{
			if (k + 1 == n)
			{
				Id = i;
			}
		}
	}
	if (Id != npos)
	{
		return Id;
	}
	return npos;
}
size_type MyString::rfind(char c, size_type pos) const{
	size_type Id = npos;
	for (size_type i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
		{
			Id = i;
		}
	}
	if (Id != npos)
	{
		return Id;
	}
	return npos;
}
//----Find character in Mystring
size_type MyString::find_first_of(const MyString& str, size_type pos) const{
	for (size_type i = 0; this->str[i] != '\0'; i++)
	{
		for (size_type j = 0; j < str.size; j++)
		{
			if (*(this->str + i) == *(str.str + j))
			{
				return i;
			}
		}
	}
	return -1;
}
size_type MyString::find_first_of(const char* s, size_type pos) const{
	MyString t(s);
	return find_first_of(t);
}
size_type MyString::find_first_of(const char* s, size_type pos, size_type n) const{
	if (n >= this->size)
	{
		n = this->size;
	}
	for (size_type i = pos; this->str[i] != '\0'; i++)
	{
		for (size_type j = 0; j < n; j++)
		{
			if (*(this->str + i) == *(s + j))
			{
				return i;
			}
		}
	}return -1;
}
size_type MyString::find_first_of(char c, size_type pos) const{
	MyString t(1,c);
	return find_first_of(t);
}
//----Find character in Mystring from the end
size_type MyString::find_last_of(const MyString& str, size_type pos) const{
	size_type Id = npos;
	for (size_type i = 0; this->str[i] != '\0'; i++)
	{
		for (size_type j = 0; j < str.size; j++)
		{
			if (*(this->str + i) == *(str.str + j))
			{
				Id = i;
			}
		}
	}
	if (Id != npos)
	{
		return Id;
	}
	return npos;
}
size_type MyString::find_last_of(const char* s, size_type pos) const{
	MyString t(s);
	return find_last_of(t);
}
size_type MyString::find_last_of(const char* s, size_type pos, size_type n) const{
	size_type Id = npos;
	if (n >= this->size)
	{
		n = this->size;
	}
	for (size_type i = pos; this->str[i] != '\0'; i++)
	{
		for (size_type j = 0; j < n; j++)
		{
			if (*(this->str + i) == *(s + j))
			{
				Id = i;
			}
		}
	}
	if (Id != npos)
	{
		return Id;
	}
	return npos;
}
size_type MyString::find_last_of(char c, size_type pos) const{
	MyString t(1, c);
	return find_first_of(t);
}
//----Find absence of character in Mystring
size_type MyString::find_first_not_of(const MyString& str, size_type pos) const{
	for (size_type i = 0; this->str[i] != '\0'; i++)
	{
		bool flag = true;
		for (size_type j = 0; j < str.size; j++)
		{
			if (*(this->str + i) == *(str.str + j))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			return i;
		}
	}
	return -1;
}
size_type MyString::find_first_not_of(const char* s, size_type pos) const{
	MyString t(s);
	return find_first_not_of(t);
}
size_type MyString::find_first_not_of(const char* s, size_type pos, size_type n) const{
	if (n >= this->size)
	{
		n = this->size;
	}
	for (size_type i = pos; this->str[i] != '\0'; i++)
	{
		bool flag = true;
		for (size_type j = 0; j < n; j++)
		{
			if (*(this->str + i) == *(s + j))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			return i;
		}
	}
	return -1;

}
size_type MyString::find_first_not_of(char c, size_type pos) const{
	MyString t(1, c);
	return find_first_not_of(t);
}
//----Find non - matching character in Mystring from the end
size_type MyString::find_last_not_of(const MyString& str, size_type pos) const{
	size_type Id = npos;
	for (size_type i = 0; this->str[i] != '\0'; i++)
	{
		bool flag = true;
		for (size_type j = 0; j < str.size; j++)
		{
			if (*(this->str + i) == *(str.str + j))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			Id = i;
		}
	}
	if (Id != npos)
	{
		return Id;
	}
	return -1;
}
size_type MyString::find_last_not_of(const char* s, size_type pos) const{
	MyString t(s);
	return find_last_not_of(t);
}
size_type MyString::find_last_not_of(const char* s, size_type pos, size_type n) const{
	size_type Id = npos;
	if (n >= this->size)
	{
		n = this->size;
	}

	for (size_type i = pos; this->str[i] != '\0'; i++)
	{
		bool flag = true;
		for (size_type j = 0; j < n; j++)
		{
			if (*(this->str + i) == *(s + j))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			Id = i;
		}
	}
	if (Id != npos)
	{
		return Id;
	}
	return -1;

}
size_type MyString::find_last_not_of(char c, size_type pos) const{
	MyString t(1, c);
	return find_last_not_of(t);
}
//----Generate subMystring
MyString MyString::substr(size_type pos) const{
	MyString t(str, pos, size - pos);
	return t;
}
MyString MyString::substr(size_type pos, size_type len) const{
	MyString t(str, pos, len);
	return t;
}
//----Compare Mystrings
int MyString::compare(const MyString& str) const{
	char* p = this->str;
	const char* q = str.str;
	while (*p != '\0' && *q != '\0')
	{
		if (*p != *q)
		{
			return *p - *q;
		}
		else
		{
			p++; q++;
		}
	}
	return *p - *q;
}
int MyString::compare(size_type pos, size_type len, const MyString& str) const{
	if (pos < 0 || pos > size)
	{
		return -1;
	}
	MyString t(this->str, pos, len);
	return t.compare(str);
}
int MyString::compare(size_type pos, size_type len, const MyString& str,
	size_type subpos, size_type sublen) const{
	if (pos < 0 || pos > size || subpos < 0 || subpos > str.size)
	{
		return -1;
	}

	MyString p(this->str, pos, len);
	MyString q(str, subpos, sublen);
	return p.compare(q);
}
int MyString::compare(const char* s) const{
	MyString t(s);
	return this->compare(t);
}
int MyString::compare(size_type pos, size_type len, const char* s) const{
	MyString t(s);
	return this->compare(pos, len, t);
}
int MyString::compare(size_type pos, size_type len, const char* s, size_type n) const{
	if (pos < 0 || pos >= size)
	{
		return -1;
	}

	char* p = this->str + pos;
	const char* q = s;

	while (len > 0 && n > 0)
	{
		if (*p != *q)
		{
			return *p - *q;
		}
		else
		{
			p++; q++;
			n--; len--;
		}
	}
	if (len > 0)
	{
		return 1;
	}
	else if (n > 0)
		return -1;
	return *p - *q;
}
//----Exchanges the values of two Mystrings
void swap(MyString& x, MyString& y){
	MyString t = x;
	x = y; 
	y = t;
}
//----Insert Mystring into stream
istream& operator>> (istream& is, MyString& str){
	char buff[128];
	is.width(128);
	is >> buff;
	str = buff;
	return is;
}
ostream& operator<< (ostream& os, const MyString& str){
	if (str.str != NULL){ os << str.str; }
	else{ os << ""; }
	return os;
}
//----Get line from stream into Mystring
istream& getline(istream& is, MyString& str, char delim){
	char buff[128];
	is.width(128);
	is.getline(buff, 128, delim);
	str = buff;
	return is;
}
istream& getline(istream& is, MyString& str){
	char buff[128];
	is.width(128);
	is.getline(buff, 128);
	str = buff;
	return is;
}

