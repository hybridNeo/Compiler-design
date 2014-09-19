# make two sections execute alternately
from threading import *
import time
import random
import sys
import _thread
# get letters in pairs
def fn1() :
	s = 'ABCDEFGH'
	for i in range(0, len(s)) :
		s1.acquire()
		print(s[i], end=' ')
		sys.stdout.flush()
		time.sleep(int(random.random() * 3))
		print(s[i], end=' ')
		sys.stdout.flush()
		s2.release()
		time.sleep(int(random.random() * 3))
			
def fn2() :
	s = 'abcdefgh'
	for i in range(0, len(s)) :
		s2.acquire()
		print(s[i], end=' ')
		sys.stdout.flush()
		time.sleep(int(random.random() * 3))
		print(s[i], end=' ')
		sys.stdout.flush()
		s1.release()
		time.sleep(int(random.random() * 3))

	

class MyThread(Thread) :
	def __init__(self, fn) :
		print("ctor called")
		Thread.__init__(self, target=fn)
	
		

print("before")
s1 = Semaphore(1)
s2 = Semaphore(0)
t1 = MyThread(fn1)
t2 = MyThread(fn2)
t1.start()
t2.start()
t1.join()
t2.join()

