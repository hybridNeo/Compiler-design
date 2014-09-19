# find all names in a directory
# globbing
import glob
#print (glob.glob('*')) # shell metachar :any char any number of times

# pickup only files
import os
#print( list(filter(os.path.isfile , glob.glob('*'))))

# find the size of all files
#print( list(map(os.path.getsize ,filter(os.path.isfile , glob.glob('*')))))

# get filename and size together
print( list(map(lambda name : (name, os.path.getsize(name)) ,\
	 filter(os.path.isfile , glob.glob('*')))))

# find the biggest file
print( max(map(lambda name : (name, os.path.getsize(name)) ,\
	 filter(os.path.isfile , glob.glob('*'))), \
	  key = lambda pair : pair[1] ) )

# just the name
print( max(map(lambda name : (name, os.path.getsize(name)) ,\
	 filter(os.path.isfile , glob.glob('*'))), \
	  key = lambda pair : pair[1] )[0] )



