#include"MyString.h"


void Test_Constructor();
void Test_Operator();
void Test_Iterators();
void Test_Capacity();
void Test_Append();
void Test_Assign();
void Test_Insert();
void Test_Replace();
void Test_Find();
void Test_Rfind();
void Test_find_first_of();
void Test_find_last_of();
void Test_find_first_not_of();
void Test_find_last_not_of();
void Test_compare();
void Test_Mystring_operations();

int main(){
	Test_Constructor();
	Test_Operator();
	Test_Iterators();
	Test_Capacity();
	Test_Append();
	Test_Assign();
	Test_Insert();
	Test_Replace();
	Test_Find();
	Test_Rfind();
	Test_find_first_of();
	Test_find_last_of();
	Test_find_first_not_of();
	Test_find_last_not_of();
	Test_compare();
	Test_Mystring_operations();
	return 0;
}
void Test_Constructor(){
	cout << "---Test_Constructor:---\n";
	MyString s0("Initial string");
	MyString s1;
	MyString s2(s0);
	MyString s3(s0, 8, 3);
	MyString s4("A character sequence");
	MyString s5("Another character sequence", 12);
	MyString s6a(10, 'x');
	MyString s6b(10, 42);
	MyString s7(s0.begin(), s0.begin() + 7);
	cout << "s1: " << s1.getMyString() << endl;
	cout << "s2: " << s2.getMyString() << endl;
	cout << "s3: " << s3.getMyString() << endl;
	cout << "s4: " << s4.getMyString() << endl;
	cout << "s5: " << s5.getMyString() << endl;
	cout << "s6a: " << s6a.getMyString() << endl;
	cout << "s6b: " << s6b.getMyString() << endl;
	cout << "s7: " << s7.getMyString() << endl;
}
void Test_Operator(){
	cout << "---Test_Operator:---\n";
	MyString str1, str2, str3;
	MyString s0("Initial string");
	str1 = "Test string: ";
	str2 = 'x';
	str3 += str1;
	str3 += "key";
	str3 += 'x';

	std::cout << str1.getMyString() << endl;
	std::cout << str2.getMyString() << endl;
	std::cout << str3.getMyString() << endl;
}
void Test_Iterators(){
	cout << "---Test_Iterators:---\n";
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
	cout << endl;
}
void Test_Capacity(){
	cout << "---Test_Capacity:---\n";
	MyString str("Test string");
	cout << "size: " << str.getSize() << "\n";
	cout << "length: " << str.getLength() << "\n";
	cout << "capacity: " << str.getCapacity() << "\n";
	cout << "max_size: " << str.max_size() << "\n";
}
void Test_Append(){
	cout << "---Test_Append:---\n";
	MyString str;
	MyString str2 = "Writing ";
	MyString str3 = "print 10 and then 5 more";
	str.append(str2);                       // "Writing "
	str.append(str3, 6, 3);                   // "10 "
	str.append("dots are cool", 5);          // "dots "
	str.append("here: ");
	str.append(10u, '.');
	str.append(str3.begin() + 8, str3.end()); // " and then 5 more"
	cout << str.getMyString() << endl;
}
void Test_Assign(){
	cout << "---Test_Assign:---\n";
	MyString str;
	MyString base = "The quick brown fox jumps over a lazy dog.";
	str.assign(base);
	cout << str.getMyString() << endl;
	str.assign(base, 10, 9);
	cout << str.getMyString() << endl;
	str.assign("pangrams are cool", 7);
	cout << str.getMyString() << endl;
	str.assign("c-string");
	cout << str.getMyString() << endl;
	str.assign(10, '*');
	cout << str.getMyString() << endl;
	str.assign(10, 0x2D);
	cout << str.getMyString() << endl;
	str.assign(base.begin() + 16, base.end() - 12);
	cout << str << '\n';     
}
void Test_Insert(){
	cout << "---Test_Insert:---\n";
	MyString str = "to be question";
	MyString str2 = "the ";
	MyString str3 = "or not to be";

	str.insert(6, str2);
	cout << str.getMyString() << endl;
	str.insert(6, str3, 3, 4);
	cout << str.getMyString() << endl;
	str.insert(10, "that is cool", 8);
	cout << str.getMyString() << endl;
	str.insert(10, "to be ");
	cout << str.getMyString() << endl;
	str.insert(15, 1, ':');
	cout << str.getMyString() << endl;
	str.insert(str.end(), 3, '.');
	cout << str.getMyString() << endl;
	MyString::iterator it = str.insert(str.begin() + 5, ',');
	cout << str.getMyString() << endl;
	str.insert(it + 2, str3.begin(), str3.begin() + 3);
	cout << str.getMyString() << endl;
}
void Test_Replace(){
	cout << "---Test_Replace:---\n";
	MyString base = "this is a test string.";
	MyString str2 = "n example";
	MyString str3 = "sample phrase";
	MyString str4 = "useful.";

	MyString str;
	str = base;
	cout << str.getMyString() << endl;
	str.replace(9, 5, str2);
	cout << str.getMyString() << endl;
	str.replace(19, 6, str3, 7, 6);
	cout << str.getMyString() << endl;
	str.replace(8, 10, "just a");
	cout << str.getMyString() << endl;
	str.replace(8, 6, "a shorty", 7);
	cout << str.getMyString() << endl;
	str.replace(22, 1, 3, '!');
	cout << str.getMyString() << endl;

	str.replace(str.begin(), str.end() - 3, str3);
	cout << str.getMyString() << endl;
	str.replace(str.begin(), str.begin() + 6, "replace");
	cout << str.getMyString() << endl;
	str.replace(str.begin() + 8, str.begin() + 14, "is coolness", 7);
	cout << str.getMyString() << endl;
	str.replace(str.begin() + 12, str.end() - 4, 4, 'o');
	cout << str.getMyString() << endl;
	str.replace(str.begin() + 11, str.end(), str4.begin(), str4.end());
	cout << str.getMyString() << endl;
}
void Test_Find(){
	cout << "---Test_Find:---\n";
	MyString str("There are two needles in this haystack with needles.");
	MyString str2("needle");

	size_t found = str.find(str2);
	if (found != -1){
		cout << "first 'needle' found at: " << found << '\n';
	}
	found = str.find("needles are small", found + 1, 6);
	if (found != -1)
		cout << "second 'needle' found at: " << found << '\n';

	found = str.find("haystack");
	if (found != -1)
		cout << "'haystack' also found at: " << found << '\n';

	found = str.find('.');
	if (found != -1)
		cout << "Period found at: " << found << '\n';
	str.replace(str.find(str2), str2.getSize(), "preposition");
	cout << str.getMyString() << '\n';
}
void Test_Rfind(){
	cout << "---Test_Rfind:---\n";
	MyString str("The sixth sick sheik's sixth sheep's sick.");
	MyString key("sixth");

	int found = str.rfind(key);
	if (found != -1)
		str.replace(found, key.getSize(), "seventh");
	cout << str.getMyString() << '\n';
}
void Test_find_first_of(){
	cout << "---Test_find_first_of:---\n";
	MyString str("Please, replace the vowels in this sentence by asterisks.");
	int found = str.find_first_of("aeiou");
	while (found != -1)
	{
		str[found] = '*';
		found = str.find_first_of("aeiou", found + 1);
	}

	cout << str.getMyString() << '\n';
}
void Test_find_last_of(){
	cout << "---Test_find_last_of:---\n";
	MyString str1("/usr/bin/man");
	MyString str3("/\\");
	cout << "Splitting: " << str1.getMyString() << '\n';
	cout << "Element at Index: " << str1[str1.find_last_of("/\\",0,2)] << "\n";
}
void Test_find_first_not_of(){
	cout << "---Test_find_first_not_of:---\n";
	MyString str("look for non-alphabetic characters...");
	int found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");
	if (found != -1)
	{
		cout << "The first non-alphabetic character is " << str[found];
		cout << " at position " << found << '\n';
	}
}
void Test_find_last_not_of(){
	cout << "---Test_find_last_not_of:---\n";
	MyString str("Please, erase trailing white-spaces   \n");
	MyString whitespaces(" \t\f\v\n\r");
	int found = str.find_last_not_of(whitespaces);
	if (found != -1)
	{
		cout << "The last character is " << str[found] << "\n";
		cout << "Position: " << found << "\n";
	}
	else
		cout << "No found!!!\n";
}
void Test_compare(){
	cout << "---Test_compare:---\n";
	MyString str1("green apple");
	MyString str2("red apple");
	if (str1.compare(str2) != 0)
		cout << str1.getMyString() << " is not " << str2.getMyString() << '\n';

	if (str1.compare(6, 5, "apple") == 0)
		cout << "still, " << str1.getMyString() << " is an apple\n";

	if (str2.compare(str2.getSize() - 5, 5, "apple") == 0)
		cout << "and " << str2.getMyString() << " is also an apple\n";

	if (str1.compare(6, 5, str2, 4, 5) == 0)
		cout << "therefore, both are apples\n";
}
void Test_Mystring_operations(){
	cout << "---Test_Mystring_operations:---\n";
	MyString str("Hello");
	MyString str1;
	cin >> str1;
	cout << str << " " << str1 << "\n";
}
