var tmp = {};
var pression = msg.payload.analog_in_3;
tmp.topic = "information sur le masque";
if (pression > 10)
  tmp.payload = "il faut changer de masque";
return tmp;
