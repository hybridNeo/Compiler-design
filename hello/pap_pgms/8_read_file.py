# read a file
# create a file
#	to write to a file
#	a) use print
#	b) use write
f = open("books.txt")
g = open("newbooks.txt", "w")
# file object is iterable
for line in f :
	line = line.strip()
#	write to the file
#	print(line, file=g)
	g.write("hello " + line + "\n")
f.close()
g.close()

