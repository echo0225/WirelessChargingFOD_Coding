#ifndef _DRV_ANALOGSWITCH_ADG1439_PORT_HPP_
#define _DRV_ANALOGSWITCH_ADG1439_PORT_HPP_
#include "inc_stdlib.hpp"

int32_t ADG1439_PORT_spi_write(uint8_t* txbuf, uint32_t len);

void ADG1439_PORT_gpio_rst(bool b);

void ADG1439_PORT_delay_ms(uint32_t ms);

#endif // ! _DRV_ANALOGSWITCH_ADG1439_PORT_HPP_
