class Solution {
public:
// Shreya
    int findKthPositive(vector<int>& arr, int k) 
    {
        int missing = 0; // count of missing numbers
        int current = 1; // start from 1
        int i = 0;       // index for arr

        while (missing < k) 
        {
            if (i < arr.size() && arr[i] == current) 
            {
                i++;  // number is in array → skip
            } 
            else 
            {
                missing++;  // number missing
            }
            current++;
        }

        return current - 1;
    }
};