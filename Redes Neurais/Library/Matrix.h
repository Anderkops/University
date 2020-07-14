/**
 *Title: AIR_BPNN-C++ Class
 *Description: Neural Network Class
 *Copyright: Copyleft (c) 2002 (See gpl.txt for details)
 *Company: www.air-robot.net
 *Author M. T. Li (mtli0913@yahoo.com)
 *Version 1.0 ; 2000.10.24 ; M. T. Li ; Rewriting from AIR_BPNN_Learn-C
 *Version 1.1 ; 2000.11.24 ; M. T. Li ; debug
 *Version 1.2 ; 2000.11.25 ; M. T. Li ; Parameter output
 *Version 1.3 ; 2000.11.25 ; M. T. Li ; Optimization
 *Version 1.4 ; 2001.04.06 ; M. T. Li ; Input array
 *Version 2.0 ; 2001.04.07 ; M. T. Li ; Show the sample
 *Version 2.1 ; 2001.04.08 ; M. T. Li ; Sample editor
 *Version 2.2 ; 2002.07.28 ; M. T. Li ; Distribute by GPL
 *Version 2.3 ; 2002.11.24 ; M. T. Li ; English version
 */


class Matrix2D
{
public:
        int xTam;
        int yTam;
        double **arrvalor; 
   
        void Instancia(int iX,int iY)
        {
            deucerto=true;
            xTam=iX;
            yTam=iY;
            arrvalor=new double*[xTam];
            for(int i=0;i<xTam;i++)
                arrvalor[i]=new double[yTam];
        }

        void Libera(void)
        {
            if(deucerto==true)
            {
                for(int i=0;i<xTam;i++)
                    delete [] arrvalor[i];

                delete [] arrvalor;
                deucerto=false;
            }
        }

private:
        bool deucerto;
};


