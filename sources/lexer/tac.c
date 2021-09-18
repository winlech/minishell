#include "minishell.h"

void	tac_compile(char *src, t_list *lst)
{
	t_lexer	*lexer;
	t_token	*token ;
	t_list	*lst_tk;

	lexer = init_lexer(src);
	token = lexer_next_token(lexer);
	if (token->type == TOKEN_EOF)
	{
		free(lst);
		lst = NULL;
		return ;
	}
	while (token->type != TOKEN_EOF)
	{
		lst_tk = ft_lstnew(token);
		ft_lstadd_back(&lst, lst_tk);
		token = lexer_next_token(lexer);
	}
}
