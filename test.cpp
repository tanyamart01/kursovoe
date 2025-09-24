#include <iostream>
using namespace std;

string str1 = "$GPRMC,125504.049,A,5542.2389,N,03741.6063,E,0.06,25.82,200906,,,*17";

enum State {
  idle,
  data,
  fin
};

int main (){
    State state{idle};
    for (const char ch:str1){
        switch (state) {
            case idle:
                if (ch == '$') {state=data};//маркер принят, переходим к приему данных}
                else {}//продолжаем ждать маркер
            break;
            case data:
                if (ch == '*') {state = fin}
                else if (ch == '$') {state=err;}
                else {buf[i++]=ch; i%= BUF_SIZE;}
            break;
            case fin:
                if(ch=''){state =data}
                else {state = err}
            break;
            case err:
                break;
            //default:
        };
    }
}