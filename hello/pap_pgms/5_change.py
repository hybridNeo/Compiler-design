a = [11, 22, 33, 44]
b = a
print(id(a), id(b), a, b)
b = [55, 66] # assignment
print(id(a), a) # will not change

a = [11, 22, 33, 44]
b = a
print(id(a), id(b), a, b)
b[0] = 55
print(id(a), a) # will change

