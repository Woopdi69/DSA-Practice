class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size(), m = matrix.size();
        int left = 0, right = (n*m)-1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(matrix[mid/n][mid%n] == target){
                return true;
            }else if(matrix[mid/n][mid%n] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        return false;
    }
};