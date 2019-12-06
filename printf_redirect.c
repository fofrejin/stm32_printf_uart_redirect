/*
	In main.h between USER CODE BEGIN Private defines and USER CODE END Private defines add:
	extern UART_HandleTypeDef huartx;
	#define DEBUG_UART &huartx
	where "huartx" is your target UART.
*/

#include "main.h"
#include "printf_redirect.h"

#ifdef ALTERNATIVE_PRINTF
	void printMsg(char * msg, ...){
		char buff[1024];
		va_list args;
		va_start(args, msg);
		vsprintf(buff, msg, args);
		HAL_UART_Transmit(DEBUG_UART, (uint8_t *)buff, strlen(buff), 0xFFFF);
	}

#else

	#ifdef __GNUC__

		#define PYTCHAR_PROTOTYPE int __io_putchar(int ch)
	#else
		#define PYTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

	#endif /* __GNUC__ */

	PYTCHAR_PROTOTYPE {
		HAL_UART_Transmit(DEBUG_UART, (uint8_t *)&ch, 1, 10);
		return ch;
	}

#endif
