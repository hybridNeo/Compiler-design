# list :
#	is a data structure
#	therefore an interface
#	check: dir(list), help(list)
#	like an array
#	no concept of homogeneity
#	indexed by int
#	lower bound:
#		0
#	no pointers => no pointer arithmetic
#	create :
#		a) using []
#		b) list ctor
a = [11, "eleven", "hattu mattondu", int("1" + "1")]
print(a)
# indices
#    0    1   2   3   4
#    -5 -4   -3  -2  -1
a = [11, 22, 33, 44, 55]
print (a[3]) # 44
# index out of bounds
# print(a[5]) #  throws an exception

#  # of elem :
print(len(a))

# slicing
print(a[2:4])  # [33, 44]

print(a[:])

b = a # shallow copy  both b and a refer to the same list ; alias
b[0] = "stupid"
print (a) # a would have changed

a = [11, 22, 33, 44, 55]
c = a[:] # deep copy
c[0] = "fool"
print (a) # a would not have changed

a = [11, 22, 33, 44, 55]
print(a[::2])
print(a[::-1]) # reverse !!!

# modify : add, remove
# check : membership, search

a = [11, 22, 33, 44, 55]
#a[5] = 66 # NO
a.append(66)
print(a)
#  extend(iterable)
#	each element is appended
a.extend([77, 88])
a.append([99, 110]) # adds a single sequence
print(a)

# 
print (33 in a, 34 in a)
print (a.index(33)) # 2
# print (a.index(34)) # throws an exception

# remove
#	based on pos
a = [11, 22, 33, 44, 55]
print(a.pop())
print(a)

print(a.pop(1))
print(a)
#	based on val 

a = [11, 22, 33, 44, 55]
a.remove(33)
#a.remove(66)#exception

# insert at any pos
# a.insert(pos, val)























