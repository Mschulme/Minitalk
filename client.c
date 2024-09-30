/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:41:05 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/09 16:38:29 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	long	res;

	res = 0;
	while (((*str == ' ' || (*str >= 9 && *str <= 13)) == 1) && *str)
		str++;
	if (*str == '-' || *str == '0')
		res = -1;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if (*str != 0 || res < 0)
	{
		write(2, "Enter input as: ./client PID 'Message'\n", 39);
		exit (1);
	}
	return (res);
}

void	stringtobinary(char ch, int recv_pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if ((ch & (0x01 << j++)) > 0)
			kill(recv_pid, SIGUSR1);
		else
			kill(recv_pid, SIGUSR2);
		usleep(150);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	recv_pid;

	if (argc == 3)
	{
		recv_pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i] != 0)
			stringtobinary(argv[2][i++], recv_pid);
		return (0);
	}
	else
		write(2, "Enter input as: ./client PID 'Message'\n", 39);
	return (1);
}

/*
'We present an algorithm that computes the product of two n-bit
integers in O(nlog n) bit operations, thus confirming a conjecture of Schonhage
and Strassen from 1971. Our complexity analysis takes place in the multitape
Turing machine model, with integers encoded in the usual binary representa-
tion. Central to the new algorithm is a novel “Gaussian resampling” technique
that enables us to reduce the integer multiplication problem to a collection of
multidimensional discrete Fourier transforms over the complex numbers, whose
dimensions are all powers of two. These transforms may then be evaluated
rapidly by means of Nussbaumer’s fast polynomial transforms.'
*/
