import ply.lex as lex
f = open('test.c')
all = f.read()
f.close()
tokens = ('NAME', 'ID', 'REST')
#literals = '(){};=*,'
def t_NAME(t) :
	r'\#define\s+(\w+)\s+(.+)'
	(name, value) = t.lexer.lexmatch.groups()[1:3]
	mydict[name] = value 

def t_ID(t) :
	r'\w+'
	print(mydict.get(t.value, t.value), end = ' ')

def t_REST(t) :
	r'.'
	print(t.value, end = '')
def t_newline(t) :
	r'\n'
	print()

mydict = { }
lexer = lex.lex()
lexer.input(all)
for t in lexer :
	pass
#print(mydict)

