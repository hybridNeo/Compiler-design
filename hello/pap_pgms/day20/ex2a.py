import multiprocessing as mp
import os
a = 100
# not shared in process model
# shared in thread model
def f(x) :
	print("par :", x, "pid : ", os.getpid())
	print("child process:  a: ", a)

def myrun() :
	global a
	p = mp.Process(target = f, args = ("test",)) 
	p.start()
	a = 200
	print("waiting")
	print("main :  a: ", a)
	p.join()

if __name__ == '__main__' :
	print("start run")
	myrun()
	print("end run")



