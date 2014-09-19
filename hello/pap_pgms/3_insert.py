import pymysql
con = pymysql.connect()
cur = con.cursor()
cur.execute("use test")
cur.execute("insert into stud values(3, 'cccc', 500)")
# saves the transaction
con.commit()  # con.rollback()
cur.close()
con.close()


