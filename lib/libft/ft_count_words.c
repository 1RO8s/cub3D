/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:29:37 by kamitsui          #+#    #+#             */
/*   Updated: 2023/07/24 20:31:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

size_t	ft_count_words(char *str, char delimiter)
{
	int		word_count;
	bool	in_word;
	int		i;

	word_count = 0;
	in_word = false;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != delimiter && !in_word)
		{
			word_count++;
			in_word = true;
		}
		if (str[i] == delimiter)
			in_word = false;
		i++;
	}
	return (word_count);
}
//
//int main() {
//    char str[] = "This is a sample string, separated by spaces.";
//    char delimiter = ' ';
//
//    int wordCount = ft_count_words(str, delimiter);
//
//    printf("Number of words: %d\n", wordCount); // Output: Number of words: 8
//
//    return 0;
//}
