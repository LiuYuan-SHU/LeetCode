#include<iostream>
#include<stack>

#define nullptr NULL

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode *l1_i = l1;		//traverse list
			int length1 = 0;			//store the length of the list
			ListNode *l2_i = l2;
			int length2 = 0;
			//get the length of two lists
			while (l1_i) {
				++length1;
				l1_i = l1_i->next;
			}
			while (l2_i) {
				++length2;
				l2_i = l2_i->next;
			}
			//operate on the longer list
			bool longer = (length1 >= length2);
			ListNode* list = longer ? l1 : l2;		//save the longer list in list
			ListNode* other = !longer ? l1 : l2;	//save the shorter list in other
			ListNode* origin = list;
			ListNode* previous = nullptr;

			int carry = 0;							//store carry
			//while both not reach the end
			while(list && other) {
				//val operation
				list->val += other->val + carry;
				carry = list->val / 10;
				list->val %= 10;				
				//pointer operation
				previous = list;
				list = list->next;
				other = other->next;
			}
			//if the longer list not reach the end
			while(list) {
				//val operation
				list->val += carry;
				carry = list->val / 10;
				list->val %= 10;				
				//pointer operation
				previous = list;
				list = list->next;
			}
			if(carry)
			{
				previous->next = new ListNode(carry);
			}

			return origin;
		}
		static void printList(ListNode* head) {
			cout << '[';
			while(head) {
				cout << head->val;
				head = head->next;
				if(head) { cout << ','; }
			}
			cout << ']' << endl;
		}

};

class Test {
	public:
		static void test1() {
			ListNode *l1,*l2;
			l1 = new ListNode(9,new ListNode(9,new ListNode(9,new ListNode(9,new ListNode(9,new ListNode(9,new ListNode(9)))))));
			l2 = new  ListNode(9,new ListNode(9,new ListNode(9,new ListNode(9))));
			ListNode *list = Solution::addTwoNumbers(l1,l2);
			Solution::printList(list);
		}

		static void test2() {
			ListNode *l1,*l2;
			l1 = new ListNode(5);
			l2 = new ListNode(5);
			ListNode *list = Solution::addTwoNumbers(l1,l2);
			Solution::printList(list);
		}

};

int main() {
	Test::test1();
	Test::test2();
}
