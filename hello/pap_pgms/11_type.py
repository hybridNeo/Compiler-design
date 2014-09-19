

import pymysql
con = pymysql.connect()
cur = con.cursor()
cur.execute("use test")
cur.execute("insert into event values(%s,%s)", ("ind day", pymysql.Date(1947, 8, 15)));
cur.execute("insert into event values(%s,%s)", ("rep day", pymysql.Date(1950, 1, 26)));
con.commit()
cur.execute("select * from event")
rows = cur.fetchall()
for r in rows :
	print(r[0], r[1],
	r[1].day, r[1].month, r[1].year)
cur.close()
con.close()


