var CO2 = msg.payload.luminosity_4;
var pression = msg.payload.analog_in_3;
var hum = msg.payload.relative_humidity_2;
var tvoc = msg.payload.temperature_1;
var payload = msg.payload;
var alarm = context.get ("alarm");
if (typeof alarm = "undefined")
  alarm = "false";

if (hum > 74 && CO2 > 5000 && tvoc > 1000 && !alarm)
{
  alarm = true;
  msg.alarm = 1;
  context.set ("alarm", alarm);
  return msg;
}
if (hum <= 74 && CO2 <= 5000 && tvoc <= 1000 && alarm)
{
  alarm = false;
  msg.alarm = 0;
  context.set ("alarm", alarm);
  return msg;
}
