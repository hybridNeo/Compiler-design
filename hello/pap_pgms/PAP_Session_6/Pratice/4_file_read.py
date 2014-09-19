
# read a file
# find all languages
#	a) readline
#	b) readlines
# find unique languages
f = open("books.txt", "r")
lines = map(str.strip , f.readlines())
f.close()
#print(l)
langdict = {}
for line in lines :
	lang = line.split(':')[0]
	langdict[lang] = None
for lang in langdict :
	print(lang)
print(langdict)

