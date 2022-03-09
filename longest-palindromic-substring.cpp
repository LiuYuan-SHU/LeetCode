#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) 
{
	//`head` points the first char of the longest p-substring
	//`tail` points the last char of the longest p-substring
	//`max_length` records   length of thelogest p-substring
	size_t head = 0,tail = 0,max_len = 0;
	//`left` points the left side of current p-subsreing
	//`right` points the right side of current p-substring
	//`nextLeft` records the next value of `left`
	int left = 0,right = 0,nextLeft = 0;
	
	while(true)
	{
		//after this loop, chars on sides of current p-substring are different from `s[left]` 
		while(s[left] == s[right] && right < s.size()) { right++; }
		//the chars between `left` and `right` are the same
		//so it's easy to prove that the first probable head of the new p-substring is `right`
		nextLeft = right;			//Record the position where the next loop starts
		//since `right` now points the first different char
		//`right--` to make it points the last same char
		right--;
			
		//Center extension algorithm
		while(left >= 0 && right < s.size() && s[left] == s[right])
		{
			//if the length of current p-substring is longer
			//record the new head, tail, max_len
			if(max_len < right - left + 1)
			{
				max_len = right - left + 1;
				head = left;
				tail = right;
			}
			//extend window
			left--;
			right++;
		}	
		//set points to the position where the next loop starts
		left = right = nextLeft;
		//if left reachs the end of the string, traversal is finished
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
