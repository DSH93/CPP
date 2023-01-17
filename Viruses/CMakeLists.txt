cmake_minimum_required(VERSION 3.23)
project(HW3)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW3 main.cpp Virus.cpp Virus.h VirusPopu.cpp VirusPopu.h GenerationsRace.cpp GenerationsRace.h Queue.cpp ../HW4/noProblem/Queue.h ../HW4/noProblem/Lentivirus.cpp ../HW4/noProblem/Lentivirus.h ../HW4/noProblem/Mimivirus.cpp ../HW4/noProblem/Mimivirus.h ../HW4/noProblem/Papilloma.cpp ../HW4/noProblem/Papilloma.h)
