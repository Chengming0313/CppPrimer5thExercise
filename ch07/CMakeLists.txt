aux_source_directory(. SRC)

#message(${SRC})

foreach(CPPFILE ${SRC})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" CPP ${CPPFILE})
#    message(${CPP})
    add_executable(${CPP} ${CPPFILE} Sales_data_test.cpp ../ch15/ex15_3_Quote.h ../ch15/ex15_3_test.cpp)
endforeach(CPPFILE)
