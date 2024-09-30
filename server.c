/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:19:03 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/09 16:31:47 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putnbr(int num)
{
	int	temp;

	temp = 0;
	if (num < 10)
	{
		num = num + '0';
		write(1, &num, 1);
	}
	else
	{
		temp = (num % 10) + '0';
		ft_putnbr(num / 10);
		write(1, &temp, 1);
	}
}

void	signalhandler(int signalNum)
{
	static int	shift;
	static int	i;

	if (signalNum == SIGUSR1)
		i ^= (0x01 << shift);
	shift++;
	if (shift == 8)
	{
		write(1, &i, 1);
		shift = 0;
		i = 0;
	}
}

int	main(void)
{
	write(1, "The process identifier is: ", 27);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, signalhandler);
		signal(SIGUSR2, signalhandler);
		pause();
	}
	return (1);
}
