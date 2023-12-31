#include "main.h"

/**
 * cvrt - function
 *
 * @nm : int
 *
 * @be : int
 *
 * @fs : int
 *
 * @prm : struct
 *
 * Return: return
 */

char *cvrt(long int nm, int be, int fs, prm_st *prm)
{
	static char *a;
	static char br[50];
	char sn = 0;
	char *pr;
	unsigned long b = nm;
	(void)prm;

	if (nm < 0 && !(fs & CONVERT_UNSIGNED))
	{
		b = -nm;
		sn = '-';
	}

	a = fs & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pr = &br[49];
	*pr = '\0';

	do {
		*--pr = a[b % be];
		b /= be;
	} while (b != 0);

	if (sn)
		*--pr = sn;
	return (pr);
}



/**
* print_ud - function
*
* @ap : argument
*
* @prm : struct
*
* Return: return
*/

int print_ud(va_list ap, prm_st *prm)
{
	unsigned long a;

	if (prm->l_m)
		a = (unsigned long)va_arg(ap, unsigned long);
	else if (prm->h_m)
		a = (unsigned short int)va_arg(ap, unsigned int);
	else
		a = (unsigned int)va_arg(ap, unsigned long);
	prm->unsn = 1;
	return (print_nbr(cvrt(a, 10, CONVERT_UNSIGNED, prm), prm));
}


/**
 * print_ae - function
 *
 * @ap : argument
 *
 * @prm : struct
 *
 * Return: return
 */

int print_ae(va_list ap, prm_st *prm)
{
	unsigned long int a = va_arg(ap, unsigned long int);
	char *s;

	if (!a)
		return (_puts("(nil)"));
	s = cvrt(a, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, prm);
	*--s = 'X';
	*--s = '0';
	return (print_nbr(s, prm));
}
