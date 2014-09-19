# special fns
# zip
import glob
import os
names = list(filter(os.path.isfile, glob.glob('*')))
print (names)
sizes = list(map(os.path.getsize, names))
print (sizes)
print(list(zip(names, sizes)))

states = ( 'karnataka', 'tamilnad', 'andhrapradesh')
capital = ( 'bangalore', 'chennai', 'hyderabad')
print (list(zip(states, capital)))

# no. of elements in the result of zip depends on the shortest
#	iterable
print (list(zip(range(5), range(10, 16), range(20, 28))))

#-------------
# read date and check
# s = input("enter a string as dd/mm/yyyy : ")
# (dd, mm, yy) = map(int ,s.split("/"))
# print(dd, type(dd))
#--------------















