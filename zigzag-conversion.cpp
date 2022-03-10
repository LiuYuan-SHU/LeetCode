#include<iostream>
#include<string>

using namespace std;

string convert(string s, int numRows) 
{
	if(numRows<=1)
	{
		return s;
	}
	//record the basic data of string
	size_t input_length = s.size();
	char* input_str = const_cast<char*>(s.c_str());
	//create an array to store the new string
	size_t cur_length = 0;
	char* str = new char[input_length];
	
	int offset = 0;
	int space = numRows - 2;
	
	if(numRows == 2)
	{
		//debug
		cout << s.c_str() << endl;
		//deal with the first line
		while(cur_length < s.size() && input_str + offset < s.c_str() + input_length)
		{
			str[cur_length++] = *(input_str += offset);
			offset = (offset == 2) ? 1 : 2;
		}
		input_str = const_cast<char*>(s.c_str()) + 1;
		offset = 2;

		str[cur_length++] = *(input_str);
		//deal with the second line
		while(cur_length < s.size() && input_str + offset < s.c_str() + input_length)
		{
			str[cur_length++] = *(input_str += 3);
		}
		
		return string(str,cur_length);
	}

}

int main()
{
	string s = "PAYPALISHIRING";
	int numRows = 2;
	
	cout << convert(s, numRows);
} 
