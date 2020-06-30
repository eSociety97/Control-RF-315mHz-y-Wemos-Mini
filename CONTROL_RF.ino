/*****************************Control de Motores con Modulo RF 315mHz**************
 * Ejemplo para control de 2 Motores con el Modulo Puente H L298N de 2 Canales    *
 * con los Modulos RF 315mHz Tx y Rx.                                             *
 *                                                                                *
 * Materiales:                                                                    *
 * -1 Wemos D1 Mini                                                               *
 * -1 Tx de RF 315Mhz                                                             *
 * -1 Integrado HT12E                                                             *
 * -1 Integrado HT12D                                                             *
 * -1 Rx de RF 315Mhz                                                             *
 * -2 Motores DC                                                                  *
 * -4 Pulsadores                                                                  *
 * -4 Resistencias de 10k                                                         *
 *                                                                                *
 *Diagramas:                                                                      *
 * https://easyeda.com/esociety97/receptor-315mhz                                 *
 * https://easyeda.com/esociety97/transmisor-315mhz                               *
 *                                                             Facebook: ESociety *
 *                                                              GitHub: eSociety97*
 **********************************************************************************/
 
//Constantes para los pines de Control de Botonera 
const int acelerar = D5; 
const int reversa = D6; 
const int derecha = D7; 
const int izquierda = D8; 

//Constantes de control de Motores
const int n1 =  D4;      // motor 1 +
const int n2 =  D3;      // motor 1 -
const int n3 =  D2;      // motor 2 +
const int n4 =  D1;      // motor 2 -

void setup() {
  Serial.begin(115200); //Inicio de Comunicacion Serial
   
  //Declaracion de Pines de Salida para Control de Motores
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4, OUTPUT);
  
  //Declaracion de Pines de Entrada Lectura de Botonera
  pinMode(acelerar, INPUT);
  pinMode(reversa, INPUT);
  pinMode(derecha, INPUT);
  pinMode(izquierda, INPUT);

  //Estado Inicial de Motores  
  digitalWrite(n1, HIGH);
  digitalWrite(n2, HIGH);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, HIGH);
}

void loop() {
/*N1 y N2 controlan el primer motor 
  N3 y N4 controla el segundo motor 
  Para activar el giro de motor se necesita un LOW*/
       
  if(digitalRead(acelerar)){ //Si el pulsador hacia adelante se activa 
    //Entonces mostramos un mensaje de "Acelerar en el Monitor Serial
    Serial.println("Acelerar");
    //Y activamos N1 y N3 para activar el movimiento hacia adelante    
    digitalWrite(n1, LOW);
    digitalWrite(n2, HIGH);
    digitalWrite(n3, LOW);
    digitalWrite(n4, HIGH); 
  } 
    else if(digitalRead(reversa)){//Si el pulsador hacia atras se activa
       
    //Entonces mostramos un mensaje de "reversa" en el Monitor Serial
    Serial.println("reversa");
    //Y activamos N2 y N4 para activar el movimiento hacia atras 
    digitalWrite(n1, HIGH);
    digitalWrite(n2, LOW);
    digitalWrite(n3, HIGH);
    digitalWrite(n4, LOW); 
  }       
    else if(digitalRead(derecha)){//Si el pulsador hacia la derecha se activa
 
    //Entonces mostramos un mensaje de "derecha" en el Monitor Serial
    Serial.println("derecha");
    
    //Y activamos N3 para activar el movimiento hacia derecha
    digitalWrite(n1, HIGH);
    digitalWrite(n2, HIGH);
    digitalWrite(n3, LOW);
    digitalWrite(n4, HIGH); 
  }     
   else if( digitalRead(izquierda)){//Si el pulsador hacia la izquierda se activa

    //Entonces mostramos un mensaje de "izquierda" en el Monitor Serial
    Serial.println("izquierda");
    
    //Y activamos N4 para activar el movimiento hacia Izquierda
    digitalWrite(n1, LOW);
    digitalWrite(n2, HIGH);
    digitalWrite(n3, HIGH);
    digitalWrite(n4, HIGH); 
  }  
     else{  //Si ningun boton es pulsado entonces 
    //Todas las salidas de control de Motores estaran Inactivas.
    digitalWrite(n1, HIGH);
    digitalWrite(n2, HIGH);
    digitalWrite(n3, HIGH);
    digitalWrite(n4, HIGH); 
  } 
}
