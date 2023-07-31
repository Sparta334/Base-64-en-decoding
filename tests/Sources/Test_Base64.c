#include "../Headers/Test_Base64.h"

void Test_Base64_Encoding(void **State)
{
    unsigned char sourceString[] = "Hello World";
    unsigned char answerString[] = "SGVsbG8gV29ybGQ=";
    unsigned int sourceStringLength = (unsigned int)(strlen((unsigned char *)sourceString));

    unsigned char* resultString = base64Encode(sourceString, sourceStringLength);
    assert_string_equal(resultString, answerString);

    free(resultString);
}

void Test_Base64_Decoding(void **State)
{
    unsigned char sourceString[] = "SSBhbSBTZXh5IEd1eQ==";
    unsigned char answerString[] = "I am Sexy Guy";
    unsigned int sourceStringLength = (unsigned int)(strlen((unsigned char *)sourceString));

    unsigned char* resultString = base64Decode(sourceString, sourceStringLength);
    assert_string_equal(resultString, answerString);

    free(resultString);
}

void Test_Base64_Encoding_Decoding(void **State)
{

    unsigned char sourceString[] = "Hello World";
    unsigned char answerString[] = "SGVsbG8gV29ybGQ=";
    unsigned int sourceStringLength = (unsigned int)(strlen((unsigned char *)sourceString));

    unsigned char* resultString = base64Encode(sourceString, sourceStringLength);
    assert_string_equal(resultString, answerString);

    unsigned char* resultString2 = base64Decode(resultString, (unsigned int)(strlen((unsigned char *)resultString)));

    assert_string_equal(resultString2, sourceString);

    free(resultString);
    free(resultString2);
}
