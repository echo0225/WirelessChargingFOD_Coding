#ifndef _DRV_ANALOGSWITCH_ADG1439_HPP_
#define _DRV_ANALOGSWITCH_ADG1439_HPP_
#include "inc_stdlib.hpp"
#include "drv_adg1439_port.hpp"


class adg1439_t
{
public:
	typedef void (*gpio_pinWrite_t)(bool b);
	typedef void (*spi_write_t)(uint8_t* txbuf, uint32_t len);
private:
	spi_write_t spiWrite;
	gpio_pinWrite_t rstControll;
public:
	enum adg1439_muxSel_t
	{
		mux0A = 1 << 0,
		mux1A = 1 << 1,
		mux2A = 1 << 2,
		mux3A = 1 << 3,
		mux0B = 1 << 4,
		mux1B = 1 << 5,
		mux2B = 1 << 6,
		mux3B = 1 << 7,
	};

	void reset(void)
	{
		(*rstControll)(0);
		ADG1439_PORT_delay_ms(1);
		(*rstControll)(1);
		ADG1439_PORT_delay_ms(1);
	}

	adg1439_t(spi_write_t _spi, gpio_pinWrite_t _rst)
		: spiWrite(_spi), rstControll(_rst)
	{
		if(rstControll != NULL)
		{
			reset();
		}
	}



	void setMux(uint8_t s)
	{
		(*spiWrite)(&s, 1);
	}

};





#endif // ! _DRV_ANALOGSWITCH_ADG1439_HPP_
