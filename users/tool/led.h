#ifndef LED_H
#define LED_H

#include "stm32f4xx.h"
#include "delay.h"


class Led {
 private:
  GPIO_TypeDef *family;
  uint16_t port;

 public:
  char status = 0;

  Led(uint32_t RCC_AHB2Periph, GPIO_TypeDef *family, uint32_t pin);

  void change(void);

  static void callback(void *data) {
    Led *led = (Led *)data;
    led->change();
  };


};

#endif