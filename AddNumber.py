class Solution:
    def addBinary(self, a: str, b: str) -> str:
        bina = int(a,2)
        binb = int(b,2)
        
        while binb:
            carry = bina & binb
            bina = bina ^ binb
            binb = carry << 1
        return str(bin(bina))[2:]
            
a = "11"
b = "1"
print(Solution().addBinary(a,b))