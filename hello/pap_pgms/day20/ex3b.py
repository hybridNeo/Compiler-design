# interprocess communication:
#	queue
#		put 
#		get
import multiprocessing as mp
import os
import time
def f(x) :
	print("par :", x, "pid : ", os.getpid())
	a = q.get()
	print("got : ", a)
	qq.put(a * a)

def myrun() :
	p = mp.Process(target = f, args = ("test",)) 
	p.start()
	q.put(10)
	print(qq.get())
	print("waiting")
	p.join()

q = mp.Queue()
qq = mp.Queue()
if __name__ == '__main__' :
	print("start run")
	myrun()
	print("end run")



