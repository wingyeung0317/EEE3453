# Project: 
> Construct an application using ESP32 micro-controller to include the sensor reading of temperature OR humidity as input, and display its value as output on an LCD display. 
> The application can either be built using simulation software or real circuit. Simulate all the input values (ignore the decimal values) in a program to read Integers from serial monitor input. Also, draft a proposal about how the application is designed (such as circuit and schematics) and can be used in real-life application (for example, smart home technologies, country parks, or any practical examples). Include the circuit and coding in the demonstration (screen capture / photo taking) to the lecturer.

## Project Stage 2 Merged
##### [Wokwi Link]
[https://wokwi.com/projects/384474872821133313](https://wokwi.com/projects/384474872821133313)
##### [Intro]
Construct an application using ESP32 micro-controller to include the sensor reading of temperature OR humidity as input, and display its value as output on an LCD display.
1. Define a new int array of 500 integers to store the data.
2. Convert and store the temperature  and humidity data to the integers array.
3. Display the size of the input data.
4. Display the data nicely
5. Stop capturing the data if the array is full.
6. Find out and display the maximum value and its position (0-indexed) of first occurrence within the input.

![image](https://github.com/wingyeung0317/EEE3453/assets/121206892/479fb2dc-9a0c-4145-a12f-5eac4e420cdf)


---

### Project Stage 2's Application
##### [Workwi Link]
[https://wokwi.com/projects/384427745444685825](https://wokwi.com/projects/384427745444685825) 
##### [Intro]
Construct an application using ESP32 micro-controller to include the sensor reading of temperature OR humidity as input, and display its value as output on an LCD display.

![image](https://github.com/wingyeung0317/EEE3453/assets/121206892/df126c7e-e91c-4f7d-85fa-165a44569c66)


### Project Stage 2's Program
##### [Wokwi Link]
[https://wokwi.com/projects/384446477466744833](https://wokwi.com/projects/384446477466744833)
##### [Intro]
1. Define a new int array of 500 integers to store the input data.
2. Copy and paste a SINGLE column of integer data (assuming those are positive numbers with at most 3 digits) from the ‘Random integer data’ worksheet of the Excel file to the Serial Monitor. These integers are separated by spaces (ASCII code 3210).
3. Convert and store the input integers to the array.
4. Display the size of the input data.
5. Display the data nicely in the Serial Monitor, say, 20 integers on a row.
6. Stop capturing the data if the array is full.
7. Find out and display the maximum value and its position (0-indexed) of first occurrence within the input.
8. The program should be able to accept new input.

![image](https://github.com/wingyeung0317/EEE3453/assets/121206892/8e382602-382f-4843-ac29-f274913e4b02)

##### [TODO]
1. Limit input integers with at most 3 digits
2. Add max number position if there is same max number
