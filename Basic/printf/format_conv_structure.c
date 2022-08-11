#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct message {
	uint8_t MsgID;
	uint8_t DoorClient;
	uint8_t DoorStatus;
	uint8_t SpeakerStatus;
	uint8_t Temparature[4];
	uint8_t Pressure[4];
	uint8_t Altitude[4];
	uint8_t Humidity[4];
	float TemparatureF;
	float PressureF;
	float AltitudeF;
	float HumidityF;
};

struct message ClientData;

int main()
{
	char buffer[50];
	ClientData.TemparatureF = 118.2;
	ClientData.PressureF = 122.4;
	ClientData.AltitudeF = 133.6;
	float c;
	int i = 0;

	//memset((char *)&ClientData, 0x5F, sizeof(struct message));
	sprintf(ClientData.Temparature, "%f",  ClientData.TemparatureF);
	sprintf(ClientData.Pressure, "%f",  ClientData.PressureF);
	sprintf(ClientData.Altitude, "%f",  ClientData.AltitudeF);
	
	memcpy(buffer, (char *)&ClientData, sizeof(struct message));

	//while(i<32)
	//	printf(" %x \t", buffer[i++]);
	
	printf(" \n ");

	printf("\nOutput String: \n");
	printf("%s\n", ClientData.Temparature);
	printf("%s\n", ClientData.Pressure);
	printf("%s\n", ClientData.Altitude);

	printf("Output Number: \n");
	sscanf(&buffer[4], "%f", &c);
//	sscanf(&ClientData.Temparature, "%f", &c);
	printf(" %f\n", c);
	sscanf(&buffer[8], "%f", &c);
//	sscanf(&ClientData.Pressure, "%f", &c);
	printf(" %f\n", c);
	sscanf(&buffer[12], "%f", &c);
//	sscanf(&ClientData.Altitude, "%f", &c);
	printf(" %f\n", c);

	return 0;
}

