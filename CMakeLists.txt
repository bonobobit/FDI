cmake_minimum_required(VERSION 3.20)
project(FDI C)

set(CMAKE_C_STANDARD 11)

# Cerca automaticamente tutti i file .c in tutte le sottocartelle
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*/*.c")

foreach(SRC_FILE ${SOURCES})
    # Estrae il nome del file senza estensione (es. indovina-numero)
    get_filename_component(EXE_NAME ${SRC_FILE} NAME_WE)

    # Estrae il nome della cartella padre (es. 2026-11-02) per evitare conflitti se due giorni hanno file con lo stesso nome
    get_filename_component(DIR_PATH ${SRC_FILE} DIRECTORY)
    get_filename_component(DIR_NAME ${DIR_PATH} NAME)

    # Crea un eseguibile chiamato "2026-11-02_indovina-numero"
    add_executable("${DIR_NAME}_${EXE_NAME}" ${SRC_FILE})
endforeach()