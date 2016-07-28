#Mulige metoder: a * b = c , 9 siffer, størrelsesorden på a, b og c?
#Øvre grense a: 1000* 9 = 9000
#Nedre grense a: 101* 99 = 9900 ?
# 1000* 1,2... while  a.str + b.str + c.str <= 987654321 && >123456789
# if tallet < 123456789 continue, > 987654321: 1000-=1
# if a.str+b.str+c.str isPandigital add sum

def main():
    summed = []
    final= 0
    for a in range(1,2000):
        for b in range(1, a):
            c = a * b
            concatted = int(str(a)+str(b)+str(c))
            if concatted >= 123456789 and concatted <= 987654321:
                if isPandigital(concatted):
                    print(a,b,c)
                    summed.append(c)
    M=list(set(summed))
    print(M)
    for i in M:
        final += i
    print(final)
        


def isPandigital(digit):
    n = digit
    a = []
    while n:
        a[len(a):] = [n % 10]
        n = (n - n% 10)// 10
    a.sort()
     
    for y in range(0,len(a)):
        if y + 1 != a[y]:
            return False
    return True



main()
