#include <iostream>
#include <string>
#include<vector>

using namespace std;

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
	// create an array to store the new string
	size_t length_result = 0;
	char* str_result = new char[length_input + 1];

	// handle special condition
	if (numRows == 2)
	{
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
			if (offset_down && str_input < s.c_str() + length_input)
			{
				str_result[length_result++] = *(str_input);
				str_input += offset_down;
			}
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

class Solution
{
public:
	static string convert(string s, int numRows)
	{
		//记录最小字符串长度
		size_t min = s.size() <= numRows ? s.size() : numRows;
		//最小情况处理
		if (min == 1) { return s; }

		//创建vector，长度仅为最小字符串长度
		//每一个vector元素存储一个字符串，第一个元素存储第一行字符串
		vector<string> row(min);
		int ret = 0;			//用ret来确定vector中的元素
		bool dir = false;		//用dir来确定方向（direction）
		for (auto ch : s)
		{
			//将字符添加到对应字符串的末尾
			row[ret] += ch;
			//如果到了两侧的字符串，那么转向
			if ((ret == 0) || (ret == numRows - 1))
			{
				dir = !dir;
			}
			//根据dir类决定下一个字符串
			ret += dir ? 1 : -1;
		}
		//将vector中的内容全部放到string中
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
