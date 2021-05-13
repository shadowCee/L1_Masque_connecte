var tmp= {};
var hum = msg.payload.humidity_2;
tmp.topic = 'Humidité masque';
if (hum > 70)
tmp.payload= 'trop humide';
else
tmp.payload = 'hum ok'
return tmp;
