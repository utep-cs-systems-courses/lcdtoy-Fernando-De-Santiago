
#include <msp430.h>
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
/** Initializes everything, clears the screen, draws "hello" and a square */
void
main(void)
{
  configureClocks();
  switch_init();
  lcd_init();
  u_char width=screenWidth,height=screenHeight;
  led_init();
  enableWDTInterrupts();
  buzzer_init();
  clearScreen(COLOR_WHITE);
  drawString8x12(10,10,"Hi",COLOR_RED,COLOR_PINK);
  or_sr(0x18);
}
void octo(u_char y,u_char x1, u_char x2, int size)
{
  clearScreen(COLOR_WHITE);
  for(int k=0;k<size+1;k++)//makes horizontal lines on the top and bottom
  {
    drawPixel(x1+k,y+(size*2)-5,COLOR_BLACK);
    drawPixel(x1+k,y-(size*2)+5,COLOR_BLACK);
    drawPixel(x2-k,y+(size*2)-5,COLOR_BLACK);
    drawPixel(x2-k,y-(size*2)+5,COLOR_BLACK);
  }

  for(int k=0;k<size-1;k++)//makes verticles lines on the edge
  {
    drawPixel(x1+((size-1)*2),y+k,COLOR_BLACK);
    drawPixel(x1+((size-1)*2),y-k,COLOR_BLACK);
    drawPixel(x2-((size-1)*2),y+k,COLOR_BLACK);
    drawPixel(x2-((size-1)*2),y-k,COLOR_BLACK);
  }
  for(int k=0;k<size-2;k++){//connects the horizontal and verticle edges with a diagonal line.
    drawPixel((x1+((size-1)*2))-k,(y+(size-2))+k,COLOR_BLACK);
    drawPixel((x1+((size-1)*2))-k,(y-(size-2))-k,COLOR_BLACK);
    drawPixel((x2-((size-1)*2))+k,(y+(size-2))+k,COLOR_BLACK);
    drawPixel((x2-((size-1)*2))+k,(y-(size-2))-k,COLOR_BLACK);
  }
	  
  
}


