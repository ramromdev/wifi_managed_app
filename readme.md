# Arduino NANO, sensor ultrasonidos y ESP8266 integrando un servidor para visualizar niveles


---

El arduino NANO se encarga de gestionar la información recibida del sensor ultrasonidos. Establece unos umbrales de distancia (en cm) entre los cuales nos encontraremos en el nivel 1,2 o 3. Esta información se envía vía serie al módulo wifi 8266. Que se encarga de alojar un servidor web y de generar el código html necesario para visualizar correctamente cada nivel en una página web local. La comunicación wifi se realiza a través de una red ad-hoc. El archivo de configuración de esta red ad-hoc no está incluido.



