class Solution {
    // Shreya
public:
// Shreya
    int smallestNumber(int n) {
        while(n!=pow(2,__builtin_popcount(n))-1){
            n++;
        }
        return n;
    }
};