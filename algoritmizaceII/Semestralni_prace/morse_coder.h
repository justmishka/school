/*

Morse code encored/decoder interface.
By Michaela Duranova.

*/


#ifndef MC_CODER
#define MC_CODER

// Encodes plaintext file to morse code.
// Returns 0 on success, -1 on error.
int MC_EncodeFile(const char* pSrcFileName,
                  const char* pDstFileName);

// Decodes file from morse code to plaintext.
// Returns 0 on success, -1 on error.
int MC_DecodeFile(const char* pSrcFileName,
                  const char* pDstFileName);
                  
#endif