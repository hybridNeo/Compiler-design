# interprocess communication:
#	Queue
#	Pipe
import multiprocessing as mp
import os
def f(x) :
	print("par :", x, "pid : ", os.getpid())
	print("got : ", pc.recv())
	pc.send("bangalore")
	pc.close()

def myrun() :
	p = mp.Process(target = f, args = ("test",)) 
	p.start()
	pp.send("pes")
	print("waiting")
	p.join()
	print("recd: ", pp.recv())
	pp.close()

(pp, pc) = mp.Pipe()
if __name__ == '__main__' :
	print("start run")
	myrun()
	print("end run")



