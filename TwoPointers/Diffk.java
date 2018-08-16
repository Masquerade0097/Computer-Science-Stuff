public class Diffk {
    public int diffPossible(ArrayList<Integer> A, int B) {
        
        HashMap<Integer, Integer> hs = new HashMap<>();
        
        for(int i=A.size()-1;i>=0;i--) {
            if (hs.containsKey(A.get(i))) {
                return 1;
            } else{
                hs.put(A.get(i)-B, A.get(i)); 
            }
        }
        
        return 0;
    }
}
