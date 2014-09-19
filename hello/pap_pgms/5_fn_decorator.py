
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

# process = pre(post(process))
@pre
@post
def process() :
	print("this is processing")

process()
