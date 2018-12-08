/********************************************************************************
 * You are given two non-empty linked lists representing two non-negative 
 * integers. The digits are stored in reverse order and each of their nodes 
 * contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the 
 * number 0 itself.
 * Example:
 *      Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *      Output: 7 -> 0 -> 8
 *
 *      Explanation: 342 + 465 = 807.
 *
 * *****************************************************************************/


#include <iostream>

using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode result(0);
        ListNode* ptr1;
        ListNode* ptr2;

        int l1_len = 0;
        ptr1 = l1;
        while(ptr1){
            l1_len ++;
            ptr1 = ptr1->next;
        }
        
        int l2_len = 0;
        ptr2 = l2;
        while(ptr2){
            l2_len ++;
            ptr2 = ptr2->next;
        }

        if(l2_len > l1_len){
            ptr1 = l2;
            ptr2 = l1;
        }else{
            ptr1 = l1;
            ptr2 = l2;
        }

        result.next = ptr1;
        ptr1 = &result;

        while(ptr2){
            if(ptr1->next == NULL){
                ptr1->next = ptr2;
            }
            ptr1->next->val += ptr2->val + carry;
            if(ptr1->next->val >= 10){
                carry = 1;
                ptr1->next->val -= 10;
            }else{
                carry = 0;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        while(carry){
            if(ptr1->next == NULL){
                ptr1->next = new ListNode(0);
            }
            ptr1->next->val += carry;
            if(ptr1->next->val >= 10){
                carry = 1;
                ptr1->next->val -= 10;
            }else{
                carry = 0;
            }
            ptr1 = ptr1->next;
        }

        return result.next;
    }
};

int main(void)
{
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(8);

    ListNode* l2 = new ListNode(1);

    ListNode* result = Solution().addTwoNumbers(l1, l2);

    while(result){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
