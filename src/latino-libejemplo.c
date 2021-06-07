
// Necesario para Windows
#ifdef _WIN32
// Especifica que se generar� una libreria DLL
#define LATINO_BUILD_AS_DLL
#endif

// Indica que esta libreria dinamica es para latino
#define LATINO_LIB

// incluir la cabecera de latino
#include <latino.h>

// se define el nombre de la libreria que se importara en latino
// incluir("libejemplo")
#define NOMBRE_LIB "libejemplo"

// se crea una funcion static void que reciba la maquina virtual de latino
static void lat_suma(lat_mv *mv)
{
  // desapila los parametros que recibe de latino
  // estos vienen en orden inverso ej.
  // suma(a, b)
  // primero se desapila el valor de b
  // postriormente se desapila el valor de a
  lat_objeto *b = latC_desapilar(mv);
  lat_objeto *a = latC_desapilar(mv);

  // estos valores se recibe como objeto de latino
  // por lo cual hay que convertilos a numeros con la funcion latC_checar_numerico
  double _b = latC_checar_numerico(mv, b);
  double _a = latC_checar_numerico(mv, a);

  // hago cualquier operacion en C
  double r = _a + _b;

  // y para regresar el resultado a latino, lo tengo que apilar con funciones que inician con latC_apilar_*
  latC_apilar_double(mv, r);
}

// Se crea la varibale para especificar las funciones que se exportarar a latino
static const lat_CReg lib_ejemplo[] = {
    // nombre_funcion_en_latino, nombre_funcion_c, numero_de_parametros
    {"suma", lat_suma, 2},
    // esta linea es necesaria para que detenga la importacion de funciones
    {NULL, NULL, 0}};

// El nombre de esta funcion debe de ser latC_abrir_liblatino_ seguido del nombre de la libreria en .dll o .so
// En este caso definida en NOMBRE_LIB
LATINO_API void latC_abrir_liblatino_libejemplo(lat_mv *mv)
{
  // Invocar a esta funcion para que cargue las funciones de C en latino
  latC_abrir_liblatino(mv, NOMBRE_LIB, lib_ejemplo);
}