class Solution {
public:
    vector<int> parent, rank_;
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false; // already same component
        
        // union by rank
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
        return true;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank_.resize(n, 0);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
        
        int components = n;
        for (auto& e : edges) {
            if (unite(e[0], e[1]))
                components--; // merged two components into one
        }
        return components;
    }
};