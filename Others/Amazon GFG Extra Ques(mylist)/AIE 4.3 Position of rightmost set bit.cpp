// Company Amazon
// AIE 4.3 Position of rightmost set bit
// https://www.geeksforgeeks.org/position-of-rightmost-set-bit/


//CPP program for above approach 
#include<bits/stdc++.h>
using namespace std;
 
// Program to find position of
// rightmost set bit
int PositionRightmostSetbit(int n)
{
  int p=1;
   
  // Iterate till number>0
  while(n > 0)
  {
     
    // Checking if last bit is set
    if(n&1){
      return p;
    }
     
    // Increment position and right shift number
    p++;
    n=n>>1;
  }
   
  // set bit not found.
  return -1;
}
 
// Driver Code
int main() 
{
  int n=18; 
   
  // Function call
  int pos=Last_set_bit(n);
 
  if(pos!=-1)
    cout<<pos;
  else
    cout<<0;
 
  return 0;
}
