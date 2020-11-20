// NASDAQ Internship Hiring
// 1. Arrays and Pizzas
// Wrong Answer (Partially Correct)

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

        int ans = 0;
        for(int i=2;i<n;i=i+4){
            ans+=v.get(i);
        }
        System.out.println(ans);
	} 
}

/*
Example
8
1 3 4 1 5 1 5 3

Output
5
*/
