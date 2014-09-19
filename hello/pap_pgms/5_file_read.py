# read a file
# find all languages
#	a) readline
langlist = []
f = open("f1.txt", "r")
# reads the newline into the variable
l = f.readline()
while l :
	# remove the newline
	# strings are immutable
	l = l.strip()
	lang = l.split(':')[0]
#	print(lang)
	if lang not in langlist : langlist.append(lang)
#	print(l)
	l = f.readline()
f.close()
for lang in langlist :
	print(lang)


