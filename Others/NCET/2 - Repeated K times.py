# 2 - Repeated K times
# Repeated K times - https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/repeated-k-times/description/

N = int(input(""))
roll = list(map(int, input("").split(" ")))
K = int(input(""))

dic = {}
for ro in roll:
    if dic.get(ro, -1)==-1:
        dic[ro]=1
    else:
        dic[ro]+=1
final_list=[]

for key, val in dic.items():
    if val==K:
        final_list.append(key)

final_list.sort()
print(min(final_list))