# find sum of digits 
# C  pgm in Python
# 2.7 : raw_input
n = input("enter an integer : ")
print(n, type(n))
n = int(n)
print(n, type(n))

total = 0
i = 0
while n :
	total += n % 10
	n //= 10
	i += 1
print(total)
print("# of iterations : ", i)

