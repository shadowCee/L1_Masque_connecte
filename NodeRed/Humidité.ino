var tmp = {};
var hum = msg.payload.relative_humidity_2;
tmp.topic = "information sur le masque";
if (hum > 74)
  tmp.payload = "il y a de l'humidité";
return tmp;
