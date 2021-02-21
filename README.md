# get_next_line
Gracias a **get_next_line** podremos leer línea a línea un archivo abierto del cual conocemos su descriptor de fichero. El objetivo principal del proyecto es ser
capaz de trabajar con variables estáticas, así como de saber gestionar bien la memoria dinámica para no obtener ninguna fuga de memoria (leaks).

### RETURN VALUES
Al ser una función de tipo int, nuestro **get_next_line** devuelve un valor de tipo int. Este valor puede ser:
<ul>
 <li>-1: si ha ocurrido un error dentro de nuestra función, ya sea porque los argumentos introducidos no tienen los valores correctos o porque se ha producido un error
durante la lectura del archivo.</li>
 <li> 0: si ha llegado a EOF, es decir, si se ha terminado la lectura del archivo, devolviendo el contenido leído hasta ese momento.</li>
 <li> 1: si se ha encontrado con un salto de línea, devolviendo el contenido leído hasta ese momento desde que se llamó a la función.</li>
</ul>

### EJEMPLOS
<img width="450" alt="Captura de pantalla 2021-02-21 a las 10 41 22" align="left" src="https://user-images.githubusercontent.com/74931024/108621227-c1e28700-7431-11eb-80ea-f9dff15c0ec9.png">
<img width="462" alt="Captura de pantalla 2021-02-21 a las 10 43 23" align="right" src="https://user-images.githubusercontent.com/74931024/108621302-2dc4ef80-7432-11eb-977c-671b16f7e84a.png">
