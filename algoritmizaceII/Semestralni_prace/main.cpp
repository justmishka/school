/*

Morse code encored/decoder demonstration.
By Michaela Duranova.

*/


#include <morse_coder.h>


int main(int argc, char *argv[])
{
	//For Decode from Morse Code to text
    return MC_DecodeFile("file_input_decode.txt", "file_output.txt");
    
    //For Encode from text to Morse Code
    //return MC_EncodeFile("file_input_encode.txt", "file_output.txt");
}
