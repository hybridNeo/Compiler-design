# operators
#	+ - * / // ** %
# * : polymorphic:
#	numbers : multiplicative
#	str and int : replicative
#	list and int : replicative
#	tuple and int : replicative

print(3 * 4, "pes" * 4, [1, 2] * 4, (1, 2) * 4)

print(4 * "pes")

#print({1:2} * 4)

print(3 + 4 , "pes" + " it", [1, 2] + [3, 4])

# ** : exponentian op; right associative
print(2 ** 3, 2 ** 3 ** 2) # 8 512

print(25 / 4, 25 // 4, 25 % 4, 25.8 % 4.2)

# relop : == <= >= != < > in
#	bool : True False
print (5 == 5) # True
print (5 == 5 == 5) # True

# a == b == c     =>   (a == b) and (b == c)
# True : 5 -5 "pes" [11] non empty data structure
# False: 0  "" []  empty data structure

# logical op :
# 'C'	 1 && 2 : 1  
#	 1 & 2  : 0
# Python: logical :  not and or
#	  bitwise  & | ^ ~ << >>

# short ckt eval
#	eval left to right logical expr
#	stop as soon as the truth or falsehood is found
# a = 0; b = 10
# c = b / a > 2  # error
# c = (a == 0) or (b / a > 2)

a = b = 10
print(a, b)
a = (b = 10)
print(a, b)


  
















