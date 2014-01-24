/*
** voir.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/ia
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:34:37 2013 antoine knockaert
** Last update Sun Jul 14 18:34:37 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

void			see(t_server *serv, t_client *cl,
			    char *cmd, char **command)
{
  int			i;
  char			*str;
  char			*tmp;

  i = 0;
  str = NULL;
  (void) cmd;
  if (command[1])
    add_client_response(&cl, "sbp\n");
  else
    {
      while (i <= cl->level)
	{
	  tmp = str;
	  str = my_sprintf("%s%s", (str) ? (str) : (""),
			   content_level(cl, i, serv));
	  if (tmp)
	    free(tmp);
	  i++;
	}
      str[strlen(str) - 1] = 0;
      str = my_sprintf("{%s}\n", str);
      add_client_response(&cl, str);
    }
}
