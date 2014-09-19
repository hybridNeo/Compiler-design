# add a document string
s = "mystrng"
def decowrap(s) :
	def deco(f) :
		def what() :
			f()
		what.__doc__ = s
		return what
	return deco
# decorator is a call to fn which in turn returns a fn which
#	decorates f
@decowrap(s)
def f() :
	print("this is f")
f()
# put a document string for the function
print(f.__doc__)

