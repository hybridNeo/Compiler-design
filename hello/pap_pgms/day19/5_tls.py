# thread local storage
import threading
def disp() :
	print(ls.x)
	print(y) # 100 200 or 100 100 or 200 200 or 200 100
def fn1() :
	global ls
	global y
	ls.x = 15
	y = 100
	print(ls.x)
	disp()
			
def fn2() :
	global ls
	global y
	ls.x = 20
	y = 200
	print(ls.x)
	disp()
	

class MyThread(threading.Thread) :
	def __init__(self, fn) :
		print("ctor called")
		threading.Thread.__init__(self, target=fn)
	
	

print("before")
# creates a thread local variable
y = 10
ls = threading.local()
ls.x = 10
t1 = MyThread(fn1)
t2 = MyThread(fn2)
t1.start()
t2.start()
print("main : ", ls.x) # 10
