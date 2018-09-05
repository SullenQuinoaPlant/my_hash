#include "inner.h"

#define SEED 5381

size_t
	h_djb2(
		char const *val, size_t len)
{
	size_t				hash;
	unsigned char const	*p;

	hash = SEED;
	p = (unsigned char*)val;
	while (len--)
		hash = (hash << 5) + hash + *p++;
	return (hash);
}

size_t
	h_djb2_str(
		char const *str)
{
	size_t				hash;
	unsigned char const *p;
	unsigned char		c;

	p = (unsigned char const*)str;
	hash = SEED;
	while ((c = *p++))
		hash = (hash << 5) + hash + c;
	return (hash);
}
