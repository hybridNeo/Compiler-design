# installation
# sudo easy_install pymysql3

import pymysql
con = pymysql.connect()
cur = con.cursor()
cur.execute("use test")
cur.execute("SELECT * FROM stud")
rows = cur.fetchall()
print(type(rows))
for row in rows:
    print(row)
print(type(con))
con.close()

