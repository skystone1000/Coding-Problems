// Aditya Verma - DP Playlist 12 Target Sum

/*
Ques - Target Sum
    Given an Input array "arr" with integers and a variable "sum". We need to assign a sign(+ve/-ve) to every element of array
    such that sum of all the elements of array becomes "sum".
    Return the total number of sign combinations possible to satisfy above condition

IP
    arr[]: 1, 1, 2, 3
    sum: 1

OP
    3

Explanation
    We have 3 combinations from given array such that their final sum is 1
    and they are => 
    +1 , -1, -2, +3
    -1 , +1, -2, +3
    +1 , +1, +2, -3

Approach
    Exacly same as previous problem => 11 Count number of subsets with given difference

    SO we are basically asked to make some numbers positive and some number negative 
    and make sum to given value, which basically means to partition the array into 2 subsets 
    such that their difference is given so everything would be same. (sum == diff)

*/
