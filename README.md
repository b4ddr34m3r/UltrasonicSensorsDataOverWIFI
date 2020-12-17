# UltrasonicSensorsDataOverWIFI
A code for two ESP8266 ships sharing Ultrasonic sensors data over WIFI.


This project holds two folders, one is for the server that has two Ultrasonic Sensors 
and the second is for client that will receive the data and will handle it. (ESP8266 ships)

You can use this code in the Arduino IDE but you should do the following:
1. Open the Arduino IDE if it is installed, if it is not, Install it first.
2. Go to  File -> Preferences.
3. After the Preferences Dialog opens, copy this URL : 	http://arduino.esp8266.com/stable/package_esp8266com_index.json 
to the "Additional Boards Manager URLs", then click OK under the Dialog.
4. Go to Tools -> Board: "************" -> Boards Manager.
5. After the Boards Manager Dialog opens, type ESP8266 in the text field.
6. Click install to the ESP8266 by ESP8266 Community, then click Close under the dialog.
		
		
After you check that it is all done copy the code and install the required libraries.
