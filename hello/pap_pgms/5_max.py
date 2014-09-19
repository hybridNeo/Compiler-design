# find the biggest
a = (22, 11, 44, 33)
print(max(a))
b = ('kalidasa', 'valmiki', 'vyasa', 'bhasa')
print(max(b)) 
# len also becomes an arg !!
# use keyword parameter to indicate that this is a callable
#	which shd be used to change each arg

#print(max(b, len)) # error
print(max(b, key = len)) 

c = [ [ "sunil", "gavaskar" ],  ["gundappa", "vishwanath" ],
	[ "brijesh", "patel" ], [ "mohinder", "amarnath" ],
	[ "zahir", "abbas" ] ]

print(max(c)) # [ zahir abbas ]
print(max(c, key = lambda x : x[1]))


