const express = require('express');
const bodyParser = require('body-parser');
const twilio = require('twilio');

const app = express();
const PORT = process.env.PORT || 3000;

app.use(bodyParser.json());

app.post('/soil', (req, res) => {
  const soil = req.body;
  console.log('Soil data Received:', soil);
  let sensorValue = soil.moisturePercentage;
  console.log(sensorValue)
  
  // Send SMS
  sendSMS(soil,sensorValue);

  // Process the crash data here
  res.sendStatus(200);
});

app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});

// Function to send SMS
function sendSMS(soil, sensorValue) {
  // Twilio credentials
  const accountSid = 'Your twillio SID';
  const authToken = 'your twillio token';
  const twilioPhoneNumber = 'twillio number'; // Twilio phone number

  const client = new twilio(accountSid, authToken);

  // Initialize messageBody
  let messageBody;

  // Construct the message body based on sensorValue
  if (sensorValue == 1) {
    messageBody = `
      Your motor has been started.
    `;
  } else {
    messageBody = `
      Your motor has been stopped.
    `;
  }

  // Send SMS
  client.messages
    .create({
      body: messageBody,
      from: twilioPhoneNumber,
      to: '+919721859946' // Replace with recipient's phone number
    })
    .then(message => console.log('Message sent:', message.sid))
    .catch(error => console.error('Error sending message:', error));
}
