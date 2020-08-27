#include ".\RBM_CODE\RBM.h"
#include "pid_model.h"

/**
 * @brief RBM Initilize
 * */
void pid_model_initilize(void)
{
    RBM_initialize();
}

/**
 * @brief RBM Func
 * */
void pid_model_proc(void)
{
    RBM_step();
}