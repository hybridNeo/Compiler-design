# multiple char regex
# * :
#	shell: any char repeated 0 or more times
#	re : closure
#		zero or more of what precedes it
# + : re : positive closure
#		one or more of what precedes it
import re


def mymatch(subjects, pat) :
	print('pattern : ', pat)
	for sub in subjects :
		m = re.search(pat, sub)
		if m :
			print(sub, ' : ', m.group())
	print('-' * 40)


subjects = [ 'ab*d', 'abcd', 'ad', 'abbbd', 'cad', 'xxadyy' ]
#pat = 'ab*d'
pat = 'ab+d'
# ab{3}d   => abbbd  : counting closure
# ab{3,5}d => abbbd | abbbbd | abbbbbd 

# how to simulate * of shell in regex => .* 
# Rules:
# 1. leftmost
# 2. eager : satisfy the eagerness
# 3. greedy : then become greedy
#	re engine backtracks to match the remaining pattern

#	to make the match non-greedy, we use a question mark
#	following the closure symbol
subjects = [ 'axxxbyyybzzz' ]
pat = 'a.*b' # greedy axxxbyyyb
pat = 'a.*?b' # non greedy axxxb


subjects = [ 'good food' ]
pat = 'o+' # match oo of good
mymatch(subjects, pat)
pat = 'o*' # match zero o before g; matches nothing successfully
mymatch(subjects, pat)
























































