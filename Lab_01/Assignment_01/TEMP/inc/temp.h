#ifndef TEMP_H
#define TEMP_H

/* function to convert Fahrenheit to Celsius */
double fahrenheit_to_celsius(long int fahrenheit);

/* function to read and process temperature values from the log file */
void process_temperature_log(const char *logFileName);

#endif