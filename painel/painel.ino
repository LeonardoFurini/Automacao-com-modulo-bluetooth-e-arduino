boolean btn1 = false;
boolean btn2 = false;
boolean btn3 = false;
boolean btn4 = false;

// Declarando pinos dos relés
int luz = 2;
int tomadaP = 3;
int tomadaS = 4;
int ventilador = 5;

//Declarando botões
int push1 = 6;
int push2 = 7;
int push3 = 8;
int push4 = 9;

//Declarando LED's
int led1 = A1;
int led2 = A2;
int led3 = A3;
int led4 = A4;

void setup(){
Serial.begin(9600);

//Declarando estados
pinMode(luz,OUTPUT);
pinMode(tomadaP,OUTPUT);
pinMode(tomadaS,OUTPUT);
pinMode(ventilador,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(push1,INPUT);
pinMode(push2,INPUT);
pinMode(push3,INPUT);
pinMode(push4,INPUT);

//Colocando botões em estado HIGH
digitalWrite(push1, HIGH);
digitalWrite(push2, HIGH);
digitalWrite(push3, HIGH);
digitalWrite(push4, HIGH);
}

void loop(){
//Leitura dos estados dos botões
int botao1 = digitalRead(6);
int botao2 = digitalRead(7);
int botao3 = digitalRead(8);
int botao4 = digitalRead(9);
  
char leitura = Serial.read();

//---Botões físicos---
     if(botao1 == LOW) leitura = 'L'; //Lampadas
else if(botao2 == LOW) leitura = 'T'; //Tomadas principais
else if(botao3 == LOW) leitura = 't'; //Tomadas Secundárias
else if(botao4 == LOW) leitura = 'V'; //ventilador

//---REQUISIÇAO---
if(leitura == 's')        //esta condição e apenas para fazer debug
{
  if(btn1 == 1) Serial.print("1on"); else Serial.print("1off");
  if(btn2 == 1) Serial.print("2on"); else Serial.print("2off");
  if(btn3 == 1) Serial.print("3on"); else Serial.print("3off");
  if(btn4 == 1) Serial.println("4on"); else Serial.println("4off");
}

//---LUZ---
else if(leitura == 'L'){
      if(btn1 == 0) //Caso o botao 2 esteja ativado
      {
        digitalWrite(luz, HIGH);        //Ative o relé correnpondente a ele
        digitalWrite(led1, HIGH);       //Ative o led correspondente a ele
        btn1 = 1;       //altere o estado da variável correspondente a ele
        Serial.println("1on");        //Mostre na serial o estado, isto tem a função de atualizar no aplicativo android o estado dos botões
      }
      else  { //Caso o botão nao esteja precionado
        digitalWrite(luz, LOW);   //Desative o relé
        digitalWrite(led1, LOW);  //Apague o LED
        btn1 = 0;       //Altere o estado da variável
        Serial.println("1off");       //Mostre na serial o estado, para o aplicativo atualizar
      }
}

//TOMADA PRINCIPAL
//o processo segue o mesmo alterando apenas as variáveis
else if(leitura == 'T'){
  if(btn2 == 0)
  {
    digitalWrite(tomadaP, HIGH);
    digitalWrite(led2, HIGH);
    btn2 = 1;
    Serial.println("2on");
  }
  else  {
    digitalWrite(tomadaP, LOW);
    digitalWrite(led2, LOW);
    btn2 = 0;
    Serial.println("2off");
  }
}

//---TOMADA SEGUNDARIA---
else if(leitura == 't'){
  if(btn3 == 0)
  {
    digitalWrite(tomadaS, HIGH);
    digitalWrite(led3, HIGH);
    btn3 = 1;
    Serial.println("3on");

  }
  else  {
    digitalWrite(tomadaS, LOW);
    digitalWrite(led3, LOW);
    btn3 = 0;
    Serial.println("3off");
  }
}

//---VENTILADOR---
else if(leitura == 'V'){
  if(btn4 == 0)
  {
    digitalWrite(ventilador, HIGH);
    digitalWrite(led4, HIGH);
    btn4 = 1;
    Serial.println("4on");

  }
  else  {
    digitalWrite(ventilador, LOW);
    digitalWrite(led4, LOW);
    btn4 = 0;
    Serial.println("4off");
  }
}

//---LIGAR TUDO---
//As opções de liga e desliga tudo sao exclusivas do aplicativo
//Quando enviados pelo aplicativo o comando 'm' ou 'n' o arduino alterar dodos os valores de uma só vez 
else if(leitura == 'm'){
    btn1 = 1;
    btn2 = 1;
    btn3 = 1;
    btn4 = 1;
    digitalWrite(luz, HIGH);
    digitalWrite(tomadaP, HIGH);
    digitalWrite(tomadaS, HIGH);
    digitalWrite(ventilador, HIGH);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    Serial.println("1on");
    Serial.println("2on");
    Serial.println("3on");
    Serial.println("4on");
}
//---DESLIGAR TUDO---
else if(leitura == 'n'){
    btn1 = 0;
    btn2 = 0;
    btn3 = 0;
    btn4 = 0;
    digitalWrite(luz, LOW);
    digitalWrite(tomadaP, LOW);
    digitalWrite(tomadaS, LOW);
    digitalWrite(ventilador, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    Serial.println("1off");
    Serial.println("2off");
    Serial.println("3off");
    Serial.println("4off");
}

//---Verificação do estado dos botoes e relés---
//Tem apenas o intuito de debug, pode ser comentada
Serial.print(leitura);Serial.print(btn1);Serial.print(btn2);Serial.print(btn3);Serial.println(btn4);
delay(200);
}
