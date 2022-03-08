#include<iostream>
#include<string>
#include<cstring>

#define nullptr NULL

using namespace std; 

int lengthOfLongestSubstring(string s)
{	
	//Special case handling
	int length = s.size();
	if(!length)
	{
		return 0;
	}
	else if(length == 1)
	{
		return 1;
	}
	
	//record the last index the character appear 
	int lastAppear[128];
	//init as -1 for not appeared
	memset(lastAppear, -1, sizeof(lastAppear));
	
	unsigned indexOfChar = 0;			//the index of array lastAppear
	unsigned max_length = 0;			//the max_length of substring
	unsigned start_index = 0;			//the start index of current substring
	//traverse the string for one time, time complexity = O(n)
	for(size_t i = 0; i < length; i++)
	{
		indexOfChar = s[i];					//get current char, use it's ASC as index
		//Compares the current index of this character to the last occurrence index
		//take "abca" as example, and start_index pointes the first 'a'
		//start_index = 0, lastApper[index] + 1 = "the last occurence index of 'a'" + 1
		//lastAppear[index] + 1 = 1 > start_index
		start_index = start_index > (lastAppear[indexOfChar] + 1) ? start_index : (lastAppear[indexOfChar] + 1);
		//the length of current substring = current index - start_index
		//if the length of current substring is bigger, take this as max_length
		max_length = max_length > (i - start_index + 1) ? max_length : (i - start_index + 1);
		//record the lax occurence index of this char
		lastAppear[indexOfChar] = i;
	}
	
	return max_length;
}

void test1()
{
	string input = " ";
	cout << "origin string: \"" << input << '\"' << endl;
	cout <<  "length of the longest substring: " << lengthOfLongestSubstring(input) << endl;
}

void test2()
{
	string input = "au";
	cout << "origin string: \"" << input << '\"' << endl;
	cout <<  "length of the longest substring: " << lengthOfLongestSubstring(input) << endl;
}

void test3()
{
	string input = "abcbbc";
	cout << "origin string: \"" << input << '\"' << endl;
	cout <<  "length of the longest substring: " << lengthOfLongestSubstring(input) << endl;
}

int main()
{
	test1();
	test2();
	test3();
	
	return 0;
}
