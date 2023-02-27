cmake_minimum_required(VERSION 2.8)
project(test)
include(ExternalProject)

execute_process (
    COMMAND bash -c ". ${CMAKE_CURRENT_SOURCE_DIR}/vars/vars-${ANDROID_ABI}"
)

ExternalProject_Add(stunnel
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/configure --with-ssl=/root/MP/stunnel-android/aarch64-linux-android/install --disable-silent-rules --host aarch64-linux-android 
    BUILD_COMMAND ${MAKE})

