#ifndef _MAIN_H_
    #define _MAIN_H_

    #include "..\ASW\TestCase1.h"
    #include "..\CSW\clock.h"
    #include "..\CSW\timer.h"
    #include "..\CSW\hwio.h"
    #include "..\CSW\interrupt.h"

    #include "stdint.h"
    //extern int __main(void);

    typedef enum os_state_type
    {
        os_uninited = 0,
        os_inited,
        os_running,
        os_pause,
        os_shutdown
    }os_state_type;

#endif