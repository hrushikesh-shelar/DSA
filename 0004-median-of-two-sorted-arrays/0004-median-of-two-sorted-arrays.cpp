class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        if (n > m)
            return findMedianSortedArrays(B, A);

        int start = 0, end = n;
        int realMidInMergedArray = (n + m + 1) / 2;

        while (start <= end) {
            int mid = (start + end) / 2;
            
            int leftAsize = mid;
            int leftBsize = realMidInMergedArray - mid;
            
            int leftA  = (leftAsize > 0) ? A[leftAsize - 1] : INT_MIN; // checking overflow of indices
            int leftB  = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
            
            int rightA = (leftAsize < n) ? A[leftAsize]     : INT_MAX;
            int rightB = (leftBsize < m) ? B[leftBsize]     : INT_MAX;

            // if correct partition is done
            if (leftA <= rightB and leftB <= rightA) {                
                if ((m + n) % 2 == 0)
                    return (max(leftA, leftB) + min(rightA, rightB))/ 2.0;

                return max(leftA, leftB);
            }
            else if (leftA > rightB) {
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return 0.0;
    }
};