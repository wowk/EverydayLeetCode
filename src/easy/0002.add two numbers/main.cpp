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
        int val = 0;
        ListNode result(0);
        ListNode* ptr = &result;

        while(l1 && l2){
            val += l1->val + l2->val;
            if(val >= 10){
                val -= 10;
                ptr->next = new ListNode(val);
                val = 1;
            }else{
                ptr->next = new ListNode(val);
                val = 0;
            }
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1){
            while(l1){
                val += l1->val;
                if(val >= 10){
                    val -= 10;
                    ptr->next = new ListNode(val);
                    val = 1;
                }else{
                    ptr->next = new ListNode(val);
                    val = 0;
                }
                ptr = ptr->next;
                l1 = l1->next;
            }
        }else if(l2){
            while(l2){
               val += l2->val;
               if(val >= 10){
                   val -= 10;
                   ptr->next = new ListNode(val);
                   val = 1;
               }else{
                   ptr->next = new ListNode(val);
                   val = 0;
               }
               ptr = ptr->next;
               l2 = l2->next;
           }        
        }

        if(val){
            ptr->next = new ListNode(1);
        }

        return result.next;
    }
};

int main(void)
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);

    ListNode* result = Solution().addTwoNumbers(l1, l2);

    while(result){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
