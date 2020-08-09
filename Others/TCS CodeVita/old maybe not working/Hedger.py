import re
def market(stocks,costs,profits,count,result):
    maxindex=profits.index(max(profits))
    maxval=costs[maxindex]
    #print(" index ",maxindex,"  val ",maxval)
    for i in range(int(stocks[1])):
        if stocks[2]>count and stocks[2]>=count+maxval:
            count=count+maxval
            result=result+((maxval*profits[maxindex])/100)
        else:
            print(int(result))
            return result
    profits.pop(maxindex);costs.pop(maxindex)
    #print(result)
    market(stocks,costs,profits,count,result)
stock=re.findall(r"[-+]?\d*\.\d+|\d+",input())
cost=re.findall(r"[-+]?\d*\.\d+|\d+",input())
profit=re.findall(r"[-+]?\d*\.\d+|\d+",input())
stocks=[];costs=[];profits=[]
for i in stock:
    stocks.append(float(i))
for i in cost:
    costs.append(float(i))
for i in profit:
    profits.append(float(i))
#print(stocks)
#print(costs)
#print(profits)
count=0;result=0
val=market(stocks,costs,profits,count,result)