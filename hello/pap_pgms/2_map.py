# given an iterable(list) which stands for some numbers,
# create an iterable(list) which has squares of those numbers

a = [11, 22, 33, 44]
b = []
for i in a :
	b.append(i * i)
print(b)

# create a list of length of each string
c = [ 'elephant', 'ant', 'deer', 'eagle' ]
d = [ ]
for i in c :
	d.append(len(i))
print(d)

# walk thro an iterable; do some operation on each element
# collect the result  : map
# first arg should be callable (could be a fn)
# returns a list in 2.7; returns an iterable object called map
#	in 3.x
d = map(len, c)
print(list(d))

b = map(lambda x : x * x, a)
print(list(b))

#------------------
x = (11, 22, 33)
y = (44, 55, 66)
print(list(map(lambda p, q : p + q, x, y)))














