# calling fn
# matching arg to para:
# 1. positional parameter : match the arg to the corr parameter
# 2. keyword parameter: specify a parameter and give a value for it
def f1(a, b, c) :
	print(a, type(a))
	print(b, type(b))
	print(c, type(c))
	print()
f1(11, 22, 33)
c = 333
# are not assignment; assignment is not an expr
f1(c = 33, b = 22, a = 11)
print("c : ", c) # 333

# combination of positional and keyword parameters
f1(10, c = 30, b = 20)
# all non-keyword args should come before the keyword parameters
#f1(10, b = 20, 30)

#f1(10, 20, b = 30) # error

# variable # of args : parameter is a tuple
def f2(*args) :
	print(args, type(args))
	return sum(args)
print(f2(10, 20, 30))
print(f2(40, 50))

# NO; only one parameter can be of variable # of arg type
#def f3(*x, *y) :
#	pass

def f4(a, b, *c) :
	print(c, type(c))

f4(1, 2)
f4(1, 2, 3)
f4(1, 2, 3, 4)

# parentheses : for an expr or for a tuple
x = (10) #int
print(x, type(x))

x = (10,) #tuple
print(x, type(x))

def f5(*c, a, b) :
	print(c, type(c))


#f5(1, 2, 3, 4) # NO
# a b shd be keyword parameters
f5(1, 2, b = 4, a = 3)

# key value pairs as args
def f6(book, author, *places, **pairs) :
	print(places, type(places))
	print(pairs, type(pairs))
f6('ramayana', 'valmiki', 'ayodhya', 'lanka', 'panchavati', \
    name = 'rama', father = 'dasharatha', mothers = [ 'kaikeyi',
    'kousalya', 'sumitra' ])
f6('yagnaphalam', '????')

def f7(**kwarg) :
	para = {'bgcolor' : 'black', 'fgcolor' : 'red', 'size' : 10,
		'pos' : 'center', 'font' : 'times new roman'}
	para.update(kwarg)
	print(para)	

f7(bgcolor = 'blue', fgcolor = 'white', size = 14)
f7()











