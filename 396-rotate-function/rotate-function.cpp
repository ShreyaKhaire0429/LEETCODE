class Solution {
    // Shreya
public:
// Shreya
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0, F0 = 0;

        // Compute sum and F(0)
        for (int i = 0; i < n; i++) 
        {
            sum += nums[i];
            F0 += (long long)i * nums[i];
        }

        long long ans = F0;
        long long curr = F0;

        // Use relation to compute F(k) from F(k-1)
        for (int k = 1; k < n; k++) 
        {
            curr = curr + sum - n * (long long)nums[n - k];
            ans = max(ans, curr);
        }

        return (int)ans;
        
    }
};