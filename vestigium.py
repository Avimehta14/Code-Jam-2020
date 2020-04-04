import numpy

t =int(input())
for p in range(t):
    mat=[]
    trace = 0
    rowc= 0
    colc = 0
    s= int(input())
    for j in range(s):
        arr = list(map(int, input().split()))
        mat.append(arr)
    for i in range(s):
        trace = trace + mat[i][i]
    
    for i in mat :
        if len(set(i)) == len(mat) :
            pass
        else :
            rowc= rowc + 1    
    
    matr=numpy.transpose(mat)
    for i in matr :
        if len(set(i)) == len(matr) :
            pass
        else :
            colc= colc + 1 
    print("Case #",p+1,": ",trace," ",rowc," ", colc , sep='')      

