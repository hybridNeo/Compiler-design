# ply : python lex and yacc
# rules with actions are matched based on the order in the file
# rules without actions : based on length
import ply.lex as lex
f = open('t.txt')
all = f.read()
f.close()
tokens = ('WORD', 'REST')
t_REST = '.'
def t_WORD(t):
	r'trouble\b'
	print(t.lexer.lineno, t.lexer.lexpos - mypos - len(t.value))
def t_newline(t) :
	r'\n'
	global mypos
#	print(dir(t))
#	print("new line")
	t.lexer.lineno += 1
	mypos = t.lexer.lexpos 
t_ignore = ' \t'
mypos = 0
lexer = lex.lex()
lexer.input(all)
for t in lexer:
	pass










