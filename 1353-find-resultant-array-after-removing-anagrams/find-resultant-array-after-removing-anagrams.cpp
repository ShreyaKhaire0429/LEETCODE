class Solution {
    // Shreya
public:
// Shreya
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        
        for (int i = 0; i < words.size(); i++) 
        {
            if (result.empty()) 
            {
                result.push_back(words[i]);
            } 
            else 
            {
                string prev = result.back();
                string curr = words[i];
                
                sort(prev.begin(), prev.end());
                sort(curr.begin(), curr.end());
                
                if (prev != curr) {  // Not an anagram
                    result.push_back(words[i]);
                }
            }
        }
        
        return result;
    }
};