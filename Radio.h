#ifndef RADIO_H
#define RADIO_H

#include <stdint.h>

//////////////////////////////////////////////////////////
//HEADERS
//////////////////////////////////////////////////////////

static const uint8_t HEADER_SERVER = 0X00;

//When we have specific devices that deserve an header, we can rename these
static const uint8_t HEADER_DEVICE_1 = 0X01;
static const uint8_t HEADER_DEVICE_2 = 0X02;
static const uint8_t HEADER_DEVICE_3 = 0X03;
static const uint8_t HEADER_DEVICE_4 = 0X04;
static const uint8_t HEADER_DEVICE_5 = 0X05;


/////////////////////////////////////////////////////////
//PROTOCOL DEFINITION
/////////////////////////////////////////////////////////

static const uint8_t MESSAGE_MAX_SIZE = 0x1E;
static const uint8_t PAYLOAD_MAX = 0x1A;

class RadioMessage {
	
	public:
		// the unique identification of the sending device
		uint8_t header;

		// the identification for this specific message (helps handle missed messages and duplicates)
		uint8_t identifier;

		//the contents of the message
		uint8_t payload[PAYLOAD_MAX];

		//Does the message have integrity
		bool wasSuccessful = false;	

		//constructors
		RadioMessage(uint8_t *rawBytes);
		RadioMessage(uint8_t header, uint8_t identifier, uint8_t *payload);
};

#endif

