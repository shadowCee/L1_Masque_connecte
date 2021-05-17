var tmp = {};
var CO2 = msg.payload.luminosity_4;
tmp.topic = "information sur masque";
if (CO2 > 5000)
  tmp.payload = "il faut changer de masque";
return tmp;
