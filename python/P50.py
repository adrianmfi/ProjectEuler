from P37 import primesSieve
def p49():
    primes = primesSieve(1000000)
    maxIters = 0
    for i in range(len(primes)):
        primtallet = primes[i]


        for n in range(i):
            pSum = 0
            counter = n
            
            while pSum <= primtallet:
                pSum += primes[counter]
                counter+=1
                if pSum == primtallet:
                    if counter - n > maxIters:
                        maxIters = counter - n
                        
    return maxIters
print(p49())
