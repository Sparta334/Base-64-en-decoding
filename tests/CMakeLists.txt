
add_executable(Test
    ./Main.c
    ./Sources/Test_Base64.c
)
target_include_directories(Test PUBLIC ./Headers)

target_link_libraries(Test
    Base64Lib
    cmocka
)