// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
//     For example, given array S = {-1 0 1 2 -1 -4},

//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        int n = num.size();
        for(int i = 0; i < n-2; ++i) {
            while(i > 0 && i < n-2 && num[i] == num[i-1]) ++i;
            int j = i+1;
            int k = n-1;
            while(j < k) {
                int sum = num[i]+num[j]+num[k];
                if(sum == 0) {
                    vector<int> sol;
                    sol.push_back(num[i]);
                    sol.push_back(num[j]);
                    sol.push_back(num[k]);
                    res.push_back(sol);
                    while(++j < k && num[j] == num[j-1]);
                    while(--k > j && num[k] == num[k+1]);
                } else if(sum < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        return res;
    }
};
