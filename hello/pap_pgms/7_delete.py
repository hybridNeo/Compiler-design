import pymysql
val = 2
con = pymysql.connect()
print(pymysql.paramstyle)
cur = con.cursor()
cur.execute("use test")
cur.execute("""delete from stud where id > %s""",  val)
print(cur.rowcount)
con.commit()
cur.close()
con.close()


# correction in cursor.py
# in execute function
# query = query.decode(charset) % escaped_args
