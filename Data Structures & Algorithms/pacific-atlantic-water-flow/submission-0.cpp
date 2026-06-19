class Solution {
public:
    int rows, cols;
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<bool>>& visited) {
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
                if (visited[nr][nc]) continue;
                if (heights[nr][nc] < heights[r][c]) continue; // uphill only
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size(), cols = heights[0].size();

        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));

        queue<pair<int,int>> pq, aq;

        for (int r = 0; r < rows; r++) {
            // Left col → Pacific | Right col → Atlantic
            pac[r][0] = true;       pq.push({r, 0});
            atl[r][cols-1] = true;  aq.push({r, cols-1});
        }
        for (int c = 0; c < cols; c++) {
            // Top row → Pacific | Bottom row → Atlantic
            pac[0][c] = true;       pq.push({0, c});
            atl[rows-1][c] = true;  aq.push({rows-1, c});
        }

        bfs(heights, pq, pac);
        bfs(heights, aq, atl);

        vector<vector<int>> res;
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (pac[r][c] && atl[r][c])
                    res.push_back({r, c});

        return res;
    }
};
