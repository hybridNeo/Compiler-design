from threading import *
# import threading
import time
def fn() :
	print("thread starts")
	time.sleep(5)
	print("thread ends")
	
# threading.Thread
class MyThread(Thread) :  #inheritance
	def __init__(self, fn) :
		print("ctor called")
		Thread.__init__(self, target=fn)
	
	def run (self) :
		print("run called")
		Thread.run(self)
		

print("before")
t1 = MyThread(fn) # register the thread fn name
# does not call the fn at this point of time

print("After")
t1.start() # calls the run of Thread which starts the thread fn
print("waiting for thread to complete")
t1.join() # waits for thread fn to complete
print("thats all")
