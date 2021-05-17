var temp = msg.payload;
msg.to = "masque1csf@gmail.com";
msg.from = "anaselgana2001@gmail.com";

var jour = new Date();
var message = "";
if (msg.alarm) // il envoie l'email juste quand msg.alarm = true
{
  msg.payload = "Info: à partir de "+jour+ "votre masque n'est plus utilisable, merci de le changer";
}
/*else
{
  msg.payload = "tout est ok";
}*/
return msg;
