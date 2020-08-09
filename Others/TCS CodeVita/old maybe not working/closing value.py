n = int(input())
trades = []
buy = {}
sell = {}

transaction = {}

for i in range(n):
 tID, tType, company, price, quantity = input().split()
 dic = {}
 dic['id'] = int(tID)
 dic['type'] = tType
 dic['company'] = company
 dic['price'] = float(price)
 dic['quantity'] = int(quantity)

 trades.append(dic)

for t in trades:
 if t['type'] == 'Sell':
  if t['company'] in sell:
   sell[t['company']].append([t['price'],t['quantity']])
  else:
   sell[t['company']] = [[t['price'],t['quantity']]]
 else:
  if t['company'] in buy:
   buy[t['company']].append([t['price'],t['quantity']])
  else:
   buy[t['company']] = [[t['price'],t['quantity']]]

for b in buy.keys():
 for j in buy[b]:
  if b in sell.keys():
   for i in sell[b]:
    if i[0] <= j[0]:
     q = min(j[1],i[1])
     j[1]-=q
     i[1]-=q
     transaction[b] = i[0]

if transaction:
 for i in transaction.keys():
  print(i+":"+str(int(transaction[i])))
else:
 print("Stocks not traded")