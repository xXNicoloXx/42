/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:58:50 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/16 17:46:50 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_info{
    
	char	*nom;
	char	*prenom;
    int		age;
	struct s_info *next; 
}t_info;

t_info *ft_new(t_info liste)
{
	t_info *adresse;
	
	adresse = liste.next;
	while (adresse->next != NULL)
	{
		adresse = adresse->next;
	}
	t_info *new;
	new = (t_info *) malloc(sizeof(t_info));
	new->next = NULL;
	new->nom = NULL;
	new->prenom = NULL;
	new->age = 0;
	adresse->next = new;

	printf("[%p]\n", new);
	return (adresse->next);
}

int main(void)
{
	t_info titou;
	t_info nico;
	t_info *adresse;

	
	titou.nom = "techev";
	titou.prenom = "titou";
	titou.age = 18;
	titou.next = &nico;
	nico.nom = "griv";
	nico.prenom = "nico";
	nico.age = 19;
	titou.next->next = NULL;

	
	printf("Mr %s %s, a l age de %d ;)\n",titou.nom, titou.prenom, titou.age);
	printf("Mr %s %s, a l age de %d ;)\n",titou.next->nom, titou.next->prenom, titou.next->age);
	printf("%p",titou.next->next);
	adresse = ft_new(titou);
	adresse->nom = "Vic"; 
	printf("prenom = %s",adresse->prenom);

	
    return (0);

}