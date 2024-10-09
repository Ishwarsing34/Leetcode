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
    ListNode* reverse(ListNode* head)
    {
        ListNode* temp = head;
        ListNode* prev  = nullptr;
        if(head==NULL || head->next==NULL) return head;
        while(temp!=nullptr)
        {
            ListNode* front = temp->next;
                      temp->next = prev;
                      prev = temp;
                      temp = front;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;

        while(second!=nullptr)
        {
            if(first->val != second->val){
                reverse(newHead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        reverse(newHead);
        return true;
    }
};