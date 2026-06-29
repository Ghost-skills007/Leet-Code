class Solution:
    def judgeSquareSum(self, c):
        n = c
        
        i = 2
        while i * i <= n:
            count = 0
            while n % i == 0:
                count += 1
                n //= i
            
            if i % 4 == 3 and count % 2 == 1:
                return False
            
            i += 1
        
        return not (n % 4 == 3)