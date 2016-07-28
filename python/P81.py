import urllib.request
import time


euler = urllib.request.urlopen(("https://projecteuler.n"
                               "et/project/resources/p081_matrix.txt"))


eulerStr = euler.read().decode("UTF-8")
start_time = time.time()

mat = [vec.split(",") for vec in eulerStr.split()]
mat = [[int(n) for n in vec] for vec in mat]
for j in range(len(mat)-1):
    #Set cost along top row
    mat[0][j+1] += mat[0][j]
    #Set cost along leftmost column
    mat[j+1][0] += mat[j][0]
for i in range(1,len(mat)):
    for j in range(1, len(mat)):
        mat[i][j] += min(mat[i-1][j],mat[i][j-1])
        
end_time =time.time()
print(mat[79][79])
print(end_time - start_time)
