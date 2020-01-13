
import random
sert = random.randint(1,10)
tem = input("输入")
temp = int(tem) 
while sert != temp:
    if sert == temp:
        print("恭喜你！")
    else:
        if(sert < temp):
            print("输入太大：")
        else:
            print("输入太小：")
        tem = input("输入错误，请重新输入：")
        temp = int(tem)