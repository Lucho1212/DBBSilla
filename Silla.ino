#include "datos_silla.h"
int i=0; //variable inicial en 0
int j=0; //variable inicial en 0
int total=0; //variable inicial en 0
int etiqueta=0; //variable inicial en 0
float matriz_p [4][5];// matriz de los promedios de cada columna
float matriz_n [308];// matriz de la normalizada de cada columna
float matriz_np [3];// matriz valor mayor de la normalizada
float matriz_val1[50][5];// matriz base de datos reducidad
int col=0;//variable inicial en 0
int fil=0; //variable inicial en 0
float promedio; //variable inicial 
float sumatoria; //variable inicial
float dist_total;//variable inicial 
float dist_mayor=0;//variable inicial 
int num1=0;
int num2=0;
int num3=0;
int num4=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
knn2(0.22,0.24); // llamamos la funcion Knn2 -> encontar la base de datos reducia
}                // Se ingresa el rango 
void loop() {
}
   
float knn2 (float rangomin, float rangomax) // funcion necesita ingrear valor en tipo flotantes
{
   for(;fil<208;fil++)
  {
    if(matriz[fil][4]== 1)
    num1++; // 48
    if(matriz[fil][4]== 2)
    num2++; // 60 
    if(matriz[fil][4]== 3)
    num3++; // 20
    if(matriz[fil][4]== 4)
    num4++; // 80
    }
  fil=0;
 col=0;
  for(;col<4;col++){ // columnas son 4 por lo que menores de 4 porque empieza desde cero
  for(;fil<num1;fil++) // recorre las filas
  {
  sumatoria=sumatoria + matriz[fil][col]; // suma toda fila que va recorriendo
  }
  promedio=sumatoria/num1; // la suma total divide para 40 y saca el promedio
  matriz_p[0][col]=promedio; // se guarda en la matriz promedio el promedio de cada una de las columnas de los tipos de flor 
  fil=0;  // inicializamos de nuevo a cero
  sumatoria=0; // inicializamos de nuevo a cero
  promedio=0;
}

col=0; // inicializamos de nuevo a cero
fil=num1; // apara q el valor de i tome un nuevo valor
  for(;col<4;col++){ // columnas son 4 por lo que menores de 4 porque empieza desde cero
  for(;fil<num2+num1;fil++) // recorre las filas
  {
  sumatoria=sumatoria + matriz[fil][col]; // suma toda fila que va recorriendo
  }
  promedio=sumatoria/num2; // la suma total divide para 40 y saca el promedio
  matriz_p[1][col]=promedio; // se guarda en la matriz promedio el promedio de cada una de las columnas de los tipos de flor 
  sumatoria=0; // inicializamos de nuevo a cero
  promedio=0;
  fil=num1;
}

col=0; // inicializamos de nuevo a cero
fil=num1+num2;
  for(;col<4;col++){ // columnas son 4 por lo que menores de 4 porque empieza desde cero
  for(;fil<num3+num1+num2;fil++) // recorre las filas
  {
  sumatoria=sumatoria + matriz[fil][col]; // suma toda fila que va recorriendo
  }
  promedio=sumatoria/num3; // la suma total divide para 40 y saca el promedio
  Serial.println(promedio);
   matriz_p[2][col]=promedio; // se guarda en la matriz promedio el promedio de cada una de las columnas de los tipos de flor 
fil=num1+num2;
  sumatoria=0; // inicializamos de nuevo a cero
  promedio=0;
}
 
col=0; // inicializamos de nuevo a cero
fil=num1+num2+num3;
  for(;col<4;col++){ // columnas son 4 por lo que menores de 4 porque empieza desde cero
  for(;fil<num2+num1+num3+num4;fil++) // recorre las filas
  {
  sumatoria=sumatoria + matriz[fil][col]; // suma toda fila que va recorriendo
  }
  promedio=sumatoria/num4; // la suma total divide para 40 y saca el promedio
   matriz_p[3][col]=promedio; // se guarda en la matriz promedio el promedio de cada una de las columnas de los tipos de flor 
fil=num1+num2+num3;
  sumatoria=0; // inicializamos de nuevo a cero
  promedio=0;
} 
fil=0;
col=0;

/*
for(;fil<208;fil++)
{
  for(;col<5;col++)
  {
    Serial.print(matriz_p[fil][col]);
    Serial.print(",");
    }
    Serial.println("");
    col=0;
  }
*/

 
fil=0; // inicializamos de nuevo a cero
col=0; // inicializamos de nuevo a cero
etiqueta=0; // inicializamos de nuevo a cero
i=0; // inicializamos de nuevo a cero

sumatoria=0;
  for(;etiqueta<4;etiqueta++){  
  for(fil=i;fil<77*etiqueta;fil++){
  for(;col<4;col++){
  sumatoria=sumatoria + pow((matriz[fil][col]- matriz_p[etiqueta-1][col]),2); //sacar las distancias de cada columna con su promedio
   }
  dist_total=sqrt(sumatoria); // sacar raiz cuadrada de la sumatoria
    matriz_n[fil]=dist_total; // guardar ese valor en la matriz normalizada
    if(dist_total>dist_mayor) // vamos a encontrar el valor mayor de la normalizada 
  {
    dist_mayor=dist_total;
    matriz_np[etiqueta-1]=dist_mayor; // guardamos el valor mayor en la normalizada 
    }
  col=0; // inicializamos de nuevo a cero
  dist_total=0; // inicializamos de nuevo a cero
  sumatoria=0; // inicializamos de nuevo a cero
  
}
dist_mayor=0; // inicializamos de nuevo a cero
fil=0; // inicializamos de nuevo a cero
i=77*etiqueta; // multiplicamos para cambiar valor de i
  }
  col=0;
  fil=0;
  etiqueta=0;
  sumatoria=0;
  for(;etiqueta<4;etiqueta++){
  for(fil=i;fil<77*etiqueta;fil++) // recorre la fila
  {
  sumatoria=matriz_n[fil] / matriz_np[etiqueta-1]; // divide la la matriz normalizada con la matriz del valor maximo de la normalizada dejando todo en funcion de 0 a 1
 //Serial.print(sumatoria);
   if((sumatoria <= rangomax)& (sumatoria >= rangomin)) // ese valor si entra en el rango se almacena en la nueva matriz
   {
    matriz_val1[j][0]=matriz[fil][0]; // se almacena los datos en la nueva matriz que cumplen el rango
   matriz_val1[j][1]=matriz[fil][1]; // se almacena los datos en la nueva matriz que cumplen el rango
   matriz_val1[j][2]=matriz[fil][2]; // se almacena los datos en la nueva matriz que cumplen el rango
   matriz_val1[j][3]=matriz[fil][3]; // se almacena los datos en la nueva matriz que cumplen el rango
   matriz_val1[j][4]=matriz[fil][4]; // se almacena los datos en la nueva matriz que cumplen el rango
    j++; // conocer cuantos datos sera nuestra tabla reducida
    }
   sumatoria=0;
  }
  i=77*etiqueta;
  }
   col=0;
fil=0;
for(;fil<50;fil++)
  {
    for(;col<5;col++)
    {
Serial.print(matriz_val1[fil][col]); // imprimir nuestra tabla reducida
Serial.print(",");
  }
Serial.println("");  
  col=0;
  }


  
}


