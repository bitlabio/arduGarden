void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

// the loop function runs over and over again forever
// we want each planet to recieve water every 15minutes.
// so totaltime = (2*pumptime + 2*chargetime) = 15min = 1000 * 60 * 15
int pumptime = 120;   //seconds
int chargetime = 330; //seconds
int timer = 0;

void loop() {
  
  digitalWrite(12, 0);
  digitalWrite(11, 0);
  
  //pump 1 on
  digitalWrite(12, 1);  
  digitalWrite(11, 0);
  wait(pumptime);      
  
  // all off chill.. battery recharging.
  digitalWrite(12, 0);
  digitalWrite(11, 0);  
  wait(chargetime);
  
  //pump 2 on
  digitalWrite(12, 0);  
  digitalWrite(11, 1);
  wait(pumptime);      
  
  // all off chill.. battery recharging.
  digitalWrite(12, 0);
  digitalWrite(11, 0);  
  wait(chargetime);
}

void wait( int duration ) {
  //This is to work around the problem of delay() not being able to go longer than 32seconds.
  int counter = 0;
  while (counter < duration) {
    counter++;
    delay(1000); 
  }
  counter = 0;
}
