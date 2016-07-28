import time
import itertools
def primesSieve(n):
    A =[False,False]
    A += [True for x in range(n-1)]

    for i in range(2,int(n**(1/2))+1):
        if A[i] == True:
            for j in range(i**2,n+1,i):
                A[j] = False
    return list(itertools.compress(range(n),A))
    
def isPrime(n):
    n = abs(n)
    if n == 2:
        return True
    if n%2 == 0:
        return False
    if n < 2:
        return False
    i = 3
    while i * i < n +1:
        if n % i == 0:
            return False
        i+=2
    return True

def truncfromL(n):#unused, slower
    num = n
    
    while True:
        num = num % (10**(len(str(num))-1))
        if num <= 0:
            break
        if not isPrime(num):
            return False
    return True

def truncfromR(n):
    num = n

    while True:
        num = (num - int(str(num)[-1]))//10
        if num <= 0:
            break
        if not isPrime(num):
            return False
    return True

def p37():
    start = time.time()
    truncLR = []
    primtall = primesSieve(1000000)
    for prime in primtall:
        if prime > 10:
            if truncfromR(prime) and truncfromR(int(str(prime)[::-1])):
                truncLR.append(prime)
    end = time.time()
    print(end - start)
    return truncLR

def timeTest(n):
    start = time.time()
    a = primesSieve(n)
    end = time.time()
    print ("Sievetime", end - start)

