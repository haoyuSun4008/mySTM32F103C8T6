#include "..\MCAL\stm32f10x_tim.h"
#include "interrupt.h"
#include "timer.h"

void Timer4_NVIC_Init(void);
void Timer4_TimeBaseInit(void);

void timer4_init(void)
{
    #if 0
    TIM_TimeBaseInitTypeDef *TimCfgStruct;
    NVIC_InitTypeDef *IRQcfgStruct;
    //set basic param
    TimCfgStruct->TIM_ClockDivision = TIM_CKD_DIV1;
    TimCfgStruct->TIM_CounterMode = TIM_CounterMode_Up;
    TimCfgStruct->TIM_Period = 72-1;
    TimCfgStruct->TIM_Prescaler = 1000-1;
    TimCfgStruct->TIM_RepetitionCounter = 0;
    //set IRQ param
    IRQcfgStruct->NVIC_IRQChannel = TIM4_IRQn;
    IRQcfgStruct->NVIC_IRQChannelPreemptionPriority = 0;
    IRQcfgStruct->NVIC_IRQChannelSubPriority = 3;
    IRQcfgStruct->NVIC_IRQChannelCmd = ENABLE;
    //config clock
    //TIM_InternalClockConfig(TIM4);
    //config TIM4
    TIM_TimeBaseInit(TIM4, TimCfgStruct);
    //clear IRQ flag
    TIM_ClearFlag(TIM4, TIM_FLAG_Update);
    //config TIM4 Update Interrupt
    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
    //config IRQ
    NVIC_Init(IRQcfgStruct);
    //enable TIM4
    TIM_Cmd(TIM4, ENABLE);
    #endif
    #if 0
    NVIC_InitTypeDef* Timer4Type;
    Timer4Type->NVIC_IRQChannel = TIM4_IRQn;
    Timer4Type->NVIC_IRQChannelPreemptionPriority = 0;
    Timer4Type->NVIC_IRQChannelSubPriority = 3;
    Timer4Type->NVIC_IRQChannelCmd = ENABLE;
    #endif
    //========TIM_TimeBaseInit========//
    Timer4_TimeBaseInit();
    //========TIM_ClearFlag========//
    /* Clear the flags */
    TIM4->SR = (uint16_t)~TIM_FLAG_Update;
    //========TIM_ITConfig========//
    /* Enable the Interrupt sources */
    TIM4->DIER |= TIM_IT_Update;
    //========NVIC_Init========//
    Timer4_NVIC_Init();
    //config IRQ
    //========TIM_Cmd========//
    /* Enable the TIM Counter */
    TIM4->CR1 |= TIM_CR1_CEN;
}

/** @defgroup Based on 72Mhz default clock
 *  @brief 1:18ms
 *  @param ms 0~65535
 **/
void delay(uint16_t ms)
{
    uint16_t t;
    ms *= 2;
    for(; ms > 0; ms--)
    {
        t = 0x9C40;//36000;
        while((t--) > 0);
    }
}

#if 1
void Timer4_NVIC_Init(void)
{
    uint32_t tmppriority = 0x00, tmppre = 0x00, tmpsub = 0x0F;
    //CanType1->NVIC_IRQChannel = ENABLE;

    /* Compute the Corresponding IRQ Priority --------------------------------*/    
    tmppriority = (0x700 - ((SCB->AIRCR) & (uint32_t)0x700))>> 0x08;
    tmppre = (0x4 - tmppriority);
    tmpsub = tmpsub >> tmppriority;

    tmppriority = (uint32_t)0 << tmppre;
    tmppriority |=  3 & tmpsub;
    tmppriority = tmppriority << 0x04;

    NVIC->IP[TIM4_IRQn] = tmppriority;

    /* Enable the Selected IRQ Channels --------------------------------------*/
    NVIC->ISER[TIM4_IRQn >> 0x05] =
      (uint32_t)0x01 << (TIM4_IRQn & (uint8_t)0x1F);
}
#endif

void Timer4_TimeBaseInit(void)
{
    uint16_t tmpcr1 = 0;
    tmpcr1 = TIM4->CR1;  

    /* Select the Counter Mode */
    tmpcr1 &= (uint16_t)(~((uint16_t)(TIM_CR1_DIR | TIM_CR1_CMS)));
    tmpcr1 |= (uint32_t)TIM_CounterMode_Up;
    
    /* Set the clock division */
    tmpcr1 &= (uint16_t)(~((uint16_t)TIM_CR1_CKD));
    tmpcr1 |= (uint32_t)TIM_CKD_DIV1;

    TIM4->CR1 = tmpcr1;

    /* Set the Autoreload value */
    TIM4->ARR = 71 ;
    
    /* Set the Prescaler value */
    TIM4->PSC = 999;

    /* Generate an update event to reload the Prescaler and the Repetition counter
       values immediately */
    TIM4->EGR = TIM_PSCReloadMode_Immediate;
}

/**
 * @brief 1ms IRQ
 **/
#include "..\BSW\os.h"
void TIM4_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
        os_tick();
    }
}