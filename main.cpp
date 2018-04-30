/*
 * The Tenfleques License
 *
 * Copyright 2018 blackjack.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* 
 * File:   main.cpp
 * Author: Tendai Chikake Mapungwana
 *
 * Created on April 30, 2018, 1:23 PM
 */

#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;
#define h 0.1

double fxy(double x, double y){
    return (log(x) + 2*y)/(x*log(x));
}
double chislenoyeUravnenie(double xi, double yi){
    double xi_1 = xi + h;
    return (yi + (h/2.0)*fxy(xi,yi) + h/(2*(xi_1))) * (xi_1 * log(xi_1))/(xi_1 * log(xi_1) - h);
}

int main(int argc, char** argv) {
    double x;
    double y[6];
    x = exp(1);
    y[0] = 0;
    int i = 1;
    cout << "["  << x << "; " << y[0] << "]\n";
    while(i < 6){
       y[i] = chislenoyeUravnenie(x,y[i-1]);
       x += h;
       cout << "["  << x << "; " << y[i] << "]\n";
       i ++;       
    }       
    return 0;
}

