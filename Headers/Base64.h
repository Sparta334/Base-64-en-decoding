/**
 * @file Base64.h
 * @author Ian, Chen
 * @brief base 64 en(de)coding definition
 * @version 1.0
 * @date 2023-07-31
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Base 64 definition*/
static const unsigned char base64Alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

unsigned char* base64Encode(unsigned char*, unsigned int);
unsigned char* base64Decode(unsigned char*, unsigned int);
unsigned int getBase64Index(unsigned char);