set(kahanerr_srcs error_analysis.cpp)

add_library(kahanerrhao STATIC ${kahanerr_srcs})

install(TARGETS kahanerrhao DESTINATION lib)
