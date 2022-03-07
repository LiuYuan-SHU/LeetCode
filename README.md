# LeetCode Note

> Created on 7th, Mar, 2022

## Linear Questions

### add-two-numbers

#### [Question](https://leetcode-cn.com/problems/add-two-numbers/submissions/)

#### [Resolution](./add-two-numbers.cpp)

![add-two-numbers 运行结果](README.assets/image-20220307172620775-16466451947221.png)

<center><b>Result</b></center>

#### Idea

![数据结构示意](README.assets/image-20220307172932511.png)

<center><b>Data Structure</b></center>

1. Save memory by selecting a longer linked list to operate on

    ```cpp
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
    ```

2. If both lists have nodes, the process is normal

    ```cpp
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
    ```

3. When the shorter chain ends, the remaining part of longer chain is connected directly, only carrying is considered

    ```cpp
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
    ```

    