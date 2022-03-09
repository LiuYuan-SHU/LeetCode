#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) 
{
	size_t head = 0,tail = 0,max_len = 0;
	int left = 0,right = 0,nextLeft = 0;
	
	while(true)
	{
		while(s[left] == s[right] && right < s.size()) { right++; }
		nextLeft = right;
		right--;
		while(left >= 0 && right < s.size() && s[left] == s[right])
		{
			if(max_len < right - left + 1)
			{
				max_len = right - left + 1;
				head = left;
				tail = right;
			}
			left--;
			right++;
		}	
		left = right = nextLeft;
		if(left == s.size()) { break; }	
	}
	
	return string(&s[head], &s[tail + 1]);	
}

void test(string input)
{
	cout << longestPalindrome(input) << endl;
}

int main()
{
	test("a");
	test("aa");
	test("abb");
	test("abccba");
	test("abaabcba");
	test("tattarrattat");
}
