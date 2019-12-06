/*
	Add this file to "Src" directory of your project.
	In main.h between USER CODE BEGIN Private defines and USER CODE END Private defines add:
	extern UART_HandleTypeDef huartx;
	#define DEBUG_UART &huartx
	where "huartx" is your target UART(for example huart2).
*/

#include "main.h"

#ifdef __GNUC__

	#define PYTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
	#define PYTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

#endif /* __GNUC__ */

PYTCHAR_PROTOTYPE {
	HAL_UART_Transmit(DEBUG_UART, (uint8_t *)&ch, 1, 0xFFFF);
	return ch;
}
