/*
 * printf_redirect.h
 *
 */

#ifndef INC_PRINTF_REDIRECT_H_
#define INC_PRINTF_REDIRECT_H_

#define ALTERNATIVE_PRINTF //You can use printMsg() alternative to printf(). Using is the same.

#ifdef ALTERNATIVE_PRINTF
	#include <stdio.h>
	#include <string.h>
	#include <stdarg.h>

	void printMsg(char * msg, ...);

#endif


#endif /* INC_PRINTF_REDIRECT_H_ */
