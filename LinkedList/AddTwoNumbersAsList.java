/**
 * Definition for singly-linked list.
 * class ListNode {
 *     public int val;
 *     public ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
public class Solution {

    //User need to handle I/O in main function accordingly

    public ListNode addTwoNumbers(ListNode A, ListNode B) {
        int sum = 0;
        int carry = 0;
        boolean complete = false;
        ListNode T = B;

        while(A!=null || B!=null) {

            sum = A.val + B.val + carry;
            carry = sum/10;
            B.val = sum%10;
            if(A.next == null && B.next==null){
                complete = true;
                break;
            }
            if(A.next == null || B.next==null){
                break;
            }else{
                A=A.next;
                B=B.next;
            }
        }
        
        
        if(complete){
            return T;
        }
        
        
        if(A.next==null){

            while(B.next!=null){
                B = B.next;
                sum = carry + B.val;
                B.val = sum%10;
                carry = sum/10;
                
                if(B.next == null && carry!=0){
                    B.next = new ListNode(carry);
                    break;
                }
            }
        }
        
        if(B.next==null){
            while(A.next!=null){
                A = A.next;
                sum = carry + A.val;
                B.next = new ListNode(sum%10);
                carry = sum/10;
                B = B.next;
                if(A.next == null && carry!=0){
                    B.next = new ListNode(carry);
                    break;
                }
            }
        }
        
        return T;
    }
}
