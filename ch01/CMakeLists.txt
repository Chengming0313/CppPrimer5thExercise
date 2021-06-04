aux_source_directory(. SRC)

message(${SRC})

foreach(CPPFILE ${SRC})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" CPP ${CPPFILE})
    message(${CPP})
    add_executable(${CPP} ${CPPFILE})
endforeach(CPPFILE)


