int SEG_a = 13;
int SEG_b = 12;
int SEG_c = 11;
int SEG_d = 10;
int SEG_e = 9;
int SEG_f = 8;
int SEG_g = 7;
int SEG_pd = 6;

void setup() {
  pinMode (SEG_a, OUTPUT);
  pinMode (SEG_b, OUTPUT);
  pinMode (SEG_c, OUTPUT);
  pinMode (SEG_d, OUTPUT);
  pinMode (SEG_e, OUTPUT);
  pinMode (SEG_f, OUTPUT);
  pinMode (SEG_g, OUTPUT);
  pinMode (SEG_pd, OUTPUT);
 }
void loop() {
  ZERO();
  delay (1000);
  ONE();
  delay (1000);
  TWO();
  delay (1000);
  THREE();
  delay (1000);
  FOUR();
  delay (1000);
  FIVE();
  delay (1000);
  SIX();
  delay (1000);
  SEVEN();
  delay (1000);
 

  EIGHT();
  delay (1000);
  NINE();
  delay (1000);
  bLetter();
  delay (1000);
  cLetter();
  delay (1000);
  CLetter();
  delay (1000);
  dLetter();
  delay (1000);
  ELetter();
  delay (1000);
  FLetter();
  delay (1000);
 

  hLetter();
  delay (1000);
  HLetter();
  delay (1000);
  JLetter();
  delay (1000);
  LLetter();
  delay (1000);
  nLetter();
  delay (1000);
  oLetter();
  delay (1000);
  pLetter();
  delay (1000);
  qLetter();
  delay (1000);
  
  rLetter();
  delay (1000);
  uLetter();
  delay (1000);
  ULetter();
  delay (1000);
}
 
void ZERO() {
  digitalWrite (SEG_a, HIGH);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, LOW);
  digitalWrite (SEG_pd, LOW);
}
 
void ONE() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, LOW);
  digitalWrite (SEG_e, LOW);
  digitalWrite (SEG_f, LOW);
  digitalWrite (SEG_g, LOW);
  digitalWrite (SEG_pd, LOW);
}
 
void TWO() {
  digitalWrite (SEG_a, HIGH);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, LOW);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, LOW);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void THREE() {
  digitalWrite (SEG_a, HIGH);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, LOW);
  digitalWrite (SEG_f, LOW);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void FOUR() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, LOW);
  digitalWrite (SEG_e, LOW);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void FIVE() {
  digitalWrite (SEG_a, HIGH);
  digitalWrite (SEG_b, LOW);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, LOW);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void SIX() {
  digitalWrite (SEG_a, HIGH);
  digitalWrite (SEG_b, LOW);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void SEVEN() {
  digitalWrite (SEG_a, HIGH);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, LOW);
  digitalWrite (SEG_e, LOW);
  digitalWrite (SEG_f, LOW);
  digitalWrite (SEG_g, LOW);
  digitalWrite (SEG_pd, LOW);
}
 
void EIGHT() {
  digitalWrite (SEG_a, HIGH);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void NINE() {
  digitalWrite (SEG_a, HIGH);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, LOW);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void bLetter() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, LOW);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void cLetter() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, LOW);
  digitalWrite (SEG_c, LOW);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, LOW);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void CLetter() {
  digitalWrite (SEG_a, HIGH);
  digitalWrite (SEG_b, LOW);
  digitalWrite (SEG_c, LOW);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, LOW);
  digitalWrite (SEG_pd, LOW);
}
 
void dLetter() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, LOW);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void ELetter() {
  digitalWrite (SEG_a, HIGH);
  digitalWrite (SEG_b, LOW);
  digitalWrite (SEG_c, LOW);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void FLetter() {
  digitalWrite (SEG_a, HIGH);
  digitalWrite (SEG_b, LOW);
  digitalWrite (SEG_c, LOW);
  digitalWrite (SEG_d, LOW);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void hLetter() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, LOW);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, LOW);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void HLetter() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, LOW);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void JLetter() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, LOW);
  digitalWrite (SEG_g, LOW);
  digitalWrite (SEG_pd, LOW);
}
 
void LLetter() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, LOW);
  digitalWrite (SEG_c, LOW);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, LOW);
  digitalWrite (SEG_pd, LOW);
}
 
void nLetter() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, LOW);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, LOW);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, LOW);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void oLetter() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, LOW);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, LOW);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void pLetter() {
  digitalWrite (SEG_a, HIGH);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, LOW);
  digitalWrite (SEG_d, LOW);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void qLetter() {
  digitalWrite (SEG_a, HIGH);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, LOW);
  digitalWrite (SEG_e, LOW);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void rLetter() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, LOW);
  digitalWrite (SEG_c, LOW);
  digitalWrite (SEG_d, LOW);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, LOW);
  digitalWrite (SEG_g, HIGH);
  digitalWrite (SEG_pd, LOW);
}
 
void uLetter() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, LOW);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, LOW);
  digitalWrite (SEG_g, LOW);
  digitalWrite (SEG_pd, LOW);
}
 
void ULetter() {
  digitalWrite (SEG_a, LOW);
  digitalWrite (SEG_b, HIGH);
  digitalWrite (SEG_c, HIGH);
  digitalWrite (SEG_d, HIGH);
  digitalWrite (SEG_e, HIGH);
  digitalWrite (SEG_f, HIGH);
  digitalWrite (SEG_g, LOW);
  digitalWrite (SEG_pd, LOW);
}
 

