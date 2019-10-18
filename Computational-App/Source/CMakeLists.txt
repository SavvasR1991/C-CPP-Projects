cmake_minimum_required(VERSION 2.8.9)
project(CalculatingProgramms)

file(GLOB SOURCES1 "Carmichael_Numbers/*.c")
add_executable(Carmichael ${SOURCES1})

file(GLOB SOURCES2 "Happy_Primes/*.c")
add_executable(HappyPrimes ${SOURCES2})

file(GLOB SOURCES3 "Calculator/*.c")
add_executable(Calculator ${SOURCES3})

file(GLOB SOURCES4 "Valid_Emails_Check/*.c")
add_executable(ValidEmailsCheck ${SOURCES4})

target_link_libraries(Carmichael m)


