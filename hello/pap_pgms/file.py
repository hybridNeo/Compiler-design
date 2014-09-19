file_pointer=open("rating.txt","r")
list=[]
for line in file_pointer:
	#fp=file_pointer.readline()
	list1,list2=line.split(',',1)
	print(list2)
	final=list2.split(',')
	#print final
	i=0
	while i<5:
		user=final[i]
		print user
		i+=1
		
