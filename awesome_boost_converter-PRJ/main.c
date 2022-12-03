/*
 * awesome_boost_converter-PRJ.c
 *
 * Created: 12/3/2022 2:13:40 PM
 * Author : Anil
 */ 
#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

uint32_t ADC_RESULT(void)
void ADC_FREERUN_INIT(void);

int main(void)
{
	
	DDRB |= (1<<DDB5);
	
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(100);
		PORTB ^= (1<<PORTB5);
			
    }
}



void ADC_FREERUN_INIT(void){
	ADCSRA|=(1<<ADEN);//ADC a�?ld?.
	ADCSRA|=(1<<ADATE);//Otomatik tetikleme modu ayarland?.
	ADCSRA|=(1<<ADPS0)|(1<<ADPS1);//�n derecelendirici 32 olarak ayarland?.
	
	ADMUX |=(1<<MUX0);//1. ADC kanal? se�ildi.
	ADMUX |=(1<<REFS0);//Referans voltaj? AVCC olarak ayarland?.
	ADMUX|=(1<<ADLAR);//�l��m sonu�lar? sola dayal? olarak se�ildi.
	
	ADCSRA|=(1<<ADSC);//�l��m ba?lat?ld?.
}
uint32_t ADC_RESULT(void){
	return (ADCL>>6)|(ADCH<<2);
}
