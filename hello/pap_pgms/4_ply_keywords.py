import ply.lex as lex
tokens = ['ID']
t_ignore = ' \t'
def t_ID(t) :
	r'\w+'
	t.type=  keywords.get(t.value, t.type)
	return t
keywords = { 'if' : 'IF', 'do' : 'DO', 'else' : 'ELSE'} 
tokens.extend(keywords.values())
lexer = lex.lex()
lexer.input('if keyword then do this else something')

for t in lexer :
	print(t.value, t.type)

