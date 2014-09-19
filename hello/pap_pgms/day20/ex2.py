import multiprocessing as mp
import os
def f(x) :
	print("par :", x, "pid : ", os.getpid())

def myrun() :
	p = mp.Process(target = f, args = ("test",)) 
	p.start()
	print("waiting")
	p.join()

if __name__ == '__main__' :
	print("start run")
	myrun()
	print("end run")



