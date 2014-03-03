SoftwareSerial mySerial(6,7);

//////////////////////////////////////////////////////// SETUP ////////////////////////////////////////////////////////////
void setup(){
 

mySerial.begin(19200); //puerto serie por software para comunicacion con modem
Serial.begin(19200);   // serie rx-tx 0,1 

modem_check();

}

void loop()
{
}

void ShowSerialData()
{
  while(mySerial.available()!=0)
    Serial.write(mySerial.read());
}


void modem_check()
{
Serial.println("//////////MODEM CHECK///////////////");
  while(1)
  {
char car='a';
char buffer[10];

int i=0;


    delay(3000);
    
if (Serial.available() > 0) {
    // lee el byte entrante:
    while (Serial.available() && i<10)
                {
                  car=Serial.read();
                  buffer[i++]=car;
                  // La recepción tiene una latencia, se produce a través de una interrupción, que a lo mejor se ejecuta
                  // un poco después del Serial.available() por lo que el dato no entraría, por eso hacemos una pequeña espera
                  delayMicroseconds(500);
                }//end while
                buffer[i++]='\0';
                Serial.print(buffer);
              
              
              mySerial.println(buffer);
              delay(3000);
              ShowSerialData(); 
              mySerial.println();

              }
            }
}
