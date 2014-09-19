# interprocess communication:
#	queue
#		put 
#		get
import multiprocessing as mp
import os
def f(x) :
	print("par :", x, "pid : ", os.getpid())
	print("got : ", q.get())

def myrun() :
	p = mp.Process(target = f, args = ("test",)) 
	p.start()
	q.put("pes")
	print("waiting")
	p.join()

q = mp.Queue()
if __name__ == '__main__' :
	print("start run")
	myrun()
	print("end run")



