/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djb2a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:43:29 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 08:44:03 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

#define SEED 5381

size_t
	h_djb2a(
		char const *val, size_t len)
{
	size_t				hash;
	unsigned char const	*p;

	hash = SEED;
	p = (unsigned char const*)val;
	while (len--)
		hash = ((hash << 5) + hash) ^ *p++;
	return (hash);
}

size_t
	h_djb2_str(
		char const *str)
{
	size_t				hash;
	unsigned char const	*p;
	unsigned char		c;

	p = (unsigned char const*)str;
	hash = SEED;
	while ((c = *(unsigned char*)p++))
		hash = ((hash << 5) + hash) ^ c;
	return (hash);
}
