import pymysql
val = 11
con = pymysql.connect()
cur = con.cursor()
cur.execute("use test")
#cur.execute("""update stud set marks = marks + 100""")
n = int(input("enter value to add : "))
# we create the sql stmt by string manipulation supported by Python
# For the database engine, it is a const string
# if we repeat executing such stmt, each time database engine has interpret

# can we have placeholders for data in sql stmt?

cur.execute("""update stud set marks = marks + %d""" % n)
print("records affected : ", cur.rowcount)
con.commit()
cur.close()
con.close()


