# user defined fn

# features:
#	definition
#	call (invoke)
#	parameters
#	return 
#	callback
#	overload ?
#	access control ?
#	recursion
#	life:existence scope:visibilty
#		variable
#		function
#	closure
#	decorator

# fn defn:
# leader:
#	suite (body)
# leader :  keyword def then fnname then parameters within parentheses
#	no return type
#	no type for parameters

#invoke : use parentheses

# can we call the fn before defn?
#	runtime error
# no concept of fn declaration
print("zero")
#what()

def what():
	print("hello from what")
print(what, type(what), id(what))
print("one")
what # fnname => expr => stmt
print("two")
what()
print("three")

# f becomes another name for the same function
f = what  #  f is callable
print(f, type(f), id(f))
f()

a = 10
print(a)
del a
#print(a) # NameError

# remove a fn
del what
f()














