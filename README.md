#### Requisitos (instalar via `sudo apt-get install`):
 - g++
 - cmake
 - libsnappy-dev
 - libgflags-dev
 - zlib1g-dev
 - libbz2-dev

#### Compilando y corriendo el proyecto:
 - Para compilar el proyecto: `./build.sh`
 - Para forzar un nuevo build desde cero: `./build.sh clean`
 - Para compilar y correr los tests: `./build.sh test`
 - Para ejecutar el servidor: `./build.sh run`

Los argumentos extra que se pasen a 'test' o 'run' se forwardean a los programas que ejecutan.
