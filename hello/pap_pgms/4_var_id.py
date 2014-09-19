# variable and id
a = 10
print(a, type(a), id(a))
b = 10
print(b, type(b), id(b))
c = a
print(c, type(c), id(c))
d = 5 + 5
print(d, type(d), id(d))
e = 10.0
print(e, type(e), id(e))
f = [ 10, 20, 30, 40 ]
print(f[0], type(f[0]), id(f[0]))
# a, b, c, d, f[0]  have the same id
b = 100
print(a, type(a), id(a)) # a has not changed !!

x = [11, 22, 33]
y = x
print(x, id(x))
print(y, id(y))
x[0] = 1111 # y also changed !
x.append(34)

print(x, id(x))
print(y, id(y))

# types:
#	a) simple type or value type
#	b) structured type or reference type
#		c) immutable type

p = [11, 22, 33]
q = p
q = [44, 55]
print(p, id(p))
print(q, id(q)) # p q are diff !

# when we change a variable of structured type, all others with the
#	same id will be affected
# when we assign to a variable of structured type, a new variable is
#	created; others with the same id are not affected
# there is no concept of changing a value type variable

# every value has a reference count associated with it
# it increases when another variable gets that value
# it decreases when the variable associated with that value changes
# when the count becomes 0, loc is reclaimed
# does garbage collection based on reference count





