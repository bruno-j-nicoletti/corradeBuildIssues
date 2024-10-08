add_library(A STATIC
  "src/bnsA.cpp"
  )

target_include_directories(A PUBLIC include)

add_subdirectory(test)
