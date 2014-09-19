# regular expression
#	type 3 language according to Chomsky's hierarchy of formal
#		languages
#	acceptor: finite state machine
#	used for pattern matching

# book: beautiful code

# tools using regex:
#	vi
#	grep
#	awk
#	lex
#	
# programming lang
#	perl
#	C++ 11
#	Java
#	...

# book: mastering regular expression 
#	
# re supported in Python is type 1

# pattern matching : we look for a pattern in a subject
import re
subject = 'monkey'
pattern = 'on'
m = re.search(pattern, subject)
print(m) # match object on success

subject = 'monkey'
pattern = 'off'
m = re.search(pattern, subject)
print(m) # None on failure


subject = 'monkey'
pattern = 'on'
m = re.search(pattern, subject)
if m :
	print(m.group()) # what is matched
	print(m.start()) # start index
	print(m.end()) # end index ; one past the end
	print(m.span())

	print('before : ', subject[:m.start()])
	print('match :', m.group())
	print('after : ', subject[m.end():])

# we are embedding regular expr
# in python pgm
# run in some shell

# same symbol may have different semantics
# for the same semantics, we may require diff symbols


















































