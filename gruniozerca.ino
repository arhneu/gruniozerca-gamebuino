//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
#include <EEPROM.h>
//imports the Gamebuino library
#include <Gamebuino.h>
//creates a Gamebuino object named gb
Gamebuino gb;
extern const byte arhn3x5[];
   
//define Grunio sprite
  const unsigned char PROGMEM grunioa[] = {
    8, 8,
    0b01111110,
    0b10000001,
    0b10000101,
    0b10000001,
    0b10000001,
    0b01111110,
    0b01000100,
    0b01100110,
  };


  //Grunio walking
  const unsigned char PROGMEM gruniob[] = {
    8, 8,
    0b01111110,
    0b10000001,
    0b10000101,
    0b10000001,
    0b10000001,
    0b01111110,
    0b00100010,
    0b00110011,
  };

  //grunio black
  const unsigned char PROGMEM grunioc[] = {
    8, 8,
    0b01111110,
    0b11111111,
    0b11111011,
    0b11111111,
    0b11111111,
    0b01111110,
    0b01000100,
    0b01100110,
  };

  //grunio black walking
  const unsigned char PROGMEM gruniod[] = {
    8, 8,
    0b01111110,
    0b11111111,
    0b11111011,
    0b11111111,
    0b11111111,
    0b01111110,
    0b00100010,
    0b00110011,
  };

  //Gruniozerca-logo
  const byte logo[] PROGMEM = {64,36,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x7,0x0,0x0,0x0,
0x1F,0x7D,0xBF,0xFF,0xFD,0xFF,0xDF,0x38,
0x31,0xC7,0xE9,0x16,0x37,0x44,0x31,0xEC,
0x20,0x92,0x49,0xB4,0x10,0x45,0x24,0x84,
0x60,0x92,0x49,0xA4,0x94,0xD5,0x24,0x92,
0x47,0xC6,0x48,0xA4,0x95,0xDC,0x67,0x92,
0x44,0x4C,0x4A,0xA4,0x9D,0xC4,0xC4,0x82,
0x67,0x4C,0xA,0x24,0x99,0x5C,0xC4,0x82,
0x20,0x46,0xA,0x24,0x93,0x54,0x64,0x92,
0x20,0x53,0x1B,0x24,0x10,0x45,0x30,0x92,
0x30,0xD9,0xB1,0x26,0x30,0x45,0x93,0x92,
0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFE,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x1,0xFF,0x0,0x0,0x0,
0x0,0x0,0x0,0xF,0x0,0x80,0x0,0x0,
0x0,0x0,0x0,0x18,0x0,0x40,0x0,0x0,
0x0,0x0,0x0,0x70,0x0,0xA0,0x0,0x0,
0x0,0x0,0x1,0xC0,0xF0,0xB0,0x0,0x0,
0x0,0x0,0x3,0x0,0xD,0x18,0x0,0x0,
0x0,0x0,0xE,0x0,0x4,0x8,0x0,0x0,
0x0,0x0,0x18,0x0,0x1,0x8,0x0,0x0,
0x0,0x0,0x30,0x0,0x1,0x8,0x0,0x0,
0x0,0x0,0x67,0x0,0x1,0x8C,0x0,0x0,
0x0,0x0,0xCF,0x80,0x1,0xCE,0x0,0x0,
0x0,0x1,0x89,0x80,0x3,0x63,0x0,0x0,
0x0,0x1,0x1B,0x80,0x7,0x31,0x0,0x0,
0x0,0x3,0x1F,0x80,0xE,0xA9,0x80,0x0,
0x0,0x6,0xF,0x80,0x3A,0xA0,0x80,0x0,
0x0,0xC,0x7,0x0,0x1,0xE0,0xC0,0x0,
0x0,0x38,0x0,0x0,0x0,0x0,0x40,0x0,
0x0,0xE0,0x0,0x0,0x0,0x0,0x40,0x0,
0x0,0x86,0x0,0x0,0x0,0x0,0x40,0x0,
0x1,0x8F,0x0,0x0,0x0,0x0,0x40,0x0,
0x1,0x19,0x80,0x0,0x0,0x0,0x40,0x0,
};

const byte burger[] PROGMEM = {8,8,0x3C,0x52,0xA5,0x81,0xFF,0xFF,0x81,0x7E,};
const byte burgerb[] PROGMEM = {8,8,0x3C,0x6E,0xDB,0xFF,0x81,0x81,0xFF,0x7E,};

//default options
    int score = 0;
    int lives = 3;
    int posx = 35;
    int posy = 30;
    int carrots = 0;
    int gcolor = 0;
    int cposx;
    int alive = 1;
    int start = 1;
    char16_t flip = NOFLIP;
    int cposy;
    int option = 0;
    int acc = 0;
    int color = 0;
    //read saved topscore
    int topscore = EEPROM.read(0);
    String konami = "1234567890123456";
    int burgerek = 0;

// the setup routine runs once when Gamebuino starts up
void setup(){
  // initialize the Gamebuino object
  gb.begin();
  gb.display.setFont(arhn3x5);
  //display the main menu:
  gb.titleScreen(F(""), logo);
  //Randomize carrots
  gb.pickRandomSeed();
}

// the loop routine runs over and over again forever
void loop(){

   //updates the gamebuino (the display, the sound, the auto backlight... everything)
  //returns true when it's time to render a new frame (20 times/second) 
  if(gb.update()){
    //Draw Main Menu
    if(start == 1){

      if(gb.buttons.pressed(BTN_B)){
         //konami code
         if(konami == "upupdndnlfrtlfrt"){
          burgerek = 1;
          gb.popup(F("BURGER Mode!"), 20);
         }
      }
      
       if(gb.buttons.pressed(BTN_A)){
          //Credits
           if(option == 1) start = 2;
          //Rules
           if(option == 2) start = 3;
          //Quit
           if(option == 3) gb.changeGame();
          //Game start
           if(option == 0){ start = 0;
           gb.popup(F("Ruszaj, Grunio!"), 20);
           }
       }
           gb.display.println("Wybierz opcje:");
           gb.display.println(" ");
           gb.display.println("   NOWA GRA");
           gb.display.println("   AUTORZY");
           gb.display.println("   INSTRUKCJE");
           gb.display.println("   KONIEC GRY");
           //gb.display.println(konami); <- konami code debug
           gb.display.print("         : ");
           gb.display.println(topscore);
           gb.display.drawChar(32, 36, 0, 1); //draw carrot score
           gb.display.println("         ARHn.EU 2018");
    
           if(gb.buttons.pressed(BTN_DOWN)){
              option++;
              if(option > 3) option = 0;
              konami.concat("dn");
              //trim konami to 16 characters
              konami = konami.substring(2);
              
           }

           if(gb.buttons.pressed(BTN_UP)){
              option--;
              if(option < 0) option = 3;
              //konamicodeappend
              konami.concat("up");
              //trim konami to 16 characters
              konami = konami.substring(2);
           }
           if(gb.buttons.pressed(BTN_LEFT)){
            konami.concat("lf");
              //trim konami to 16 characters
              konami = konami.substring(2);
           }
           if(gb.buttons.pressed(BTN_RIGHT)){
            konami.concat("rt");
              //trim konami to 16 characters
              konami = konami.substring(2);
           }
          if(burgerek == 1){
           gb.display.drawBitmap(1, (10+option*6), burger, NOROT, flip);
          }else{
            gb.display.drawBitmap(1, (10+option*6), grunioa, NOROT, flip);
          }
    //Draw Credits
    }else if(start == 2){
           gb.display.println("Gruniozerca GBuino");
           gb.display.println(" ");
           gb.display.println("Kod,gfx: Dark Archon");
           gb.display.println("Logo: Neko");
           gb.display.println("Koncept: Dizzy9");
           gb.display.println(" ");
           gb.display.println("WWW: ARHN.EU");
           gb.display.println("\25 - MENU");
           //literka ż
           gb.display.drawPixel(25, 0);
           if(gb.buttons.pressed(BTN_A)){
              start = 1;              
           }
    }else if(start == 3){
        gb.display.println("Grunio jest glodny!");
        gb.display.println("Jedz marchewki");
        gb.display.println("i zbieraj punkty.");
        gb.display.println(" ");
        gb.display.println("Przycisk \25 koloruje");
        gb.display.println("Grunia, by dopasowac");
        gb.display.println("go do warzywa.");
        gb.display.println("Smacznego! Mlem!");

        //polish ogonki
        //ł
        gb.display.drawPixel(52, 2);
        gb.display.drawPixel(54, 2);
        //ć
        gb.display.drawPixel(78, 30);
        
        
        if(gb.buttons.pressed(BTN_A)){
              start = 1;              
        }
    //DRAW GAME
    }else if(alive == 1){
        //Game Over on "C" Press
        if(gb.buttons.pressed(BTN_C)){
          lives = 0;
        }
        int keyp = 0;
        //grunio moves left
        if(gb.buttons.repeat(BTN_LEFT, 1)){
          //acceleration
          acc++;
          if(posx > 0){
          if(acc > 10){
          posx = posx -2;
          if(posx < 0) posx = 0;
          }else{
          posx = posx -1;
          }
          flip = FLIPH;
          keyp = 1;
          }
        }
    
        //grunio moves right
       if(gb.buttons.repeat(BTN_RIGHT, 1)){
          acc++;
          if(posx < LCDWIDTH-8){
          if(acc > 10){
          posx = posx +1;
          }
          posx = posx +1;
          if(posx > LCDWIDTH-8) posx = LCDWIDTH-8;
          flip = NOFLIP;
          keyp = 1;
          }
        }

        //reset acceleration
        if(gb.buttons.released(BTN_LEFT) || gb.buttons.released(BTN_RIGHT)){
          acc = 0;
        }
        //change Grunio Color!
       if(gb.buttons.pressed(BTN_A)){
          gcolor++;
          if(gcolor > 1) gcolor = 0;
        }
      
        //Prints interface on the screen
        //Lives - \3
        int draw = 0;
        while(draw < lives){
          gb.display.print("\3");
          draw++;
        }
        //place cursor to the right of the screen, same line
        gb.display.drawChar(65, 0, 0, 1); //draw carrot score
        gb.display.cursorX = 70;
        //print score value
        gb.display.print(score);
    
        //Draw Grunio!
       //color
       //position
       //konami code :D
       if(gb.frameCount % 2 == 0 && keyp == 1){
        if(burgerek == 1){
          if(gcolor == 0) gb.display.drawBitmap(posx, posy, burger, NOROT, flip);
          if(gcolor == 1) gb.display.drawBitmap(posx, posy, burgerb, NOROT, flip);
        }else{
          if(gcolor == 0) gb.display.drawBitmap(posx, posy, gruniob, NOROT, flip);
          if(gcolor == 1) gb.display.drawBitmap(posx, posy, gruniod, NOROT, flip);
        }
       }else{
        if(burgerek == 1){
          if(gcolor == 0) gb.display.drawBitmap(posx, posy, burger, NOROT, flip);
          if(gcolor == 1) gb.display.drawBitmap(posx, posy, burgerb, NOROT, flip);
        }else{
        if(gcolor == 0) gb.display.drawBitmap(posx, posy, grunioa, NOROT, flip);
        if(gcolor == 1) gb.display.drawBitmap(posx, posy, grunioc, NOROT, flip);
        }
       }
       //Falling carrots
       if(carrots == 0){
          //carrot color = custom font - 0x0 for white, 0x1 for black
          color = rand() % 2;
          carrots = 1;
          cposx = rand() % 78;
          cposy = 5;
       }
      //draw carrot
       gb.display.drawChar(cposx, cposy, color, 1);
       cposy++;
    
      //grunio - carrot collide
      if(cposy > posy-3 && (cposx >= posx-1 && cposx < posx+8)){
        //are they same color?
        if(color == gcolor){
          carrots = 0;
          score += 1;
          gb.sound.playTick();
          gb.popup(F("Mlem!"), 20);
        }
      }
    
      //life lost
       if(cposy > LCDHEIGHT){
          lives = lives - 1;
          carrots = 0;
          gb.sound.playCancel();
          gb.popup(F("Nieeeee!"), 20);
       }
      if(lives == 0){
       alive = 0;
      }

   //GAME OVER
  }else{
      int rekord = 0;
    if(score > topscore){
      rekord = 1;
      topscore = score;
      //write new topscore
      EEPROM.write(0, topscore);
    }
    gb.display.drawBitmap(-7, -14, logo, NOROT, NOFLIP);
    gb.display.cursorX = 44;
    gb.display.cursorY = 6;
    gb.display.println("KONIEC GRY!");
    gb.display.cursorX = 44;
    gb.display.print("Wynik: ");
    gb.display.println(score);
    
    gb.display.cursorY = 24;
    gb.display.cursorX = 0;
    if(score == topscore){
      gb.display.println("!NOWY GRUNIO REKORD!");
    }else{
      gb.display.println(" ");
    }
    gb.display.print("Rekord: ");
    gb.display.println(topscore);
    gb.display.println(" ");
    gb.display.print("\26 - RESTART  \27 - MENU");

  //restart the game
   if(gb.buttons.pressed(BTN_B) || gb.buttons.pressed(BTN_C)){
      score = 0;
      lives = 3;
      posx = 35;
      posy = 30;
      carrots = 0;
      gcolor = 0;
      alive = 1;
      if(gb.buttons.pressed(BTN_B)) gb.popup(F("Jeszcze raz, Guno!"), 20);
      if(gb.buttons.pressed(BTN_C)) start = 1;
    }
    
  }
  }
}
