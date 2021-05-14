#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char	*str;
	int		i;

	if (!(str = malloc(141)))
		return (1);
	i = -1;
	while (++i < 10)
		memcpy(str + (i * 14), "Hello, World!\n", 14);
	str[140] = '\0';
	printf("%s", str);
	return (0x0);
}
