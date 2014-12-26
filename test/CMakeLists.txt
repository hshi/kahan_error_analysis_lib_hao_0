set(kahanerr_test_srcs error_analysis_test.cpp  kahan_test.cpp test_all.cpp)

add_executable(kahanerrtest ${kahanerr_test_srcs})

target_link_libraries(kahanerrtest kahanerrhao)

install(TARGETS kahanerrtest  DESTINATION test)
