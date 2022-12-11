find_package(GTest 1.12.1 REQUIRED)

add_executable(
        tests
        src/GlobalTest.cpp src/GlobalTest.h
)

target_link_libraries(
        tests
        PRIVATE
        GTest::gtest GTest::gmock GTest::gmock_main
        lib
)

target_compile_definitions(
        tests
        PRIVATE
        RESOURCE_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/resources/\"
)
