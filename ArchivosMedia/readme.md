# Proyecto: SortMedia
Este proyecto tiene como objetivo desarrollar un sistema de análisis de interacciones en una plataforma multimedia. Este sistema permitirá a los administradores y analistas de la plataforma obtener información valiosa sobre cómo los usuarios interactúan con el contenido, lo que les ayudará a tomar decisiones informadas para mejorar la experiencia del usuario y aumentar la eficiencia de la plataforma. Para la filtración de datos utilizaremos como likes, comentarios, tiempo de visualización,  visitas e interacciones

## Descripción del avance 1
El objetivo de este avance consistió en establecer la capacidad de buscar o crear una base de datos, así como implementar funciones de ordenamiento y búsqueda. Esto permite iniciar un proceso de análisis de datos más efectivo y facilita una mayor eficiencia en la manipulación de la información, mejorando las capacidades de extracción de conocimiento y la toma de decisiones informadas.

## Descripción del avance 2
El propósito fundamental de este avance es la implementación de una estructura de pila con el fin de permitir al usuario la flexibilidad de organizar los datos de acuerdo a sus necesidades y preferencias individuales. Esta capacidad para personalizar la disposición de la información no solo aumenta la usabilidad del sistema, sino que también brinda una experiencia más intuitiva y eficiente para el usuario, mejorando en última instancia la calidad y eficacia de la interacción con la plataforma.

### Cambios sobre el primer avance
1. Escribe la lista de cambios realizados sobre el planteamiento original: Argumenta la razón por la que decidiste el cambio. Estos argumentos puedes retomarlos más adelante en tu argumentación de competencias.
2. Cambio 2: Razón del cambio
3. Cambio 3: Razón del cambio
4. etc...: etc...

## Descripción del avance 3
Este avance se enfocó en la implementación de una función fundamental denominada addData. Esta función se encarga de la inclusión de datos relevantes en un archivo CSV destinado a almacenar información crucial sobre el contenido de la plataforma multimedia. La función addData recibe tres parámetros: el nombre del contenido, su identificación única y el número de visitas. A través de la apertura del archivo en modo de agregado, la función anexa la nueva información al final del archivo existente. Esto proporciona una manera sencilla y efectiva de registrar la actividad y el impacto de cada pieza de contenido en la plataforma.

La inclusión de esta función es vital, ya que se constituye como un pilar para la recopilación constante de datos relevantes para el análisis. Al facilitar la adición de nueva información al archivo CSV, se sientan las bases para el posterior procesamiento y análisis de datos, permitiendo la obtención de estadísticas y patrones que serán esenciales para la toma de decisiones informadas en el mejoramiento de la plataforma multimedia. 

### Cambios sobre el segundo avance
1. Mejore el ReadMe de la anterior entrega.
2. Elimine funciones que no se estaba utilizando en la entrega.
3. Cambie la lectura del Archchivo para que se hiciera adentro de while y se actualizara cada vez que se realizara una función

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
Archivos CSV (Comma-Separated Values)

Ejemplo:

<!-- usuario_id,contenido_id,fecha_hora,likes,comentarios,tiempo_visualizacion,visitas
101,001,2023-09-01 10:15:00,5,2,10:30,3
102,002,2023-09-01 11:30:00,8,4,15:45,5
103,003,2023-09-02 09:45:00,12,6,25:15,8 -->

Estos archivos contienen registros de las interacciones de los usuarios con el contenido multimedia. Cada fila representa una interacción y contiene información sobre el usuario, el contenido, la fecha y hora de la interacción, el número de likes, comentarios, tiempo de visualización y visitas asociadas a esa interacción.

Si se crea un menu tambien contaria como una entrada para navegar por el programa

## Descripción de las salidas del avance de proyecto
Los resultados de la ejecución del programa ofrecerán una visión completa de cómo los usuarios interactúan con la plataforma multimedia, dandonos el contenidos que acomodados en un vector para ver cuales son los que nos llaman la atención viendo cuale svideos son lo que tienen mayores y menores visitas

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Se utilizarian algoritmos de ordenamiento búsqueda ShellSort, ya que este es útil en situaciones en las que se necesita una ordenación eficiente en tiempo y espacio, y puede ser especialmente eficaz en listas de datos que están casi ordenadas, pero no necesariamente completamente ordenadas. Aunque Shell Sort no es tan rápido como algoritmos de ordenación más avanzados como QuickSort o MergeSort, puede ser una opción razonable en algunos casos, especialmente en este, ya que contamos con una cantidad de datos moderados. Ya que este programa actualmete no se utilizara para manejar una gran cantidad de datos este seria el más simple de implemetar.En el peor de los casos la comlejidad del algoritmo sería O(n^2) y el mejor de lo casos seria O(n log n).

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Una pila es una estructura de datos de tipo LIFO (Last In, First Out), lo que significa que el último elemento añadido es el primero en ser eliminado. Esto es útil para gestionar el historial de reproducción. Al usar una pila en este programa de ordenamiento de contenido de redes sociales puede ser una buena, ya que si se desea gestionar el historial de reproducción y permitir una navegación sencilla entre canciones anteriores y posteriores en la lista. Además gracias a esto tambien podemos crear varias listas de reproduccion en forma de pila, la coplejidad de las operaciones de la pila tienden a ser 0(1), ya sea Push,Pop, y Top

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.


1.-Archivo::writeData(vector<Video> inventory)
Complejidad: O(n)
Recorre cada elemento del vector una vez para escribir en el archivo.

2.-Archivo::clearData(vector<Video> inventory)
Complejidad: O(1)
Escribe una línea en el archivo, no depende del tamaño del vector.

3.-Archivo::swap(vector<Video> &v, int i, int j)
Complejidad: O(1)
Realiza un intercambio directo de dos elementos en un vector.

4.-Archivo::shellSortLess(vector<Video> v)
Complejidad: O(n log^2 n)
Shell Sort tiene una complejidad que depende del tamaño del vector, aunque es más eficiente que O(n^2) en el caso promedio.

5.-Archivo::shellSortMore(vector<Video> v)
Complejidad: O(n log^2 n)
Similar al caso anterior.


6.-Archivo::CargaArchivo(const string &name)
Complejidad: O(n)
Lee el archivo línea por línea y crea los objetos, por lo que depende linealmente del tamaño del archivo.

7.- addData(string nombre, int id, int visitas)
Complejidad: O(1)
Agrega una línea al final del archivo, independientemente del contenido existente.

En resumen, el programa tiene una complejidad máxima de O(n log^2 n), asociada con las operaciones de ordenamiento mediante Shell Sort, y una complejidad mínima de O(1), relacionada con la operación que borra datos del archivo. Las demás funciones se sitúan entre estos extremos, con complejidades que van desde lineales hasta logarítmicas, dependiendo de la operación que realizan y el algoritmo empleado.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
En mi proyecto, he utilizado algoritmos de ordenamiento como ShellSort para ordenar los datos. Esta elección se basó en una evaluación de la complejidad de los algoritmos disponibles y en la naturaleza de los datos que se van a ordenar.  La complejidad de tiempo de shellsort es O(n^2), lo que significa que su rendimiento es adecuado para conjuntos de datos moderados además de ofrecer un redimiento .

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Para gestionar el historial de reproducción en el programa, opté por implementar una pila, que sigue el principio de Last In. Esta elección se basó en la necesidad de permitir una navegación sencilla entre canciones anteriores y posteriores en la lista de reproducción. Una pila es la estructura de datos perfecta para este propósito, ya que permite agregar elementos al historial de reproducción y eliminarlos en el orden en que se reprodujeron. Esta decisión demuestra que he seleccionado una estructura de datos adecuada para el problema y he considerado la eficiencia en términos de la gestión del historial de reproducción.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Como mencioné anteriormente, he utilizado una pila para gestionar el historial de reproducción en el programa. La competencia de implementar acciones científicas se refleja en la capacidad de consultar información de esta estructura de datos de manera correcta. En mi proyecto, he implementado funciones que permiten a los usuarios consultar la última canción reproducida, la canción anterior en el historial y otras operaciones relacionadas con la pila. Estas consultas se realizan de manera eficiente, ya que una pila es una estructura de datos adecuada para mantener un historial de reproducción

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
En el contexto de la gestión del historial de reproducción, he implementado mecanismos que permiten cargar datos de archivos de música en la pila de reproducción. Estos archivos de música contienen información sobre las canciones, como el título, el artista, el género, y otros detalles relevantes. La competencia se refleja en la capacidad de leer estos archivos de manera adecuada y cargar la información de las canciones en la pila de reproducción de forma correcta. Esto garantiza que los datos se almacenan de manera precisa y que los usuarios pueden acceder a ellos de manera eficiente.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Considero que he desarrollado la competencia en la implementación de mecanismos de escritura de archivos para guardar datos de estructuras de manera correcta a través de la función que diseñé, llamada addData. Esta función específica se encarga de registrar datos relevantes en un archivo CSV, asegurando un formato adecuado y una escritura correcta.

La forma en que organizo los datos antes de escribirlos en el archivo es un ejemplo del desarrollo de esta competencia. La función addData recibe parámetros estructurados (nombre, id y visitas) y los concatena de manera coherente antes de escribirlos en el archivo. Utilizo la delimitación con comas para asegurar que la información se registre en el formato deseado para un archivo CSV. Además, abro el archivo en modo de agregado (ios::app) para garantizar que los datos se añadan correctamente al final del archivo sin sobrescribir información previa.0