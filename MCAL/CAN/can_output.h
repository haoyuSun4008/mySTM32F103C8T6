#ifndef _CAN_OUTPUT_H_
#define _CAN_OUTPUT_H_

#include "..\std_err.h"
#include "..\std_typ.h"

void CAN_init(void);
void ccp_send(uint32_t id, uint8_t *dat, uint8_t dlc);
void com_send(uint32_t id, uint8_t *dat, uint8_t dlc);

#endif
/*EOF*/
