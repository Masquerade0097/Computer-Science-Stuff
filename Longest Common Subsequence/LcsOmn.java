public class LcsOmn {

    /**  Implementation of longest common subsequence in O(mn) space complexity
     *   and O(mn) space complexity. Also has the backtracking function to print the
     *   complete subsequence.
     */

    static int[][] a;
    static int[][] aux;

    public static int lcs(char[] c, char[] d, int lc, int ld) {

        if(lc == 0|| ld == 0) {
            return 0;
        }

        if(c[lc-1] == d[ld-1]) {
            a[lc][ld] = 1 + lcs(c,d,lc-1,ld-1);
        }
        else {
            a[lc][ld] = imax(lcs(c,d,lc-1,ld), lcs(c,d,lc,ld-1));
        }

        return a[lc][ld];
    }

//    public static int lcsAuxilliary(char[] c, char[] d, int lc, int ld) {
//        for(int i=0; i<2; i++) {
//            for(int j=0; j<d.length-1; j++) {
//                if(i==0) {
//                    aux[i][j] = 0;
//                    continue;
//                }
//
//                if(lc == 0|| ld == 0) {
//                    return 0;
//                }
//
//                if(c[lc-1] == d[ld-1]) {
//                    aux[i][1] = 1 + lcs(c,d,lc-1,ld-1);
//                }
//                else {
//                    aux[i][1] = imax(lcs(c,d,lc-1,ld), lcs(c,d,lc,ld-1));
//                }
//            }
//        }
//    }

    public static void backtrack(char[] c, char[] d, int[][] k) {

        for (int i=c.length-1; i>=0; i--) {
            for(int j=d.length-1; j>=0; j--) {
                if(c[i] == d[j]) {
                    System.out.print(c[i]);
                    i--;
                }else{
                    if(k[i+1][j] < k[i][j+1]) {
                        i--;
                        j++;
                    }
                }
            }
        }
    }

    public static void printFk(int[][] k) {
        for (int i=0; i<k.length; i++) {
            for(int j=0; j<k[0].length; j++) {
                System.out.print(a[i][j]);
            }
            System.out.print("\n");
        }
    }

    public static int imax(int w, int z) {
        return (w > z) ? w : z;
    }

    public static void main(String[] args) {
        String s1 = "ALAKAZAM";
        String s2 = "ANARKMZ";

        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();

        int lc = c1.length;
        int ld = c2.length;

        a = new int[lc+1][ld+1];
        aux = new int[lc+1][2];

        for(int i=0; i<lc+1; i++) {
            a[i][0] = 0;
        }
        for(int i=0; i<ld+1; i++) {
            a[0][i] = 0;
        }

        int res = lcs(c1,c2,lc,ld);
        System.out.println("length - " + res + "\n");

//        System.out.println("length in auxilliary space - " + lcsAuxilliary(c1,c2,lc,ld) + "\n");

        printFk(a);

        System.out.println("\nbacktrack ");
        backtrack(c1,c2,a);
    }
}
