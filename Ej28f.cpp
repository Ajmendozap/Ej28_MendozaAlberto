#include <iostream>
#include <cmath>
#include <fstream>

double f0(double k, double t,double vx, double normv, double n)
{
    return (-k*pow(vx,n)*vx/normv)*t;
}

double f1(double k, double t,double vy, double normv, double n, double g)
{
    return ((-k*pow(vy,n)*vy/normv)-g)*t;
}

double f2(double vx)
{
    return vx;
}


double f3(double vy,double t, double g)
{
    return vy-g*t;
}

void rk4(double t0, double tf, double k, double vy, double vx, double normv, double n, double g, double delta_w,double w,std::string nombre)
{
    double x=0, y=0;
    double t=t0;
    double k1_x, k2_x, k3_x, k4_x;
    double k1_y, k2_y, k3_y, k4_y;
    double delta_t= delta_w/w;
    double h= delta_w;
    std::ofstream file(nombre);
    while(t<tf)
    {
        file<< x<< " "<<y<<std::endl;
        vx += f0(k,t,vx,normv,n);
        vy= f3(vy,t,g) + f1(k,t,vy,normv,n,g);
        k1_x= h*f2(vx);
        k2_x= h*f2(vx+(k1_x/2));
        k3_x= h*f2(vx+(k2_x/2));
        k4_x= h*f2(vx+k3_x);
        x+= (k1_x+(2*k2_x)+2*(k3_x)+k4_x)/6; 
        
        k1_y= h*f3(vy,t,g);
        k2_y= h*f3(vy+(k1_y/2),t+(h/2),g);
        k3_y= h*f3(vy+(k2_y/2),t+(h/2),g);
        k4_y= h*f3(vy+k3_y,t+h,g);
        y+= (k1_y+(2*k2_y)+(2*k3_y)+k4_y)/6;
            
        t+=delta_t;
    }
    file.close();
}

int main(void)
{
    double t0 = 0;
    double tf= 5;
    double vy= 10;
    double vx= 10;
    double normv= sqrt(vy*vy+vx*vx);
    double n = 1, k=0.7, g= 9.8, delta_w=0.1, w=1;
    rk4(t0, tf, 0, vy, vx, normv, n, g, delta_w,w, "data.dat");
    rk4(t0, tf, k, vy, vx, normv, n, g, delta_w,w, "dataf.dat");   
    return 0;
}