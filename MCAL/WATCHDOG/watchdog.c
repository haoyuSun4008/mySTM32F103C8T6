#include "..\FWLib\stm32f10x_wwdg.h"
#include "..\FWLib\stm32f10x_iwdg.h"
#include "watchdog.h"

#define IWDG_ENABLE (1U)
#define WWDG_ENABLE (0U)

/**
  @brief init iwdt 1000ms
  **/
void watchdog_init(void)
{
	//iwdt
	#if (IWDG_ENABLE)

	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(IWDG_Prescaler_4);
	IWDG_SetReload(625);
	IWDG_ReloadCounter();
	IWDG_Enable();

	#endif

	#if (WWDG_ENABLE)

	WWDG_DeInit(void);
	WWDG_SetPrescaler(uint32_t WWDG_Prescaler);
	WWDG_SetWindowValue(uint8_t WindowValue);
	WWDG_EnableIT(void);
	WWDG_SetCounter(uint8_t Counter);
	WWDG_Enable(uint8_t Counter);

	#endif
}

/**
 * @brief feed watchdog
 **/ 
void watchdog_reinit(void)
{
	#if (IWDG_ENABLE)
	IWDG_ReloadCounter();
	#endif
}

// window watch dog func
FlagStatus get_wwdt_pvu_sts(void)
{
	//
	return IWDG_GetFlagStatus(IWDG_FLAG_PVU);
}

FlagStatus get_wwdt_rvu_sts(void)
{
	//
	return IWDG_GetFlagStatus(IWDG_FLAG_RVU);
}

// independent watch dog func
FlagStatus get_iwdt_sts(void)
{
	WWDG_ClearFlag();
	return WWDG_GetFlagStatus();
}
/*EOF*/
