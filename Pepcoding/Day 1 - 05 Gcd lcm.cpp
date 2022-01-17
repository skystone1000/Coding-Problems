// Pepcoding
// Ques - https://www.pepcoding.com/resources/online-java-foundation/getting-started/gcd-and-lcm-official/ojquestion
// Soln - https://www.pepcoding.com/resources/online-java-foundation/getting-started/gcd_and_lcm/topic

#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    int num1, num2;
    cin >> num1 >> num2;
    int n1 = num1, n2 = num2;

    while(n1 != n2){
        if(n1>n2){
            n1 = n1-n2;
        }else{
            n2 = n2-n1;
        }
    }
    cout<<n1<<endl;
    cout<<num1*num2/n1;
}