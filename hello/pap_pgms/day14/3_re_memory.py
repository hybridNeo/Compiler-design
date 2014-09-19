# back reference or memory
import re


def mymatch(subjects, pat) :
	print('pattern : ', pat)
	for sub in subjects :
		m = re.search(pat, sub)
		if m :
			print(sub, ' : ', m.group())
	print('-' * 40)

subjects = [ 'hello' ]
# match if two consecutive chars are same
pat = '..'   #he
# memory or backreference
# 	use parentheses in the pattern
# pattern is made dynamically
# . matches h ; pattern becomes hh
# . matches e ; pattern becomes ee
# . matches l ; pattern becomes ll
# pattern should preferably raw strings
pat = r'(.)\1' # python would not expand the escape sequences
mymatch(subjects, pat) #

sub = 'abcdefgh'
# number these based on left parenthesis
#      12   3    4 5
pat = '((..)(..))(.(..).)'
m = re.search(pat, sub)
if m :
	print('matched : ', m.group())
	print('matched : ', m.groups())
	print('matched : ', m.group(1))
	print('matched : ', m.group(2))
	print('matched : ', m.group(3))
	print('matched : ', m.group(4))
	print('matched : ', m.group(5))

sub = 'bad teacher bad python bad re'
pat = 'bad (\w+)'
pat = 'bad (\w+) bad (\w+) bad (\w+)'
m = re.search(pat, sub)
if m :
	print(m.groups())

print(re.findall('bad (\w+)', sub))











