import pymysql
con = pymysql.connect()
cur = con.cursor()
cur.execute("use test")
cur.executemany("insert into stud values(%s, %s, %s)",
	[
		(3, 'cccc', 300),
		(4, 'dddd', 400),
		(5, 'eeee', 500)
	]
)
con.commit()
cur.close()
con.close()

