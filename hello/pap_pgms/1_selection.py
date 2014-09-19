# selection
# if stmt
# no switch stmt
#	how python solves dangling else problem

# given 3 sides forming a triangle, classify the triangle as 
#	equilateral, isosceles and scalele
line = input("enter 3 sides of a triangle separated by comma : ")
(a, b, c) = line.split(",")
#print(a)
#print(b)
#print(c)
# do convert the variables to int
a = int(a)
b = int(b)
c = int(c)
if a == b :
    if b == c :
         print('equi')
    else:
         print("iso")
elif b == c :
    print("iso")
elif c == a :
    print("iso")
else:
    print("scalene")

    



