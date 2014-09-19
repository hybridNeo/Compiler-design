# return mechanism
#	no default return mechanism
def f1() :
	1729
res = f1()
print(res, type(res)) # None of NoneType

def f2() :
	return	1729
res = f2()
print(res, type(res)) # 1729 int

# what can the fn return ? anything in python
def f3() :
	return [1, 2, 3, 4]
res = f3()
print(res, type(res)) # 

# single parameter; no type
def f4(n) :
	return n * n

res = f4(5)
print(res, type(res)) # 

def f5(n) :
	return f4(n)

res = f5(5)
print(res, type(res)) # 


def f6() :
	print("f6 called")
	return f4
#del f4 # results in error when f6 is called
res = f6()
print(res, type(res)) # 

res = f6()(5)
print(res, type(res)) # 



# 1. execution of fn defn : leader is checked
# 2. execution of fn call : suite is checked








