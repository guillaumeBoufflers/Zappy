/*
** buffer.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:51:08 2013 antoine knockaert
** Last update Sun Jul 14 18:51:09 2013 antoine knockaert
*/

#include	"buffer.h"
#include	"utils.h"

t_buffer	*create_buffer_list()
{
  int		i;
  t_buffer	*tmp;
  t_buffer	*ini;

  i = 0;
  tmp = NULL;
  while (i < 1000)
    {
      if (tmp == NULL)
	{
	  tmp = malloc(sizeof(t_buffer));
	  ini = tmp;
	  bzero(&tmp->buff, 512);
	}
      else
	{
	  tmp->next = malloc(sizeof(t_buffer));
	  tmp = tmp->next;
	  bzero(&tmp->buff, 512);
	}
      i++;
    }
  tmp->next = ini;
  return (ini);
}

int		stock_in_buff(int fd, t_buffer *list)
{
  int		quit;
  int		size;
  int		i;

  quit = 0;
  i = 0;
  while (!quit)
    {
      bzero(list->buff, 512);
      size = read(fd, list->buff, 512);
      if (size > 0 && list->buff[strlen(list->buff) - 1] == '\n')
	quit = 1;
      if (size == 0 || size == -1 || i >= 1000)
      	return (-1);
      list = list->next;
    }
  return (1);
}

char		*build_buff_command(t_buffer **list)
{
  char		*ret;
  char		*tmp;
  int		quit;

  quit = 0;
  ret = NULL;
  while (!quit)
    {
      if ((*list)->buff && (*list)->buff[strlen((*list)->buff) - 1] == '\n')
	quit = 1;
      if (ret == NULL)
	ret = my_sprintf("%s", (*list)->buff);
      else
	{
	  tmp = ret;
	  ret = my_sprintf("%s%s", ret, (*list)->buff);
	  free(tmp);
	}
      (*list) = (*list)->next;
    }
  if (ret && strlen(ret))
    ret[strlen(ret) - 1] = 0;
  return (ret);
}

int		write_socket(int fd, char *str)
{
  unsigned int	size;
  int		tmp;

  size = 0;
  while (size < strlen(str))
    {
      tmp = write(fd, &str[size], strlen(str) - size);
      if (tmp == 0 || tmp == -1)
	return (-1);
      size += tmp;
    }
  return (0);
}

