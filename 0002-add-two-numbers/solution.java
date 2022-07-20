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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) 
    {
        int carry = 0;
        int digit = 0;
        
        ListNode ans = new ListNode();
        ListNode cur = ans;
        
        ListNode head1, head2;
        head1 = l1; head2 = l2;
        
        while(head1 != null || head2 != null)
        {
            digit = carry;
            if(head1 != null)
            {
                digit += head1.val;
                head1 = head1.next;
            }
            if(head2 != null)
            {
                digit += head2.val;
                head2 = head2.next;
            }
            
            if(digit >= 10)
            {
                digit -= 10;
                carry = 1;
            }
            else carry = 0;
            
            cur.next = new ListNode(digit);
            cur      = cur.next;
        }
        
        if(carry == 1) cur.next = new ListNode(carry);
        return ans.next;
        
        
    }
}
