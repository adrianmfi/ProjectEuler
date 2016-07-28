import time
def fillSpiral(spiral,sideLength):
    if sideLength > 0:
        bottomRight = sideLength*sideLength
        bottomLeft = bottomRight - sideLength+1
        topLeft = bottomLeft -  sideLength +1
        topRight = topLeft - sideLength +1
        
        minIndex = int((len(spiral)- sideLength)/2)
        maxIndex = len(spiral) -1  - minIndex
        
        for i in range(sideLength):   
            #fill right
            spiral[i+minIndex][maxIndex] = topRight - i            
            #fill top
            spiral[minIndex][i+minIndex] = topLeft -i
            #fill left
            spiral[i + minIndex][minIndex] = topLeft + i            
            #fill bottom
            spiral[maxIndex][i+minIndex] = bottomLeft + i
        fillSpiral(spiral,sideLength-2)
    
def generateSpiral(sideLength):
    if sideLength % 2 == 0:
        return []
    spiral = [[ 0 for i in range(sideLength)] for j in range(sideLength)]
    fillSpiral(spiral,sideLength)

    return spiral

class Spiral:
    def __init__(self,sideLength):
        self.sideLength = sideLength
        self.spiral = generateSpiral(sideLength)
    def __str__(self):
        if self.sideLength % 2 == 0:
            return 'Invalid spiral'
        toString = ''
        width = len(str(self.spiral[self.sideLength-1][self.sideLength-1]))+2
        for row in self.spiral:
            for value in row:
                toString += str(value).ljust(width)
            toString += '\n'
        return toString
    
def isPrime(n):
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
    
def P58():
    ratio = 1
    numberOfPrimes = 3
    checkedNumbers = 5
    sideLength = 3
    while(ratio > 0.1):
        sideLength +=2
        n1 = sideLength*sideLength
        n2 = n1 - sideLength +1
        n3 = n2 - sideLength +1
        n4 = n3 - sideLength +1
        if(isPrime(n1)):
            numberOfPrimes+=1
        if(isPrime(n2)):
            numberOfPrimes+=1
        if(isPrime(n3)):
            numberOfPrimes+=1
        if(isPrime(n4)):
            numberOfPrimes+=1
        checkedNumbers +=4
        ratio = numberOfPrimes / checkedNumbers
    print (sideLength)
if __name__ == "__main__":
    start = time.time()
    P58()
    end = time.time()
    print(end - start)
    
