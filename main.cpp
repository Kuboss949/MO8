#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

template<typename T>
T forwardDiff(T x, T h){
    return (sin(x+h) - sin(x))/h;
}

template<typename T>
T backwardDiff(T x, T h){
    return (sin(x) - sin(x-h))/h;
}

template<typename T>
T centralDiff(T x, T h){
    return (sin(x+h) - sin(x-h))/(2*h);
}

template<typename T>
T tripleF(T x, T h){
    T a = static_cast<T>(1.5);
    T b = static_cast<T>(2.0);
    T c = static_cast<T>(0.5);
    return (-a*sin(x)+b*sin(x+h)-c*sin(x+2*h))/h;
}

template<typename T>
T tripleB(T x, T h){
    T a = static_cast<T>(1.5);
    T b = static_cast<T>(2.0);
    T c = static_cast<T>(0.5);
    return (c*sin(x-2*h)-b*sin(x-h)+a*sin(x))/h;
}

float fcos(float x){
    return cos(x);
}

int main() {

    double pi_d = M_PI, error;

    ofstream plik;
    double begin = 10e-2;
    double end = 10e-17;
    double x1 = 0.0;
    double x2 = pi_d/4.0;
    double x3= pi_d/2.0;
    //double

    for (double h = begin; h >= end; h/=10.) {
        //x1
        plik.open("wynik11.txt", std::ofstream::app);
        error = log10(fabs(forwardDiff(x1, h)-cos(x1)));
        plik << log10(h) << " " << error << '\n';
        plik.close();
        //x1
        plik.open("wynik12.txt", std::ofstream::app);
        error = log10(fabs(tripleF(x1, h)-cos(x1)));
        plik << log10(h) << " " << error << '\n';;
        plik.close();

        //x3
        plik.open("wynik31.txt", std::ofstream::app);
        error = log10(fabs(backwardDiff(x3, h)-cos(x3)));
        plik << log10(h) << " " << error << '\n';
        plik.close();
        //x3
        plik.open("wynik32.txt", std::ofstream::app);
        error = log10(fabs(tripleB(x3, h)-cos(x3)));
        plik << log10(h) << " " << error << '\n';;
        plik.close();

        //x2
        plik.open("wynik21.txt", std::ofstream::app);
        error = log10(fabs(backwardDiff(x2, h)-cos(x2)));
        plik << log10(h) << " " << error << '\n';
        plik.close();
        //x2
        plik.open("wynik22.txt", std::ofstream::app);
        error = log10(fabs(forwardDiff(x2, h)-cos(x2)));
        plik << log10(h) << " " << error << '\n';;
        plik.close();
        //x2
        plik.open("wynik23.txt", std::ofstream::app);
        error = log10(fabs(centralDiff(x2, h)-cos(x2)));
        plik << log10(h) << " " << error << '\n';
        plik.close();
    }

    float pi_f = (float)M_PI, errorf;
    float beginf = 10e-2f;
    float endf = 10e-18f;
    float x1f = 0.00f;
    float x2f = pi_f/4.0f;
    float x3f= pi_f/2.0f;
    //double

    for (float h = beginf; h >= endf; h/=10.0f) {
        //x1
        plik.open("wynik11f.txt", std::ofstream::app);
        errorf = log10(fabs(forwardDiff(x1f, h)-cos(x1f)));
        plik << log10(h) << " " << errorf << '\n';
        plik.close();
        //x1
        plik.open("wynik12f.txt", std::ofstream::app);
        errorf = log10(fabs(tripleF(x1f, h)-cos(x1f)));
        plik << log10(h) << " " << errorf << '\n';;
        plik.close();

        //x3
        plik.open("wynik31f.txt", std::ofstream::app);
        errorf = log10(fabs(backwardDiff(x3f, h)-cos(x3f)));
        plik << log10(h) << " " << errorf << '\n';
        plik.close();
        //x3
        plik.open("wynik32f.txt", std::ofstream::app);
        errorf = log10(fabs(tripleB(x3f, h)-cos(x3f)));
        plik << log10(h) << " " << errorf << '\n';;
        plik.close();

        //x2
        plik.open("wynik21f.txt", std::ofstream::app);
        errorf = log10(fabs(backwardDiff(x2f, h)-cos(x2f)));
        plik << log10(h) << " " << errorf << '\n';
        plik.close();
        //x2
        plik.open("wynik22f.txt", std::ofstream::app);
        errorf = log10(fabs(forwardDiff(x2f, h)-cos(x2f)));
        plik << log10(h) << " " << errorf << '\n';;
        plik.close();
        //x2
        plik.open("wynik23f.txt", std::ofstream::app);
        errorf = log10(fabs(centralDiff(x2f, h)-cos(x2f)));
        plik << log10(h) << " " << errorf << '\n';
        plik.close();
    }
    return 0;
}