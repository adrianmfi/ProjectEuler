def gcd(a,b):
    while b != 0:
        gammel_b = b
        b = a % b
        a = gammel_b
    return a

def reduce_fraction(a,b):
    return a//gcd(a,b),b//gcd(a,b)

tallene = [[0 for x in range(2)] for x in range(4)]
totalDenom = 1
for nevner in range(11,100):
    for teller in range(10, nevner):
        nyTeller = (teller - (teller % 10))/10
        nyNevner = nevner % 10;
        if(nyTeller < nyNevner):
            if(teller/nevner == nyTeller /nyNevner and teller%10 == (nevner-(nevner%10))/10):
                a,b = reduce_fraction(teller,nevner)
                totalDenom *= b
print(totalDenom)
