
t = int(input())
for p in range(t):
    stk= []
    zer=0
    n = input()
    res = [int(x) for x in str(n)] 
    lt = len(res)
    for i in res :
        if i == 0 :
            zer=zer+1
            stk.append(0)
        elif i > 0 :    
            for j in range(i):
                stk.append("(")
            break
       
    c = res.index(i)    
    for a in range(c, lt):
        stk.append(res[a])
        if a == lt-1:
            for f in range(res[a]):
                stk.append(")")
            break        
        elif res[a] == res[a+1]:
            pass
        elif res[a] > res[a+1]:
            br= res[a]- res[a+1] 
            for i in range(br):
                stk.append(")")
              

        elif res[a] < res[a+1]:
            br= res[a+1]-res[a] 
            for i in range(br):
                stk.append("(")    

    if zer == lt :
        po = stk[len(stk)//2:]
        zerl = ''.join([str(item) for item in po])

        print("Case #",p+1,": ",zerl, sep='')
    else:    
        stringList = ''.join([str(item) for item in stk])
        print("Case #",p+1,": ",stringList, sep='')

