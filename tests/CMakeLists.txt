find_package(GTest 1.12.1 REQUIRED)

add_executable(
        tests
        mocks/MockResource.h
        src/GlobalTest.cpp src/GlobalTest.h
        src/resource/NullResourceTest.cpp src/resource/NullResourceTest.h
        src/resource/NodeResourceTest.cpp src/resource/NodeResourceTest.h
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
