#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>

const uint8_t PIN_SPI_RST_RES_RESET = 2; // Used for UC1609
const uint8_t PIN_SPI_DC_RS_A0 = 4; // Used for UC1609
const uint8_t PIN_SPI_CS_SS = 15; // Used for UC1609
const uint8_t PIN_SPI_SDA_SDI_DARA_IN_MOSI = 13; // Used for UC1609
const uint8_t PIN_SPI_SDO_DATA_OUT_MISO = 12; // Used for UC1609
const uint8_t PIN_SPI_SCK_CLK_SCL_SCLK = 14; // Used for UC1609
const uint8_t PIN_I2C_SDA = 21;
const uint8_t PIN_I2C_SCL = 22;
const uint8_t PIN_UART_TX = 17;
const uint8_t PIN_UART_RX = 16;
const uint8_t PIN_DISPLAY_BRIGHTNESS = 5; // Used for UC1609, You can connect A pin to 5V for full brightness

const uint8_t DISPLAY_CONTRAST = 120;

// A = Anode = VCC
// K = Cathode = GND

U8G2_UC1609_SLG19264_F_4W_HW_SPI u8g2(
        U8G2_R0,
        PIN_SPI_CS_SS,
        PIN_SPI_DC_RS_A0,
        PIN_SPI_RST_RES_RESET
        );

TaskHandle_t Task1;
TaskHandle_t Task2;

void setupDisplay() {
    pinMode(PIN_DISPLAY_BRIGHTNESS, OUTPUT);
//    analogWrite(PIN_DISPLAY_BRIGHTNESS, DISPLAY_BRIGHTNESS * 8421504);
    digitalWrite(PIN_DISPLAY_BRIGHTNESS, HIGH);
    SPI.begin(PIN_SPI_SCK_CLK_SCL_SCLK, PIN_SPI_SDO_DATA_OUT_MISO, PIN_SPI_SDA_SDI_DARA_IN_MOSI, PIN_SPI_CS_SS);
    u8g2.begin();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setContrast(DISPLAY_CONTRAST);
    u8g2.clearBuffer();
    u8g2.drawStr(80,34,"Start");
    u8g2.sendBuffer();
}

void task1(void *pvParameters) {
    while (true) {

    }
}

void task2(void *pvParameters) {
    while (true) {

    }
}

void setupTasks() {
    xTaskCreatePinnedToCore(
            task1,
            "task1",
            50000,
            NULL,
            1,
            &Task1,
            0);
    xTaskCreatePinnedToCore(
            task2,
            "task2",
            50000,
            NULL,
            1,
            &Task2,
            1);
}

void setup() {
    setupDisplay();
//    setupTasks();
}

void loop() {

}