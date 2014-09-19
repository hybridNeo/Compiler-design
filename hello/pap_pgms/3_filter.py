# filter
a = range(5)
# map : n inputs => n outputs
print(list(map(lambda x : x % 2, a))) # 0 1 0 1 0
# filter : select elements when the callable returns True
# filter : n inputs => 0 .. n outputs
print(list(filter(lambda x : x % 2, a))) # 1 3  

b = [ 'aaaa', 'bbb', 'ccccc', 'dddd', 'e', 'ff' ]
# all uppercase
print(list(map(str.upper, b)))
# all strings longer than 3 char
print(list(filter(lambda s : len(s) > 3, b)))

# find all strings longer than 3 char and convert to uppercase

print(list(map(str.upper, filter(lambda s : len(s) > 3, b))))
