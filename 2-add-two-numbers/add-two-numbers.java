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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ptr=new ListNode(-1);
        ListNode dummy=ptr;
        int carry=0;
        while(l1!=null && l2!=null){
            int sum=l1.val+l2.val+carry;
            l1.val=sum%10;
            carry=sum/10;
            ptr.next=l1;
            l1=l1.next;
            l2=l2.next;
            ptr=ptr.next;
        }
        while(l1!=null){
            int sum=l1.val+carry;
            l1.val=sum%10;
            carry=sum/10;
            ptr.next=l1;
            l1=l1.next;
            ptr=ptr.next;
        }

        while(l2!=null){
            int sum=l2.val+carry;
            l2.val=sum%10;
            carry=sum/10;
            ptr.next=l2;
            l2=l2.next;
            ptr=ptr.next;
        }

        if(carry!=0){
            ptr.next=new ListNode(carry);
            ptr=ptr.next;
        }

        return dummy.next;
    }
}