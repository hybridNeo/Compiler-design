# nesting of fn defn
# fn returns a fn
def f() :
	def g() :
		print("g in f")
	print("in f")
	#g()
	return g
	

#pass :dummy executable stmt
#g() : error

#f()
#g() : error

#f.g() : NO

what = f()
what()


# factory : has the responsibility of creation
def create(os) :
	def mylist() :
		if os == "ms" :
			print("ms: dir")
		elif os == "unix" :
			print("unix: ls")
	print("g : ", id(mylist))
	return mylist
	
		
# closure:
#	an object has # of attributes. two objects of the same class
#	can have diff states
#	a pointer to a fn in 'C' has just one value - addr of a text
#		segment
#	Python: create callable(fn) which also can hold
#		some attributes - has a state
#	having atributes for a fn : fn closure


f1 = create("unix")
f2 = create("ms")
print(f1, id(f1))
print(f2, id(f2))
f1()
f2()









