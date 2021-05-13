#define CFG_EU 1

#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>
#include "LowPower.h"
#include <Wire.h>
#include "Adafruit_CCS811.h"
#include "cactus_io_BME280_I2C.h"
#include <SI7021.h>



// Create BME280 object
//BME280_I2C bme; // I2C using address 0x77
// or BME280_I2C bme(0x76); // I2C using address 0x76
BME280_I2C bme(0x76);
Adafruit_CCS811 ccs;
#define debugSerial Serial
#define SHOW_DEBUGINFO
#define debugPrintLn(...) { if (debugSerial) debugSerial.println(__VA_ARGS__); }
#define debugPrint(...) { if (debugSerial) debugSerial.print(__VA_ARGS__); }

SI7021 sensor;


static const u4_t DEVADDR = 0x2604113D;
static const PROGMEM u1_t NWKSKEY[16] = {  0xED, 0x4C, 0x3A, 0xEB, 0xD3, 0xFF, 0x94, 0xE6, 0xD1, 0x1C, 0xD5, 0x5D, 0x7D, 0xA2, 0x9B, 0x38 };
static const u1_t PROGMEM APPSKEY[16] = { 0xA5, 0xEF, 0xE9, 0xF1, 0xFC, 0x1C, 0xF4, 0x14, 0x0A, 0x20, 0xB3, 0xDC, 0x50, 0xA4, 0x61, 0x37 };

void os_getArtEui (u1_t* buf) { }
void os_getDevEui (u1_t* buf) { }
void os_getDevKey (u1_t* buf) { }
static uint8_t mydata[] = "Hello, world!";
static osjob_t sendjob;

static float temp = 0.0;
static float pressure = 0.0;
static float humidity = 0.0;
static float CO2;

const unsigned TX_INTERVAL = 30;
const lmic_pinmap lmic_pins = {
    .nss = 10,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 8,
    .dio = {3, 7, 6},
};
void onEvent (ev_t ev) {
    Serial.print(os_getTime());
    Serial.print(": ");
    switch(ev) {
        case EV_SCAN_TIMEOUT:
            Serial.println(F("EV_SCAN_TIMEOUT"));
            break;
        case EV_BEACON_FOUND:
            Serial.println(F("EV_BEACON_FOUND"));
            break;
        case EV_BEACON_MISSED:
            Serial.println(F("EV_BEACON_MISSED"));
            break;
        case EV_BEACON_TRACKED:
            Serial.println(F("EV_BEACON_TRACKED"));
            break;
        case EV_JOINING:
            Serial.println(F("EV_JOINING"));
            break;
        case EV_JOINED:
            Serial.println(F("EV_JOINED"));
            break;
        case EV_RFU1:
            Serial.println(F("EV_RFU1"));
            break;
        case EV_JOIN_FAILED:
            Serial.println(F("EV_JOIN_FAILED"));
            break;
        case EV_REJOIN_FAILED:
            Serial.println(F("EV_REJOIN_FAILED"));
            break;
        case EV_TXCOMPLETE:
            Serial.println(F("EV_TXCOMPLETE (includes waiting for RX windows)"));
            if (LMIC.txrxFlags & TXRX_ACK)
              Serial.println(F("Received ack"));
            if (LMIC.dataLen) {
              Serial.print(F("Received "));
              Serial.print(LMIC.dataLen);
              Serial.println(F(" bytes of payload"));
              for (int i = 0; i < LMIC.dataLen; i++) {
              if (LMIC.frame[LMIC.dataBeg + i] < 0x10) {
              Serial.print(F("0"));
              }
              Serial.print(LMIC.frame[LMIC.dataBeg + i], HEX);
              }
              Serial.println("");
            }
            
            // Schedule next transmission
            os_setTimedCallback(&sendjob, os_getTime()+sec2osticks(TX_INTERVAL), do_send);
            break;
        case EV_LOST_TSYNC:
            Serial.println(F("EV_LOST_TSYNC"));
            break;
        case EV_RESET:
            Serial.println(F("EV_RESET"));
            break;
        case EV_RXCOMPLETE:
            // data received in ping slot
            Serial.println(F("EV_RXCOMPLETE"));
            break;
        case EV_LINK_DEAD:
            Serial.println(F("EV_LINK_DEAD"));
            break;
        case EV_LINK_ALIVE:
            Serial.println(F("EV_LINK_ALIVE"));
            break;
         default:
            Serial.println(F("Unknown event"));
            break;
    }
}
void loop() {
os_runloop_once();
bme.readSensor();
//zsxghhuyjtrhttghujiijhugyftghj,njnsfvkjnfsjvnfjbgrgnhrignerjgnerkjgnetgne
Serial.print("pression: ");
Serial.print(bme.getPressure_MB()); Serial.print(" mb\t"); // Pressure in millibars
Serial.print("humidité: ");
Serial.print(bme.getHumidity()); Serial.print(" %\t\t");
Serial.print("température en °C: ");
Serial.print(bme.getTemperature_C()); Serial.print(" *C\t");
Serial.print("température en °F: ");
Serial.print(bme.getTemperature_F()); Serial.println(" *F");
if(ccs.available()){
    if(!ccs.readData()){
      Serial.print("CO2: ");
      Serial.print(ccs.geteCO2());
      Serial.print("ppm, TVOC: ");
      Serial.println(ccs.getTVOC());
    }
    else{
      Serial.println("ERROR!");
      while(1);
    }
  }

 //Add a 2 second delay.
delay(2000); //just here to slow down the output.
} 
//urfhbxdxfcgvhbjnklkjbhgvcgfdxdsqswdgdxfcfgvhbnjk,lkn;jbh,gncf
void updateEnvParameters()
{

       int p=bme.getPressure_MB();
       temp = 20.0;
       int temperature = bme.getTemperature_C();
       temp = temperature / 100;
       humidity = bme.getHumidity();
       int TVOC = ccs.getTVOC();
       CO2 = ccs.geteCO2(); // readVCC returns in tens of mVolt 
          
     
}
void do_send(osjob_t* j){
    // Check if there is not a current TX/RX job running
    if (LMIC.opmode & OP_TXRXPEND) {
        Serial.println(F("OP_TXRXPEND, not sending"));
    } else {

        
       int p=bme.getPressure_MB();
       temp = 20.0;
       int t = bme.getTemperature_C();
       int h = bme.getHumidity();
       int bat = ccs.getTVOC();
       int l = ccs.geteCO2();
        // per inviare i dati a node
            unsigned char mydata[19];
            mydata[0] = 0x1; // CH1
            mydata[1] = 0x67; // Temp
            mydata[2] = bat >> 8;
            mydata[3] = bat*10 & 0xFF;
            mydata[4] = 0x2; // CH2
            mydata[5] = 0x68; // Humidity ok
            mydata[6] = h*2 & 0xFF;
            mydata[7] = 0x3; // CH3
            mydata[8] = 0x2; // Analog output
            mydata[9] = p >> 8;
            mydata[10] = p & 0xFF;
            mydata[11] = 0x4; // CH4
            mydata[12] = 0x65; // Luminosity ok
            mydata[13] =  l >> 8;
            mydata[14] = l & 0xFF;
            mydata[15] = 0x5; //CH5
            mydata[16] = 0x65; 
            mydata[17] =  t >> 8;
            mydata[18] = t & 0xFF;
            
            
            LMIC_setTxData2(1, mydata, sizeof(mydata), 0);
            #ifdef SHOW_DEBUGINFO
            debugPrintLn(F("PQ")); //Packet queued
            Serial.println(F("Packet queued"));
            #endif
    }
    // Next TX is scheduled after TX_COMPLETE event.
}

void setup() {

Serial.begin(9600);
Serial.println("Bosch BME280 Pressure - Humidity - Temp Sensor | cactus.io");
Serial.println("CCS811 test");
    os_init();
    LMIC_reset();
LMIC_setClockError(MAX_CLOCK_ERROR * 10 / 100);

    // Set static session parameters. Instead of dynamically establishing a session
    // by joining the network, precomputed session parameters are be provided.
    #ifdef PROGMEM
    // On AVR, these values are stored in flash and only copied to RAM
    // once. Copy them to a temporary buffer here, LMIC_setSession will
    // copy them into a buffer of its own again.
    uint8_t appskey[sizeof(APPSKEY)];
    uint8_t nwkskey[sizeof(NWKSKEY)];
    memcpy_P(appskey, APPSKEY, sizeof(APPSKEY));
    memcpy_P(nwkskey, NWKSKEY, sizeof(NWKSKEY));
    LMIC_setSession (0x1, DEVADDR, nwkskey, appskey);
    #else
    // If not running an AVR with PROGMEM, just use the arrays directly
    LMIC_setSession (0x1, DEVADDR, NWKSKEY, APPSKEY);
    #endif

    #if defined(CFG_EU)
    // Set up the 8 channels used    
    LMIC_setupChannel(0, 868100000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(1, 868300000, DR_RANGE_MAP(DR_SF12, DR_SF7B), BAND_CENTI);      // g-band
    LMIC_setupChannel(2, 868500000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(3, 867100000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(4, 867300000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(5, 867500000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(6, 867700000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(7, 867900000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(8, 868800000, DR_RANGE_MAP(DR_FSK,  DR_FSK),  BAND_MILLI);      // g2-band
    
    #elif defined(CFG_VN)
    // Set up the 8 channels used    
    LMIC_setupChannel(0, 921400000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(1, 921600000, DR_RANGE_MAP(DR_SF12, DR_SF7B), BAND_CENTI);      // g-band
    LMIC_setupChannel(2, 921800000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(3, 922000000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(4, 922200000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(5, 922400000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(6, 922600000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(7, 922800000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(8, 922700000, DR_RANGE_MAP(DR_FSK,  DR_FSK),  BAND_MILLI);      // g2-band    
    #endif

    // Disable link check validation
    LMIC_setLinkCheckMode(0);

    // TTN uses SF9 for its RX2 window.
    LMIC.dn2Dr = DR_SF9;

    // Set data rate and transmit power for uplink (note: txpow seems to be ignored by the library)
    LMIC_setDrTxpow(DR_SF9,20);

    // Start job
    do_send(&sendjob);

if(!ccs.begin()){
    Serial.println("Failed to start sensor ccs! Please check your wiring.");
    while(1);
  }
if (!bme.begin()) {
Serial.println("Could not find a valid BME280 sensor, check wiring!");
while (1);
}

bme.setTempCal(-1);// Temp was reading high so subtract 1 degree

Serial.println("Pressure\tHumdity\t\tTemp\ttTemp");
}
