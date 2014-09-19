#! /usr/bin/env python
import getopt
import sys
def ind_rating(p):
	s=5
	sum=0
	for a in p:
		sum+=a*s
		s-=1
	return sum




def main():



	try:
		opts, args = getopt.getopt(sys.argv[1:], "f:", ["file"])
	except getopt.GetoptError as err:
		print str(err)
		sys.exit(2)

	length=len(sys.argv)


	
	for o, a in opts:
		if o=='-f':
			file=a


	file_pointer=open(file,"r")
	array=[]
	i=0
	users=[] #
	individual_sum=[]
	line=file_pointer.readline();
	for line in file_pointer:
		list=[]
		k=0
		j=6
		total=0 #
		list1,list2=line.split(',',1)
		final=list2.split(',')

		while k<5:
			given=final[k]
			given=int(given)
		        list.append(given)
			total+=given #
			k+=1
		
		ind=ind_rating(list)
		individual_sum.append(ind)
		users.append(total) #
		array.append(list)	
		i+=1
	total=0
	total_users=sum(users)
	individual_average=[]
	i=0
	
	while i<len(array):
		ind_avg=float(individual_sum[i])/users[i]
		individual_average.append(ind_avg)
		i+=1
	overall_sum=sum(individual_sum)
	overall_average=float(overall_sum)/total_users
	n=0
	bayesian_average=[]
	dupli=[]
	while n<len(array):
		bay_avg=((individual_sum[n]*individual_average[n])+(overall_sum*overall_average))/(individual_sum[n]+overall_sum)
		bayesian_average.append(bay_avg)	
		dupli.append(bay_avg)		
		#print "Product",n+1,bay_avg	
		n+=1
	dupli.sort()
	dupli.reverse()
	
	print "\nADJUSTED BAYESIAN AVERAGE:\n"	
	l=0	
	k=0
	
	while l<len(array):
		k=0
		while k<len(array):
			if dupli[l] is bayesian_average[k]:
				print "Product-",k+1,"adjusted bayesian average",dupli[l],"\n"
 				
			k+=1
		l+=1

	file_pointer.close()
				
	
	
	
main()





