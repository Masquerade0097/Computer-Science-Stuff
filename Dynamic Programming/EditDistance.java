public class Solution {

    //User need to handle I/O in main function accordingly  
    
    public int iMin(int x,int y,int z) {
        if (x<=y && x<=z) return x;
        if (y<=x && y<=z) return y;
        else return z;	
    }
    
    public int minDistance(String A, String B) {
        char[] as = A.toCharArray();
        char[] bs = B.toCharArray();
        int la = as.length;
        int lb = bs.length;
        int[][] a = new int[la+1][lb+1];
        
        for(int i=0;i<=la;i++) {
            for (int j = 0; j <=lb; j++) {
                if (i==0)
                    a[i][j] = j;  
                    
                else if (j==0)
                    a[i][j] = i;
                
                else if(as[i-1] == bs[j-1]) {
                    a[i][j] = a[i - 1][j - 1];
                    
                } else {
                    a[i][j] = 1 + iMin(a[i - 1][j - 1], a[i][j - 1], a[i - 1][j]);
                }
            }
        }
        
        return a[la][lb];
    }
    
}
