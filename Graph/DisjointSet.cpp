class DisjointSet {
    vector<int> rank,parent,size;

    public :

    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0 ; i <= n ; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if(node == parent[node]) 
        return node;
        // Path Compression
        return parent[node] = findParent(parent[node]);
    }

   void unionByRank(int u,int v) {
     int ultimateParent_u = findParent(u);
     int ultimateParent_v = findParent(v);
     if(ultimateParent_u == ultimateParent_v) {
        return ;
     }
     if(rank[ultimateParent_u] < rank[ultimateParent_v]) {
        parent[ultimateParent_u] = ultimateParent_v;
     }
     else if(rank[ultimateParent_u] > rank[ultimateParent_v]) {
        parent[ultimateParent_v] = ultimateParent_u;
     }
     else {
        parent[ultimateParent_v] = ultimateParent_u;
        rank[ultimateParent_u]++;
     }
   }

    void unionBySize(int u,int v) {

     int ultimateParent_u = findParent(u);
     int ultimateParent_v = findParent(v);

     if(ultimateParent_u == ultimateParent_v) {
        return ;
     }
     if(size[ultimateParent_u] < size[ultimateParent_v]) {
        parent[ultimateParent_u] = ultimateParent_v;
        size[ultimateParent_v]+=size[ultimateParent_u];
     }
     else {
        parent[ultimateParent_v] = ultimateParent_u;
        size[ultimateParent_u]+=size[ultimateParent_v];
     }

   }

};
