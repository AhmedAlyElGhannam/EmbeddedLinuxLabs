#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp.h"

/* function to convert Fahrenheit to Celsius */
double fahrenheit_to_celsius(long int fahrenheit) 
{
    return ((fahrenheit - 32) * 5.0 / 9.0);
}

/* function to read and process temperature values from the log file */
void process_temperature_log(const char *logFileName) 
{
    FILE *logFile;
    char line[256];

    /* open the log file + pass READ flag */
    logFile = fopen(logFileName, "r");
    if (logFile == NULL) 
    {
        /* if fopen returned NULL => file does not exist or it failed to open */
        perror("Error opening file");
    }
    else /* file opened successfully */
    {
        /* status message */
        printf("Converted Temperature Readings:\n\n");

        /* as long as the file has readable strings */
        while (fgets(line, sizeof(line), logFile) != NULL)
        {
            /* check if the line contains the pattern "Temperature =" */
            char *tempPtr = strstr(line, "Temperature =");
            if (tempPtr != NULL) 
            {
                /* if pattern exists in line => extract Fahrenheit value */
                long int fahrenheit;
                if (sscanf(tempPtr, "Temperature = %dF", &fahrenheit) == 1) 
                {
                    /* convert to Celsius */
                    double celsius = fahrenheit_to_celsius(fahrenheit);
                    /* print converted value */
                    printf("%s -> %.2fC\n", line, celsius);
                }
            }
        }

        /* close log file before exiting function */
        fclose(logFile);
    }
}