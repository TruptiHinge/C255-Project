# include <SPI.h>
# include <Wire.h>
# include <Adafruit_GFX.h>
# include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {
  Serial.begin(115200);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 display"));
    while (1);
  }

  delay(2000); 
  display.setCursor(0, 0);
}


void loop(){

display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(2, SCREEN_HEIGHT/2);
display.println("WOW");


display.drawCircle(65, 17, 5, WHITE); 
display.drawCircle(85, 17, 5, WHITE);
display.drawCircle(75, 45, mouth_radius, WHITE);
display.display();
delay(100);

if (mouth_radius == 15){
    change =- 1;
    delay(500);
  }


else if(mouth_radius == 5){
    change = 1;
    delay (500);
  }

  mouth_radius = mouth_radius + change;
}
