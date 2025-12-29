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
     ListNode reverseList(ListNode head){
        ListNode dummy=null;

        while(head!=null){
            ListNode  temp=head.next;
          head.next=dummy;
          dummy=head;
          head=temp;
        }

        return dummy;
    }
    public boolean isPalindrome(ListNode head) {
        ListNode slow=head,fast=head;
        ListNode curr=head;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        ListNode newhead;
        if(fast==null) newhead=reverseList(slow);
        else newhead=reverseList(slow.next);
        

        while(curr!=null && newhead!=null){
            if(curr.val!=newhead.val)return false;
            curr=curr.next;
            newhead=newhead.next;
        }
        return true;
    }
}