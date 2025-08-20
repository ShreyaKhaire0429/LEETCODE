class Solution:
    # Shreya
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        count = [0] * 26  # frequency array for a-z
        
        for ch in s:
            count[ord(ch) - ord('a')] += 1
        
        for ch in t:
            count[ord(ch) - ord('a')] -= 1
            if count[ord(ch) - ord('a')] < 0:
                return False
        
        return True
