# installation
# sudo easy_install pymysql3

# con.autocommit_mode
# con.autocommit(True)
# help(con.cursor)
# help(con.cursor())

import sys
import pymysql
con = pymysql.connect()
cur = con.cursor()
cur.execute("use test")
# shows the error thrown by the database
#cur.execute("insert into stud values(3, 500)")
#sys.exit()
try:
	cur.execute("insert into stud values(3, 500)")
except Exception as e:
	print(e)
finally:
	cur.close()
con.close()


