/*
    Variations of Knapsack
    1) Subset sum problem
    2) Equal sum partition
    3) Count of subset sum
    4) Minimum subset sum difference
    5) Target Sum
    6) Number of subsets with given difference

    Identification of Knapsack problems

    In the question we solved we had the following structure
        Weights [ ] : 1    3    4    5
        Values  [ ] : 1    4    5    7
        Capacity(W): 7 kg (Capacity of knapsack)
        Find max profit that we can get by adding elements in the bag?

    Two arrays (which is basically just one array of items which has two properties i.e. wt and val)
    But in future we might get just one array, so we can consider that one array as wt[] and neglect val[].
    So basically when we see question with 
    - number of items 
    - Capacity (max)
    and we have to choice either to choose or not, in that case we have the Knapsack Pattern  

*/