from threading import *
# import threading
import _thread
import random
import time
global_sum = 0
def fn(limit) :
	global global_sum
#	print("thread starts")
#	print(limit)
	low, high = limit
	s = sum(a[low:high])
	print(s)
	m.acquire()
	global_sum += s
	m.release()
#	time.sleep(5)
#	print("thread ends")
	
# threading.Thread
class MyThread(Thread) :  #inheritance
	def __init__(self, fn, arg) :
	#	print("ctor called")
		Thread.__init__(self, target=fn, args = arg)
	
	def run (self) :
	#	print("run called")
		Thread.run(self)
		
n = 10000000
p = 4
step = int(n / p)
low = 0
#a = [ int(random.random() * 100) for i in range(100) ]
a = list(range(n))
t = []
m = _thread.allocate_lock()
#print(a)
for i in range(p) :
	t.append(MyThread(fn, ([low, low +step],)))
	low += step
	t[i].start()

for i in range(p) :
	t[i].join()

print("sum : ", global_sum)
