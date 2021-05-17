var tmp = {}; 
var tvoc = msg.payload.temperature_1;
tmp.topic = "information sur masque";
if (tvoc > 1000)
  tmp.payload = "il faut changer de masque";
return tmp;
