class Solution {
    public:
      int countLessEqual(vector<int> &arr, int target) {
          int low = 0, high = arr.size() - 1;
          while (low <= high) {
              int mid = (low + high) / 2;
              if (arr[mid] <= target) {
                  low = mid + 1;
              } else {
                  high = mid - 1;
              }
          }
          return low; // Count of numbers <= target
      }
  
      int countLessEqualMatrix(vector<vector<int>> &mat, int mid) {
          int total = 0;
          for (int i = 0; i < mat.size(); i++) {
              total += countLessEqual(mat[i], mid);
          }
          return total;
      }
  
      int median(vector<vector<int>> &mat) {
          int low = INT_MAX, high = INT_MIN;
          int n = mat.size(), m = mat[0].size();
          int left = (n * m) / 2 + 1; // Correct formula
  
          for (int i = 0; i < n; i++) {
              low = min(low, mat[i][0]);
              high = max(high, mat[i][m - 1]);
          }
  
          while (low < high) {
              int mid = (low + high) / 2;
              int total = countLessEqualMatrix(mat, mid);
  
              if (total < left) {
                  low = mid + 1;
              } else {
                  high = mid;
              }
          }
          return low;
      }
  };
  