# function with no name - anonymous fn
#	should be having a single expr in the suite
# lambda : is becoming popular in multicore technologies
#	   support pure and re-entrant fns (functional programming)

# pure fn : output depends only on inputs ; like mathematical fns
#		no side effects; no global variables used
# re-entrant fn : if the order of execution gets interrupted,
#		it should have no effect on the result

f = lambda x : x * x
print (f, type(f))
print(f(10))
print((lambda x : x * x * x)(11))

g = lambda x, y : x + y;
print(g(10, 20))

f1 = lambda x : x * x
print(id(f), id(f1)) # diff
