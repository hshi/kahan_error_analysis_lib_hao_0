set(test_exe kahanerrtest)

file(GLOB test_srcs "*.cpp")

add_executable(${test_exe} ${test_srcs})

target_link_libraries(${test_exe} kahanerrhao)

install(TARGETS ${test_exe}  DESTINATION test)
