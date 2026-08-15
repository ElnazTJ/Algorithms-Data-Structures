c=list(map(int , input().split()))

pos=[0,1,2,3]
eaten=[0,0,0,0]
person=0

while True:

    section=pos[person]
    c[section]-=1
    eaten[person]+=1

    if c[section]==0: 
        break

    for i in range(4):
        pos[i]=(pos[i]+1)%4

    person=(person+1)%4

for i in range(4):
    print(eaten[i])

