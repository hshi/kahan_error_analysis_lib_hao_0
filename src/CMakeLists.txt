set(src_lib kahanerrhao)

set(srcs
        ../inc/error_analysis.h
        ../inc/kahan.h
        ../inc/thread_error_analysis.h
        error_analysis.cpp
        kahan.cpp
        thread_error_analysis.cpp
        )

add_library(${src_lib} STATIC ${srcs})

install(TARGETS ${src_lib}  DESTINATION lib)
