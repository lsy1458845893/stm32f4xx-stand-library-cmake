#include <stm32f4xx.h>
#include <delay.h>
#include <led.h>
#include <oled.h>
#include <stimer.h>
#include <stm32f4xx_rcc.h>

int main(void) {
    delay_init(72);
    Led led = Led(RCC_AHB1ENR_GPIOCEN, GPIOC, GPIO_Pin_13);
    OLED oled = OLED(RCC_AHB1ENR_GPIOCEN,GPIOB,GPIO_Pin_8,GPIOB,GPIO_Pin_9);
    SoftwareTimer timer = SoftwareTimer();


    timer.setInterval(Led::callback, &led, 97);
    timer.setInterval(OLED::callback, &oled, 337);

    oled.print(0,0,0,"it works!");

    while (1) {
        timer.refresh();
        timer.execult();
        delay_ms(1);
    }
}
