#include <led.h>
#include <stm32f4xx_gpio.h>

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

void Led::change(void) {
  if (status) {
    status = 0;
    GPIO_SetBits(family, port);
  } else {
    status = 1;
    GPIO_ResetBits(family, port);
  }
}

Led::Led(uint32_t RCC_AHB2Periph, GPIO_TypeDef *family, uint32_t pin) {
  RCC_AHB2PeriphClockCmd(RCC_AHB2Periph, ENABLE);

  GPIO_InitTypeDef led;
  led.GPIO_Mode = GPIO_Mode_OUT;
  led.GPIO_OType = GPIO_OType_PP;
  led.GPIO_PuPd = GPIO_PuPd_NOPULL;
  led.GPIO_Speed = GPIO_Speed_100MHz;
  led.GPIO_Pin = pin;

  GPIO_Init(this->family = family, &led);
}
