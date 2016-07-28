MAX = 999999

def loadGraph(filepath):
    adjMatrix = []
    with open(filepath) as file:
        for line in file:
            adjRow = []
            for weight in line.split(","):
                if weight.strip() == '-':
                    adjRow.append(MAX)
                else:
                    adjRow.append(int(weight))
            adjMatrix.append(adjRow)
    return adjMatrix

def P107():
    adjMatrix = loadGraph("p107_network.txt")
    verticesSize = len(adjMatrix)

    origTotalWeight = 0 
    for i in range(verticesSize):
        for j in range(i+1,verticesSize):
            w = adjMatrix[i][j]
            if w < MAX:
                origTotalWeight += w
    
    included = set([0])
    remaining = set(i for i in range(1,verticesSize))
    print (origTotalWeight)
    newTotalWeight = 0
    while len(included) < verticesSize:
        minW = MAX
        minU = 0
        minV = 0
        for u in included:
            for v in remaining:
                if adjMatrix[u][v] < minW:
                    minW = adjMatrix[u][v]
                    minU = u
                    minV = v
        print(minU,minV,minW)
        included.add(minV)
        remaining.remove(minV)
        newTotalWeight += minW
    print (origTotalWeight-newTotalWeight)
P107()
