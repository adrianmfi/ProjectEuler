#Loop through all numbers from 1-> 9 999 999
#split the number into digits
#make a recursive function that takes in a number and ..


def digitsSquared(number):
    theSum = 0
    while(number > 0):
        theSum += (number%10)**2
        number//=10
    return theSum

def P92():
    endsAt89 = set()
    endsAt89.add(89)
    endsAt1 = set()
    endsAt1.add(1)
    
    nrOfTimes = 0
    
    for i in range(1,649):
        nextNumber = i
        while nextNumber not in endsAt89 and nextNumber not in endsAt1:
            nextNumber = digitsSquared(nextNumber)
        if(nextNumber in endsAt89):
            endsAt89.add(i)
            nrOfTimes+=1
        elif(nextNumber in endsAt1):
            endsAt1.add(i)

    print(endsAt1)
    for i in range(649,10000000):
        if not(i % 1000000):
            print(i)
        if(digitsSquared(i) in endsAt89):
            nrOfTimes +=1
            
    print(nrOfTimes)
P92()
