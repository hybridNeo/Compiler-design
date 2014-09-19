import ply.lex as lex
tokens = ( 'ID', )
identifier = r'[A-za-z]\w*'
#builtin decorator (is a fn call) which in turn assigns the
# identifier to fnname.__doc__
@lex.TOKEN(identifier)
def t_ID(t) :
	print(t)
	return t
lexer = lex.lex()
lexer.input('test123')
t = lexer.token()

# not covered:
#	state
#	error handling
#	tokens with lots of state info




