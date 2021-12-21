cmake_minimum_required(VERSION 3.10)
project(feup-aed)

set(CMAKE_CXX_STANDARD 11)

set(CREATE_EXE TRUE)

set(SOURCE_FILES
		src/Airline/Airline.cpp
		src/Airline/Airport.cpp		
		src/Airline/Baggage.cpp
		src/Airline/Cart.cpp
		src/Airline/Date.cpp
		src/Airline/Flight.cpp
		src/Airline/Passenger.cpp
		src/Airline/Plane.cpp
		src/Airline/Service.cpp
		src/Airline/Ticket.cpp
		src/Airline/Airline.h
		src/Airline/Airport.h
		src/Airline/Baggage.h
		src/Airline/Cart.h
		src/Airline/Date.h
		src/Airline/Flight.h
		src/Airline/Passenger.h
		src/Airline/Plane.h
		src/Airline/Service.h
		src/Airline/Ticket.h

		src/App/App.cpp
		src/App/AppAirport.cpp
		src/App/AppCart.cpp
		src/App/AppFlight.cpp
		src/App/AppHelp.cpp
		src/App/AppPassenger.cpp
		src/App/AppPlane.cpp
		src/App/AppTicket.cpp
		src/App/App.h
		)

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
