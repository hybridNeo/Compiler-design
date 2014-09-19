# special fn : reduce
#	map : input : n elements : output : n elements
#	filter : input n elements : output : 0 .. n elements
#	reduce : input n elements : output : one element

a = [2, 4, 6, 8, 10 ]
print("reduce : ", reduce(lambda x, y : x + y, a))
print("reduce : ", reduce(lambda x, y : x + y, a, 100))
print("reduce : ", reduce(lambda x, y : x * y, a))

a = [ 'raja', 'ram', ' mohan', ' roy']
print("reduce : ", reduce(lambda x, y : x + y, a))

print("reduce : ", reduce(lambda x, y : x + y, [10]))
print("reduce : ", reduce(lambda x, y : x * y, [10]))
