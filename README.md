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

#### Requisitos para correr los tests:

  -  python
  -  requests (pip install requests)


#### Corriendo los tests:

 - Para compilar y correr los tests de la rest api: Siatuarse en /tests/rest y ejecutar "python run_test.py"
 - Para compilar y correr el resto de los tests: `./build.sh test`

#### Requisitos para correr la documentación técnica y del usuario:

 - Instalar Sphinx: `sudo pip install -U Sphinx`

#### Generando el html de la documentación:

 - Pararse en la ruta de la documentación y ejecutar: `make html`
 - Para limpiar: `make clean`
 
#### Para generar el HTML de la documentación del codigo:

 - Requisitos: `sudo apt-get install doxygen`
 - Pararse en la ruta de la documentación (`docs/doxygen`) y ejecutar: `doxygen`
 
