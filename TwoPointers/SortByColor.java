public class SortByColor {

	public void sortColors(ArrayList<Integer> a) {

		 Integer zero = 0;
		 Integer one = 0;
		 Integer two = 0;
		 
		 for(int i=0;i<a.size();i++) {
		     if (a.get(i).equals(0)) {
		         zero++;
		     } else if(a.get(i).equals(1)){
		         one++;
		     } else {
		         two ++;
		     }
		 }
		 
		 for(int i=0;i<a.size();i++) {
		     if(!zero.equals(0)) {
		         a.set(i,0);
		         zero--;
		     } else if(!one.equals(0)) {
		         a.set(i,1);
		         one--;
		     }  
		     else {
		         a.set(i,2);
		     }
		         
		 }
	     
	}
}
