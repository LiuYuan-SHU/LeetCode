#include <iostream>
#include <string>
#include <vector>

using namespace std;

//My own solution 
string convert(string s, int numRows)
{
	// handle special condtion
	if (numRows <= 1 || s.size() <= 2)
	{
		return s;
	}
	// record the basic data of string
	size_t length_input = s.size();
	char* str_input = const_cast<char*>(s.c_str());
	
	// record current length of result
	size_t length_result = 0;
	// create an array to store the new string
	char* str_result = new char[length_input + 1];

	// handle special condition
	if (numRows == 2)
	{
		// record the half length of input
		size_t length_input_half = (length_input + length_input % 2) / 2;
		char* firstLine = str_result;
		char* secondLine = str_result + length_input_half;
		while (str_input < s.c_str() + length_input)
		{
			*(firstLine++) = *(str_input);
			str_input++;
			if (str_input == s.c_str() + length_input)
			{
				break;
			}
			*(secondLine++) = *(str_input);
			str_input++;
		}
		return string(secondLine - length_input, secondLine);
	}

	// handle normal condition
	const int offset_max = 2 * (numRows - 3) + 3 + 1;
	char* originStart = const_cast<char*>(s.c_str());
	int offset_up = 0;
	int offset_down = offset_max;

	while (str_input < s.c_str() + numRows)
	{
		while (length_result < s.size() && str_input < s.c_str() + length_input)
		{
			// if offset_down is 0, reaches the last string
			if (offset_down && str_input < s.c_str() + length_input)
			{
				str_result[length_result++] = *(str_input);
				str_input += offset_down;
			}
			// if offset_up is 0, reaches the first string
			if (offset_up && str_input < s.c_str() + length_input)
			{
				str_result[length_result++] = *(str_input);
				str_input += offset_up;
			}
		}
		str_input = ++originStart;
		offset_down -= 2;
		offset_up = offset_max - offset_down;
	}

	return string(str_result, length_result);
}

//copied from the fastest solution on leetcode-cn.com
class Solution
{
public:
	static string convert(string s, int numRows)
	{
		//Record the minimum string length
		size_t min = s.size() <= numRows ? s.size() : numRows;
		//Special case processing
		if (min == 1) { return s; }

		//Create vector, its length is `numRows` 
		//Each elem is a string
		vector<string> row(min);
		int ret = 0;			//index of elems in vector
		bool dir = false;		//determin direction
		for (auto ch : s)
		{
			//Appends the character to the end of the corresponding string
			row[ret] += ch;
			//Determine the direction according to dir
			if ((ret == 0) || (ret == numRows - 1))
			{
				dir = !dir;
			}
			//
			ret += dir ? 1 : -1;
		}
		//Put everything in the vector into string 
		string res = "";
		for (auto str : row)
		{
			res += str;
		}
		return res;
	}
};

int main()
{
	string s = "ABCDE";
	int numRows = 2;

	cout << Solution::convert(s, numRows);
}
