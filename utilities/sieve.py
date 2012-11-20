from math import sqrt
 
    def FindPrimes(self, limit):
        isPrime = {}
        for i in range(1, limit + 1):
            isPrime[i] = True
 
        isPrime[2] = False
        for i in range(2, int(math.sqrt(limit)) + 1):
            if not isPrime[i]:
                for factor in range(1, limit + 1):
                    j = i * factor
                    if (j > limit): break
                    isPrime[j] = False
 
        isPrime[2] = True
