# create a thread
# _thread : low level module
import _thread
import time
def fn (x):
	print("enter thread fn")
	time.sleep(5)
	print("exiting thread fn")

print("main program - creating  a thread")
t1 = _thread.start_new_thread(fn, (1,))
print(type(t1))
print(t1)
print("main program - created thread")
time.sleep(10)
#_thread.exit() 
	
# when the main thread exits, the process dies
# all the threads die

# can call to thread.exit() allow other threads to continue?
#	NO in python library

# may have to use mutex lock to stop main thread exiting
