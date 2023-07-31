#include "../Headers/Base64.h"
/**
 * @file Base64.h
 * @author Ian, Chen
 * @brief base 64 en(de)coding implementation
 * @version 1.0
 * @date 2023-07-31
 *
 *
 */



/**
 * Base64 encode; users don't feel like knowing the length of encoded data in advance. In return,
 * users shall free encoded data memory manually. If the return value is NULL, please don't free the returned memory.
 *
 * @param plainText unsigned char* The plain text which users feel like encoding
 * @param plainTextLength unsigned int The length of the plain text which users feel like encoding
 * @return unsigned char* The encoded text; users shall free encoded data memory manually; if the return value is NULL,
 * please don't free the returned memory
 */
unsigned char* base64Encode(unsigned char* plainText, unsigned int plainTextLength)
{
    unsigned int encodedLength = 4 * ((plainTextLength + 2) / 3);
    unsigned char* encodedData = (unsigned char*)malloc(encodedLength + 1);
    if (encodedData == NULL) {
        return NULL;
    }

    /** Converting three bytes (decimal) to four base64 alphabets */
    for (unsigned int i = 0, j = 0; i < plainTextLength;) {
        /** Taking three alphabets for handling*/
        unsigned int octFirst = i < plainTextLength ? plainText[i++] : 0;
        unsigned int octSecond = i < plainTextLength ? plainText[i++] : 0;
        unsigned int octThird = i < plainTextLength ? plainText[i++] : 0;

        /** According to binary theorem, the first one shall shift 16 bits, the second one is 8 bits and the last one is occupied 0 bit;
         *  therefore, the three alphabets in binary can be displayed in the following.
         */
        unsigned int triple = (octFirst << 0x10) + (octSecond << 0x08) + octThird;

        /** Calculating the one alphabet's index of base 64 in order
         *  where `triple >> 3 * 6` implies triple will right shift 18 bits (i.e., only 6 bits remained);
         *  `0x3F` (hex) implies the significant bits `00111111` (binary); According to the theorem above,
         *  users can obtain the six bits to obtain an alphabet in base 64 encoding
         */
        encodedData[j++] = (unsigned char)base64Alphabets[(triple >> 3 * 6) & 0x3F];
        encodedData[j++] = (unsigned char)base64Alphabets[(triple >> 2 * 6) & 0x3F];
        encodedData[j++] = (unsigned char)base64Alphabets[(triple >> 1 * 6) & 0x3F];
        encodedData[j++] = (unsigned char)base64Alphabets[(triple >> 0 * 6) & 0x3F];
    }

    /** Padding with '=' characters if necessary */
    for (unsigned int i = 0; i < (3 - plainTextLength % 3) % 3; i++) {
        encodedData[encodedLength - 1 - i] = '=';
    }

    encodedData[encodedLength] = '\0';
    return encodedData;
}

/**
 * Base64 decode; users don't feel like knowing the length of decoded data (the plain text) in advance. In return,
 * users shall free decoded data memory manually. If the return value is NULL, please don't free the returned memory.
 *
 * @param encodedData unsigned char* The encoded text which users feel like decoding
 * @param encodedLength unsigned int The length of the plain text which users feel like encoding
 * @return unsigned char* The plain text; users shall free decoded data memory manually;
 * if the return value is NULL, please don't free the returned memory
 */
unsigned char* base64Decode(unsigned char* encodedData, unsigned int encodedLength)
{
    unsigned int decodedLength = encodedLength / 4 * 3;
    if (encodedData == NULL) {
        return NULL;
    }

    if (encodedLength % 4 != 0) {
        return NULL;
    }

    /** Checking the last two characters; according to the base 64 encoding,
     * the `=` notation will occur twice at most
     */
    if (encodedData[encodedLength - 1] == '=') {
        (decodedLength)--;
    }
    if (encodedData[encodedLength - 2] == '=') {
        (decodedLength)--;
    }

    unsigned char* decodedData = (unsigned char*)malloc(decodedLength + 1);
    if (decodedData == NULL) {
        return NULL;
    }

    for (unsigned int i = 0, j = 0; i < encodedLength;) {
        unsigned int sextet_a = encodedData[i] == '=' ? 0 & i++ : getBase64Index(encodedData[i++]);
        unsigned int sextet_b = encodedData[i] == '=' ? 0 & i++ : getBase64Index(encodedData[i++]);
        unsigned int sextet_c = encodedData[i] == '=' ? 0 & i++ : getBase64Index(encodedData[i++]);
        unsigned int sextet_d = encodedData[i] == '=' ? 0 & i++ : getBase64Index(encodedData[i++]);

        /** Like encoding, four alphabets are treated in each round in base64 encoding */
        unsigned int triple = (sextet_a << 3 * 6) + (sextet_b << 2 * 6) + (sextet_c << 1 * 6) + (sextet_d << 0 * 6);

        /** Like encoding, obtaining results by using significant bits */
        if (j < decodedLength) {
            decodedData[j++] = (triple >> 2 * 8) & 0xFF;
        }
        if (j < decodedLength) {
            decodedData[j++] = (triple >> 1 * 8) & 0xFF;
        }
        if (j < decodedLength) {
            decodedData[j++] = (triple >> 0 * 8) & 0xFF;
        }
    }

    decodedData[decodedLength] = '\0';
    return decodedData;
}


/**
 *  To obtain the character from the given alphabet in base 64 encoding
 *
 * @param alphabet unsigned char The alphabet in base 64 encoding
 * @return unsigned int The decimal value of the ASCII code
 */
unsigned int getBase64Index(unsigned char alphabet)
{
    int returnedValue = 0;

    if (alphabet >= (unsigned char)'A' && alphabet <= (unsigned char)'Z') {
        returnedValue = alphabet - (unsigned char)'A';
    } else if (alphabet >= (unsigned char)'a' && alphabet <= (unsigned char)'z') {
        returnedValue = alphabet - (unsigned char)'a' + 26;
    } else if (alphabet >= (unsigned char)'0' && alphabet <= (unsigned char)'9') {
        returnedValue = alphabet - (unsigned char)'0' + 52;
    } else if (alphabet == (unsigned char)'+') {
        returnedValue = 62;
    } else if (alphabet == (unsigned char)'/') {
        returnedValue = 63;
    }

    return returnedValue;
}