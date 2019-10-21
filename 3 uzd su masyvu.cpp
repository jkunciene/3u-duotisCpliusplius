#include <iostream>
#include <fstream>

using namespace std;

ifstream skaitymas("Duomenys.txt"); //komanda duomenu nuskaitymui
ofstream irasymas("Rezultatai.txt"); //komanda duomenu rasymui


void nuskaitymasIsFailo(int &dienuSkaicius, double &SimoFondas, double &LinoFondas, double &MantoFondas, double SimoMasyvas[10], double LinoMasyvas[10], double MantoMasyvas[10]);
void FailoIrasymas(double SimoMasyvas[10], double LinoMasyvas[10], double MantoMasyvas[10]);
double piniguIsleidimui(double M[10]);
double VidutDienos(double M[10], int dienuSkaicius);


int main() {

    int dienuSkaicius;
    double SimoFondas, SimoSum, SimasperDiena, LinoFondas, LinoSum, LinasperDiena, MantoFondas, MantoSum, MantasperDiena, SimoMasyvas[10], LinoMasyvas[10], MantoMasyvas[10], M[10];

    nuskaitymasIsFailo(dienuSkaicius, SimoFondas, LinoFondas, MantoFondas, SimoMasyvas, LinoMasyvas, MantoMasyvas);

    cout<<dienuSkaicius<<"   "<<SimoFondas<<"   "<<LinoFondas<<"   "<<MantoFondas<<endl;

    //-------kodel negalima buvo uzrasyti SimoSuma = piniguIsleidimui(SimoMasyvas); ir tt klaida incompatible types in assignment of double to double
    SimoSum=piniguIsleidimui(SimoMasyvas);
    LinoSum=piniguIsleidimui(LinoMasyvas);
    MantoSum=piniguIsleidimui(MantoMasyvas);
    cout<<"Simas isleido  "<<SimoSum<<"   Linas isleido  "<<LinoSum<<"   Mantas isleido  "<<MantoSum<<endl;

    SimasperDiena=VidutDienos(SimoMasyvas, dienuSkaicius);
    LinasperDiena=VidutDienos(LinoMasyvas, dienuSkaicius);
    MantasperDiena=VidutDienos(MantoMasyvas, dienuSkaicius);
    cout<<"Simas isleidzia vidutiniskai per diena   "<<SimasperDiena<<"  Linas isleidzia vidutiniskai per diena   "<<LinasperDiena<<"  Mantas isleidzia vidutiniskai per diena   "<<MantasperDiena;
    FailoIrasymas(SimoMasyvas, LinoMasyvas, MantoMasyvas);


    skaitymas.close();
    irasymas.close();
  return 0;
}
void nuskaitymasIsFailo(int &dienuSkaicius, double &SimoFondas, double &LinoFondas, double &MantoFondas, double SimoMasyvas[10], double LinoMasyvas[10], double MantoMasyvas[10]){

    skaitymas>>dienuSkaicius>>SimoFondas>>LinoFondas>>MantoFondas;

        for(int i=0; i<10; i++){
            skaitymas>>SimoMasyvas[i]>>LinoMasyvas[i]>>MantoMasyvas[i];
        }
}
double piniguIsleidimui(double M[10]){
    double suma;
    suma=0;
    for(int i=0; i<10; i++){
        suma= suma + M[i];
    }
    return suma;
}
void FailoIrasymas(double SimoMasyvas[10], double LinoMasyvas[10], double MantoMasyvas[10]){
    for(int i=0; i<10; i++){
            irasymas<<"Simo "<<SimoMasyvas[i]<<"  Lino  "<<LinoMasyvas[i]<<" Manto "<<MantoMasyvas[i]<<endl;
            }
    irasymas<<"Simas isleido  "<<piniguIsleidimui(SimoMasyvas)<<"    Linas isleido  "<<piniguIsleidimui(LinoMasyvas)<<"   Mantas isleido  "<<piniguIsleidimui(MantoMasyvas)<<endl;
}
double VidutDienos(double M[10], int dienuSkaicius){
    double suma;
    suma=0;
    for(int i=0; i<10; i++){
        suma= suma + M[i];
    }
    return(suma/dienuSkaicius);
}
