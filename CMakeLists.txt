cmake_minimum_required(VERSION 2.8)
project(test)

include(ExternalProject)

if (${ANDROID_ABI} STREQUAL "arm64-v8a")
    set(target_autotools "aarch64-linux-android")
endif()
if (${ANDROID_ABI} STREQUAL "armeabi-v7a")
    set(target_autotools "armv7a-linux-androideabi")
endif()
if (${ANDROID_ABI} STREQUAL "x86_64")
    set(target_autotools "x86_64-linux-android")
endif()
if (${ANDROID_ABI} STREQUAL "x86")
    set(target_autotools "i686-linux-android")
endif()

set(stunnel_libfolder "/stunnel/src/stunnel-build/src/.libs")


ExternalProject_Add(stunnel
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    CONFIGURE_COMMAND . ${CMAKE_CURRENT_SOURCE_DIR}/vars/android-sdk-path && . ${CMAKE_CURRENT_SOURCE_DIR}/vars/vars-${ANDROID_ABI} && export SSL_ARCHIVE=/root/MP/stunnel-android/aarch64-linux-android/install/lib && ${CMAKE_CURRENT_SOURCE_DIR}/configure --with-ssl=/root/MP/stunnel-android/aarch64-linux-android/install --disable-silent-rules --host ${target_autotools} 
    BUILD_COMMAND make all # ${MAKE}
    PREFIX "stunnel"
    INSTALL_COMMAND cmake -E echo "moving the built libraries to build folder" &&
    mv ${CMAKE_CURRENT_BINARY_DIR}${stunnel_libfolder}/libstunnel.so ${CMAKE_CURRENT_BINARY_DIR} &&
    mv ${CMAKE_CURRENT_BINARY_DIR}${stunnel_libfolder}/libstunnel.a ${CMAKE_CURRENT_BINARY_DIR}
    )

