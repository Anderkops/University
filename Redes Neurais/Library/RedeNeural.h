#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <float.h>
#include <string.h>
#include <fstream.h>
#include <Math.h>  
#include "Matrix.h"

class Neuronio
{
public:
    int xCamadaEntrada;
    int xIDentrada;
    double xSaida1;
    double xAlvo;
    double xDelta;
    double xTeta1;
    double xTeta2;
    double *xPeso1;
    double *xPeso2;    

private:

};


class BackPropagation
{

private:
    int i,j,k; 
    int nCamadasOcultas;      
    int *nNosDeEntrada;    
    int nLinhasAmostras;   
    int nColunasAmostras;  

    long int    HoraInicio;
    long int    HoraFim;

    AnsiString stringAux;

    double **xxEntradasAmostrasTreinamento;   
    double **xxSaidasAmostrasTreinamento;     
    double *xMaxValorEntradas;   
    double *xMinValorEntradas;   
    double *xMaxValorSaidas;   
    double *xMinValorSaidas;   

    String xArquivoRedeNeural; 

    Neuronio **xNeuronios;    

public:
    int xIteracoes;           

    double TaxaDeAprendizagem;
    double dnInertia;         
    double erroMedQuad;  


    void SetaCamadasOcultas(int iHidLayerNum)
    {
        nCamadasOcultas=iHidLayerNum;
        nNosDeEntrada=new int[nCamadasOcultas+2];

        xNeuronios=new Neuronio*[iHidLayerNum+2];
    }


    void SetaNosDeEntrada(int iLayerID,int iLayerNNNum)
    {
        nNosDeEntrada[iLayerID]=iLayerNNNum;
    }


    int cEntradas(void)
    {
        return nNosDeEntrada[0];
    }


    int cSaidas(void)
    {
        return nNosDeEntrada[nCamadasOcultas+1];
    }


    void CreateNeuralNetwork(void)
    {
        HoraInicio=time(NULL);

        xIteracoes=0;

        int xIDentradaCounter=0;

        time_t t;
        srand((unsigned)time(&t));

        xNeuronios[0]=new Neuronio[nNosDeEntrada[0]];

        for(i=0;i<nNosDeEntrada[0];i++)
        {
            xNeuronios[0][i].xCamadaEntrada=0;
            xNeuronios[0][i].xIDentrada=i;
            xNeuronios[0][i].xSaida1=0.0;
            xNeuronios[0][i].xAlvo=0.0;
            xNeuronios[0][i].xDelta=0.0;
            xNeuronios[0][i].xTeta1=0.0;
            xNeuronios[0][i].xTeta2=0.0;
        }

        for(k=1;k<nCamadasOcultas+2;k++)
        {

            xNeuronios[k]=new Neuronio[nNosDeEntrada[k]];
            for(i=0;i<nNosDeEntrada[k];i++)
            {
                xNeuronios[k][i].xCamadaEntrada=k;
                xNeuronios[k][i].xIDentrada=i;
                xNeuronios[k][i].xSaida1=0.0;
                xNeuronios[k][i].xAlvo=0.0;
                xNeuronios[k][i].xDelta=0.0;
                xNeuronios[k][i].xTeta1=(rand()%20000-10000)/10000.0;
                xNeuronios[k][i].xTeta2=0.0;
            }

            for(j=0;j<nNosDeEntrada[k];j++)
            {
                xNeuronios[k][j].xPeso1=new double[nNosDeEntrada[k-1]];
                xNeuronios[k][j].xPeso2=new double[nNosDeEntrada[k-1]];
                for(i=0;i<nNosDeEntrada[k-1];i++)
                {
                    xNeuronios[k][j].xPeso1[i]=(rand()%20000-10000)/10000.0; 
                    xNeuronios[k][j].xPeso2[i]=0.0;
                }
            }

        }


        xMaxValorEntradas=new double[nNosDeEntrada[0]];   
        xMinValorEntradas=new double[nNosDeEntrada[0]];   

        xMaxValorSaidas=new double[nNosDeEntrada[nCamadasOcultas+1]];   
        xMinValorSaidas=new double[nNosDeEntrada[nCamadasOcultas+1]];   

        for(i=0;i<nNosDeEntrada[0];i++)
        {
             xMaxValorEntradas[i]=-9999999;
             xMinValorEntradas[i]=9999999;

        }

        for(j=0;j<nColunasAmostras;j++)
            for(i=0;i<(nNosDeEntrada[0]);i++)
            {
                if(xMaxValorEntradas[i]<=xxEntradasAmostrasTreinamento[j][i])
                    xMaxValorEntradas[i]=xxEntradasAmostrasTreinamento[j][i];
                if(xMinValorEntradas[i]>=xxEntradasAmostrasTreinamento[j][i])
                    xMinValorEntradas[i]=xxEntradasAmostrasTreinamento[j][i];
            }


        for(j=0;j<nColunasAmostras;j++)
            for(i=0;i<nNosDeEntrada[0];i++)
            {
            if((xMaxValorEntradas[i]-xMinValorEntradas[i])!=0)
                xxEntradasAmostrasTreinamento[j][i]=(xxEntradasAmostrasTreinamento[j][i]-xMinValorEntradas[i])/(xMaxValorEntradas[i]-xMinValorEntradas[i]);
             }
        for(i=0;i<nNosDeEntrada[nCamadasOcultas+1];i++)
        {
             xMaxValorSaidas[i]=-9999999;
             xMinValorSaidas[i]=9999999;

        }   

        for(j=0;j<nColunasAmostras;j++)
            for(i=0;i<(nNosDeEntrada[nCamadasOcultas+1]);i++)
            {
                if(xMaxValorSaidas[i]<=xxSaidasAmostrasTreinamento[j][i])
                    xMaxValorSaidas[i]=xxSaidasAmostrasTreinamento[j][i];
                if(xMinValorSaidas[i]>=xxSaidasAmostrasTreinamento[j][i])
                    xMinValorSaidas[i]=xxSaidasAmostrasTreinamento[j][i];
            }

        for(j=0;j<nColunasAmostras;j++)
            for(i=0;i<(nNosDeEntrada[nCamadasOcultas+1]);i++)
            {
            if((xMaxValorSaidas[i]-xMinValorSaidas[i])!=0)
                xxSaidasAmostrasTreinamento[j][i]=(xxSaidasAmostrasTreinamento[j][i]-xMinValorSaidas[i])/(xMaxValorSaidas[i]-xMinValorSaidas[i]);
            }
    }

    void SalvaRedeNeural(String sDumpNNFileName)
    {
        ofstream fout;   
        fout.open(sDumpNNFileName.c_str());
        xArquivoRedeNeural=sDumpNNFileName;
        fout<<"CamadasOcultas=";
        fout<<"\n";
        fout<<nCamadasOcultas;
        fout<<"\n";
        fout<<"NosDeEntrada=";
        fout<<"\n";
        fout<<nNosDeEntrada[0];
        fout<<"\n";
        fout<<"NosDeSaida=";
        fout<<"\n";
        fout<<nNosDeEntrada[nCamadasOcultas+1];
        fout<<"\n";
        fout<<"QtdeNosDeCadaCamadaOculta:";
        fout<<"\n";
        for(i=1;i<nCamadasOcultas+1;i++)
        {
            fout<<nNosDeEntrada[i];
            fout<<"\n";
        }

        fout<<"ConteudoDoNo:";
        fout<<"\n";


        for(i=0;i<nNosDeEntrada[0];i++)
        {
            fout<<"camada[";
            fout<<xNeuronios[0][i].xCamadaEntrada;
            fout<<"],id[";
            fout<<xNeuronios[0][i].xIDentrada;
            fout<<"]No:Output=";
            fout<<"\n";
            fout<<xNeuronios[0][i].xSaida1;
            fout<<"\n";

            fout<<"camada[";
            fout<<xNeuronios[0][i].xCamadaEntrada;
            fout<<"],id[";
            fout<<xNeuronios[0][i].xIDentrada;
            fout<<"]No:Target=";
            fout<<"\n";
            fout<<xNeuronios[0][i].xAlvo;
            fout<<"\n";

            fout<<"camada[";
            fout<<xNeuronios[0][i].xCamadaEntrada;
            fout<<"],id[";
            fout<<xNeuronios[0][i].xIDentrada;
            fout<<"]No:Delta=";
            fout<<"\n";
            fout<<xNeuronios[0][i].xDelta;
            fout<<"\n";

            fout<<"camada[";
            fout<<xNeuronios[0][i].xCamadaEntrada;
            fout<<"],id[";
            fout<<xNeuronios[0][i].xIDentrada;
            fout<<"]No:Theta=";
            fout<<"\n";
            fout<<xNeuronios[0][i].xTeta1;
            fout<<"\n";

            fout<<"camada[";
            fout<<xNeuronios[0][i].xCamadaEntrada;
            fout<<"],id[";
            fout<<xNeuronios[0][i].xIDentrada;
            fout<<"]No:dTheta=";
            fout<<"\n";
            fout<<xNeuronios[0][i].xTeta2;
            fout<<"\n";
        }


        for(k=1;k<nCamadasOcultas+2;k++)
        {
            for(j=0;j<nNosDeEntrada[k];j++)
            {
                fout<<"camada[";
                fout<<xNeuronios[k][j].xCamadaEntrada;
                fout<<"],id[";
                fout<<xNeuronios[k][j].xIDentrada;
                fout<<"]No:Output=";
                fout<<"\n";
                fout<<xNeuronios[k][j].xSaida1;
                fout<<"\n";

                fout<<"camada[";
                fout<<xNeuronios[k][j].xCamadaEntrada;
                fout<<"],id[";
                fout<<xNeuronios[k][j].xIDentrada;
                fout<<"]No:Target=";
                fout<<"\n";
                fout<<xNeuronios[k][j].xAlvo;
                fout<<"\n";

                fout<<"camada[";
                fout<<xNeuronios[k][j].xCamadaEntrada;
                fout<<"],id[";
                fout<<xNeuronios[k][j].xIDentrada;
                fout<<"]No:Delta=";
                fout<<"\n";
                fout<<xNeuronios[k][j].xDelta;
                fout<<"\n";

                fout<<"camada[";
                fout<<xNeuronios[k][j].xCamadaEntrada;
                fout<<"],id[";
                fout<<xNeuronios[k][j].xIDentrada;
                fout<<"]No:Theta=";
                fout<<"\n";
                fout<<xNeuronios[k][j].xTeta1;
                fout<<"\n";

                fout<<"camada[";
                fout<<xNeuronios[k][j].xCamadaEntrada;
                fout<<"],id[";
                fout<<xNeuronios[k][j].xIDentrada;
                fout<<"]No:dTheta=";
                fout<<"\n";
                fout<<xNeuronios[k][j].xTeta2;
                fout<<"\n";

                for(i=0;i<nNosDeEntrada[k-1];i++)
                {
                    fout<<"camada[";
                    fout<<xNeuronios[k][j].xCamadaEntrada;
                    fout<<"],id[";
                    fout<<xNeuronios[k][j].xIDentrada;
                    fout<<"]No:Weight[";
                    fout<<i;
                    fout<<"]=";
                    fout<<"\n";
                    fout<<xNeuronios[k][j].xPeso1[i];
                    fout<<"\n";
                }

                for(i=0;i<nNosDeEntrada[k-1];i++)
                {
                    fout<<"camada[";
                    fout<<xNeuronios[k][j].xCamadaEntrada;
                    fout<<"],id[";
                    fout<<xNeuronios[k][j].xIDentrada;
                    fout<<"]No:dWeight[";
                    fout<<i;
                    fout<<"]=";
                    fout<<"\n";
                    fout<<xNeuronios[k][j].xPeso2[i];
                    fout<<"\n";
                }

            }

        }

        for(i=0;i<nNosDeEntrada[0];i++)
        {       
            fout<<"InputNode[";
            fout<<i;
            fout<<"]Maximun=\n";
            fout<<xMaxValorEntradas[i];
            fout<<"\n";
            fout<<"InputNode[";
            fout<<i;
            fout<<"]Minimum=\n";
            fout<<xMinValorEntradas[i];
            fout<<"\n";
        }

         for(i=0;i<nNosDeEntrada[nCamadasOcultas+1];i++)
        {
            fout<<"OutputNode[";
            fout<<i;
            fout<<"]Maximun=\n";
            fout<<xMaxValorSaidas[i];
            fout<<"\n";
            fout<<"OutputNode[";
            fout<<i;
            fout<<"]Minimum=\n";
            fout<<xMinValorSaidas[i];
            fout<<"\n"; 
        }


        fout.close();
    }

    void SetaQtasAmostrasTreinar(int iTrainSampleSetNum)
    {
        int i;
        nColunasAmostras=iTrainSampleSetNum;
        xxEntradasAmostrasTreinamento=new double*[nColunasAmostras];
        xxSaidasAmostrasTreinamento=new double*[nColunasAmostras];
        for(i=0;i<nColunasAmostras;i++)
            xxEntradasAmostrasTreinamento[i]=new double[nNosDeEntrada[0]];
        for(i=0;i<nColunasAmostras;i++)
            xxSaidasAmostrasTreinamento[i]=new double[nNosDeEntrada[nCamadasOcultas+1]];
    }


    int tiposAmostraTreinamento(void)
    {
        return nColunasAmostras;
    }


    void SetaQtosTiposAmostrasTreinar(Matrix2D M2DTrainInputSample)
    {
        for(int i=0;i<nColunasAmostras;i++)
            for(int j=0;j<nNosDeEntrada[0];j++)
                xxEntradasAmostrasTreinamento[i][j]=M2DTrainInputSample.arrvalor[i][j];
    }


    void SetaQtasSaidasTreinar(Matrix2D M2DTrainOutputSample)
    {
        for(int i=0;i<nColunasAmostras;i++)
            for(int j=0;j<nNosDeEntrada[nCamadasOcultas+1];j++)
                xxSaidasAmostrasTreinamento[i][j]=M2DTrainOutputSample.arrvalor[i][j];
    }


    void Treina(void)
    {
        xIteracoes++;
        double xSoma=0.0;
        erroMedQuad=0.0;

        int xTotalCamadas=nCamadasOcultas+2;
        int xIDCamadaSaida=nCamadasOcultas+1;

        int iColuna; 
        for(iColuna=0;iColuna<nColunasAmostras;iColuna++)
        {
            for(i=0;i<nNosDeEntrada[0];i++)
                xNeuronios[0][i].xSaida1=xxEntradasAmostrasTreinamento[iColuna][i];

            for(k=1;k<xTotalCamadas;k++)
                for(j=0;j<nNosDeEntrada[k];j++)
                {
                    xSoma=0.0;
                    for(i=0;i<nNosDeEntrada[k-1];i++)
                        xSoma+=xNeuronios[k][j].xPeso1[i]*xNeuronios[k-1][i].xSaida1;

                    xNeuronios[k][j].xSaida1=1.0/(1.0+exp(-(xSoma-xNeuronios[k][j].xTeta1)));
                }

            for(i=0;i<nNosDeEntrada[xIDCamadaSaida];i++)
            {
                xNeuronios[xIDCamadaSaida][i].xAlvo=xxSaidasAmostrasTreinamento[iColuna][i];
                xNeuronios[xIDCamadaSaida][i].xDelta=xNeuronios[xIDCamadaSaida][i].xSaida1*(1.0-xNeuronios[xIDCamadaSaida][i].xSaida1)*(xNeuronios[xIDCamadaSaida][i].xAlvo-xNeuronios[xIDCamadaSaida][i].xSaida1);
            }


            for(k=nCamadasOcultas;k>0;k--)
                for(j=0;j<nNosDeEntrada[k];j++)
                {
                    xSoma=0.0;
                    for(i=0;i<nNosDeEntrada[k+1];i++)
                        xSoma+=xNeuronios[k+1][i].xPeso1[j]*xNeuronios[k+1][i].xDelta;

                    xNeuronios[k][j].xDelta=xNeuronios[k][j].xSaida1*(1.0-xNeuronios[k][j].xSaida1)*xSoma;
                }



            for(k=1;k<xTotalCamadas;k++)
                for(j=0;j<nNosDeEntrada[k];j++)
                {
                    xNeuronios[k][j].xTeta2=-TaxaDeAprendizagem*xNeuronios[k][j].xDelta+dnInertia*xNeuronios[k][j].xTeta2;
                    xNeuronios[k][j].xTeta1+=xNeuronios[k][j].xTeta2;

                    for(i=0;i<nNosDeEntrada[k-1];i++)
                    {
                        xNeuronios[k][j].xPeso2[i]=TaxaDeAprendizagem*xNeuronios[k][j].xDelta*xNeuronios[k-1][i].xSaida1+dnInertia*xNeuronios[k][j].xPeso2[i];
                        xNeuronios[k][j].xPeso1[i]+=xNeuronios[k][j].xPeso2[i];
                    }

                }

            for(i=0;i<nNosDeEntrada[xIDCamadaSaida];i++)
                erroMedQuad+=(xNeuronios[xIDCamadaSaida][i].xAlvo-xNeuronios[xIDCamadaSaida][i].xSaida1)*(xNeuronios[xIDCamadaSaida][i].xAlvo-xNeuronios[xIDCamadaSaida][i].xSaida1);

        }

        erroMedQuad=erroMedQuad/nColunasAmostras/nNosDeEntrada[xIDCamadaSaida];
        erroMedQuad=sqrt(erroMedQuad);
    }


    void InsereEntradasNaAmostraDeRec(int iInputRecallInputSampleOrder,double dRecallInputSample)
    {
        xNeuronios[0][iInputRecallInputSampleOrder].xSaida1=(dRecallInputSample-xMinValorEntradas[iInputRecallInputSampleOrder])/(xMaxValorEntradas[iInputRecallInputSampleOrder]-xMinValorEntradas[iInputRecallInputSampleOrder]);
    }


    void AbreRedeNeural(String sLoadNNFileName)
    {
        ifstream fin;   
        fin.open(sLoadNNFileName.c_str());    

        char cTemp[256];
        int iTemp;
        double xTemp;

        fin>>cTemp; 
        fin>>iTemp;
        SetaCamadasOcultas(iTemp);
        
        fin>>cTemp;
        fin>>nNosDeEntrada[0];

        fin>>cTemp;  
        fin>>nNosDeEntrada[nCamadasOcultas+1];   

        fin>>cTemp;
        for(i=1;i<nCamadasOcultas+1;i++)
        {
            fin>>nNosDeEntrada[i]; 
        }   
        xNeuronios[0]=new Neuronio[nNosDeEntrada[0]];
        for(i=0;i<nNosDeEntrada[0];i++)
        {
            xNeuronios[0][i].xCamadaEntrada=0;
            xNeuronios[0][i].xIDentrada=i;
            xNeuronios[0][i].xSaida1=0.0;
            xNeuronios[0][i].xAlvo=0.0;
            xNeuronios[0][i].xDelta=0.0;
            xNeuronios[0][i].xTeta1=0.0;
            xNeuronios[0][i].xTeta2=0.0;
        }

        for(k=1;k<nCamadasOcultas+2;k++)
        {

            xNeuronios[k]=new Neuronio[nNosDeEntrada[k]];
            for(i=0;i<nNosDeEntrada[k];i++)
            {
                xNeuronios[k][i].xCamadaEntrada=k;
                xNeuronios[k][i].xIDentrada=i;
                xNeuronios[k][i].xSaida1=0.0;
                xNeuronios[k][i].xAlvo=0.0;
                xNeuronios[k][i].xDelta=0.0;
                xNeuronios[k][i].xTeta1=(rand()%20000-10000)/10000.0;
                xNeuronios[k][i].xTeta2=0.0;
            }
            for(j=0;j<nNosDeEntrada[k];j++)
            {
                xNeuronios[k][j].xPeso1=new double[nNosDeEntrada[k-1]];
                xNeuronios[k][j].xPeso2=new double[nNosDeEntrada[k-1]];
                for(i=0;i<nNosDeEntrada[k-1];i++)
                {
                    xNeuronios[k][j].xPeso1[i]=(rand()%20000-10000)/10000.0;
                    xNeuronios[k][j].xPeso2[i]=0.0;
                }
            }

        }

        
        fin>>cTemp;
        for(i=0;i<nNosDeEntrada[0];i++)
        {
            fin>>cTemp;
            fin>>xNeuronios[0][i].xSaida1;

            fin>>cTemp;
            fin>>xNeuronios[0][i].xAlvo;

            fin>>cTemp;
            fin>>xNeuronios[0][i].xDelta;

            fin>>cTemp;
            fin>>xNeuronios[0][i].xTeta1;

            fin>>cTemp;
            fin>>xNeuronios[0][i].xTeta2;
        }


        for(k=1;k<nCamadasOcultas+2;k++)
        {
            for(j=0;j<nNosDeEntrada[k];j++)
            {
                fin>>cTemp;
                fin>>xNeuronios[k][j].xSaida1;

                fin>>cTemp;
                fin>>xNeuronios[k][j].xAlvo;

                fin>>cTemp;
                fin>>xNeuronios[k][j].xDelta;

                fin>>cTemp;
                fin>>xNeuronios[k][j].xTeta1;

                fin>>cTemp;
                fin>>xNeuronios[k][j].xTeta2;

                for(i=0;i<nNosDeEntrada[k-1];i++)
                {
                    fin>>cTemp;
                    fin>>xNeuronios[k][j].xPeso1[i];

                }

                for(i=0;i<nNosDeEntrada[k-1];i++)
                {
                    fin>>cTemp;
                    fin>>xNeuronios[k][j].xPeso2[i];
                }
            }
        }


        xMaxValorEntradas=new double[nNosDeEntrada[0]];   
        xMinValorEntradas=new double[nNosDeEntrada[0]];   

        xMaxValorSaidas=new double[nNosDeEntrada[nCamadasOcultas+1]];
        xMinValorSaidas=new double[nNosDeEntrada[nCamadasOcultas+1]];
        for(i=0;i<nNosDeEntrada[0];i++)
        {
            fin>>cTemp;
            fin>>xMaxValorEntradas[i];
            fin>>cTemp;
            fin>>xMinValorEntradas[i];

        }

         for(i=0;i<nNosDeEntrada[nCamadasOcultas+1];i++)
        {
            fin>>cTemp;
            fin>>xMaxValorSaidas[i];
            fin>>cTemp;
            fin>>xMinValorSaidas[i];
        }
        fin.close();
    }

    void Reconhece(void)
    {
        double xSoma=0.0;
        erroMedQuad=0.0;
        for(k=1;k<nCamadasOcultas+2;k++)
            for(j=0;j<nNosDeEntrada[k];j++)
            {
                xSoma=0.0;
                for(i=0;i<nNosDeEntrada[k-1];i++)
                    xSoma+=xNeuronios[k][j].xPeso1[i]*xNeuronios[k-1][i].xSaida1;
                xNeuronios[k][j].xSaida1=1.0/(1.0+exp(-(xSoma-xNeuronios[k][j].xTeta1)));
            }
    }

    double ImprimeResultadoReconhecimento(int xSaidaTreinamento)
    {
        double xTemp=0.0;
        xTemp=xNeuronios[nCamadasOcultas+1][xSaidaTreinamento].xSaida1*(xMaxValorSaidas[xSaidaTreinamento]-xMinValorSaidas[xSaidaTreinamento])+xMinValorSaidas[xSaidaTreinamento];
        return xTemp;
    }

    double tangentehiperbolica2(double valor) {
        double val = exp(2 * valor);
        return ((val - 1) / (val + 1));
    }

    double tangentehiperbolica1(double valor,double limSup, double limInf) {
        double a = (2 * valor) / (limSup - limInf);
        double val = (((limSup - limInf) / 2) * tangentehiperbolica2(a * val)) + ((limSup  + limInf) / 2);
        return (val);
    }


    double logistica(double valor,double limSup, double limInf,double taxa) {
        double x =0;

        double y = (x - limInf) / (limSup - limInf);
        y = taxa * y * (1 - y);
        x = ((limSup - limInf) * y) + limInf;
        return x;
    }
};
