# no operator with side effect
# no sequence point
# no ++   no --
# all assignment operators modify variables -  do not give a value
# assignment is not an expr
# += -= *= /= %= **= <<= >>= ...
# 
# in
#	checks for membership
print ( "g" in "together")
print ( "get" in "together") # check for sustring
print ( 10 in [20, 10, 30])
print ( 10 not in [ (20, 10), 30])
print ( 10 in [ (20, 10), 30][0])
print ( (20, 10)  in [ (20, 10), 30])
print (  "karnataka" in { "karnataka" : "bangalore", "telangana" : "hyderabad" })
print (  "hyderabad" not in { "karnataka" : "bangalore", "telangana" : "hyderabad" })
print (  "hyderabad" in { "karnataka" : "bangalore", "telangana" : "hyderabad" }.values())
