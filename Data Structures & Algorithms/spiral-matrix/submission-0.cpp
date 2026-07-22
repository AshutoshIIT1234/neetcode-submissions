class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // traverse top row, left -> right
            for (int col = left; col <= right; col++) {
                result.push_back(matrix[top][col]);
            }
            top++;

            // traverse right column, top -> bottom
            for (int row = top; row <= bottom; row++) {
                result.push_back(matrix[row][right]);
            }
            right--;

            // traverse bottom row, right -> left (if still valid)
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            // traverse left column, bottom -> top (if still valid)
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    result.push_back(matrix[row][left]);
                }
                left++;
            }
        }

        return result;
    }
};
