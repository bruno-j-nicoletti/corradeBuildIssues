add_executable(ATest
  "src/unitTest.cpp"
)

set_property(TARGET ATest PROPERTY OUTPUT_NAME unitTest)

if (DEFINED EMSCRIPTEN)
  target_link_options(ATest
                      PUBLIC -sEXIT_RUNTIME)
endif()

target_link_libraries(ATest
    PRIVATE
    A
    Catch2::Catch2WithMain
)

add_test(NAME A COMMAND ATest)
