import pymysql
con = pymysql.connect()
cur = con.cursor()
print("autocommit mode : ", con.autocommit_mode)
cur.execute("use test")
cur.execute("insert into stud values(3, 'cccc', 500)")
cur.close()
con.close()

# autocommit is off
# record is not stored in the database !

