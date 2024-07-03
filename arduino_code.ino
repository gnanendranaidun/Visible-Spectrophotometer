#include <math.h>
class Value {
public:
    float R, G, B;

    Value()
     {
        R = 0.0;
        G = 0.0;
        B = 0.0;
     }

    float red(float a) 
    {
        if (646 <= a && a <= 780) {
            R = 1;
        } else if (581 <= a && a <= 645) {
            R = 1;
        } else if (511 <= a && a <= 580) {
            R = (a - 510) / 70;
        } else if (491 <= a && a <= 510) {
            R = 0;
        }
        if (441 <= a && a <= 490) {
            R = 0;
        }
        if (380 <= a && a <= 440) {
            R = (440 - a) / 60;
        }
        return R;
    }

    float green(float a) 
    {
        if (646 <= a && a <= 780) {
            G = 0;
        } else if (581 <= a && a <= 645) {
            G = (645 - a) / 65;
        } else if (511 <= a && a <= 580) {
            G = 1;
        } else if (489 <= a && a <= 510) {
            G = 1;
        }
        if (441 <= a && a <= 490) {
            G = (a - 440) / 50;
        }
        if (380 <= a && a <= 440) {
            G = 0;
        }
        return G;
    }

    float blue(float a) 
    {
        if (646 <= a && a <= 780) {
            B = 0;
        } else if (581 <= a && a <= 645) {
            B = 0;
        } else if (511 <= a && a <= 580) {
            B = 0;
        } else if (491 <= a && a <= 510) {
            B = (510 - a) / 20;
        }
        if (441 <= a && a <= 490) {
            B = 1;
        }
        if (380 <= a && a <= 440) {
            B = 1;
        }
        return B;
    }

    float factor(float a) 
    {
        float fac = 1;
        if (701 <= a && a <= 780) {
            fac = (3.0 / 10) + (((7.0 / 10) * (780 - a)) / 80);
        } else if (421 <= a && a <= 700) {
            fac = 1;
        } else if (380 <= a && a <= 420) {
            fac = (3.0 / 10) + (((7.0 / 10) * (a - 380)) / 40);
        }
        return fac;
    }

    float fina(float a, float b) 
    {
        float f = 255 * pow((a * b), (8.0 / 10));
        return f;
    }
};

void setup()
{
  Serial.begin(9600);
  int j = 0;
  int R[402];
  int G[402];
  int B[402];
  int L[402]; 
 
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,INPUT);
  for(int i=450;i<=700;i++)
  {  
    Value V;
    L[j] = i;
    R[j] = static_cast<int>(V.fina(V.factor(i), V.red(i)));
    G[j] = static_cast<int>(V.fina(V.factor(i), V.green(i)));
    B[j] = static_cast<int>(V.fina(V.factor(i), V.blue(i)));
    //Serial.print("{");
    //Serial.print(R[j]);
    //Serial.print(",");
    //Serial.print(G[j]);
    //Serial.print(",");
    //Serial.print(B[j]);
    //Serial.print("}");
    j++;
  }


}
void loop()
{
  int LDR[402];
  int A[402];
  int R[402];
  int G[402];
  int B[402];
  int L[402];
  int Res[402];
  if(digitalRead(7)==LOW)
  {
  Serial.print("[");
  for(int c=0;c<=250;c++)
  {
    analogWrite(9,R[c]);
    analogWrite(10,G[c]);
    analogWrite(11,B[c]);
    delay(50);
    LDR[c]=analogRead(0);
    Res[c]=(500/LDR[c])-100;
    A[c]=-log(Res[c]);
    Serial.print(LDR[c]);
    Serial.print(",");
    delay(50);

  }
  Serial.print("]");
  }
  else
  {
    analogWrite(9,0);
    analogWrite(10,0);
    analogWrite(11,0);
    exit; 
  }
}
  
