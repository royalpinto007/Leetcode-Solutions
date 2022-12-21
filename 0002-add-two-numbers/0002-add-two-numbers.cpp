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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //new linked list
        ListNode* dummy=new ListNode(0);
        
        ListNode* temp=dummy;
        int carry=0;
        
        // to perform- sum = l1 + l2 + carry
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10); // the value we'll get by moduloing it, will become as new node so. add it to our list 
            temp->next=newnode; // temp will point to that new node if we get
            temp=temp->next; // update the temp every time
        }
        return dummy->next; // return dummy->next because, we don't want the value that we have consider in it intially!!
    }
};