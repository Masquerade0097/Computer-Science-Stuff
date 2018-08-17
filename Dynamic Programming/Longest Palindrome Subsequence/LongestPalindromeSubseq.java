public class LongestPalindromeSubseq {

    /**
     * This is a different approach to calculate longest palindrome subsequence. Here I'm applying
     * longest common subsequence on a string and it's mirror image string and then \
     * calculating longest common subsequence to get the longest palindrome subsequence.
     * This will take more space complexity but is cool. We all know how to do it the usual
     * DP way.
     */

    static int[][] a;

    public static int lcs(char[] c, char[] d, int lc, int ld) {

        if (lc == 0 || ld == 0) {
            return 0;
        }

        if (c[lc - 1] == d[ld - 1]) {
            a[lc][ld] = 1 + lcs(c, d, lc - 1, ld - 1);
        } else {
            a[lc][ld] = imax(lcs(c, d, lc - 1, ld), lcs(c, d, lc, ld - 1));
        }

        return a[lc][ld];
    }

    public static void backtrack(char[] c, char[] d, int[][] k) {

        for (int i = c.length - 1; i >= 0; i--) {
            for (int j = d.length - 1; j >= 0; j--) {
                if (c[i] == d[j]) {
                    System.out.print(c[i]);
                    i--;
                } else {
                    if (k[i + 1][j] < k[i][j + 1]) {
                        i--;
                        j++;
                    }
                }
            }
        }
    }

    public static void printFk(int[][] k) {
        for (int i = 0; i < k.length; i++) {
            for (int j = 0; j < k[0].length; j++) {
                System.out.print(a[i][j]);
            }
            System.out.print("\n");
        }
    }

    public static int imax(int w, int z) {
        return (w > z) ? w : z;
    }

    public static void main(String[] args) {
        String s1 = "BBABCBCAB";
        String s2 = "BACBCBABB";

        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();

        int lc = c1.length;
        int ld = c2.length;

        a = new int[lc + 1][ld + 1];
        aux = new int[lc + 1][2];

        for (int i = 0; i < lc + 1; i++) {
            a[i][0] = 0;
        }
        for (int i = 0; i < ld + 1; i++) {
            a[0][i] = 0;
        }

        int res = lcs(c1, c2, lc, ld);
        System.out.println("length - " + res + "\n");

        printFk(a);

        System.out.println("\nbacktrack ");
        backtrack(c1, c2, a);

    }
}
