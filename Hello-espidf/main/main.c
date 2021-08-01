#include <stdio.h>
#include "esp_log.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <string.h>

/***
 *@Program: This program is a quick demo of ESP-IDP for ESP32-WROOM
  
  Random number is also generated and printed on the console as a lucky number.
  Then an external LED is blinked on Pin 13 which is IO14 equivalent to the luck number
  Then ESP waits from input from the keyboard and echos the type characters back to the console.  
  
  ESP_LOGx where x is E for Error , W for warning , V for verbose and D for debug.
*/

// Define TAG as a placeholder for LOG
# define TAG "LOG"
#define LED_PIN 14

void app_main(void)
{
  printf("Hello world!\n");

  // Set the level to display debug and verbose
  esp_log_level_set("LOG", ESP_LOG_INFO);

  ESP_LOGE("LOG","This is an error");
  ESP_LOGI("LOG","This is an Info");
  ESP_LOGD("LOG","This is a debug");
  ESP_LOGV("LOG","This is a verbose");

  // Random number generation
  int luckNumber = esp_random()%6;
  printf("Your lucky number today is:%d \n",luckNumber);


  // Setup  the GPIO on IO14
  gpio_pad_select_gpio(LED_PIN);
  gpio_set_direction(LED_PIN,GPIO_MODE_OUTPUT);
  int isOn = 0;
  
  int total_blinks = 0;
  // Blink LED 6 times 
  while((total_blinks < (luckNumber+1)))
  {
    // Togle the level
    isOn = !isOn ;
    gpio_set_level(LED_PIN,isOn);
    printf("LED is:%i \n",isOn);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    total_blinks++;
    
  }

  // Taking echo in the input from keyboard

  // One character from keyboard
  char characterFromKeyBoard = 0;
  // array to store the characters
  char str[100];

  // clean the array
  memset(str,0,sizeof(str));

  // Keep listening for the charaters from keyboard till no carriange return is pressed \n
  while(characterFromKeyBoard != '\n'){
    characterFromKeyBoard = getchar();
    if(characterFromKeyBoard !=0xff){
      str[strlen(str)] = characterFromKeyBoard;
      printf("%c",characterFromKeyBoard);
    }
    vTaskDelay(10/portTICK_PERIOD_MS);
  }
  printf("You typed :%s \n ",str);

  
  
}
//EOF
  