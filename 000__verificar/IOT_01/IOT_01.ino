https://youtu.be/d5liGDDvzNs
https://giltesa.com/2016
https://giltesa.com/2016/04/07/6-curso-iot-con-arduino-y-esp8266-wifi-ejemplo-arduino-como-puente
https://giltesa.com/2016/04/14/8-curso-iot-con-arduino-y-esp8266-wifi-ejemplo-cliente-recepcion-datos
https://giltesa.com/2016/04/19/9-curso-iot-con-arduino-y-esp8266-wifi-ejemplo-cliente-envio-y-recepcion-datos
https://ditecnomakers.com/espressif-esp8266/

Curso IoT con Arduino y ESP8266 WiFi: Ejemplo cliente -> Envió y recepción datos

5.8.4) Cliente: Envió de correos electrónicos

Ya hemos aprendido a enviar datos, también a recibirlos, esta vez juntaremos ambos códigos para poder enviar correos electrónicos desde el Arduino y recibir la respuesta del servidor.

De nuevo el código se divide en dos partes, por un lado tenemos la parte del servidor que se encargara de recibir todos los datos que envié el Arduino, también nos autenticara con una key al igual que se hace en Thingspeak para que nadie use el servicio sin nuestro permiso, y por último enviara los correos electrónicos y nos devolverá una respuesta.

<?php
   // Código completo 6.1: https://goo.gl/zDkntx
 
   define("KEY",   "f0RPRWWADWic8tn");
   define("OK",                  "1");
   define("ERROR_AUTENTICATION", "2");
   define("ERROR_PARAMETERS",    "3");
   define("ERROR_SEND_MAIL",     "4");
 
   $key     = $_GET['key'];
   $name    = $_GET['name'];
   $from    = $_GET['from'];
   $to      = $_GET['to'];
   $subject = $_GET['subject'];
   $message = $_GET['message'];
 
   if( !isset($key) || $key !== KEY )
   {
      echo ERROR_AUTENTICATION;
   }
   else if( !isset($name) || !isset($from)    ||
            !isset($to)   || !isset($subject) || !isset($message) )
   {
      echo ERROR_PARAMETERS;
   }
   else
   {
      echo mail( $to, $subject, $message, "From: $name<$from>\r\nReturn-path: $from" ) ? OK : ERROR_SEND_MAIL;
   }
?>

En el primer bloque de código primero se definen todas las constantes, en ellas está la key que deberá de ser igual a la enviada desde el Arduino, así como unos números que devolveremos como respuesta dependiendo del resultado de la ejecución.

El segundo bloque contiene las variables que almacenan la información enviada desde el Arduino.

Por ultimo en el tercer bloque se realizan ciertas validaciones, en el if se comprueba que la key no haya llegado vacía ni sea distinta de la del servicio. En el else if se comprueba que ninguno de los campos obligatorios haya llegado vacío. Y en el else se manda el correo y dependiendo de si la función mail devuelve true o false pues se devuelve el código correspondiente de los definidos como constantes.

En cuanto al código del Arduino hay dos bloques interesantes y diferentes respecto a los ejemplos anteriores.
	
#define NAME     "Arduino"
#define FROM     "arduino@domain.com"
#define TO       "tuemail@domain.com"
#define SUBJECT  "Alerta!"
#define MESSAGE  "Se ha disparado el sensor de la puerta!"

El primero de ellos solo son unas constantes que almacenaran la información a enviar al servidor y que este a su vez enviara por correo electrónico.

Estos campos son el nombre y email del remitente, el email del destinatario y el asunto y mensaje del correo.

Si alguien quisiera enviar algún dato, como una lectura de un sensor, solo tendrá que concatenar la información en un String como se hace en la función addParameter y enviar ese contenido en vez del de la constante. Si en vez de eso se quisiera enviar otro tipo de información, como una imagen capturada con una cámara, sería necesario realizar una comunicación POST y mandar los bytes en la cabecera de la llamada. Esto es bastante más complejo pero lo comento para que os suena si lo necesitáis.
	
void loop()
{
   if( digitalRead(pBTN) )
   {
      while(digitalRead(pBTN));
      delay(100);
 
      addParameter("key"    , KEY     );
      addParameter("name"   , NAME    );
      addParameter("from"   , FROM    );
      addParameter("to"     , TO      );
      addParameter("subject", SUBJECT );
      addParameter("message", MESSAGE );
 
      if( !send(IP, PORT, SERVICE) )
         pc.println("  Error con el servidor" );
      else if( !receiveData() )
         pc.println("  Error al recuperar los datos");
      else
      {
         switch( resultEmail )
         {
            case  1: pc.println("  Email enviado");       break;
            case  2: pc.println("  Error autenticacion"); break;
            case  3: pc.println("  Faltan parametros");   break;
            case  4: pc.println("  Email no enviado");    break;
            default: pc.println("  Error desconocido");   break;
         }
      }
   }
}

Esta vez la ejecución del código no se realiza cada cierto tiempo, si no cuando el sensor digital o el botón que tengamos conectado al pin pBTN activa una señal HIGH.

Tras llamar a la función send para enviar los datos y a la función receiveData para recoger la respuesta, se comprueba en un switch qué número ha devuelto el servicio y en consecuencia se muestra un mensaje concreto.


	
   cmd = "GET ";
   cmd += service;
   parameters.replace(" ", "%20");
   cmd += parameters;
   cmd += "\r\n";

En la función send ha hecho falta añadir la línea de código superior, esta remplaza todos los caracteres de espacio por %20 antes de concatenar los parámetros con el comando a enviar al ESP8266. Esto es necesario debido a que las URLs y los espacios no se llevan especialmente bien y los textos se pueden cortar si no.

Y este es el resultado de la ejecución del ejemplo, se ejecutó dos veces, la primera con una key incorrecta y la segunda con todo correcto.
