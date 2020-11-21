// Java program to demonstrate the 
// working of Vector 

import java.io.*; 
import java.util.*; 
import java.util.Collections;
import java.util.Comparator;

class VectorExample { 
	
	public static void main(String[] args) 
	{ 
		Scanner s = new Scanner(System.in);
        
        int n = s.nextInt(); 

		Vector<Integer> v = new Vector<Integer>(n); 
        for (int i = 1; i <= n; i++) 
			v.add(s.nextInt()); 

        Comparator comparator = Collections.reverseOrder();
        Collections.sort(v,comparator);

		// Printing elements 
		// System.out.println(v); 

		// // Remove element at index 3 
		// v.remove(3); 

		// // Displaying the vector 
		// // after deletion 
		// System.out.println(v); 

		// // Printing elements one by one 
		// for (int i = 0; i < v.size(); i++) 
		// 	System.out.print(v.get(i) + " "); 

        int ans = 0;
        for(int i=2;i<n;i=i+4){
            ans+=v.get(i);
        }
        System.out.println(ans);
	} 
}
