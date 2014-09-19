# check whether a number is bet 0 and 100
n = int(input("enter a number:"))
#if n < 0 or n > 100 :
#if not n in range(0, 101) :
if not 0 <= n <= 100 :
	print("NO")
else :
	print("YES")

