# magager 
import multiprocessing as mp
import os
def f(l, d) :
	l.append(10); l.append(20)
	d['aaa'] = 3; d['aaaa'] = 4
	print("this is  a test  : ", os.getpid())
	
def myrun() :
	m = mp.Manager()
	l = m.list()
	d = m.dict()
#	pass an argument across the processes and save the result back

	p = mp.Process(target=f, args=(l, d))
	p.start()
	p.join()
	print(l)
	print(d)

if __name__ == '__main__' :
	print("start run")
	myrun()
	print("end run")



