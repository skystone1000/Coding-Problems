for _ in range(int(input())):
    inv_dic = {}
    cost = {}
    cart = {}
    while True:
        cmd = input().split()
        if cmd[0] == "END":
            break
        if cmd[1] == "SM":
            if cmd[2] == "ADD":
                try:
                    val = int(cmd[4])
                    if val>0 and (cmd[3] not in inv_dic):
                        inv_dic[cmd[3]] = val
                        print(val)
                    else:
                        print(-1)
                except:
                    print(-1)
            elif cmd[2] == "REMOVE":
                try:
                    del inv_dic[cmd[3]]
                    print(1)
                except:
                    print(-1)
            elif cmd[2] == "INCR":
                try:
                    val = int(cmd[4])
                    if val>0:
                        inv_dic[cmd[3]] = inv_dic[cmd[3]]+val
                    print(val)
                except:
                    print(-1)
            elif cmd[2] == "DCR":
                try:
                    val = int(cmd[4])
                    if val<inv_dic[cmd[3]]:
                        inv_dic[cmd[3]] = inv_dic.get(cmd[3],0)-val
                        print(val)
                    elif val==inv_dic[cmd[3]]:
                        del inv_dic[cmd[3]]
                        print(val)
                    else:
                        del inv_dic[cmd[3]]
                        print(-1)
                except:
                    print(-1)
            elif cmd[2] == "SET_COST":
                try:
                    cost[cmd[3]] = float(cmd[4])
                    print(float(cmd[4]))
                except:
                    print(-1)
            elif cmd[2] == "GET_QTY":
                try:
                    print(inv_dic.get(cmd[3],0))
                except:
                    print(-1)
        elif cmd[1] == "S":
            if cmd[2] == "ADD":
                try:
                    val = int(cmd[4])
                    if val>0 and (cmd[3] not in cart):
                        cart[cmd[3]] = val
                        print(val)
                except:
                    print(-1)
            elif cmd[2] == "REMOVE":
                try:
                    del cart[cmd[3]]
                    print(1)
                except:
                    print(-1)
            elif cmd[2] == "INCR":
                try:
                    val = int(cmd[4])
                    if val>0:
                        cart[cmd[3]] = cart[cmd[3]]+val
                    print(val)
                except:
                    print(-1)
            elif cmd[2] == "DCR":
                try:
                    val = int(cmd[4])
                    if val<cart[cmd[3]]:
                        cart[cmd[3]] = cart.get(cmd[3],0)-val
                        print(val)
                    elif val==cart[cmd[3]]:
                        del cart[cmd[3]]
                        print(val)
                    else:
                        del cart[cmd[3]]
                        print(-1)
                except:
                    print(-1)
            elif cmd[2] == "GET_ORDER_AMOUNT":
                out = 0
                try:
                    for i in cart.items():
                        out+= (cost[i[0]]*i[1])
                    print("{:.2f}".format(out))
                except:
                    print(-1)