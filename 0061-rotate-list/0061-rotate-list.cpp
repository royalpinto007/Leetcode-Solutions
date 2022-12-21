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
    ListNode* rotateRight(ListNode* head, int k) {

        ListNode* cur=head;
        int length=0;
        
        // base case
        if(k<=0|| head==NULL||head->next==NULL)
            return head;

        // Find length of the linked list
        while(cur){
            cur=cur->next;
            length++;
        }
        // set the number of rotations
        k=k%length;

        //Return head if no rotation is required
        if(k==0){
            return head;
        }

        //set the current node as head and iterate till the node  after which we would need to bring it forward.
        cur=head;
        int n=length-k;
        while(--n){
            cur=cur->next;
        }

        //set temp as the node next to the current node
        ListNode* temp=cur->next;

        //set the next of current node as NULL 
        cur->next=NULL;

        //set head1 as temp(from which we need to bring forward)
        ListNode* head1=temp;

        //iterate to the end
        while(temp->next){
            temp=temp->next;
        }
        //set the next of the last node as head.
        temp->next=head;
        
        return head1;

    } 
};