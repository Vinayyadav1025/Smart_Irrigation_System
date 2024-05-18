# Smart_Irrigation_System

[Project video link](https://youtu.be/XtPWUWkVXfk?si=JcN2UBrWRrkCJx57)<br/>

# How to setup this project in your local environment<br/>

# Step 1: Download required Softwares<br/>
  i) Download Arduino IDE from [Arduion website](https://www.arduino.cc/en/software)<br/>
  ii) Download node js from [Node js Website](https://nodejs.org/en/download/prebuilt-installer)<br/>
  iii) Download Processing Software from [Processing website](https://processing.org/download)<br/>
  iv) Download ESP8266 library in arduino IDE <br/>
  v) Remember select correct PORT number before uploading code in NodeMCU and Arduino UNO in Step 4 and Step 5.<br>
# Step 2: create account<br/>
  i) create a twillio account on [twillio website](https://www.twilio.com/en-us)<br/>
After creating twillio account you will got twillio SID, Token and mobile number then update these fildes in server.js file<br/>
# Step 3: install required modules in node js <br/>
  i) Express<br/>
  ii) body-parse<br/>
  iii) twillio<br/>
# Step 4: Open arduino IDE<br/>
  i) open soil.ino file update your wifi SSID and password<br/>
  ii) Change your server URL <br/>
    For changing server url Go to command prompt and run as Admistration<br/>
    You will got your local IP<br/>  [like](https://github.com/Vinayyadav1025/Smart_Irrigation_System/blob/main/cmd.png)
    write same ip in place of your IP in soil.ino file<br/>
    iv) Upload this file in NodeMCU and remember correct port should be selected.<br/>
# Step 5: Open Moisture file in Arduino and upload in Arduino UNO<br/>
# Step 6: Open irragation.pde file
  Open irragation.pde in processing Software and select same port as which selected in Arduino Uno port in Arduino IDE<r>
  click on run
# Step 7: Start node.js server
  Go to file director in vscode terminal <br>
  Write command node server.js <br/.
  Server will started on port 3000 By default you can change this port number.<br>
# Step 8: Finally your project is Running 
## If you got any error or any problem you can message me.
# Thank You.
