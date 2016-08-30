set(header
        ../inc/error_analysis.h
        ../inc/kahan.h
        ../inc/thread_error_analysis.h
        )

#For double_error_analysis
add_executable(double_error_analysis double_error_analysis.cpp ${header})
target_link_libraries(double_error_analysis kahanerrhao)
install(TARGETS double_error_analysis  DESTINATION bin)

#For complex_double_error_analysis
add_executable(complex_double_error_analysis complex_double_error_analysis.cpp ${header})
target_link_libraries(complex_double_error_analysis kahanerrhao)
install(TARGETS complex_double_error_analysis DESTINATION bin)
