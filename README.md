## latino-lib-ejemplo
Ejemplo minimo para crear una libreria para [latino](https://github.com/lenguaje-latino/latino) en C.
En el archivo src/latino-libejemplo.c se encuentra comentado con lo minimo que se requiere.

## Instalación

### Linux / Mac

#### Prerequisitos

Tener instalado:
[latino](https://github.com/lenguaje-latino/latino)
[cmake](https://cmake.org/download/)

Ejecutar lo siguiente en bash:

```
git clone https://github.com/lenguaje-latino/latino-lib-ejemplo
cd latino-lib-ejemplo
cmake .
make
sudo make install
```

### Windows

#### Prerequisitos

Tener instalado:
[latino](https://github.com/lenguaje-latino/latino)
[cmake](https://cmake.org/download/)
[visual studio](https://visualstudio.microsoft.com/es/vs/community/)

Ejecutar lo siguiente en cmd:

```
git clone https://github.com/lenguaje-latino/latino-lib-ejemplo
cd latino-lib-ejemplo
md build
cd build
cmake -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Release ..\
```

Abrir con visual studio 2019 y compilar la solucion latino-lib-ejemplo.sln 
generada en la carpeta build/

Compilar el proyecto en modo Release.

Para instalar la libreria abrir visual studio con permisos de administrador
Generar el proyecto de INSTALL.vcxproj dando clic derecho sobre el proyecto y build
o copiar la libreria .dll generada con este proyecto en la ruta de instalación
de latino. 
Por ejemplo:

`C:/Program Files/Latino/bin`

### MSYS

Abrir un terminal de MSYS y correr lo siguiente.

```
pacman -S libreadline libreadline-devel
git clone https://github.com/lenguaje-latino/latino-lib-ejemplo
cd latino-lib-ejemplo
cmake .
make
make install
```

### Uso de esta librería en código latino

```
// incluye el modulo en latino
incluir("libejemplo")

x = libejemplo.suma(1, 1.5)

escribir(x)
```

ver ejemplo.lat

### Ejecutar el ejemplo:
`latino ejemplo.lat`


### Dependecias

Ninguna

#### Cualquier aportación o sugerencia es bienvenida
