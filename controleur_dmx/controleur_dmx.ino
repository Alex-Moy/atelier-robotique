#include <DmxSimple.h>

//Déclaration du tableau des channels
const int channel[9][6] = {
  {1 , 2 , 3 , 4 , 5 , 6},
  {7 , 8 , 9 , 10, 11, 12},
  {13, 14, 15, 16, 17, 18},
  {19, 20, 21, 22, 23, 24},
  {25, 26, 27, 28, 29, 30},
  {31, 32, 33, 34, 35, 36},
  {37, 38, 39, 40, 41, 42},
  {43, 44, 45, 46, 47, 48},
  {49, 50, 51, 52, 53, 54}};

//Déclaration des pins des potentiomètres
const int potar[6] = {A0, A1, A2, A3, A4, A5};

//Déclaration des pins du 7 segments
const int sevseg[7] = {12, 11, 10, 9, 8, 7, 6, 5};

//Déclaration des pins des boutons
const int btup = 4;
const int btdown = 2;

int page = 0;

void setup() {
  DmxSimple.usePin(3);
  DmxSimple.maxChannel(54);
  declaration_inputs_outputs();
}

void loop() {
  sevsegaffiche(page + 1);
  for(int n = 0; n <= 5; n++) {DmxSimple.write(channel[page][n], map(analogRead(potar[n]), 0, 1023, 0, 255));}
  if(btup == 0 && page != 8) {page++;}
  if(btdown == 0 && page != 0) {page--;}
}

void declaration_inputs_outputs() {
  //Définition des pins du 7 segments en output
  for(int n = 0; n <= 6; n++) {pinMode(sevseg[n], OUTPUT);}

  //Définition des pins des potentiomètres en output
  for(int n = 0; n <= 5; n++) {pinMode(potar[n], OUTPUT);}

  //Définition des pins des boutons en input_pullup
  pinMode(btup, INPUT_PULLUP);
  pinMode(btdown, INPUT_PULLUP);
}

void sevsegaffiche(int value) {
  //Allume/éteint les bon segments en fonction de la valeur
  if(value == 0) {digitalWrite(sevseg[0], LOW); digitalWrite(sevseg[1], LOW); digitalWrite(sevseg[2], LOW); digitalWrite(sevseg[3], LOW); digitalWrite(sevseg[4], LOW); digitalWrite(sevseg[5], LOW); digitalWrite(sevseg[6], HIGH);}
  if(value == 1) {digitalWrite(sevseg[0], HIGH); digitalWrite(sevseg[1], LOW); digitalWrite(sevseg[2], LOW); digitalWrite(sevseg[3], HIGH); digitalWrite(sevseg[4], HIGH); digitalWrite(sevseg[5], HIGH); digitalWrite(sevseg[6], HIGH);}
  if(value == 2) {digitalWrite(sevseg[0], LOW); digitalWrite(sevseg[1], LOW); digitalWrite(sevseg[2], HIGH); digitalWrite(sevseg[3], LOW); digitalWrite(sevseg[4], LOW); digitalWrite(sevseg[5], HIGH); digitalWrite(sevseg[6], LOW);}
  if(value == 3) {digitalWrite(sevseg[0], LOW); digitalWrite(sevseg[1], LOW); digitalWrite(sevseg[2], LOW); digitalWrite(sevseg[3], LOW); digitalWrite(sevseg[4], HIGH); digitalWrite(sevseg[5], HIGH); digitalWrite(sevseg[6], LOW);}
  if(value == 4) {digitalWrite(sevseg[0], HIGH); digitalWrite(sevseg[1], LOW); digitalWrite(sevseg[2], LOW); digitalWrite(sevseg[3], HIGH); digitalWrite(sevseg[4], HIGH); digitalWrite(sevseg[5], LOW); digitalWrite(sevseg[6], LOW);}
  if(value == 5) {digitalWrite(sevseg[0], LOW); digitalWrite(sevseg[1], HIGH); digitalWrite(sevseg[2], LOW); digitalWrite(sevseg[3], LOW); digitalWrite(sevseg[4], HIGH); digitalWrite(sevseg[5], LOW); digitalWrite(sevseg[6], LOW);}
  if(value == 6) {digitalWrite(sevseg[0], LOW); digitalWrite(sevseg[1], HIGH); digitalWrite(sevseg[2], LOW); digitalWrite(sevseg[3], LOW); digitalWrite(sevseg[4], LOW); digitalWrite(sevseg[5], LOW); digitalWrite(sevseg[6], LOW);}
  if(value == 7) {digitalWrite(sevseg[0], LOW); digitalWrite(sevseg[1], LOW); digitalWrite(sevseg[2], LOW); digitalWrite(sevseg[3], HIGH); digitalWrite(sevseg[4], HIGH); digitalWrite(sevseg[5], HIGH); digitalWrite(sevseg[6], HIGH);}
  if(value == 8) {digitalWrite(sevseg[0], LOW); digitalWrite(sevseg[1], LOW); digitalWrite(sevseg[2], LOW); digitalWrite(sevseg[3], LOW); digitalWrite(sevseg[4], LOW); digitalWrite(sevseg[5], LOW); digitalWrite(sevseg[6], LOW);}
  if(value == 9) {digitalWrite(sevseg[0], LOW); digitalWrite(sevseg[1], LOW); digitalWrite(sevseg[2], LOW); digitalWrite(sevseg[3], LOW); digitalWrite(sevseg[4], HIGH); digitalWrite(sevseg[5], LOW); digitalWrite(sevseg[6], LOW);}
}

