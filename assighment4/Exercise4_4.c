/*****************************************************
 *
 *  CSCV352 - Exercise4_4.c
 *
 *  Student:  <Student's Name>
 *
******************************************************/
#include <stdio.h>
#include <string.h>


///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////
void DumpHex(const void* data, size_t size, int width);
int DisplayTCPSegment(unsigned char *pSegment, int segmentLen);

/*****************************************************
 *
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
 *
******************************************************/
int main(int argc, char *argv[]) 
{
    unsigned char segmentBuffer[1500];
    int bytesRead;

    // Read the TCP segment from stdin
    bytesRead = fread(segmentBuffer, 1, 1500, stdin);

    // Uncomment this line to dump the packet to the console
    DumpHex(segmentBuffer, bytesRead, 16);
	DisplayTCPSegment(segmentBuffer, bytesRead);

    // ADD YOUR CALL TO DisplayTCPSegment() HERE

    return 0;

}

int DisplayTCPSegment(unsigned char *pSegment, int segmentLen)//define the function
{
	unsigned short sourcePort;// create variables 
	unsigned short destPort;
	int sequenceNumber;
	int ackNumber;
	unsigned char flags;
	int i = 0;
	
	for (i=0; i<segmentLen; i++){//loop through every element found in the hex dump
		unsigned char data[segmentLen];//a array to store the elements
		unsigned char *pSegment = data;// the pointer to the first element in the array
		if (i<2){//get the first two bytes
			unsigned short sourcePort = 0;//create the sourceport as all 0s
			sourcePort += *pSegment << 8;//add the numbers to sourceport
			pSegment ++;//update our pointer
			sourcePort += *pSegment;//update sourceport number
			printf("sourcePort: 0x%08x\n",sourcePort);
		}
		if (i >= 2 && i < 4){//get the dest port
			pSegment +=2;
			unsigned short destPort = 0;
			destPort += *pSegment << 8;
			pSegment ++;
			destPort += *pSegment;
		}
		if (i >= 4 && i < 8){//get the sequence number
			unsigned int sequenceNum = 0;
			sequenceNum = *pSegment << 24;
			pSegment ++;
			sequenceNum += *pSegment << 16;
			pSegment ++;
			sequenceNum += *pSegment << 8;
			pSegment ++;
			sequenceNum += *pSegment;
		}
		if (i >= 8 && i < 12){//get the ack number
			unsigned int ackNumber = 0;
			ackNumber = *pSegment << 24;
			pSegment ++;
			ackNumber += *pSegment << 16;
			pSegment ++;
			ackNumber += *pSegment << 8;
			pSegment ++;
			ackNumber += *pSegment;
		}
		if (i == 13){//get the flag number
			
			pSegment +=2;
			unsigned char flags = *pSegment;
			if((flags & 0x80)!= 0){//check each of condition to see which flag is on use
				printf("\nCWR");
			}else if ((flags &0x40) != 0){
				printf("\nECE");
			}else if ((flags &0x20) != 0){
				printf("\nURG");
			}else if ((flags &0x10) != 0){
				printf("\nACK");
			}else if ((flags &0x8) != 0){
				printf("\nPSH");
			}else if ((flags &0x4) != 0){
				printf("\nRST");
			}else if ((flags &0x2) != 0){
				printf("\nSYN");
			}else if ((flags &0x1) != 0){
				printf("\nFIN");
			}

		}

	}
	printf("TCP Header Field: \n");//print out the TCP hearder parse.
	printf("\tSource Port: %12d\n", sourcePort);
	printf("\tDest Port: %12d\n", destPort);
	printf("\tSequence No: %12d\n", sequenceNumber);
	printf("\tAck No: %12d\n", ackNumber);
	printf("\tFlags: %12d\n", flags);
	return 0;
	
}

/*******************************************************************
 * 
 *   DumpHex()
 * 
 *   Formatted output of raw data.
 * 
*******************************************************************/
void DumpHex(const void* data, size_t size, int width) 
{
	char ascii[17];
	size_t i, j;

	ascii[width] = '\0';
	for (i = 0; i < size; ++i) 
    {
        // Print the value
		printf("%02X ", ((unsigned char*)data)[i]);

        // save the ascii display value in the relative position
		if (((unsigned char*)data)[i] >= ' ' && ((unsigned char*)data)[i] <= '~') 
        {
			ascii[i % width] = ((unsigned char*)data)[i];
		} 
        else 
        {
			ascii[i % width] = '.';
		}


		if ((i+1) % (width / 2) == 0 || i+1 == size) 
        {
			printf(" ");
			if ((i+1) % width == 0) 
            {
				printf("|  %s \n", ascii);
			} 
            else if (i+1 == size) 
            {
				ascii[(i+1) % width] = '\0';
				if ((i+1) % width <= (width / 2)) 
                {
					printf(" ");
				}
				for (j = (i+1) % width; j < width; ++j) 
                {
					printf("   ");
				}
				printf("|  %s \n", ascii);
			}
		}
	}
}
