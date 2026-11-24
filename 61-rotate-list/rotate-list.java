/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null || k==0 || head.next==null)return head;
        int len =0;
        ListNode last=null, root=head,tail=head, newHead=head;
        while(head!=null){
            len++;
            last=head;
            head=head.next;
            
        }
        if(k%len==0)return newHead;
        k=k%len;

        int rem=len-k;

        while(rem!=0){
            rem--;
            if(rem==0){
                newHead=root.next;
                 root.next=null;
                 last.next=tail;   
            }
            root=root.next;
        }

        return newHead;
    }
}