/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:04:41 by ngonzo            #+#    #+#             */
/*   Updated: 2020/11/01 19:05:03 by ngonzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

# define buffer_size 100

ssize_t			ft_write(int fd, const void *buf, int len);
ssize_t			ft_read(int fd, void *buf, int len);
unsigned long	ft_strlen(const char *str);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *str1, const char *str2);
char			*ft_strdup(const char *str);

int		main(void)
{
	printf("\n    //--Starting tests--\\\\\n");

	// ft_strlen ---------------------------------------
	printf("\n  --ft_strlen vs strlen:\n");// 1 //
	char	str_len[] = "String for testing ft_strlen!";// <-
	printf(" -line - %s:\n", str_len);
	printf("ft_strlen |%lu|\n",ft_strlen(str_len));
	printf("___strlen |%lu|\n",strlen(str_len));
	printf(" -empty line:\n");// 2 //
	char	str_len_empty[] = "";// <-
	printf("ft_strlen |%lu|\n",ft_strlen(str_len_empty));
	printf("___strlen |%lu|\n",strlen(str_len_empty));
	printf(" -very long line:\n");// 3 //
	char	str_very_long[] = "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
	printf("ft_strlen |%lu|\n",ft_strlen(str_very_long));
	printf("___strlen |%lu|\n",strlen(str_very_long));
	// printf("ft_strlen -|%lu|\n",ft_strlen(NULL));
	// printf("___strlen -|%lu|\n",strlen(NULL));

	// ft_strcpy ---------------------------------------
	printf("\n  --ft_strcpy vs strcpy:\n");// 1 //
	char	str_cpy[] = "Test of strcpy! Bu-bu-bu! 111";// <-
	char	ft_cpy[buffer_size];
	char	cpy[buffer_size];
	bzero(ft_cpy, buffer_size);
	bzero(cpy, buffer_size);
	ft_strcpy(ft_cpy, str_cpy);
	strcpy(cpy, str_cpy);
	printf("ft_strcpy -|%s|\n",ft_cpy);
	printf("___strcpy -|%s|\n",cpy);
	printf(" -empty line:\n");// 2 //
	char	str_cpy_empty[] = "";// <-
	bzero(ft_cpy, buffer_size);
	bzero(cpy, buffer_size);
	ft_strcpy(ft_cpy, str_cpy_empty);
	strcpy(cpy, str_cpy_empty);
	printf("ft_strcpy |%s|\n",ft_cpy);
	printf("___strcpy |%s|\n",cpy);
	printf(" -very long line:\n");// 3 //
	char	ft_cpy_very_long[300];
	char	cpy_very_long[300];
	bzero(ft_cpy_very_long, 300);
	bzero(cpy_very_long, 300);
	ft_strcpy(ft_cpy_very_long, str_cpy_empty);
	strcpy(cpy_very_long, str_cpy_empty);
	printf("ft_strcpy |%s|\n",str_very_long);
	printf("___strcpy |%s|\n",str_very_long);
	// printf("ft_strcpy -|%s|\n",ft_strcpy(ft_cpy, NULL));
	// printf("___strcpy -|%s|\n",strcpy(cpy, NULL));


	// ft_strcmp ---------------------------------------
	printf("\n  --ft_strcmp vs strcmp:\n");

	printf(" -Hello_world / Hello_world:\n");// 1 //
	char	str_cmp[] = "Hello_world";// <-
	printf("ft_strcmp: %d\n___strcmp: %d\n",
	ft_strcmp(str_cmp, str_cmp) ,
	strcmp(str_cmp, str_cmp));

	printf(" -Hello_world1 / Hello_world2:\n");// 2 //
	char	str_cmp1[] = "Hello_world1";// <-
	char	str_cmp2[] = "Hello_world2";// <-
	printf("ft_strcmp: %d\n___strcmp: %d\n",
	ft_strcmp(str_cmp1, str_cmp2) ,
	strcmp(str_cmp1, str_cmp2));

	printf(" -Hello_world2 / Hello_world1:\n");// 3 //
	printf("ft_strcmp: %d\n___strcmp: %d\n",
	ft_strcmp(str_cmp2, str_cmp1) ,
	strcmp(str_cmp2, str_cmp1));

	printf(" -Hello / Hello_world:\n");// 4 //
	printf("ft_strcmp: %d\n___strcmp: %d\n",
	ft_strcmp("Hello", "Hello_world") ,
	strcmp("Hello", "Hello_world"));

	printf(" -Hello_world / Hello:\n");// 5 //
	printf("ft_strcmp: %d\n___strcmp: %d\n",
	ft_strcmp("Hello_world", "Hello") ,
	strcmp("Hello_world", "Hello"));

	printf(" -two empty strings:\n");// 6 //
	printf("ft_strcmp: %d\n___strcmp: %d\n",
	ft_strcmp("", "") ,strcmp("", ""));

	printf(" -one empty string as first argument:\n");// 7 //
	printf("ft_strcmp: %d\n___strcmp: %d\n",
	ft_strcmp("Hello", "") ,strcmp("Hello", ""));

	printf(" -one empty string as second argument:\n");// 8 //
	printf("ft_strcmp: %d\n___strcmp: %d\n",
	ft_strcmp("", "Hello") ,strcmp("", "Hello"));

	// ft_write ----------------------------------------
	printf("\n  --ft_write vs write:\n");// 1 //
	char	ft_wr[] = "ft_write |ABC_! @_@ O^O|\n";// <-
	char	wr[] = "___write |ABC_! @_@ O^O|\n";// <-
	ft_write(1, &ft_wr, ft_strlen(ft_wr));
	write(1, &wr, strlen(wr));
	printf(" -test empty line:\n");// 2 //
	char	wr_empty[] = "";// <-
	printf("ft_write |%zi|\n",ft_write(1, &wr_empty, ft_strlen(wr_empty)));
	printf("___write |%zi|\n",write(1, &wr_empty, strlen(wr_empty)));
	printf(" -test error/NULL:\n");// 3 //
	errno = 0;
	printf("ft_write |%zi| ",ft_write(1, NULL, 1));
	printf("(errno: %d - %s)\n", errno, strerror(errno));
	errno = 0;
	printf("___write |%zi| ",write(1, NULL, 1));
	printf("(errno: %d - %s)\n", errno, strerror(errno));
	printf(" -test error/wrong file descriptor:\n");// 4 //
	errno = 0;
	printf("ft_write |%zi| ",ft_write(999, ft_wr, 1));
	printf("(errno: %d - %s)\n", errno, strerror(errno));
	errno = 0;
	printf("___write |%zi| ",write(999, wr, 1));
	printf("(errno: %d - %s)\n", errno, strerror(errno));
	printf("\n -open file descriptor:\n");// 5 //
	int		fdw = open("./_test.txt", O_RDWR|O_APPEND|O_CREAT,S_IWRITE|S_IREAD);
	char	ft_wr1[] = "TEST no-no-no ft_write 1\n";// <-
	char	wr1[] = "TEST yes-yes-yes write 2\n";// <-
	ft_write(fdw, ft_wr1, ft_strlen(ft_wr1));
	write(fdw, wr1, strlen(wr1));

	// ft_read -----------------------------------------
	printf("\n  --ft_read vs read:\n");// 1 //
	printf(" -read from input:\n");
	char	str_read[buffer_size];
	bzero(str_read, buffer_size);
	printf("- input symbols for testing ft_read\n");
	printf("- input symbols for testing read\n");
	printf("ft_read |%zd|\n",ft_read(0, &str_read, buffer_size));
	printf("___read |%zd|\n",read(0, &str_read, buffer_size));
	printf(" -read from file \"main.c\":\n");// 2 //
	int		ft_fd = open("./main.c", O_RDONLY);
	int		fd = open("./main.c", O_RDONLY);
	char	str_read_fd[10000];
	printf("ft_read |%zd|\n",ft_read(ft_fd, &str_read_fd, 10000));
	printf("___read |%zd|\n",read(fd, &str_read_fd, 10000));
	printf(" -test error/wrong file descriptor:\n");// 3 //
	bzero(str_read, buffer_size);
	errno = 0;
	printf("ft_read |%zd| ",ft_read(999, &str_read, buffer_size));
	printf("(errno: %d - %s)\n", errno, strerror(errno));
	errno = 0;
	printf("___read |%zd| ",read(999, &str_read, buffer_size));
	printf("(errno: %d - %s)\n", errno, strerror(errno));

	// ft_strdup ---------------------------------------
	printf("\n  --ft_strdup vs strdup:\n");// 1 //
	char	str_dup[] = "Test of strdup! Ora-ora-ora! 333";// <-
	char	*ft_dup;
	char	*dup;
	ft_dup = ft_strdup(str_dup);
	dup = strdup(str_dup);
	printf("ft_strdup -|%s|\n",ft_dup);
	printf("___strdup -|%s|\n",dup);
	printf(" -empty line:\n");// 2 //
	printf("ft_strdup -|%s|\n",ft_strdup(""));
	printf("___strdup -|%s|\n",strdup(""));
	printf(" -very long string :\n");// 3 //
	printf("ft_strdup -|%s|\n",ft_strdup(str_very_long));
	printf("___strdup -|%s|\n",strdup(str_very_long));
	// printf("ft_strdup -|%s|\n",ft_strdup(NULL));
	// printf("___strdup -|%s|\n",strdup(NULL));

	printf("\n    \\\\--Tests completed--//\n");

	return (0);
}

