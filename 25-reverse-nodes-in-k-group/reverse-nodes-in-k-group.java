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

    ArrayList<ListNode> rev(ListNode root, int k){
        ListNode temp,prev=null,oldhead=root;
        while(k>0){
            temp=root.next;
            root.next=prev;
            prev=root;
            root=temp;
             k--;
        }
        return new ArrayList<>(Arrays.asList(prev,oldhead,root));
    }

    public ListNode reverseKGroup(ListNode head, int k) {
         if (head == null || k <= 1) return head;
        int len =0;

        ListNode slow=head, fast=head, originalhead=null;
        int n=0;
        while(fast!=null && fast.next !=null){
            slow=slow.next;
            fast=fast.next.next;
            n++;
        }

        if(fast==null) len = n*2;
        else len=n*2+1;

        int time=len/k;
         ListNode tail=null, hd=head;

        while(time>0){
            time--;
           ArrayList<ListNode> var = rev(hd,k);
            ListNode newhead = var.get(0);
            ListNode oldhead = var.get(1);
            ListNode nxt = var.get(2);
           if(tail!=null){
            tail.next=newhead;
           }
           if(originalhead==null){
                originalhead=newhead;
           }
           tail=oldhead;
            hd=nxt;
        }

        if(tail!=null){
            tail.next=hd;
        }
        return originalhead;
    }
}