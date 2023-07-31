
/**
 * @file Main.c
 * @author Ian.Chen
 * @brief Unit test for the library.
 * @version 1.0
 * @date 2023-07-03
 *
 */

#include "./Headers/Test_Base64.h"

const struct CMUnitTest tests[] = {

    cmocka_unit_test(Test_Base64_Encoding),
    cmocka_unit_test(Test_Base64_Decoding),
    cmocka_unit_test(Test_Base64_Encoding_Decoding),
    
    

};

int main(){

    return cmocka_run_group_tests(tests, NULL, NULL);

}