#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) 
{
	if(s.size() == 0 || s.size() == 1)
	{
		return s;
	}
	else if(s.size() == 2)
	{
		return s[0] == s[1] ? s : string(1,s[0]);
	}
	
	string* result = new string();
	const char* str = s.c_str();
	
	char repeat;
	unsigned length = 0;
	for(size_t i = 0; i < s.size(); length = 0,i++)
	{
		repeat = str[i];
		do
		{
			i++;
			length++;
		}while(i < s.size() && repeat == str[i]);
		i--;
		result =  result->size() >= length ? result : new string(length, repeat); 
	}
	
	int offset = 0;
	for(size_t i = 1; i < s.size(); offset = 0, i++)
	{
		if(str[i - 1] == str[i] && result->size() < 2)
		{
			result = new string(2, str[i - 1]);
		}
		do 
		{
			offset++;
		}while(offset <= i && offset < (s.size() - i) && str[i - offset] == str[i + offset]);
		offset--;
		result = result->size() >= (1 + 2 * offset) ? result : (new string(&str[i - offset],2 * offset + 1));
	}
	
	return *result;
}

void test(string input)
{
	cout << longestPalindrome(input) << endl;
}

int main()
{
	test("tattarrattat");
}
