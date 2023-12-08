cmake_minimum_required(VERSION 3.25)
project(Easy_Trip C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Easy_Trip
        ArrayStack.h
        Bus.h
        LinkedQueue.h
        Node.h
        Passenger.h
        QueueADT.h
        StackADT.h
        Station.h)
