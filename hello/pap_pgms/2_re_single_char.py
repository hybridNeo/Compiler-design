# single char regular expression
# 't'	=> matches t
# '\t'  => matches tab; escape to give a special meaning
# '\'   => error
# '\\'  => matches a \; escape to remove the special meaning
# what is special depends on the context

# match a lowercase letter of English
# alternator
#	a|e|i|o|u
#	very powerful for this task
# character class
#	[aeiou]
#	is a set
#	matches a char
import re
sub = 'dear'
pat = '[aeiou]'
m = re.search(pat, sub)
if m :
	print("matched : ", m.group()) # e

# scanning is left to right
# get a single match by default
# match from subject to pattern
# Rule 1:
#	find the leftmost match in the subject string

# pattern: diff?
# 'aaa' : 3 a
# '[aaa]' a     char class is a set


def mymatch(subjects, pat) :
	print('pattern : ', pat)
	for sub in subjects :
		m = re.search(pat, sub)
		if m :
			print(sub, ' : ', m.group())
	print('-' * 40)

subjects = ['0', '9', '5', '.', '-', '5a', 'b6', 'c7d' ]
# match a decimal digit
#pat = '0123456789'  # NO; 10 char string having all digits
#	in that order
#pat = '[0123456789]' # ok
pat = '[0-9]' # range op -
# [25-79]
#	char class matches a char
#	char range and not numeric range
#	[25679]

pat = '[0\-9]' #  0 or - or 9
pat = '[09-]' # 0 or - or 9
# - is special only in the middle of the char class
# pat = '[9-0]' # lower to higher only; error

# ^ as the first char of the char class
#	inverts pattern maching
pat = '[^0-9]' #  match a non-digit
# [^^] match anything other than a caret
# [^\^] match anything other than a caret
# [\^^] match a caret

# macros:
# digit [0-9]   \d
# non-digit [^0-9] \D
# word char(letter digit _)  [A-Za-z0-9_]  \w
# nonword char : [^A-Za-z0-9_]  \W
# white space [ \t\n\r\f]    \s
# non white space [^ \t\n\r\f]    \S
subjects = [ '345xyz' ]
pat = '[\d\D]'
mymatch(subjects, pat)

pat = '\d\D'
mymatch(subjects, pat)

subjects = [ 'cat', 'cut', 'c+t', 'c.t', 'cot', 'coat',
	'ct' ]
# match c any char t
# re: ? : what precedes is optional
# shell : ? matches any one char
pat = 'c?t' # ct or t
# re : . matches a char
pat = 'c.t'
mymatch(subjects, pat)

# diff?
# 'c.t'
# 'c\.t'
# 'c[.]t'
# '[c.t]'
# 'cat'
# 'c[a]t'
# '[cat]'





























































