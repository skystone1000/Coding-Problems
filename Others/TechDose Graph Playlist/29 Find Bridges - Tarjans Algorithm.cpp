// GRAPHS PLAYLIST TECHDOSE

// #29 Find Bridges - Tarjans Algorithm Cut Edge
// 29 Find Bridges in a graph using Tarjans Algorithm Cut Edge
// Time Complexity: O()

/*
    29 - 1
    - Find all bridges
    - Connectivity

    29 - 2
    BRIDGE - A bridge is an edge, removing which increases the number of components
    Bridges in a Network can represent critical wires or connectors and is similar 
    to SOPF (Single Point of Failure) . We can eliminate such vulnerabilities by 
    adding edges or redesigning. I increases reliability

    29 - 3
    Method 1 - Check for each edge one by one

    For each Edge : Repeat
        1) Remove the edge from the graph
        2) Perform DFS and see if there is only 1 Component
            if(Component == 1)
                then removed edge is not a bridge
            else
                removed edge is a bridge
        3) Put Back the edge in the graph
        
    Time: O(E(V+E))

    29 - 4
    CONDITION FOR A BRIDGE
    If there are no back edges from a subgraph its ancestor or parent 
    (across the edge being checked) then the edge will be a BRIDGE

    29 - 5
    - We need to assign timestamp values to nodes to know the ordering
    - We use DISC and LOW values for nodes to find back edges 
 */