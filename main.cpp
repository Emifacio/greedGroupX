#include<iostream>
#include<ctime>
using namespace std;

void tiradaBloqueadores(int v[],int t)
{
    t=2;
    int x,dado;
    cout<<"Dados bloqueadores "<<endl;
    cout<<"==================================="<<endl;
    for(x=0; x<2; x++)
    {
        dado=(rand()%6+1);
        v[x]=dado;
        cout<<"Dado "<<x+1<<" = " <<v[x]<<endl;
    }
}

void tiradaDeDados(int vD[],int tam)
{
    tam=5;
    int x;
    cout<<"Dados "<<endl;
    cout<<"==================================="<<endl;
    for(x=0; x<5; x++)
    {
        vD[x]=(rand()%6+1);
        cout<<"Dado "<<x+1<<" = " <<vD[x]<<endl;
    }
}

//cout<<"==================================="<<endl;
//cout<<"dados con descuentos"<<endl;
int dadosNuevos(int vD[5],int vB[2])
{
    int x,t=5,cD=0;
    for(x=0; x<t; x++)
    {
        if(vD[x]==vB[0] || vD[x]==vB[1])
        {
            vD[x]=0;

        }
    }
    for(x=0; x<t; x++)
    {
        if(vD[x]!=0)
        {
            vD[cD]=vD[x];
            cD++;
        }
    }
    return cD;
}
//cout<<"==================================="<<endl;
void mostrarDados(int vD[],int nT)
{
    int x;
    for(x=0; x<nT; x++)
    {
        cout<<"Dado "<<vD[x]<<" - ";
    }
}

int sumarDados(int vD[],int t)
{
    int x,aP=0;
    for(x=0; x<t; x++)
    {
        aP+=vD[x];
    }
    return aP;
}

int main()
{
    srand(time(0));

    int x,tam=2,t=5,vB[2]= {},vD[t]= {},nT=0,vDn[t]= {},cD=0,puntaje=0;
    char pregunta='S';

    tiradaBloqueadores(vB,tam);
    cout<<"==================================="<<endl;
    tiradaDeDados(vD,t);
    cout<<"==================================="<<endl;
    cD=dadosNuevos(vD,vB);


    mostrarDados(vD,cD);
    cout<<endl;
    puntaje=sumarDados(vD,cD);
    cout<<"puntaje "<<puntaje<<endl;
    do
    {
        cout<<"Desea continuar tirando (S para seguir o N para sumar los puntos acumulados):"<<endl;
        cin>>pregunta;



    }
    while(pregunta!='N');


    return 0;
}
