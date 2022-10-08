Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?

---------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:  
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode *tmp = head;
        while (tmp) {
            len++;
            tmp = tmp -> next;
        }
        ListNode *headMid = head;
        int cnt = 1;
        while (headMid && (cnt <= len / 2 + len % 2)) {
            headMid = headMid -> next;
            cnt++;
        }
        headMid = reverseList(headMid);
        while (headMid) {
            if (head -> val != headMid -> val) {
                return false;
            }
            head = head -> next;
            headMid = headMid -> next;
        }
        return true;
    }
    
    
    ListNode* reverseList(ListNode* head) {
        ListNode *h = new ListNode(0, head);
        ListNode *p = head, *q;
        h -> next = NULL;
        while (p) {
            q = p -> next;
            p -> next = h -> next;
            h -> next = p;
            p = q;
        }
        return h -> next;
    }

};
