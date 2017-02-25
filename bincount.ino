void light(int bubble);

int clk = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  Serial.println("counter 2^6 = 0 to 63\n");
  for (int i = 0; i < 64; i++) {
    light(i);
    Serial.println(i);
    delay(clk);
  }
  light(0);
}

void light(int bubble) {
  int pin = 0;
  for (int i = 6; i >= 0; i--) {
    switch(i) {
      case 0: {
        pin = 13;
        break;
      }
      case 1: {
        pin = 12;
        break;
      }

      case 2: {
        pin = 11;
        break;
      }

      case 3: {
        pin = 10;
        break;
      }

      case 4: {
        pin = 9;
        break;
      }

      case 5: {
        pin = 8;
        break;
      }
    }
    if ((bubble & (0x01 << i)) == 0) {
      digitalWrite(pin, LOW);
      Serial.print("0");
    }
    else {
      digitalWrite(pin, HIGH);
      Serial.print("1");
    }
  }
  Serial.print("\n");
}
