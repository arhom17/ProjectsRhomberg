# 955KirkwoodEnergy

Take-home Final Exam for BAN 330  
Due: December 12, 2019

## The data

The data in the `raw_data` folder is the electricity usage of my house.  In the `Enphase` folder are datafiles reported by the monitoring system that works with our solar panels.  In the `Alliant` folder are datafiles from Alliant Energy, the electric utility for Dubuque. It is divided into two folders: `ToAlliant`, the data on how much Alliant recieved from our house and `FromAlliant`, the data on how much our house recieved from Alliant.  All data is from these folders is given in 15 minute intervals. 

The Excel file contains the amount of usage as determined by monthly bills from the utility.  The Solar Production column is the value reported by the solar monitoring for the same time-period.  Columns of ones and zeros are boolean values for the presence of the device in the header of that column.

## The task

Answer the following questions:

 1. What does energy usage in our house look like?  What are the seasonal patterns?  What are the daily patterns? (XC) How do they correspond to weather?
 
 2. We switched from a natural gas water heater to an electric heat pump water heater.  Estimate the impact of that switch on natural gas and electric usages.
 
 3. How is the electricity usage reported by Alliant related to the electricity usage recorded by the Enphase device in our house?
 
 4. Are the values in our bills consistent with the usage collected by Alliant?

 5. Was going to Time of Day Pricing a good decision?  

For information on how time-of-day pricing works visit (https://www.alliantenergy.com/WaysToSave/SavingsTipsandPrograms/TimeofDayPricingIOWARES/TimeofDayRates).

One thing I forgot to mention is the cash-out date is Apr. 23 for our house.  On this date, any excess credit on our account is split in half, with half of its value going to us and half to Alliant's Hometown Care Energy Fund.  The value of the credit is 3.1506¢ per kWh.


## The rules

Ask Rissler lots of questions.  This is about his house. Do not talk about details of implementation with other students.  You may discuss what you have done in prior assignments, but not what you are doing in this assignment.

Assignments should be uploaded as an Rmd that compiles and the resulting html or pdf.  I have started an Rmd as an example on how to read in all the files in a directory.






