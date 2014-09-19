# modify a string
#	
import re
sub = 'bad teacher bad python bad re'
newstr = re.sub('bad', 'worse', sub)
print(newstr)
sub = 'this   string            has   lots of   spaces'
newstr = re.sub('\s+', ' ', sub)
print(newstr)

def fn(m) :
	return 'universe'
sub = 'we are the world'
newstr = re.sub('world', fn, sub)
print(newstr)

x = '2B'
print(int(x, 16))
print(chr(int(x, 16)))

def change(m) :
	#print(m.group(1))
	return chr(int(m.group(1), 16))

sub = 'a%2Bb%25c' #  a+b%c
newstr = re.sub('%(..)', change, sub)
print(newstr)









