def countRectangles(width,height):
    combinations = []
    total = __countInstanceRectangles(width,height,width,height,combinations)
    return total
    
def __countInstanceRectangles(width,height,totalWidth,totalHeight,combinations):
    if (width,height) in combinations: return 0
    
    combinations.append((width,height))
    total = (totalWidth-width+1)*(totalHeight-height+1)
    
    if(width > 1):
        total += __countInstanceRectangles(width -1,height,totalWidth,totalHeight,combinations)
    if(height > 1):
        total += __countInstanceRectangles(width, height -1, totalWidth, totalHeight,combinations)
    return total

if __name__ == "__main__":

