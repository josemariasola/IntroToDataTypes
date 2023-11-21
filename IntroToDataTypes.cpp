/*
Definición de tipo de dato.
Tipos de datos primitivos 
(definición de los conjuntos de valores y operaciones aplicadas a los mismos.
Definición y alcance de tipos de datos simples, 
ordinales y no ordinales, 
introducción al concepto de cadenas de caracteres..”
*/
    
#include<cassert>                     //aseveraciones en tiempo de ejecución
#include<type_traits>                 //is_same
#include<string>                      //string 
using std::string;
using namespace std::string_literals; //""s

template<typename T, typename E>
constexpr void static_assert_same(const E&) {
    static_assert(std::is_same_v<T, E>);
}

template<typename T, typename E>
constexpr void static_assert_not_same(const E&) {
    static_assert(not std::is_same_v<T, E>);
}

int main(){
    {//Intro
        // TD = CV + CO
        // Un tipo de dato define un conjunto de posible valores y un conjunto de operaciones sobre esos valores.
        // Un objetos de almacenamiento es un área de memoria que mantiene valores de cierto tipo.
        // Un valor es una secuencia de bits que se interpretan según un tipo.
        
        // Para qué
        // Cada tipo primitivo o funadamental se corresponde directamente a prestaciones del hardware y tiene un tamaño fijo que determina el conjunto de valores que puede almacenar.  
        // Una variable, es un objeto nombrado; próxima clase.
    }

    {//Ecuaciones e Inecuaciones ==> Aseveraciones.
     //Confirmación de conceptos y pruebas unitarias
        static_assert( 0 == 0 );
        static_assert( 0 != 1 );
        static_assert( 0 <  1 );
        static_assert( 1 >  0 );
        static_assert( 0 <= 1 );
        static_assert( 1 >= 0 );
    }
    
    {//Tipos Primitivos o Fundamentales
        //Valores Literales y su Tipo de Dato
        //Otras notaciones, mismo tipo
        //Conjunto de Valores y Conunto de Operaciones
        
        {//Tipos Enteros
            //ℤ Enteros ==> int
            static_assert_same<int>(   21 );
            static_assert_same<int>(    0 );
            static_assert_same<int>( -107 ); //operador unario
            //Separaradores y bases
            static_assert( 1000000 == 1'000'000   );
            static_assert(      15 == 0xF         ); //0XF 0xF 0xf
            static_assert(      15 == 017         );
            static_assert(      15 == 0b00001111  );
            static_assert(      15 == 0b0000'1111 ); 
            //Operaciones
            static_assert( 2 * 3 + 1 == 1 + 2 * 3 ); // Precedencia
            static_assert(   21 - 42 <  0         ); // Negativos
            static_assert(     7 / 2 == 3         ); // Operaciones cerradas
            static_assert(     7 % 2 == 1         ); 
                      
            //ℕ Natruales ==> unsigned    
            static_assert_same<unsigned>(  0u);
            static_assert_same<unsigned>( 42u);
            //Operaciones
            static_assert(   0u - 1u > 0u        ); // Overflow
            static_assert(   0u - 1u == UINT_MAX ); // std::numeric_limits<unsigned>::max()
            static_assert( 19u % 12u == 7u       ); // Aritmética módulo N

            //Trabajo clase #1: Codifique una ecuación que muestre 
            //la descomposición de 30 en sus factores primos.
            static_assert( 30 == 2 * 3 * 5 );
        }
 
        {//ℝ Reales ==> double
            static_assert_same<double>(  0.0  );
            static_assert_same<double>(  3.14 );
            //Notación científica
            static_assert(   1e3 == 1000.0    );
            static_assert(  1e-3 ==    0.001  );
            //Conjunto: mismas que enteros, pero sin incluyen módulo/resto
            static_assert(  7.0 / 2.0 == 3.5  ); // Operación cerrada
            //Representación no exacta: Flotantes binarios IEEE 768-2009
            static_assert( 10.0 != 10.0 * 0.1 );
            static_assert( 10.0 != 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
        
            // Para el próximo encuentro A: Lea el material de estudio de Arquitectura de Computadoras y explique porque la representación de números flotantes en IEEE 768-2009 no es exacta.

            // Trabajo en clase #2: ¿Cúal tipo utilizaría para representar la plata (magnitudes monetarias)? Justifique.
        }

        {//𝔹 Booleanos ==> bool
            static_assert_same<bool>(  true  );
            static_assert_same<bool>(  false );
            //Operaciones
            static_assert(   (      not true   ) == false ); 
            static_assert(   (   true or false ) == true  ); // precedencia ==
            static_assert(   ( false and true  ) == false );
            // Trabajo en clase #3: Codifique las ecuaciones para la tabla de verdad de NAND. Revisar el material de estudio de Lógica y Estructuras Discretas.
            static_assert( not( false or false ) == true  ); // precedencia not
            static_assert( not( false or true  ) == false );
            static_assert( not(  true or false ) == false );
            static_assert( not(  true or true  ) == false );
        }
    
        {//𝚺 Alfabeto ASCII ó Set de Caracteres del Sistema ==> char
            static_assert_same<char>('A');
            static_assert_same<char>('@');
            static_assert_same<char>('1');
            static_assert('A' == 65);
            static_assert('A' == '\x41');
            static_assert('A' == '\101');
            //Trabajo en clase #4: Debatir y proponer cuál es el conjunto de operaciones para caracteres.
            //Categorización, depende del locale (cultura) seleccionada
            assert(     std::isdigit('1') );
            assert(     std::isupper('A') );
            assert(     std::islower('a') );
            assert(     std::isalpha('A') );
            assert(     std::isalpha('a') );
            assert( not std::isdigit('C') );
            assert( not std::isupper('y') );
            assert( not std::islower('Y') );
            assert( not std::isalpha('@') );
            assert( not std::isalpha('1') );
            assert(     std::isalnum('A') );
            assert(     std::isalnum('a') );
            assert( not std::isalnum(' ') );
            assert( not std::isalnum('@') );
            //Conversión, también depende del locale
            assert( std::toupper('a') == 'A' );
            assert( std::tolower('A') == 'a' );
            //Presentación de Tipos Ordinales
            static_assert(   'A' + 1 == 'B'        );
            static_assert(       'A' == 'C' - 2    );
            static_assert( 'C' - 'A' == 2          );
            static_assert( 'A' < 'B' and 'B' < 'C' );
            static_assert( 'Z' > 'Y' and 'Y' > 'X' );
        }
        
        {//Información complementaria: Alfabeto Unicode
            static_assert_same<char32_t>(U'😀');
            static_assert(        U'😀' == 128'512 );
            static_assert(        U'😀' == 0x1F600 );
            static_assert( sizeof U'😀' == 4       ); // bytes en memoria   
            static_assert(   sizeof 'A' == 1       ); // bytes en memoria   
        }
    }

    {//Clasificaciones
        // Ordinales
        //     Contables ==> Mapeo con Enteros
        //     No contables ==> Se pueden disponer en una escala continua
        // No ordinales
        //     Nominales
        //
        // Cualitativos: Nominales y Ordinales
        //     Estado Civil    Nivel Education
        // Cuantitaivos: Discretos y Continuos
        //     Contar: Estudiantes presentes, No-contables: Velocidad de un vehículo
        // Para la próxima clase #1: Leer "Enumeraciones: Construcción de Tipo por Extensión" y asociarlo con los Tipos Cualitativos Nominales
    }

    {//Tipos Simples: ¿Qué tienen en común? ==> Átomicos
        void( true );
        void(  'A' );
        void(    7 );
        void(   0u );
        void( 3.14 );

        static_assert( sizeof true >= 1        ) ; // 1
        static_assert( sizeof  'A' == 1        ) ; // 1
        static_assert( sizeof    7 >= 1        ) ; // 4
        static_assert( sizeof   0u == sizeof 7 ) ; // 4
        static_assert( sizeof 3.14 >= 1        ) ; // 8
        
        //Tipos Compuestos, secuencias de elementos, secuencia de caracteres: Cadenas ó Strings
    }

    {//𝚺* Cadena de Caracteres ==> string // Kleene lo van a profundizar en SSL.
        static_assert_same<string>( "AED"s);
        static_assert_same<string>("FRBA"s);
        static_assert_same<string>(    ""s);
        //𝚺* Operaciones
        static_assert(           "AED"s.length() == 3             );
        static_assert(          "FRBA"s.length() == 4             );
        static_assert(              ""s.length() == 0             );
                             
        static_assert(       "video"s + "juego"s == "videojuego"s );
        static_assert(    "videojuego"s.length() == 10            );

        static_assert(   "videojuego"s[5]        == 'j'           ); //.at(5)
        static_assert(   "videojuego"s.find('j') == 5             );

        static_assert( "videojuego"s.substr(0,5) == "video"s      );
        static_assert( "videojuego"s.substr(5)   == "juego"s      );
    }
}
