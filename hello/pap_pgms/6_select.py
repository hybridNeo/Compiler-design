import pymysql
con = pymysql.connect()
cur = con.cursor()
cur.execute("use test")
#cur.execute("SELECT * FROM stud")
cur.execute("SELECT name, marks + 100  FROM stud")
#print(cur.description)
for col in cur.description :
	print(col[0], end = "\t")
print()
rows = cur.fetchall()
for row in rows:
    for val in row :
        print(val, end = "\t")
    print()
cur.close()
con.close()

