# dict :
#	has key value pairs
#	keys are unique
#	has diff names :
#		java : map  hashtable
#		C++ : map unordered_map
#		perl : hash
#		tcl : array
#		
#	create :
#		{ k1 : v1, k2 : v2 }
#		ctor
#			sequence of pairs
a = { 'apple' : 'newton',  'snake' :  'kekule', 'orange' : 'hanuman' }
print(a) # order is not defined
# uses hashing
# get value for a key
print(a['apple'])
# replace a value for a given key
a['apple'] = 'turing'
print(a['apple'])
# add key value pairs
a['grapes'] = 'jackal'
print(a) # order is not defined
del a['grapes']
print(a) # order is not defined

print (a.keys())
print (a.values())

z = [('kalidasa', 'shakuntala'), ('bhasa', 'swapna vasavadatta'),
	('baana', 'kadambari') ]
print(z, z[-1])

d = dict(z)
print(d)


#z = [('kalidasa', 'shakuntala'), ('bhasa', 'swapna vasavadatta'),
#	('baana' ) ]  # error
#d = dict(z)
#print(d) 

z = [('kalidasa', 'shakuntala'), ('bhasa', 'swapna vasavadatta'),
	('baana', 'kadambari'), ('kalidasa', [ 'raghuvamsha', 
	'kumarasambhava' ]) ]

d = dict(z)
print(d)

for k in d.keys() :
	print(k, d[k])

for k in d :
	print(k, d[k])

























