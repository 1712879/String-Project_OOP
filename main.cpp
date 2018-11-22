#include"MyString.h"
#include <fstream>
#include <string>


int main(){
	/*MyString s0("Initial string");
	MyString s1;
	MyString s2(s0);
	MyString s3(s0, 8, 3);
	MyString s4("A character sequence");
	MyString s5("Another character sequence", 12);
	MyString s6a(10, 'x');
	MyString s6b(10, 42);
	cout << "s1: " << s1.getMyString() << endl;
	cout << "s2: " << s2.getMyString() << endl;
	cout << "s3: " << s3.getMyString() << endl;
	cout << "s4: " << s4.getMyString() << endl;
	cout << "s5: " << s5.getMyString() << endl;
	cout << "s6a: " << s6a.getMyString() << endl;
	cout << "s6b: " << s6b.getMyString() << endl;
	
	MyString str1, str2;
	str1 = "Test string: "; 
	str2 = 'x';

	std::cout << str1.getMyString() << endl;
	std::cout << str2.getMyString() << endl;

	MyString str("Test string");
	cout << endl;
	for (MyString::iterator i = str.begin(); i != str.end(); i++)
	{
		cout << *i;
	}
	cout << endl;

	MyString str3("now step live...");
	cout << endl;
	for (MyString::reverse_iterator i = str3.rbegin(); i != str3.rend(); i++)
	{
		cout << *i;
	}
	cout << endl;

	MyString str4("Lorem ipsum");
	cout << endl;
	for (auto i = str4.cbegin(); i != str4.cend(); i++)
	{
		cout << *i;
	}
	cout << endl;

	for (auto it = str4.crbegin(); it != str4.crend(); it++)
	{
		cout << *it;
	}
	cout << endl;*/
	
	/*MyString str("I like to code in C");
	cout << str.getMyString() << endl;
	unsigned int n = str.size();
	str.resize(n + 2, '+');
	cout << str.getMyString() << endl;
	str.resize(14);
	cout << str.getMyString() << endl;*/

	/*char c;
	MyString str;
	cout << "Please type some lines of text. Enter a dot (.) to finish:\n";
	do
	{
		c = cin.get();
		str.operator+=(c);
		if (c == '\n')
		{
			cout << str.getMyString() << endl;
			str.clear();
		}
	} while (c != '.');*/

	/*MyString str("This is test demo");
	if (!str.empty())
	{
		cout << str.getMyString() << endl;
	}
	else
	{
		cout << "str is Empty" << endl;
	}*/
	MyString str(100, 'x');
	
	cout << str.getMyString() << endl;
	cout <<" 1. capacity of str : " << str.capacity() << endl;;
	str.resize(10);
	cout << "2. capacity of str: " << str.capacity() << endl;

	return 0;
}