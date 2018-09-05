#ifndef MYHASH_H
# defile MYHASH_H

size_t
	h_djb2(
		char const *val, size_t len);

size_t
	h_djb2_str(
		char const *str);

size_t
	h_djb2a(
		char const *val, size_t len);

size_t
	h_djb2a_str(
		char const *str);

#endif
