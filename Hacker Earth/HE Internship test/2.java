// Q2.What is the Output of the following java code

// To run the file rename it as "PetA.java" then compile and run

class PetA{
    public static void main(String [] args) {
        PetA p = new PetA();
        p.start();
    }

    void start(){
        long [] a1 = {3,4,5};
        long [] a2 = fix(a1);
        System.out.println(a1[0] + a1[1] + a1[2] + " ");
        System.out.println(a2[0] + a2[1] + a2[2]);
    }

    long [] fix(long [] a3){
        a3[1] = 7;
        return a3;
    }
}

/*
OUTPUT:
skystone@skystone-HP-Notebook:/opt/lampp/htdocs/github/Coding-Problems/Hacker Earth/HE Internship test$ javac PetA.java
skystone@skystone-HP-Notebook:/opt/lampp/htdocs/github/Coding-Problems/Hacker Earth/HE Internship test$ java PetA 
15 
15
*/