int main(int argc, char** argv)
{
     unsigned char data[] = "Hello, World!";
     unsigned int dataLength = (unsigned int)strlen((const char*)data);
   /** Base64 encode */
    unsigned char* encodedData = NULL;
    encodedData = base64Encode(data, dataLength);
    if (encodedData != NULL) {
        printf("Encoded: %s\n", encodedData);
        /** Base64 decode*/
        unsigned int encodedLength = (unsigned int)strlen((char*)encodedData);
        unsigned char* decodedData = base64Decode(encodedData, encodedLength);
        if (decodedData != NULL) {
            printf("Decoded: %s\n", decodedData);
            free(decodedData);
        }
        free(encodedData);
    }

}