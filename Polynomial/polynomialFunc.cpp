#include "Polynomial.h"

Polynomial::Polynomial() {
    degree = 0;
}

Polynomial::~Polynomial() {
   // cout << "deconstructor" << endl;
}

    void Polynomial::read() {
    cin >> degree;

    for (int i = degree; i >= 0; i--)
        cin >> coef[i];

}

    void Polynomial::add(Polynomial a, Polynomial b) {
    int i;
    
    if (a.degree > b.degree) {
        *this = a;
        for (i = 0; i <= b.degree; i++)
            coef[i] += b.coef[i];
    }
    else {
        *this = b;
        for (i = 0; i <= a.degree; i++)
            coef[i] += a.coef[i];
    }
    }


    void Polynomial::display() {
    int i;

    for (i = degree; i > 0; i--) {
        if (coef[i]) {
            if (i != degree)
                cout << " + ";
            if (coef[i] == 1)
                cout << "x^" << i;
            else
                cout << coef[i] << "x^" << i;
        }
    }
    if (coef[0])
        cout << " + " << coef[0];
    
    cout << endl;
}

void Polynomial::sub(Polynomial a, Polynomial b)
    {
        int i;
        
        if (a.degree > b.degree) 
        {
            *this = a;
            for (i = 0; i <= b.degree; i++)
            {
                coef[i] -= b.coef[i];
            }          
        }
        else
        {
            
            *this = b;
            for(int i = 0; i<=degree; i++) // 뺄셈을 덧셈으로 구현하기 위해 b 배열의 모든 부호를 반대로 전환 A-B  = A + (-B)
            {
                coef[i] = -coef[i];
            }
            for (i = 0; i <= a.degree; i++)
            {
                coef[i] += a.coef[i];
            }

        }
        
    }

void Polynomial::trim()
{
    int count = 0;
    for (int i = degree; i >= 0; i--) // 최고차항의 계수가 0임을 확인하는 반복문
    {
        if(coef[i] == 0) 
            count++; // 
        else
            break;
    }

    if(count)
    {
        degree -= count - 1;
    }
}

void Polynomial::mult(Polynomial a, Polynomial b) {
    degree = a.degree + b.degree;
    for (int i = 0; i <= degree; i++)
        coef[i] = 0;

    if (a.degree > b.degree) {
            
        for (int i = 0; i<=a.degree;i++){
            for (int j =0;j<=b.degree;j++) {
                coef[i+j] += a.coef[i]*b.coef[j];
            }
        }
    }
    else {
        for (int i = 0; i<=b.degree;i++)
        {
            for (int j =0;j<=a.degree;j++) 
            {
                coef[i+j] += b.coef[i] * a.coef[j];
            }
        }

    }
}


