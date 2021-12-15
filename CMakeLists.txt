cmake_minimum_required(VERSION 3.10)
project(feup-aed)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
		src/Airline.cpp
		src/Airport.cpp
		src/Baggage.cpp
		src/Cart.cpp
		src/Flight.cpp
		src/Passenger.cpp
		src/Plane.cpp
		src/Service.cpp
		src/Ticket.cpp
		src/Airline.h
		src/Airport.h
		src/Baggage.h
		src/Cart.h
		src/Flight.h
		src/Passenger.h
		src/Plane.h
		src/Service.h
		src/Ticket.h
		src/Date.cpp
		src/Date.h src/App.cpp src/App.h)

set(TEST_FILES
		tests/AirlineTest.cpp
		tests/PassengerTest.cpp
		tests/CartTest.cpp
		tests/PlaneTest.cpp)

include_directories(src)

add_subdirectory(tests/googletest)
include_directories(tests/googletest/googletest/include)
include_directories(tests/googletest/googlemock/include)

add_executable(${CMAKE_PROJECT_NAME}_run main.cpp ${TEST_FILES} ${SOURCE_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME}_run gtest gtest_main)



