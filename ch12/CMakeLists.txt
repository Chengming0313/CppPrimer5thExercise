aux_source_directory(. SRC)

#message(${SRC})

foreach(CPPFILE ${SRC})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" CPP ${CPPFILE})
#    message(${CPP})
    add_executable(${CPP} ${CPPFILE})
endforeach(CPPFILE)

target_sources(ex12_27_30_test
        PRIVATE
        ex12_27_30.cpp)

target_sources(ex12_32_test
        PRIVATE
        ex12_32.cpp)

target_sources(ex12_33_test
        PRIVATE
        ex12_33.cpp)
