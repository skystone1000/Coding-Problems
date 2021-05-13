// GRAPHS PLAYLIST TECHDOSE

// #17 Spanning Tree MST

/*

    Spanning Tree: 
        - For a given graph if you can construct another graph(also a tree) with 
        min number of edges.
        - There can be multiple possible spanning trees
        - Spanning Tree is a subset of graph
        - Spanning Tree cannot be disconnected
        - Graph should be SINGLE-Component to find spanning tree

        In Spanning Tree
            - No of Vertices = V
            - No od Edges = V-1
            - Therefore we can never have any cycle in a Spanning Tree
            - Covering V-vertices using (V-1) edges can create loop

        GOAL: Cover all vertices with min possible edges
        All Spanning Trees have same number of edges

        - A connected and unidirected graph has atleast 1 Spanning tree
        - A complete undirected graph has N^(N-2) number od different Spanning Trees possible
        (A complete graph has an edge from every node to every other node) 
        - Spanning tree is minimally connected, i.e.e removing 1 edge will disconnect the graph
        - Spanning Tree is maximally Acyclic, i.e. adding 1 edge wll form a cycle in graph

    Minimum Spanning Tree (MST):
        - A Spanning Tree with min cost in a weighted graph is called MST.

    Applications
        - Design Network cable route for cities using minimum cable, hence minimizing cost.
        - Design water supply Network, transportation networks

    MST Algorithms
        - Prim's Algo
        - Kruskal's Algo

*/