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
    ListNode merge(ListNode head,ListNode mid){
        ListNode ptr=new ListNode(-1);
        ListNode dummy=ptr;
        while(head!=null && mid!=null){
            if(head.val<mid.val){
                ptr.next=head;
                head=head.next;
            }
            else{
              ptr.next=mid;
                mid=mid.next;  
            }
            ptr=ptr.next;
        }
        if(head!=null)ptr.next=head;
        else ptr.next=mid;

        return dummy.next;
    }

    ListNode mergesort(ListNode head){
        if(head==null ||  head.next==null)return head;
        ListNode mid,slow=head,fast=head,prev=null;
        while(fast!=null && fast.next!=null){
             prev=slow;
            slow=slow.next;
            fast=fast.next.next;
        }
        mid=slow;
        prev.next=null;

       head= mergesort(head);
       mid= mergesort(mid);
       return merge(head,mid);

    }
    public ListNode sortList(ListNode head) {
        if(head==null || head.next==null )return head;
        return mergesort(head);
    }
}