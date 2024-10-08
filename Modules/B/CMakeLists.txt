add_library(B STATIC
  "src/bnsB.cpp"
  )

target_include_directories(B PUBLIC include)

add_subdirectory(test)
