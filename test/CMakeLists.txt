set(test_exe kahanerrtest)

set(test_srcs
        ../inc/error_analysis.h
        ../inc/kahan.h
        ../inc/thread_error_analysis.h
        error_analysis_test.cpp
        kahan_test.cpp
        test_all.cpp
        thread_error_analysis_test.cpp
        )

add_executable(${test_exe} ${test_srcs})

target_link_libraries(${test_exe} kahanerrhao)

install(TARGETS ${test_exe}  DESTINATION test)
