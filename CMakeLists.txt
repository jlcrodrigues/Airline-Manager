cmake_minimum_required(VERSION 3.10)
project(feup-aed)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
		src/Airport.cpp
		src/Baggage.cpp
		src/Cart.cpp
		src/Flight.cpp
		src/Passenger.cpp
		src/Plane.cpp
		src/Service.cpp
		src/Ticket.cpp
		src/Airport.h
		src/Baggage.h
		src/Cart.h
		src/Flight.h
		src/Passenger.h
		src/Plane.h
		src/Service.h
		src/Ticket.h)

set(TEST_FILES
		tests/PassengerTest.cpp
		tests/CartTest.cpp)

include_directories(src)

add_subdirectory(tests/googletest)
include_directories(tests/googletest/googletest/include)
include_directories(tests/googletest/googlemock/include)

add_executable(${CMAKE_PROJECT_NAME}_run main.cpp ${TEST_FILES} ${SOURCE_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME}_run gtest gtest_main)


# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()
    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
        message("Doxygen build started")
        add_custom_target(Doxygen ALL
        COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
else(DOXYGEN_FOUND)
message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)
