#include "mbed.h"
#define dot 200
#define dash 600
#define space 600
#define pause 1200

const char* morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--..", " "
};

void wait_ms(int milliseconds) {
    int waitUntil = us_ticker_read() + milliseconds * 1000; 
    while (us_ticker_read() < waitUntil) {
        
    }
}


char toupper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

void blinkMorse(DigitalOut& led, const char* morseChar) {
    for (int i = 0; morseChar[i]; i++) {
        if (morseChar[i] == '.') {
            led = 1;
            wait_ms(dot);  
        } else if (morseChar[i] == '-') {
            led = 1;
            wait_ms(dash);  
        } else if (morseChar[i] == ' ') {
            wait_ms(space);  
        }
        led = 0;
        wait_ms(dot);  
    }
}


int main() {
   
    DigitalOut led(LED1);
    const char* word = "Morseovka";

    while (true) {
        for (int i = 0; word[i]; i++) {
            char uppercaseChar = toupper(word[i]);
            if (uppercaseChar >= 'A' && uppercaseChar <= 'Z') {
                blinkMorse(led, morseCode[uppercaseChar - 'A']);
                wait_ms(space); 
            }
        }
        wait_ms(pause);
    }
}
