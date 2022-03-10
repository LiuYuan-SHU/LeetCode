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
		//��¼��С�ַ�������
		size_t min = s.size() <= numRows ? s.size() : numRows;
		//��С�������
		if (min == 1) { return s; }

		//����vector�����Ƚ�Ϊ��С�ַ�������
		//ÿһ��vectorԪ�ش洢һ���ַ�������һ��Ԫ�ش洢��һ���ַ���
		vector<string> row(min);
		int ret = 0;			//��ret��ȷ��vector�е�Ԫ��
		bool dir = false;		//��dir��ȷ������direction��
		for (auto ch : s)
		{
			//���ַ���ӵ���Ӧ�ַ�����ĩβ
			row[ret] += ch;
			//�������������ַ�������ôת��
			if ((ret == 0) || (ret == numRows - 1))
			{
				dir = !dir;
			}
			//����dir�������һ���ַ���
			ret += dir ? 1 : -1;
		}
		//��vector�е�����ȫ���ŵ�string��
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
