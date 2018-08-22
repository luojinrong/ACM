f=open("list.txt","w")
for i in range(0,1000):
    f.write("\""+(str)(2**i)+"\""+",")
f.close()
