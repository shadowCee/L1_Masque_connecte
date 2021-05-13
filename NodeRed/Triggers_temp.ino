var tmp= {};
var temp = msg.payload.temperature_1;
tmp.topic = 'Capteur masque';
if (temp > 20)
tmp.payload = 'trop chaud';
else
tmp.payload = 'temp ok'
return tmp;
