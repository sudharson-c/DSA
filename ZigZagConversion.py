class Solution:
    def convert(self, s: str, numRows: int) -> str:
        res= ["" for _ in range(len(s))]
        current = 0
        step = 1
        for i in range(len(s)):
            res[current] += s[i]
            if current == 0:
                step = 1
            elif current == numRows - 1:
                step = -1
            current += step
            
        return "".join(res)

s = "123456789"
numRows = 3
print(Solution().convert(s,numRows))
