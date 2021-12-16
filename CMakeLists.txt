cmake_minimum_required(VERSION 3.10)
project(feup-aed)

set(CMAKE_CXX_STANDARD 11)

set(CREATE_EXE TRUE)

set(SOURCE_FILES
		src/Airline.cpp
		src/Airport.cpp
		src/App.cpp
		src/Baggage.cpp
		src/Cart.cpp
		src/Flight.cpp
		src/Passenger.cpp
		src/Plane.cpp
		src/Service.cpp
		src/Ticket.cpp
		src/Airline.h
		src/Airport.h
		src/App.h
		src/Baggage.h
		src/Cart.h
		src/Flight.h
		src/Passenger.h
		src/Plane.h
		src/Service.h
		src/Ticket.h
		src/Date.cpp
		src/Date.h)

set(TEST_FILES
		tests/AirlineTest.cpp
		tests/AirportTest.cpp
		tests/AppTest.cpp
		tests/CartTest.cpp
		tests/PassengerTest.cpp
		tests/PlaneTest.cpp)

include_directories(src)

if(CMAKE_BUILD_TYPE MATCHES Debug)
	add_subdirectory(tests/googletest)
	include_directories(tests/googletest/googletest/include)
	include_directories(tests/googletest/googlemock/include)

	add_executable(${CMAKE_PROJECT_NAME}_run mainTest.cpp ${TEST_FILES} ${SOURCE_FILES})

	target_link_libraries(${CMAKE_PROJECT_NAME}_run gtest gtest_main)
	message("Debug mode")
endif()

if (CMAKE_BUILD_TYPE MATCHES Release)
	add_executable(${CMAKE_PROJECT_NAME}_run main.cpp ${SOURCE_FILES})
	message("Release mode")
endif()
