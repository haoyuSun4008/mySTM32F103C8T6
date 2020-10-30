#ifndef _USART_H_
#define _USART_H_
#include "..\std_typ.h"

#define _USART1_FUNC_ON_             (0)
#define _USART2_FUNC_ON_             (1)
#define _USART_DEBUG_FUNC_ON_        (1)

typedef union
{
    uint8_t u8dat[8];
    double  s64dat;
} NON_INT_DATA_t;

void Usart_Init(void);
#if (_USART_DEBUG_FUNC_ON_)
void USART_SendAscii(void);
void USART_SendString(char *str);
void USART_SendSine(void);
#endif

#endif
/* EOF */
