#!/bin/bash

# define a var whose default value is 3 and is overwritten if the user added an argument
pressureReadingIter=${1:-5}

upperPressureLimit=1013
lowerPressureLimit=500

echo "########Pressure Readings#######" > pressure.log
echo "" >> pressure.log

# loop to generate dummy pressure data
for ((iter=0; iter<${pressureReadingIter}; iter++))
do
	# command to generate random pressure value
	pressure=$(( RANDOM % (${upperPressureLimit} - ${lowerPressureLimit} + 1) + ${lowerPressureLimit}))
	
 	# append date and temp and echo them into pressure log file
	echo "$(date), Pressure = ${pressure}hPa" >> pressure.log
	
	# leave an empty line	
	echo "" >> pressure.log
done


