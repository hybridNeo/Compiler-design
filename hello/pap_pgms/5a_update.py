# bug fix:
#/usr/local/lib/python3.3/dist-packages/pymysql/cursors.py
#    query = query % escaped_args
#    change to
#    query = query.decode(charset) % escaped_args
  

import sys
import pymysql
print("param style :", pymysql.paramstyle)
# sys.exit()
val = 11
con = pymysql.connect()
cur = con.cursor()
cur.execute("use test")
cur.execute("""update stud set marks = marks + %s""",  val)
print(cur.rowcount)
con.commit()
cur.close()
con.close()


