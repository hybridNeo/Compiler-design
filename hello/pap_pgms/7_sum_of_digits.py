# find sum of digits 
n = input("enter an integer : ")
# slicing :  similar to range 
# always [] while indexing or slicing on any data structure
#print (n[2]) # indexing
#print (n[2:4])  # slicing
#print (n[2:])
#print (n[:4])
#print (n[2:6:2])

i = 0
total = 0
while i < len(n) :
	total += int(n[i])
	i += 1
print(total)
