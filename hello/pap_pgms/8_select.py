import pymysql
con = pymysql.connect()
cur = con.cursor(pymysql.cursors.DictCursor)
cur.execute("use test")
cur.execute("SELECT * FROM stud")
for name in cur.description:
	print(name[0], end = "\t")
print()
rows = cur.fetchall()
for row in rows:
    print(row, type(row))
    print(row['id'], row['name'], row['marks'], sep = "\t")
con.close()

