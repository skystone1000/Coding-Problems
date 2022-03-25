// GRAPHS PLAYLIST TECHDOSE

// #15 Disjoint Set UNION and FIND
// Time Complexity: O(E.V)

/*
    1) Disjoint  Set: Two or more sets with nothing in common are called disjoint sets
        1 2 3 4 5 =>  1 2 3     (s1)
                      4 5       (s2)

        S1 ^(intersection) S2 = PHI  (In Disjoint Set)

        - Uses Of Disjoint set
            a) Keeps track of the SET that an element belongs to. Therefore it is easier to check, given 2 elements,
            whether they belong to same subset. (FIND OPERATION)
                S(1) == S(2) ?

            1,2,3,4 | 5,6,7
                S1      S2

            b) Used to merge 2 sets into one (UNION OPERATION)
            Union of 2 elements is same as union of 2 SETs.

            1,2,3 (UNION) 5,6,7  =>  1,2,3,5,6,7
              S1            S2

        - Set Representation 
        Disjoin set uses chaining to define a set. The chaining is defined by a parent child relationship.
        That is the elements are represent in heirarchical format (Tree format) (Str of set doesn't matter)

        Check 5:35 of video for representation

        - 2 Set Representation (5:55)

        - Operations on SET (7:22)
            a) FIND
            b) UNION

        a) Find Operation(8:52)
            If root parent of A & B are same then they must be in the same SET
            Examples

        b) Union of 2 Sets (11:17)
            Union of 2 elements
            Union of one element and a set 
            Union of all elements in 2 sets
            All are the same

            To get the union (the process of merging)==>
                Step 1: Find Absolute root of both the elements
                Step 2: Point absolute root of 1st point to absolute root of 2nd or
                        (vice versa) absolute root of 2nd point to absolute root of 1st 

                To optimize this we can take union by rank

            Example


        Exampe Problem : Detect Cycle in an Undirected Graph using Disjoint set(13:57)
        Disjoint set can't detect cycle in a directed graph

        Given: A set edges which represent the graph

        Concept: 
        1) We go with array representation and treat all nodes to be independent initially (Not connected)
        2) We then iterate through the set of edges given 
            a) For each pair of nodes(edge) we check if they are in same set (FIND Operation)
            b) If they are in same set ==> we found a cycle
               else ==> add the new node to set (UNION Operation)

        Time Complexity: O( E * V ) (19:59)
        E => Process all edges
        V => FIND or UNION worst case in a skewed str

        Disjoint Set can't detect cycle in a directed graph because UNION operation has no directionality
        (A V B) ==> It doesn't mean (A to B) or (B to A)
        We can't make directional decisions.  


*/

// Code
#include<iostream>
#include<vector>

using namespace std;

vector<int> dsuf;

// Find Operation
int find(int v){
    if(dsuf[v] == -1)
        return v;
    
    return find(dsuf[v]);
}

void union_op(int fromP, int toP){
    fromP = find(fromP);
    toP = find(toP);
    dsuf[fromP] = toP;
}

bool isCyclic(vector<pair<int,int>>& edge_List){
    for(auto p:edge_List){
        // FIND absolute parent of subset
        int fromP = find(p.first);
        int toP = find(p.second);

        if(fromP == toP)
            return true;

        // UNION Operation
        union_op(fromP, toP); // UNION of 2 sets
    }
    return false;
}


int main(){
    // Total Edges and Vertices(0 to V-1)
    int E, V;
    cin>>E>>V;

    // Mark all vertices as separate subsets with only 1 element
    dsuf.resize(V, -1); // Disjoint set Union Find  Operation

    // Adjacency List (From, To)
    vector<pair<int,int>> edge_List;
    for(int i=0;i<E;i++){
        int from, to;
        cin>>from>>to;
        edge_List.push_back({from,to});
    }

    if(isCyclic(edge_List))
        cout<<"TRUE"<<endl;
    else
        cout<<"False"<<endl;

    return 0;
}