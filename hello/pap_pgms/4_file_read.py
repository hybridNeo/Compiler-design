# read a file
#	a) readline
f = open("f1.txt", "r")
l = f.readline()
print(l, type(l))
# reads the next line
l = f.readline()
print(l, type(l))
f.close()

