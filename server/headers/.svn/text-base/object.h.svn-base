/*
** object.h for zappt in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/headers
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:44:30 2013 antoine knockaert
** Last update Sun Jul 14 18:44:32 2013 antoine knockaert
*/

#ifndef			OBJECT_H_
# define		OBJECT_H_

typedef enum		e_object_types
{
  FOOD,
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME,
  PLAYER
}			t_object_types;

typedef struct		s_object
{
  t_object_types	type;
}			t_object;

typedef struct		s_object_list
{
  t_object		*item;
  struct s_object_list	*next;
  struct s_object_list	*prev;
}			t_object_list;

t_object		*new_object(t_object_types type);
void			new_object_list(t_object *, t_object_list **);

#endif			/* !OBJECT_H_ */
