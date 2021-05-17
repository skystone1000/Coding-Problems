// GRAPHS PLAYLIST TECHDOSE

// #20 Kruskal Algorithm Implementation


void Kruskals(vector<Edge>& edge_List, int V, int E){
    // cout<<"edge_List before sort"<<endl;
    // printEdgeList(edge_List);
    sort(edge_List.begin(), edge_list.end(), comparator);
    // cout<<"edge_List after sort"<<endl;
    // printEdgeList(edge_List);

    int i=0,j=0;
    while(i<V-1 && j<E){
        // FIND absolute parent of subset
        int fromP = find(edge_List[j].src); 
        int toP = find(edge_List[j].dst);

        if(fromP == toP){
            j++;
            continue;
        }

        // UNION operation
        union_op(fromP, toP); // Union of 2 sets
        mst.push_back(edge_List[j]);
        i++;
    }
}

void printMST(vector<Edge>& mst){
    cout<<"MST formed is "<<endl;
    for(auto p:mst){
        cou<<"src: "<<p.src<<" dst: "<<p.dst<<" wt: "<<p.wt<<endl;
    }
}

int main(){
    int E; // No of Edges
    int V; // No of Vertices(0 to V-1)
    cin>>E>>V;

    // Mark all vertices as separate subsets with only 1 element
    dsuf.resize(V);

    // Mark all nodes as independent set
    for(int i=0;i<V;i++){
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }

    vector<Edge> edge_List; // Adjacency List;
    Edge temp;
    for(int i=0;i<E;i++){
        int from, to, wt;
        cin>>from>>to>>wt;
        temp.src = frm;
        temp.dst = to;
        temp.wt = wt;
        edge_List.push_back(temp);
    }

    Kruskals(edge_List,V,E);
    printMST(mst);

    return 0;
}