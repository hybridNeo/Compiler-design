# for looping structure
# for <var> in <iterable> :
#	<suite>

#  keyword parameter : end is a parameter
#  does not create a variable
for i in [0, 1, 2, 3, 4] :
	print(i, end ="\t")
#print(end)  # error
print()

for i in range(5) :
	print(i, end ="\t")
print()

# what is the relationship bet loop variable and the iterable object?
# loop variable is always a copy of the element of the iterable object
# it could be a copy of value type or copy of reference type
# any change to a copy of value type will not affect the iterable object
# any assignment to a copy of ref type will not affect the iterable object
# any change to a copy of ref type will affect the iterable object
a = [11, 22, 33, 44]
for i in a :
	print(i, end = "\t")
	i += 100
print()
print(a) # no change

a = [[11], [22], [33], [44]]
for i in a :
	print(i, end = "\t")
	i = i + [100]
print()
print(a) # no change

a = [[11], [22], [33], [44]]
for i in a :
	print(i, end = "\t")
	i.append(100)
print()
print(a) # change
























