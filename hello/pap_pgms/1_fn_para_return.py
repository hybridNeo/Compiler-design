# parameter passing
#	checks for # of args and # of parameters
#	type is dynamic
#	cannot specify type of parameter
#	can pass args of any type
def f1(a, b) :
	pass
#f1(1)
#f1(2, 3, 4)
f1(1, 2)
f1("1", "2")
f1([11, 22], (33, 44))

# what is the parameter passing mechanism?
# always by value
#	value itself could be value type or reference type
#	assign a new value to a reference type, parameter will
#		change; no effect on arg
#	modify a component of the reference type, arg is also
#		changed

def f2(x) :
	x = x + 10
a = 10
f2(a)
print("a : ", a)# 10

def f3(x) :
	x = [20]
a = [10]
f3(a)
print("a : ", a) # [10]

def f4(x) :
	x[0]  = 20
a = [10]
f4(a)
print("a : ", a) # [20]

def f5(x) :
	x.append(20)
a = [10]
f5(a)
print("a : ", a) # [10, 20]]

#--------------
def foo(x, y) :
	t = x; x = y; y = t
a = [10,  20]; b = [30, 40]
foo(a, b) # does not swap
# a, b unchanged
print("a : ", a)
print("b : ", b)

#---------------

a, b = b, a
#(a, b) = (b, a)
print("a : ", a)
print("b : ", b)

#-----
# default parameters
#	to make the client life easier

#	default can be of any type
#	rightmost parameters can be default
def g1(a, b = [11, 22, 33], c = 10) :
	print(a, type(a))
	print(b, type(b))
	print(c, type(c))


g1(10, 20, 30)
g1(40, 50)
g1(60)

# non-default para cannot follow default para
#def g2(x = 10, y) :
#	pass

# can the default be a variable? yes
# default is fixed at the point of execution of the fn defn
x = 111
def g2(a = x) :
	print(a, type(a))
	print()
x = 222
g2()

x = [111]
def g3(a = x) : # x has not changed; what x refers to is changed !!
	print(a, type(a))
	print()
x.append(222)
g3()

# how does default behave?
def g4(e, l = [] ) :
	l.append(e)
	return l

print(g4(10)) # [10]
print(g4(20)) # [10, 20]
mylist = [11, 22]
print(g4(30, mylist)) # [11, 22, 30]

print(g4(40)) # [10, 20, 40]














































