void llegirpolinomi(int argc, char* argv[], double *v, int n);
void derivarpolinomi(double *v, int n, double *d);
double newtonpolinomi(double x0, int k, double *v, int n);
double avaluarpolinomi(double *v, int n, double x);
double secantpolinomi(double a, double b, int k, double *v, int n);
double bisecciopolinomi(double a, double b, int k, double *v, int n);

void llegirpolinomifl(int argc, char* argv[], float *v, int n);
void derivarpolinomifl(float *v, int n, float *d);
float newtonpolinomifl(float x0, int k, float *v, int n);
float avaluarpolinomifl(float *v, int n, float x);
