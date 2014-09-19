

# read a file
# find all languages
#	a) readline
#	b) readlines
#	c) read
#	d) read(n)   read n bytes
# find unique languages
f = open("books.txt", "r")
all = f.read()
f.close()
#print(all, type(all))
lib = { }
for line in all.split('\n') :
	line = line.strip()
	if not line : break # skip any blank line
	print(line)
	(lang, author, title) = line.split(':')
#	print (lang)
#	print (author)
#	print (title)
	if lang not in lib : lib[lang] = {}
	if author not in lib[lang] : lib[lang][author] = []
	lib[lang][author].append(title)

	 
#print(lib)
for lang in lib :
	print(lang)
	for author in lib[lang] :
		print("\t", author)
		for title in lib[lang][author] :
			print("\t\t", title)












