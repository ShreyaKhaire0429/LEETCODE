class Solution {
    // Shreya
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        if (minVal == maxVal) return 0;

        int n = nums.size();
        int bucketSize = max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> filled(bucketCount, false);

        // put numbers in buckets
        for (int num : nums) {
            int idx = (num - minVal) / bucketSize;
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
            filled[idx] = true;
        }

        // find max gap between buckets
        int prev = minVal, ans = 0;
        for (int i = 0; i < bucketCount; i++) {
            if (!filled[i]) continue;
            ans = max(ans, bucketMin[i] - prev);
            prev = bucketMax[i];
        }
        return ans;
    }
};
