public class Solution {

    //User need to handle I/O in main function accordingly

    public int climbStairs(int A) {
        int[] st = new int[A+1];
        
        if(A==0 || A==1){
            return 1;
        }
        if(A==2) {
            return 2;
        }
        st[0] = 1;
        st[1] = 1;
        st[2] = 2;
        
        for(int i=2;i<A;i++) {
            st[i] = st[i-1] + st[i-2];
        }
        
        return st[A];
    }
}
