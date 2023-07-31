#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include "../../Headers/Base64.h"

void Test_Base64_Encoding(void** State);
void Test_Base64_Decoding(void** State);
void Test_Base64_Encoding_Decoding(void** State);