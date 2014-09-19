# files
#	physical name : name by which OS knows it ; string
#	logical name : name by which the pgm knows it - depends
#		on the lang - identifier
#	modes : read, write, append, i/o modes(r+, w+, a+)
#	pipe open mode
#		send input to a cmd as if it is a file
#		read output of a cmd as if it is a file

f = open("f1", "r")
# f is an object
print(f, type(f))
f.close()


