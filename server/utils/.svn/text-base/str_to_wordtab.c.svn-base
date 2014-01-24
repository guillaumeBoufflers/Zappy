/*
** str_to_wordtab.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:53:38 2013 antoine knockaert
** Last update Sun Jul 14 18:53:39 2013 antoine knockaert
*/

#include		"utils.h"

static int		size_tab(char *s)
{
  char			*tmp;
  int			size;
  char			*token;

  size = 0;
  tmp = strdup(s);
  if (tmp)
    {
      token = strtok(tmp, " ");
      while (token)
	{
	  size++;
	  token = strtok(NULL, " ");
	}
      free(tmp);
      return (size);
    }
  return (0);
}

char			**str_to_wordtab(char *s)
{
  char			*tmp;
  int			i;
  char			*token;
  char			**t;

  i = 0;
  tmp = strdup(s);
  if (tmp)
    {
      t = xmalloc((size_tab(s) + 1) * sizeof(char *));
      if (t)
	{
	  token = strtok(tmp, " ");
	  while (token != NULL)
	    {
	      t[i] = strdup(token);
	      token = strtok(NULL, " ");
	      i++;
	    }
	  free(tmp);
	  t[i] = NULL;
	  return (t);
	}
    }
  return (NULL);
}
