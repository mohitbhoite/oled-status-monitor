#include "application.h"
#include "Adafruit_SSD1306.h"

FuelGauge fuel;


// use hardware SPI
// OLED_D0 -> A3 (SPI CLK)
// OLED_D1 -> A5 (SPI MOSI)
#define OLED_DC     D3
#define OLED_CS     D4
#define OLED_RESET  D5
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);


#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16


#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {     

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  delay(500);
}


void loop() {
    
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  
  //Set time zone to CST
  Time.zone(-5);
  //Format time using : http://strftime.net/
  display.println(Time.format(Time.now(), "%a %b,%e %l:%M%p"));
  display.println("------------------");

  //Battery Voltage
  display.print("BATT VOLTAGE: ");
  display.print( fuel.getVCell() );
  display.println("V");
  
  //Battery State Of Charge
  display.print("SOC: ");
  display.print( fuel.getSoC() );
  display.println("%");
  
  //Signal strength
  CellularSignal sig = Cellular.RSSI();
  display.print("RSSI: ");
  display.print(sig.rssi);
  display.println(" -dB");

  display.display();
  delay(2000);
  display.clearDisplay();

}