class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> a;
        for(int i = 1; i<matrix.size();i++){
            matrix[i][0] = matrix[i-1][0]^matrix[i][0];
        }
        for(int i = 1; i<matrix[0].size();i++){
            matrix[0][i] = matrix[0][i-1]^matrix[0][i];
        }
        
        for(int i = 1; i<matrix.size();i++){
            for(int j = 1; j<matrix[i].size();j++){
                matrix[i][j] = matrix[i-1][j]^matrix[i][j-1]^matrix[i][j]^matrix[i-1][j-1];
            }
        }
        for(int i = 0; i<matrix.size();i++){
            for(int j = 0; j<matrix[i].size();j++){
                a.push_back(matrix[i][j]);
            }
        }
        sort(a.begin(),a.end());
        
        return a[a.size() - k];
    }
};