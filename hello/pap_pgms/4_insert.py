import pymysql
con = pymysql.connect()
con.autocommit(True)
cur = con.cursor() # autocommit is on; transaction processing disabled
cur.execute("use test")
cur.execute("insert into stud values(4, 'dddd', 300)")
cur.close()
con.close()


