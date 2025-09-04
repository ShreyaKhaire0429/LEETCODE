class Solution {
    // Shreya
public:
    int findClosest(int x, int y, int z) {
        int dxz = abs(x-z), dyz = abs(y-z);
        if (dxz < dyz) return 1;
        else if (dyz < dxz) return 2;
        return 0;
    }
};