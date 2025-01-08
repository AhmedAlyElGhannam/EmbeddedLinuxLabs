#!/bin/bash

# define a var whose default value is 3 and is overwritten if the user added an argument
tempReadingIter=${1:-3}
dataTime=$(date)


upperTempLimit=212
lowerTempLimit=32

echo "########Temperature Readings#######" > temp.log
echo "" >> temp.log

# loop to generate dummy temperature data
for ((iter=0; iter<${tempReadingIter}; iter++))
do
	# command to generate random temperature value
	temp=$(( RANDOM % (${upperTempLimit} - ${lowerTempLimit} + 1) + ${lowerTempLimit}))
	
 	# append date and temp and echo them into temp log file
	echo "$(date), Temperature = ${temp}F" >> temp.log
	
	# leave an empty line	
	echo "" >> temp.log
done


