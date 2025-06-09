// https://leetcode.com/problems/range-sum-query-2d-immutable
// 2024/08/18

class NumMatrix {
    vector<vector<int>> num_matrix;

    int value_at(const int row, const int col) {
        if (row < 0 || row >= num_matrix.size() || col < 0 || col >= num_matrix[0].size()) {
            return 0;
        }

        return num_matrix[row][col];
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        num_matrix = matrix;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = matrix[0].size() - 2; j >= 0; --j) {
                num_matrix[i][j] += num_matrix[i][j + 1];
            }
        }

        for (int i = matrix.size() - 2; i >= 0; --i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                num_matrix[i][j] += num_matrix[i + 1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return value_at(row1, col1) + value_at(row2 + 1, col2 + 1) -
               value_at(row2 + 1, col1) - value_at(row1, col2 + 1); 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */