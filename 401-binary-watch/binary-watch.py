class Solution:
    # Shreya
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        result = []
        # hours: 0–11, minutes: 0–59
        for h in range(12):
            for m in range(60):
                # Count total "1"s in binary representations
                if (bin(h).count("1") + bin(m).count("1")) == turnedOn:
                    result.append(f"{h}:{m:02d}")
        return result
