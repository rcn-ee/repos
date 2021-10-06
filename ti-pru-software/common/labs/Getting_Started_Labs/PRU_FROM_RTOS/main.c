/*
 *  ======== main.c ========
 */

#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/knl/Task.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/drv/uart/test/src/UART_board.h>
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>
#include <ti/drv/pruss/test/src/test_pruss_intc_mapping.h>


#include "ASM1.h"


// Set parameters to change PRU-ICSS Module [1 on the  AM335X, 1 or 2 on the AM437X or AM572X] and PRU core [0 or 1]
int pruicss_num = 1, pru_core_num = 0;

PRUICSS_Handle PruHandle = NULL;


/*
 *  ======== taskFxn ========
 */
Void taskFxn(UArg a0, UArg a1){
    PRUICSS_Config  *cfg;

    int32_t ret  = PRUICSS_socGetInitCfg(&cfg);
                if (ret  != PRUICSS_RETURN_SUCCESS)
                {
                    return;
                }
    PruHandle = PRUICSS_create(cfg, pruicss_num);


    for(pru_core_num = PRUICCSS_PRU0; pru_core_num <= PRUICCSS_PRU1;pru_core_num++)
    {

        PRUICSS_setPRUBuffer(PruHandle,pru_core_num, (void*)ASM1_image_0, sizeof(ASM1_image_0));
        PRUICSS_pruExecProgram(PruHandle,pru_core_num);
    }
}

/*  ======== main ========
 */
int main(void)
{

        Task_Handle task;
        Error_Block eb;
        Task_Params taskParams;

        //Board_initCfg boardCfg = BOARD_INIT_MODULE_CLOCK;
        //Board_init(boardCfg);



        Error_init(&eb);
        Task_Params_init(&taskParams);
        taskParams.instance->name = (char*)"taskFxn";
        task = Task_create(taskFxn, &taskParams, &eb);
        if (task == NULL) {

                BIOS_exit(0);
        }

        BIOS_start();
        return 0;


}
