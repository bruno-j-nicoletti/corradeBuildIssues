add_executable(BTest
  "src/unitTest.cpp"
)

set_property(TARGET BTest PROPERTY OUTPUT_NAME unitTest)

if (DEFINED EMSCRIPTEN)
  target_link_options(BTest
                      PUBLIC -sEXIT_RUNTIME)
endif()

target_link_libraries(BTest
    PRIVATE
    B
    Catch2::Catch2WithMain
)

add_test(NAME B COMMAND BTest)
