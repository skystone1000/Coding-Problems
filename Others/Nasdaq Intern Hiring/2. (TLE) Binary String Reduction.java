// NASDAQ Internship Hiring
// 2. Binary String Reduction

import java.io.*; 
import java.util.*; 
import java.util.Collections;
import java.util.Comparator;

class BinaryExample { 
	
	public static void main(String[] args) 
	{ 
		Scanner sc = new Scanner(System.in);
        
        int testCases = Integer.parseInt(sc.nextLine()); 

        for(int t=0;t<testCases;t++){
            int n = Integer.parseInt(sc.nextLine());
            String s = sc.nextLine();
            int count = 0;
            while(s.length() > 0){
                char prev = ' ';
                String rem="";
                count++;
                // deb2(count,s);
                for(int i=0;i<s.length();i++){
                    if(i==0){
                        prev = s.charAt(i);
                    }else{
                        // deb2(prev,s[i]);
                        if(prev == s.charAt(i)){
                            rem += s.charAt(i);
                            prev = s.charAt(i);
                        }else{
                            prev = s.charAt(i);
                            continue;
                        }
                    }
                }
                s = rem;
            }
            System.out.println(count);
        }

	} 
}

/*
Example
1
10
0100100111

Output
3

*/