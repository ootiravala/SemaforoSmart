//Pines utilizados

#define VERDE1 2
#define AMARILLO1 3
#define ROJO1 4
#define VERDE2 5
#define AMARILLO2 6
#define ROJO2 7

#define PULSADOR1 8
#define PULSADOR2 9

//Variables
bool activo = true; // Indica que el semaforo uno esta activo, si es false será el semaforo dos el que este activo
int tiempoCambio = 1500; // Definimos el tiempo de cambio entre LEDs
int tiempoEspera = 3000; // Define tiempo de espera desde que se detecta un coche, hasta que se produce cambio en los semaforos

void setup() {
  // Inicializar el monitor serie
  Serial.begin(9600);

  // Modo E/S de los pines
 pinMode (VERDE1, OUTPUT);
 pinMode (AMARILLO1, OUTPUT);
 pinMode (ROJO1, OUTPUT);
 pinMode (VERDE2, OUTPUT);
 pinMode (AMARILLO2, OUTPUT);
 pinMode (ROJO2, OUTPUT);

 pinMode (PULSADOR1, INPUT);
 pinMode (PULSADOR2, INPUT);
 
  // Apagamos todos los LEDs
 digitalWrite (VERDE1, LOW);
 digitalWrite (AMARILLO1, LOW);
 digitalWrite (ROJO1, LOW);
 digitalWrite (VERDE2, LOW);
 digitalWrite (AMARILLO2,LOW);
 digitalWrite (ROJO2, LOW);
 
  // Ponemos estado inicial: sem1 abierto, sem2 cerrado
 digitalWrite (VERDE1, HIGH);
 digitalWrite (ROJO2, HIGH);
  
}

void loop() {

if (activo){
  // Si el sem1 esta activo, vigilo el pulsador2
  int sem2 = digitalRead(PULSADOR2);

  if (sem2 == HIGH){
    encenderSemaforo2();
    activo = false;
  }
}else{

  // El sem2 está encendido, vigilo pulsador1
  int sem1=digitalRead(PULSADOR1);

  if (sem1 == HIGH){
    encenderSemaforo1();
    activo = true;
  }  
 }
}


// Creamos las funciones

void encenderSemaforo2 ()
{
  delay (tiempoEspera);

  digitalWrite (VERDE1, LOW);
  digitalWrite (AMARILLO1, HIGH);

  delay (tiempoCambio);

  digitalWrite (AMARILLO1, LOW);
  digitalWrite (ROJO1, HIGH);

  delay (tiempoCambio);

  digitalWrite (ROJO2, LOW);
  digitalWrite (VERDE2, HIGH);  
}

void encenderSemaforo1()
{
  delay (tiempoEspera);

  digitalWrite (VERDE2,LOW);
  digitalWrite (AMARILLO2,HIGH);

  delay (tiempoCambio);

  digitalWrite (AMARILLO2,LOW);
  digitalWrite (ROJO2,HIGH);

  delay (tiempoCambio);

  digitalWrite (ROJO1,LOW);
  digitalWrite (VERDE1,HIGH);
}
