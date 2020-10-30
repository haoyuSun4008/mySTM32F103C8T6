#ifndef _CAN_H_
#define _CAN_H_
#include "..\std_err.h"
#include "..\std_typ.h"

#define _CAN1_FUNC_ON_               (1)
#define _CAN2_FUNC_ON_               (0)
#define _CAN_INT_RX_FUNC_ON_         (1)
#define _CAN_BAUDRATE_250_ON_        (0)
#define _CAN_BAUDRATE_500_ON_        (1)
#define _CAN_DEBUGE_FUNC_ON_         (1)

#define _CAN_TOTAL_ID_NUM_           (7)
#define _CAN_COM_ID_NUM_             (3)

extern uint32_t CAN_ID_LIST[_CAN_TOTAL_ID_NUM_];

extern uint16_t ADC1_Temperature_sample(void);

#endif
/*EOF*/
