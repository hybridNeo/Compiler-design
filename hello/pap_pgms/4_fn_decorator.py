#decorator
def pre(op) :
#	process() # ok
	def what():
		print("before processing")
		op()
	return what

def post(op):
	def what() :
		op()
		print("after processing")
	return what
def process() :
	print("this is processing")
#process = pre(process)
#process()

process = pre(post(process))
process()



# fn can be called only after defn
# checked when fn call is executed and not fn defn
# pls note that execution of fn defn is not same as execution of fn call

