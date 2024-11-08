#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <string.h>

char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

#endif
