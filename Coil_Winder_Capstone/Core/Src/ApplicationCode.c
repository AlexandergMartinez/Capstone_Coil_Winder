/*
 * ApplicationCode.c
 *
 *  Created on: Sep 15, 2026
 *      Author: alexandermartinez
 */


void ApplicationInit(void){
	buttConfig(); //Button Control
	configureBTimer(); //Timer Control
	initialise_monitor_handles(); // Allows printf functionality
	LTCD__Init();
	LTCD_Layer_Init(0);
	LCD_Clear(LCD_COLOR_WHITE);
}

void LCD_Visual_Demo(void){

}
