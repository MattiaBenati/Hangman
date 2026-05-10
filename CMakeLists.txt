cmake_minimum_required(VERSION 4.0)

# impostare NOME del progetto
set(PROJECT_NAME Hangman)

project(${PROJECT_NAME} C)
set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME}
        src/main.c
        src/core/aggiornamento.c
        src/ui/console.c
        src/ui/disegno.c
        src/core/gioco.c
        src/ui/grafica.c
        src/core/inizializzazione.c
        src/core/input.c
        src/core/verifica.c
)

# include il file di risorse Windows (.rc) per incorporare icona e informazioni di versione nell'eseguibile finale
set_source_files_properties(assets/resource.rc PROPERTIES LANGUAGE RC)
target_sources(${PROJECT_NAME} PRIVATE assets/resource.rc)

# aggiunge la cartella degli header ai search paths
target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)