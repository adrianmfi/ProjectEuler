from P37 import *

def isPermutation(a,b):# returns true if a and b are permutations of eachother
    a = list(str(a))
    b = list(str(b))
    return a == b

def isPermutations(*args):#returns true if all args are permutations
    ret = True
    first = sorted(list(str(args[0])))
    for i in range(1,len(args)):
        
        ret = sorted(list(str(args[i]))) == first
        if ret == False:
            return ret
    return ret

                 
def p49():    
    for i in range (1000,10000):
        n = 1
        while i + 2*n < 10000:
            if isPrime(i) and isPrime(i+n) and isPrime(i + 2*n):
                if isPermutations(i,i+n,i+2*n):
                    print(i,i+n,i+2*n)
            n+=1
p49()
