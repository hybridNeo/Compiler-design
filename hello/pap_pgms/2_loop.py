# loop
# display n to 1
n = 5
# 'C'
# while(n)
# {
#	printf("%d\n", n);
#	--n;
# }
# Python
# leader:
#	suite

n = 5
while n : 
    print(n)
    n -= 1

# infinte loop
#n = 5
#while n : 
#    print(n)
#n -= 1

# ok
n = 5
while n : 
 print(n)
 n -= 1

# indentation by tab
n = 5
while n : 
	print(n)
	n -= 1

# comibination of tab and spaces : not reco; error in 3.x
#n = 5
#while n : 
#	print(n)
#        n -= 1

# reco: 4 spaces for indentation

a = [ 
	["dhoni", 80, 40, 50, 60 ],
	["kohli", 20, 100, 30, 90 ],
	["raina", 78, 52, 33, 47 ],
	["sehwag", 200, 0, 5 ]
]
# len : polymorphic
print("size : ", len(a))
i = 0
while i < len(a) :
	print(a[i][0])
	j = 1
	total = 0
	while j < len(a[i]) :
		total += a[i][j]
		j += 1
	i += 1
	print(total)

#increase indention for suite wrt leader
# can increase indentation following the leader
# when decreasing indentation, it should match the 
#	indentation of some earlier stmt





















