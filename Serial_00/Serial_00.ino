int datafromUser=0;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Inicie el monitor serial y tipee 1 para encender y 0 para apagar");
}
void loop() 
{

  if(Serial.available()>0)
    {
      datafromUser=Serial.read();
      }

  if(datafromUser =='1')
    {
      Serial.println(LED_BUILTIN);
      Serial.print("\n\nEncendido");
      digitalWrite(LED_BUILTIN, HIGH);
      }  
   else if(datafromUser =='0')
    {
      Serial.println(LED_BUILTIN);
      Serial.print("\n\nApagado");
      digitalWrite(LED_BUILTIN, LOW);
      }  
}
