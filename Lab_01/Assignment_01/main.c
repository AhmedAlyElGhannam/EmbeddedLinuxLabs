#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp.h"


int main(void)
{
    /* temperature log file name */
    const char *logFileName = "./logs/temp.log"; 

    /* pass log file name to function to extract value and convert it to C */
    process_temperature_log(logFileName);
    
    return 0;
}