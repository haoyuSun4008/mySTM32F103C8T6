#include "..\FWLib\stm32f10x_adc.h"
#include "adc.h"

#define  TemperatureSensor_Channel      (16U)

/**
 * @brief init ADC1 Temperature Sensor within MCU
 * @param void
 * @retval void
 * */
void ADC1_Temperature_Sample_init(void)
{
    //
    ADC_InitTypeDef tempTyp;

    ADC_StructInit(&tempTyp);
    tempTyp.ADC_Mode               = ADC_Mode_Independent;         // 
    tempTyp.ADC_ScanConvMode       = DISABLE;                      // single channel
    tempTyp.ADC_ContinuousConvMode = DISABLE;                      // single conversion
    tempTyp.ADC_ExternalTrigConv   = ADC_ExternalTrigConv_None;    // trigger by sw
    tempTyp.ADC_DataAlign          = ADC_DataAlign_Right;          // 
    tempTyp.ADC_NbrOfChannel       = 1;                            // channel num
    ADC_Init(ADC1, &tempTyp);

    // Ena internal TempSensor Channel
    ADC_TempSensorVrefintCmd(ENABLE);

    // Ena ADC1 Func
    ADC_Cmd(ADC1, ENABLE);

    // Reset specified ADC1
    ADC_ResetCalibration(ADC1);

    //just wait
    while (ADC_GetResetCalibrationStatus(ADC1));
    
    ADC_StartCalibration(ADC1);

    //just wait
    while (ADC_GetCalibrationStatus(ADC1));
}

/**
 * @brief get a Single ADC Channel Conversion Res
 * @param CH
 * @retval Res
 * */
static uint16_t ADC1_SingleResult_get(uint8_t CH)
{
    //
    ADC_RegularChannelConfig(ADC1,                        // ADC module
                            ADC_Channel_16,               // specify the channel linked to TempSensor interally
                            1,                            // sequence ranked 1
                            ADC_SampleTime_239Cycles5     // specify the sample cycle 239.5
                            );
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);

    // wait the end of conversion EOC
    while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));

    return (ADC_GetConversionValue(ADC1));
}

/**
 * @brief get a Average ADC Channel Conversion Res
 * @param CH
 * @retval Res
 * */
static uint16_t ADC1_AverageResult_get(uint8_t CH, uint8_t TIMES)
{
    //
    uint32_t AdcVal = 0;
    uint16_t i;
    
    for (i = 0; i < TIMES; i++ )
    {
        AdcVal += ADC1_SingleResult_get(CH);
        //delay 5ms least
    }
    return (uint16_t)(AdcVal/TIMES);
}

/**
 * @brief sample the MCU temperature
 * @param void
 * @retval void
 * */
int8_t ADC1_Temperature_sample(void)
{
    //
    uint32_t AdcVal;
    int8_t temp;
    
    AdcVal = ADC1_SingleResult_get(TemperatureSensor_Channel);

    
}