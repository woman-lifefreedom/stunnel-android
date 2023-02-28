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


ExternalProject_Add(stunnel
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    CONFIGURE_COMMAND . ${CMAKE_CURRENT_SOURCE_DIR}/vars/android-sdk-path && . ${CMAKE_CURRENT_SOURCE_DIR}/vars/vars-${ANDROID_ABI} && ${CMAKE_CURRENT_SOURCE_DIR}/configure --with-ssl=/root/MP/stunnel-android/aarch64-linux-android/install --disable-silent-rules --host ${target_autotools} 
    BUILD_COMMAND make all # ${MAKE}
    INSTALL_COMMAND cmake -E echo "Skipping install step."
    )

