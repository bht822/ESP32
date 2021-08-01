
# Hello ESP-IDF

This program is a quick demo of ESP-IDP for ESP32-WROOM
Random number is also generated and printed on the console as a lucky number.
Then an external LED is blinked on Pin 13 which is IO14 equivalent to the luck number
Then ESP waits from input from the keyboard and echos the type characters back to the console.  
ESP_LOGx where x is E for Error , W for warning , V for verbose and D for debug.

## flashing the esp32

1. in vs code, open a new terminal by pressing ctrl + \` (or pressing F1 and typing `open new terminal`)
2. type the following command

```bash
idf.py -p [your com port] flash monitor
```


## vs code intellisense

intellisense should just work so long as you have set up the paths correctly. If you have trouble double check your idf and tools paths and correct them in the **/.vscode/c_cpp_properties.json** file
