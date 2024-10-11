class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int sum = 0;
        int carry = 0;
        ListNode* dummyNode = new ListNode(-1);  // Corrected to ListNode
        ListNode* curr = dummyNode;

        while(t1!=NULL || t2!=NULL)
        {
            sum = carry;

            if(t1) sum+=t1->val;
            if(t2) sum+=t2->val;

            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;

            curr->next = newNode;
            curr = curr->next;

            if(t1) t1=t1->next;
            if(t2) t2=t2->next;


        }

        if(carry)
        {
            ListNode* myNode = new ListNode(carry);
            curr->next = myNode;
        }


        return dummyNode->next;

       
      
    }
};
