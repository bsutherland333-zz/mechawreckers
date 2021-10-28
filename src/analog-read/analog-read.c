#include "analog-read.h"

void analog_init()
{
    /*** Select Voltage Reference Source ***/
	// use AVdd for positive reference
	_PVCFG = 0b00;		// AD1CON2<15:14>, pg. 212-213 datasheet
	// use AVss for negative reference
	_NVCFG = 0;			// AD1CON2<13>


	/*** Select Analog Conversion Clock Rate ***/
	// make sure Tad is at least 600ns (see Table 29-41 datasheet), section 51.4.3 family reference manual
	_ADCS = 0x3F;	// AD1CON3<7:0>, pg. 213 datasheet -- scale by 64 x tcf


	/*** Select Sample/Conversion Sequence ***/
	// use auto-convert
	_SSRC = 0b0111;		// AD1CON1<7:4>, pg. 211 datasheet
	// use auto-sample
	_ASAM = 1;			// AD1CON1<2>register
	// choose a sample time >= 1 Tad, see Table 29-41 datasheet
	_SAMC = 0b00001;	// AD1CON3<12:8>


	/*** Choose Analog Channels to be Used ***/
	// scan inputs
	_CSCNA = 1;			// AD1CON2<10>

    /*** Select How Results are Presented in Buffer ***/
	// set 12-bit resolution
	_MODE12 = 1;		// AD1CON1<10>
	// use absolute decimal format
	_FORM = 0b00;		// AD1CON1<9:8>
	// load results into buffer determined by converted channel, e.g. ch AN12 
    // results appear in ADC1BUF12
	_BUFREGEN = 1;		// AD1CON2<11>


    /*** Select Interrupt Rate ***/
	// interrupt rate should reflect number of analog channels used, e.g. if 
    // 5 channels, interrupt every 5th sample
	_SMPI = 0;	// AD1CON2<6:2>  ----------

    /*** Turn on A/D Module ***/
	_ADON = 1;			// AD1CON1<15>
}

void setup_analog(int rgstr) 
{
	
    
    // choose which channels to scan, e.g. for ch AN12, set _CSS12 = 1;
    // Also configure the approriate pins as analog
    // if register doesn't exist, do nothing
    switch (rgstr)
    {
    case 0:

        _TRISA0 = 1;
        _ANSA0 = 1;
        _CSS0 = 1;
        break;

    case 1:

        _TRISA1 = 1;
        _ANSA1 = 1;
        _CSS1 = 1;
        break;

    case 2:
        
        _TRISB0 = 1;
        _ANSB0 = 1;
        _CSS2 = 1;
        break;

    case 3:
        _TRISB1 = 1;
        _ANSB1 = 1;
        _CSS3 = 1;
        break;

    case 4:
        
        _TRISB2 = 1;
        _ANSB2 = 1;
        _CSS4 = 1;
        break;

    case 9:
        
        _TRISB15 = 1;
        _ANSB15 = 1;
        _CSS9 = 1;
        break;

    case 10:

        _TRISB14 = 1;
        _ANSB14 = 1;
        _CSS10 = 1;
        break;

    case 11:
        
        _TRISB13 = 1;
        _ANSB13 = 1;
        _CSS11 = 1;
        break;

    case 12:

        _TRISB12 = 1;
        _ANSB12 = 1;
        _CSS12 = 1;
        break;

    case 13:

        _TRISA2 = 1;
        _ANSA2 = 1;
        _CSS13 = 1;
        break;

    case 14:

        _TRISA3 = 1;
        _ANSA3 = 1;
        _CSS14 = 1;
        break;

    case 15:

        _TRISB4 = 1;
        _ANSB4 = 1;
        _CSS15 = 1;
        break;
    
    default:
        break;
    }
	
	_SMPI++; // increment the number of analog channels scanned

}

// returns the analogue reading of a certain register
int read_analog(int rgstr)
{   
    int val = -1;
   
    // return the result of the given register
    // if it doesn't exist return -1
    switch (rgstr)
    {
    case 0:

        val = ADC1BUF0;
        break;

    case 1:

        val = ADC1BUF1;
        break;

    case 2:
        
        val = ADC1BUF2;
        break;

    case 3:

        val = ADC1BUF3;
        break;

    case 4:
        
        val = ADC1BUF4;
        break;

    case 9:
        
        val = ADC1BUF9;
        break;

    case 10:

        val = ADC1BUF10;
        break;

    case 11:
        
        val = ADC1BUF11;
        break;

    case 12:

        val = ADC1BUF12;
        break;

    case 13:

        val = ADC1BUF13;
        break;

    case 14:

        val = ADC1BUF14;
        break;

    case 15:

        val = ADC1BUF15;
        break;
    
    default:
        break;
    }
	
	return val;

}


// returns the analogue reading of a certain pin
int read_analog_pin(int pin)
{   
    int val = -1;
   
    // return the result of the given pin
    // if it doesn't exist return -1
    switch (pin)
    {
    case 2:

        val = ADC1BUF0;
        break;

    case 3:

        val = ADC1BUF1;
        break;

    case 4:
        
        val = ADC1BUF2;
        break;

    case 5:

        val = ADC1BUF3;
        break;

    case 6:
        
        val = ADC1BUF4;
        break;

    case 18:
        
        val = ADC1BUF9;
        break;

    case 17:

        val = ADC1BUF10;
        break;

    case 16:
        
        val = ADC1BUF11;
        break;

    case 15:

        val = ADC1BUF12;
        break;

    case 7:

        val = ADC1BUF13;
        break;

    case 8:

        val = ADC1BUF14;
        break;

    case 9:

        val = ADC1BUF15;
        break;
    
    default:
        break;
    }
	
	return val;

}