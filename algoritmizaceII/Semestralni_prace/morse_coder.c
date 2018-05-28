/* 
Morse code encored/decoder implementation.
By Michaela Duranova.
*/

////////////////////////////////////////////////////////////////////////////////
// Includes.
////////////////////////////////////////////////////////////////////////////////

#include <stddef.h>      // NULL
#include <stdlib.h>      // malloc
#include <stdio.h>       // file operations
#include <morse_coder.h> // Morse coder API


////////////////////////////////////////////////////////////////////////////////
// Macros.
////////////////////////////////////////////////////////////////////////////////

// Common function return codes.
#define MC_SUCCESS 0
#define MC_ERROR  -1

// The number of supported Morse code characters (A-Z and space).
#define MC_ALPHABET_SIZE 27

// ASCII value of A.
#define MC_ASCII_A 65

// Maximum tree depth.
#define MC_MAX_DEPTH 4

// Chars used to parse Morse code.
#define MC_SPACE_CHAR ' ' // separates words
#define MC_SLASH_CHAR '/' // separates letters
#define MC_EOF        EOF // file end
#define MC_DOT_CHAR   '.'
#define MC_DASH_CHAR  '-'
#define MC_NULL_CHAR  '\0'


////////////////////////////////////////////////////////////////////////////////
// Data types.
////////////////////////////////////////////////////////////////////////////////

// Types of signal in Morse code.
typedef enum
{
    MC_DOT   = 0,
    MC_DASH  = 1
} MC_SignalType_t;


// Direction of coding.
typedef enum
{
    MC_ENCODE = 0,
    MC_DECODE = 1
} MC_Direction_t;


// Morse code tree node.
struct MC_Node_t;
typedef struct MC_Node_t
{
    // Children nodes. NULL if this node is a leaf.
    struct MC_Node_t* pDotChild;
    struct MC_Node_t* pDashChild;
    
    // Character value that the node represents.
    char value;
} MC_Node_t;


////////////////////////////////////////////////////////////////////////////////
// Internal function declarations.
////////////////////////////////////////////////////////////////////////////////

// Adds a child node with assigned value to pParent depending on signalType.
int MC_AddNode(MC_Node_t* pParent, MC_SignalType_t signalType, char value);

// Builds the tree to be used in encoding/decoding.
int MC_BuildTree(MC_Node_t* pRoot);

// Recursively free memory allocated for children of specified node.
void MC_Cleanup(MC_Node_t* pNode);

// Encodes stream from plaintext to Morse code.
int MC_EncodeStream(FILE* pSrc, FILE* pDst);

// Decodes stream from Morse code to plaintext.
int MC_DecodeStream(MC_Node_t* pRoot, FILE* pSrc, FILE* pDst);

// Common code for MC_EncodeFile and MC_DecodeFile.
// Includes building the tree and file operations.
int MC_CodeFile(const char* pSrcFileName,
                const char* pDstFileName,
                MC_Direction_t direction);


////////////////////////////////////////////////////////////////////////////////
// Function implementations.
////////////////////////////////////////////////////////////////////////////////

int MC_AddNode(MC_Node_t* pParent, MC_SignalType_t signalType, char value)
{
    int result = 0;
    MC_Node_t* pChild = NULL;

    if (pParent == NULL)
    {
        return 1;
    }
    
    // Allocate memory for new node.
    pChild = (MC_Node_t*)malloc(sizeof(MC_Node_t));
    if (pChild == NULL)
    {
        return 1;
    }
    
    // Assign char value to new node.
    pChild->value = value;
    
    // Initialize pointers to NULL.
    pChild->pDotChild = NULL;
    pChild->pDashChild = NULL;
    
    // Assign the child node to parent correctly.
    switch (signalType)
    {
        case MC_DOT:
            pParent->pDotChild = pChild;
            break;
        case MC_DASH:
            pParent->pDashChild = pChild;
            break;
        default:
            result = 1;
            break;
    }
    
    return result;
}


int MC_BuildTree(MC_Node_t* pRoot)
{
    int result = 0;

    if (pRoot == NULL)
    {
        return MC_ERROR;
    }
    
    pRoot->value = MC_SPACE_CHAR;

    // Add depth 1 descendants.
    result |= MC_AddNode(pRoot, MC_DOT, 'E');
    result |= MC_AddNode(pRoot, MC_DASH, 'T');
    
    if (result != 0)
    {
        return MC_ERROR;
    }
    
    // Add depth 2 descendants.
    result |= MC_AddNode(pRoot->pDotChild, MC_DOT, 'I');
    result |= MC_AddNode(pRoot->pDotChild, MC_DASH, 'A');
    result |= MC_AddNode(pRoot->pDashChild, MC_DOT, 'N');
    result |= MC_AddNode(pRoot->pDashChild, MC_DASH, 'M');
    
    if (result != 0)
    {
        return MC_ERROR;
    }
    
    // Add depth 3 descendants.
    result |= MC_AddNode(pRoot->pDotChild->pDotChild, MC_DOT, 'S');
    result |= MC_AddNode(pRoot->pDotChild->pDotChild, MC_DASH, 'U');
    result |= MC_AddNode(pRoot->pDotChild->pDashChild, MC_DOT, 'R');
    result |= MC_AddNode(pRoot->pDotChild->pDashChild, MC_DASH, 'W');
    result |= MC_AddNode(pRoot->pDashChild->pDotChild, MC_DOT, 'D');
    result |= MC_AddNode(pRoot->pDashChild->pDotChild, MC_DASH, 'K');
    result |= MC_AddNode(pRoot->pDashChild->pDashChild, MC_DOT, 'Z');
    result |= MC_AddNode(pRoot->pDashChild->pDashChild, MC_DASH, 'O');
    
    if (result != 0)
    {
        return MC_ERROR;
    }
    
    // Add depth 4 descendants.
    result |= MC_AddNode(pRoot->pDotChild->pDotChild->pDotChild, MC_DOT, 'H');
    result |= MC_AddNode(pRoot->pDotChild->pDotChild->pDotChild, MC_DASH, 'V');
    result |= MC_AddNode(pRoot->pDotChild->pDotChild->pDashChild, MC_DOT, 'F');
    result |= MC_AddNode(pRoot->pDotChild->pDashChild->pDotChild, MC_DOT, 'L');
    result |= MC_AddNode(pRoot->pDotChild->pDashChild->pDashChild, MC_DOT, 'P');
    result |= MC_AddNode(pRoot->pDotChild->pDashChild->pDashChild, MC_DASH, 'J');
    result |= MC_AddNode(pRoot->pDashChild->pDotChild->pDotChild, MC_DOT, 'B');
    result |= MC_AddNode(pRoot->pDashChild->pDotChild->pDotChild, MC_DASH, 'X');
    result |= MC_AddNode(pRoot->pDashChild->pDotChild->pDashChild, MC_DOT, 'C');
    result |= MC_AddNode(pRoot->pDashChild->pDotChild->pDashChild, MC_DASH, 'Y');
    result |= MC_AddNode(pRoot->pDashChild->pDashChild->pDotChild, MC_DOT, 'Z');
    result |= MC_AddNode(pRoot->pDashChild->pDashChild->pDotChild, MC_DASH, 'Q');
    
    if (result != 0)
    {
        return MC_ERROR;
    }
    
    return MC_SUCCESS;
}


void MC_Cleanup(MC_Node_t* pNode)
{
    if (pNode != NULL)
    {
        if (pNode->pDotChild != NULL)
        {
            MC_Cleanup(pNode->pDotChild);
        }
        if (pNode->pDashChild != NULL)
        {
            MC_Cleanup(pNode->pDashChild);
        }
        
        free(pNode);
    }
}


int MC_EncodeStream(FILE* pSrc, FILE* pDst)
{
    char current = MC_NULL_CHAR;
    bool wasLastChar = false; // Needed to decide whether to write '/'.
    int result = MC_SUCCESS;
    
    // Max depth + NULL terminator for each alphabet letter.
    char alphabet[MC_ALPHABET_SIZE][MC_MAX_DEPTH + 1] =
    {
        {MC_DOT_CHAR,  MC_DASH_CHAR, MC_NULL_CHAR, MC_NULL_CHAR, MC_NULL_CHAR}, // A
        {MC_DASH_CHAR, MC_DOT_CHAR,  MC_DOT_CHAR,  MC_DOT_CHAR,  MC_NULL_CHAR}, // B
        {MC_DASH_CHAR, MC_DOT_CHAR,  MC_DASH_CHAR, MC_DOT_CHAR,  MC_NULL_CHAR}, // C
        {MC_DASH_CHAR, MC_DOT_CHAR,  MC_DOT_CHAR,  MC_NULL_CHAR, MC_NULL_CHAR}, // D
        {MC_DOT_CHAR,  MC_NULL_CHAR, MC_NULL_CHAR, MC_NULL_CHAR, MC_NULL_CHAR}, // E
        {MC_DOT_CHAR,  MC_DOT_CHAR,  MC_DASH_CHAR, MC_DOT_CHAR,  MC_NULL_CHAR}, // F
        {MC_DASH_CHAR, MC_DASH_CHAR, MC_DOT_CHAR,  MC_NULL_CHAR, MC_NULL_CHAR}, // G
        {MC_DOT_CHAR,  MC_DOT_CHAR,  MC_DOT_CHAR,  MC_DOT_CHAR,  MC_NULL_CHAR}, // H
        {MC_DOT_CHAR,  MC_DOT_CHAR,  MC_NULL_CHAR, MC_NULL_CHAR, MC_NULL_CHAR}, // I
        {MC_DOT_CHAR,  MC_DASH_CHAR, MC_DASH_CHAR, MC_DASH_CHAR, MC_NULL_CHAR}, // J
        {MC_DASH_CHAR, MC_DOT_CHAR,  MC_DASH_CHAR, MC_NULL_CHAR, MC_NULL_CHAR}, // K
        {MC_DOT_CHAR,  MC_DASH_CHAR, MC_DOT_CHAR,  MC_DOT_CHAR,  MC_NULL_CHAR}, // L 
        {MC_DASH_CHAR, MC_DASH_CHAR, MC_NULL_CHAR, MC_NULL_CHAR, MC_NULL_CHAR}, // M
        {MC_DASH_CHAR, MC_DOT_CHAR,  MC_NULL_CHAR, MC_NULL_CHAR, MC_NULL_CHAR}, // N
        {MC_DASH_CHAR, MC_DASH_CHAR, MC_DASH_CHAR, MC_NULL_CHAR, MC_NULL_CHAR}, // O
        {MC_DOT_CHAR,  MC_DASH_CHAR, MC_DASH_CHAR, MC_DOT_CHAR,  MC_NULL_CHAR}, // P
        {MC_DASH_CHAR, MC_DASH_CHAR, MC_DOT_CHAR,  MC_DASH_CHAR, MC_NULL_CHAR}, // Q
        {MC_DOT_CHAR,  MC_DASH_CHAR, MC_DOT_CHAR,  MC_NULL_CHAR, MC_NULL_CHAR}, // R
        {MC_DOT_CHAR,  MC_DOT_CHAR,  MC_DOT_CHAR,  MC_NULL_CHAR, MC_NULL_CHAR}, // S
        {MC_DASH_CHAR, MC_NULL_CHAR, MC_NULL_CHAR, MC_NULL_CHAR, MC_NULL_CHAR}, // T
        {MC_DOT_CHAR,  MC_DOT_CHAR,  MC_DASH_CHAR, MC_NULL_CHAR, MC_NULL_CHAR}, // U
        {MC_DOT_CHAR,  MC_DOT_CHAR,  MC_DOT_CHAR,  MC_DASH_CHAR, MC_NULL_CHAR}, // V
        {MC_DOT_CHAR,  MC_DASH_CHAR, MC_DASH_CHAR, MC_NULL_CHAR, MC_NULL_CHAR}, // W
        {MC_DASH_CHAR, MC_DOT_CHAR,  MC_DOT_CHAR,  MC_DASH_CHAR, MC_NULL_CHAR}, // X
        {MC_DASH_CHAR, MC_DASH_CHAR, MC_DOT_CHAR,  MC_DOT_CHAR,  MC_NULL_CHAR}, // Z
    };
    
    if (pSrc == NULL || pDst == NULL)
    {
        return MC_ERROR;
    }
    
    do
    {
        current = fgetc(pSrc); // Read next character from pSrc.
        
        if (current == MC_EOF)
        {
            // Do nothing, finished.
        }
        else if (current == MC_SPACE_CHAR) // Write space.
        {
            current = fputc(current, pDst); // EOF in case of error.
            if (current == MC_EOF)
            {
                result = MC_ERROR;
            }
            wasLastChar = false;
        }
        else if (current >= 'A' && current <= 'Z') // Write Morse code.
        {
        	if (wasLastChar)
        	{
        		// Write slash between each two characters.
	            if (fputc(MC_SLASH_CHAR, pDst) == MC_EOF)
	            {
	                result = MC_ERROR;
	            }
			}
            // Remove offset from ASCII. EOF returned in case of error.
            current = fputs(alphabet[current - MC_ASCII_A], pDst);
            if (current == MC_EOF)
            {
                result = MC_ERROR;
            }
            wasLastChar = true;
        }
        else // Error - unexpected character read.
        {
            result = MC_ERROR;
        }
    } while (current != MC_EOF && result != MC_ERROR);
    
    return result;
}


int MC_DecodeStream(MC_Node_t* pRoot, FILE* pSrc, FILE* pDst)
{
    char current = MC_NULL_CHAR;
    int result = MC_SUCCESS;
    MC_Node_t* pNode = pRoot;
    
    if (pRoot == NULL || pSrc == NULL || pDst == NULL)
    {
        return MC_ERROR;
    }
    
    do
    {
        current = fgetc(pSrc); // Read next character from pSrc.
        
        switch (current)
        {
            case MC_DOT_CHAR: // Move current node pointer.
                pNode = pNode->pDotChild;
                break;
            case MC_DASH_CHAR: // Move current node pointer.
                pNode = pNode->pDashChild;
                break;
            case MC_SPACE_CHAR: // Write current letter and space.
                current = fputc(pNode->value, pDst); // EOF in case of error.
                if (current == MC_EOF)
                {
                    result = MC_ERROR;
                }
                pNode = pRoot; // Reset tree position.
                // No break - next fputc will write the value of pRoot (space).
            case MC_SLASH_CHAR:  // End of letter - write current value.
                current = fputc(pNode->value, pDst); // EOF in case of error.
                if (current == MC_EOF)
                {
                    result = MC_ERROR;
                }
                pNode = pRoot; // Reset tree position.
                break;
            case MC_EOF: // Do nothing, finished.
                (void)fputc(pNode->value, pDst);
                break;
            default: // Error - unexpected character read.
                result = MC_ERROR;
                break;
        }
    } while (current != MC_EOF && result != MC_ERROR);
    
    return result;
}


int MC_CodeFile(const char* pSrcFileName,
                const char* pDstFileName,
                MC_Direction_t direction)
{
    int result = MC_SUCCESS;
    MC_Node_t root = {0};
    FILE* pSrc = NULL;
    FILE* pDst = NULL;
    
    // Open files.
    pSrc = fopen(pSrcFileName, "rb");
    if (pSrc == NULL)
    {
    	printf("Could not open source file!!!\n");
        return MC_ERROR;
    }
    
    pDst = fopen(pDstFileName, "wb");
    if (pDst == NULL)
    {
    	printf("Could not open destination file!!!\n");
        fclose(pSrc);
        return MC_ERROR;
    }
    
    switch(direction)
    {
        case MC_ENCODE:
            result = MC_EncodeStream(pSrc, pDst);
            break;
        case MC_DECODE:
            // Build the binary tree.
            result = MC_BuildTree(&root);
            if (result == MC_SUCCESS)
            {
                result = MC_DecodeStream(&root, pSrc, pDst);
            }
            // Clean up all dynamically allocated nodes.
            MC_Cleanup(root.pDotChild);
            MC_Cleanup(root.pDashChild);
            break;
        default:
            result = MC_ERROR;
            break;
    }
    
    // Close files.
    fclose(pSrc);
    fclose(pDst);
    
	if (result != MC_SUCCESS)
    {
    	printf("Error in encoding/decoding!!!\n");
	}
	
	printf("Success!!!\nYou can find result in output file.\n");
    return result;
}


int MC_EncodeFile(const char* pSrcFileName,
                  const char* pDstFileName)
{
    return MC_CodeFile(pSrcFileName,
                       pDstFileName,
                       MC_ENCODE);
}


int MC_DecodeFile(const char* pSrcFileName,
                  const char* pDstFileName)
{
    return MC_CodeFile(pSrcFileName,
                       pDstFileName,
                       MC_DECODE);
}
