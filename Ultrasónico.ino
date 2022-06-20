void loop() {
  
 int distanceR = 0;
 int distanceL =  0;
 delay(40);
 
 if(distance<=15)
 {
  moveStop();                   
  delay(200);                   
  moveBackward(); 
delay(800);                      
  moveStop();
  delay(200);
  distanceR = lookRight();       
  delay(200);
  distanceL = lookLeft();         
  delay(200);
 
  if(distanceR>=distanceL)
  {
    turnRight();           
    moveStop();
  }
  
      else
      
  {
    turnLeft();            
    moveStop();
  }
  
 }else   
                        
 {
  moveForward();         
 }
 distance = readPing();
}
 
int lookRight()          
{
    myservo.write(50);    
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115);        
    return distance;
}
 
int lookLeft()
{
    myservo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
    delay(100);
}
 
int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}
 
void moveStop() {
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
  } 
  
void moveForward() {        //CARRITO AVANZA
 
 
    analogWrite(motorPin1, 180);       
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 180);     
    analogWrite(motorPin4, 0);  
  
}
 
void moveBackward() {        //HACIA ATRAS
    
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);       
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);      
  
}  
 
void turnRight() {     //GIRA A LA DERECHA Y AVANZA
  
    analogWrite(motorPin1, 180);     
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);   
    delay(300);
    moveForward();      
  
} 
 
void turnLeft() {           //GIRA A LA IZQUIERDA Y AVANZA
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);   
    analogWrite(motorPin3, 180);    
    analogWrite(motorPin4, 0);     
    delay(300);
    moveForward();
}  
