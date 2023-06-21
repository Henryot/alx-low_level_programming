#include "main.h"

/**
 * jack_bauer - the function prints time and shit
 * Return: there is no return value here bro
 */

void jack_bauer(void)
{
	int hour, minute;

	for (hour = 0; hour < 24; hour++)
	{
		for (minute = 0; minute < 60; minute++)
		{
	    		int hour_tens = hour / 10;
			int hour_ones = hour % 10;
			int minute_tens = minute / 10;
			int minute_ones = minute % 10;


			_putchar('0' + hour_tens);
			_putchar('0' + hour_ones);
			_putchar(':');
			_putchar('0' + minute_tens);
			_putchar('0' + minute_ones);
			_putchar('\n');
		}
	}
}

