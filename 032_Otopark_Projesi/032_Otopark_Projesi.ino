       #include <Servo.h>            /* Servo kutuphanesi projeye dahil edildi */
       Servo servo_giris;            /* servo motor isimlendirildi */
       Servo servo_cikis;            /* servo motor isimlendirildi */

       #define   cikis_sensor_dis  A0    
       #define   cikis_sensor_ic  A1 
       #define   giris_sensor  A2         
       #define   giris_dugme   2
       #define   giris_lamba   3
       #define   cikis_lamba   4

       #define  a     8
       #define  b     7
       #define  c     9
       #define  d     10
       #define  e     11
       #define  f     12
       #define  g     13

       int bos_yer = 9;
       int sayac = 0;
//-----------------------------------------------------------------------------------       
      void setup()
      {
      Serial.begin(9600);
      servo_giris.attach(5);        /* Servo motor 5 numarali pine baglandi */
      servo_cikis.attach(6);        /* Servo motor 6 numarali pine baglandi */ 
      servo_giris.write(0);         // girişteki servoyu yatay konuma ayarladım
      servo_cikis.write(0);         // çıkıştaki servoyu yatay konuma ayarladım

      pinMode(giris_lamba,OUTPUT);
      pinMode(cikis_lamba,OUTPUT);
      pinMode(giris_dugme,INPUT);
      
      arac_sayisi_goster(bos_yer); 

      while(sayac<10)
      {
      digitalWrite(giris_lamba, HIGH);
      digitalWrite(cikis_lamba, HIGH);
      delay(50);
      digitalWrite(giris_lamba, LOW);
      digitalWrite(cikis_lamba, LOW);       
      delay(50);
      sayac++;
      }
      
      digitalWrite(giris_lamba, HIGH);
      digitalWrite(cikis_lamba, HIGH);
      }
//-----------------------------------------------------------------------------------     
      void loop()
      {
      if(digitalRead(giris_dugme) == HIGH) 
      {
              if(bos_yer == 0)
              {
              goto kapiyi_acma;  
              }

              for(int i = 0; i < 90; i++) 
              {
              servo_giris.write(i);
              delay(15);
              }
              
              while(analogRead(giris_sensor)>800)
              {
              }
              delay(5000);     
              for(int i = 90; i > 0; i--) 
              {
              servo_giris.write(i);
              delay(15);
              }
              
              bos_yer = bos_yer - 1;
              arac_sayisi_goster(bos_yer);
        }  
             
kapiyi_acma:          
      delay(11);  //?????
//-------------------------------------------aşağısı çıkış bölümü
      
 
      if(analogRead(cikis_sensor_ic) < 750)
      {
              for(int i = 0; i < 90; i++) 
              {
              servo_cikis.write(i);
              delay(15);
              }

              Serial.print(analogRead(cikis_sensor_ic));
              Serial.print(analogRead(cikis_sensor_dis));  
                          
              while(analogRead(cikis_sensor_dis)>600)
              {
              }
              Serial.print(analogRead(cikis_sensor_ic));
              Serial.print(analogRead(cikis_sensor_dis));  
              
              delay(5000);     
              for(int i = 90; i > 0; i--) 
              {
              servo_cikis.write(i);
              delay(15);
              }    

              bos_yer = bos_yer + 1;
              arac_sayisi_goster(bos_yer);              
        }
     
//------------------------------------------yukarısı çıkış bölümüne ait.....     
    
      } // void loop    








//===============================================/*//fonksiyon başlıyor
void arac_sayisi_goster(int sayi)
{
switch (sayi)
    {
    case 0:
          digitalWrite(a,HIGH);   
          digitalWrite(b,HIGH); 
          digitalWrite(c,HIGH); 
          digitalWrite(d,HIGH); 
          digitalWrite(e,HIGH); 
          digitalWrite(f,HIGH);
          digitalWrite(g,LOW);           
      break;
   
    case 1:        
          digitalWrite(a,LOW);    
          digitalWrite(b,HIGH);  
          digitalWrite(c,HIGH); 
          digitalWrite(d,LOW); 
          digitalWrite(e,LOW); 
          digitalWrite(f,LOW);
          digitalWrite(g,LOW);          
      break;

    case 2:
          digitalWrite(a,HIGH);  
          digitalWrite(b,HIGH);
          digitalWrite(c,LOW); 
          digitalWrite(d,HIGH); 
          digitalWrite(e,HIGH); 
          digitalWrite(f,LOW); 
          digitalWrite(g,HIGH); 
      break;

    case 3:
          digitalWrite(a,HIGH); 
          digitalWrite(b,HIGH); 
          digitalWrite(c,HIGH); 
          digitalWrite(d,HIGH); 
          digitalWrite(e,LOW); 
          digitalWrite(f,LOW); 
          digitalWrite(g,HIGH); 
      break;

    case 4:
           digitalWrite(a,LOW); 
           digitalWrite(b,HIGH); 
           digitalWrite(c,HIGH); 
           digitalWrite(d,LOW); 
           digitalWrite(e,LOW); 
           digitalWrite(f,HIGH); 
           digitalWrite(g,HIGH); 
      break;

    case 5:
          digitalWrite(a,HIGH); 
          digitalWrite(b,LOW); 
          digitalWrite(c,HIGH); 
          digitalWrite(d,HIGH); 
          digitalWrite(e,LOW); 
          digitalWrite(f,HIGH); 
          digitalWrite(g,HIGH); 
      break;

    case 6:
          digitalWrite(a,HIGH);
          digitalWrite(b,LOW);  
          digitalWrite(c,HIGH); 
          digitalWrite(d,HIGH); 
          digitalWrite(e,HIGH); 
          digitalWrite(f,HIGH); 
          digitalWrite(g,HIGH); 
      break;
  
    case 7:
          digitalWrite(a,HIGH); 
          digitalWrite(b,HIGH); 
          digitalWrite(c,HIGH); 
          digitalWrite(d,LOW); 
          digitalWrite(e,LOW); 
          digitalWrite(f,LOW); 
          digitalWrite(g,LOW); 
      break;

    case 8:
          digitalWrite(a,HIGH);  
          digitalWrite(b,HIGH); 
          digitalWrite(c,HIGH); 
          digitalWrite(d,HIGH); 
          digitalWrite(e,HIGH); 
          digitalWrite(f,HIGH);
          digitalWrite(g,HIGH); 
      break;

    case 9:
          digitalWrite(a,HIGH);   
          digitalWrite(b,HIGH); 
          digitalWrite(c,HIGH); 
          digitalWrite(d,HIGH);
          digitalWrite(e,LOW);  
          digitalWrite(f,HIGH);
          digitalWrite(g,HIGH); 
      break;
  }
}
