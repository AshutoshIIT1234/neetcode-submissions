class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);  // b -> a
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0) q.push(i);

        int processed = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            processed++;
            for (int neighbor : adj[node]) {
                if (--indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return processed == numCourses;
    }
};