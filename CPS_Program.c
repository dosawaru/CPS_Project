#include <stdio.h>
#include <stdlib.h>
#define DAYS_IN_YEAR 365

void Part1(double dataset[365][8])
{
    double superior, michigan, huron, erie, ontario, clair;
    double total1 = 0, total2 = 0, total3 , total4 = 0, total5 = 0, total6 = 0, total = 0;

    for(int z = 0; z<365; z++)
    {
        total1 += dataset[z][2];
        total2 += dataset[z][3];
        total3 += dataset[z][4];
        total4 += dataset[z][5];
        total5 += dataset[z][6];
        total6 += dataset[z][7];
    }

    superior = total1/365;
    michigan = total2/365;
    huron = total3/365;
    erie = total4/365;
    ontario = total5/365;
    clair = total6/365;
    total =(superior + michigan + huron + erie + ontario + clair)/6;

    printf("Average Temperatures for Each Lake:\n");
    printf("Lake Superior\t %0.2lf\n", superior);
    printf("Lake Michigan\t %0.2lf\n", michigan);
    printf("Lake Huron\t %0.2lf\n", huron);
    printf("Lake Erie\t %0.2lf\n", erie);
    printf("Lake Ontario\t %0.2lf\n", ontario);
    printf("Lake St. Clair\t %0.2lf\n", clair);
    printf("\nYearly average for all six lakes together %0.2lf\n", total);
}

void Part2(double dataset[365][8])
{
    double total1 = 0,total2 = 0,total3 = 0,total4 = 0,total5 = 0,total6 = 0,total=0;
    int counter = 0;
    double superior = 0, michigan = 0, huron = 0, erie = 0, ontario = 0, clair = 0;
    double x, coldest, hottest;

    for(int z = 0; z < 365; z++)
    {
        total1 += dataset[z][2];
        total2 += dataset[z][3];
        total3 += dataset[z][4];
        total4 += dataset[z][5];
        total5 += dataset[z][6];
        total6 += dataset[z][7];
    }

    superior = total1/365;
    michigan = total2/365;
    huron = total3/365;
    erie = total4/365;
    ontario = total5/365;
    clair = total6/365;
    total = (superior + michigan + huron + erie + ontario + clair)/6;

    double temp[6] = {superior, michigan, huron, erie, ontario, clair};

    for (int L = 0; L < 6; L++)
    {
        x = temp[L];

        if (counter == 0)
        {
            hottest = x;
            coldest = x;
        }
        if (x >hottest)
        {
            hottest = x;
        }
        else if(x <coldest)
        {
            coldest = x;
        }
        counter++;
    }

  if (hottest==superior)
    printf("The warmest lake is Lake Superior with temperature of %0.2lf\n\n", hottest);
  else if(coldest==superior)
    printf("The coldest Lake is Lake Superior with temperature of %0.2lf\n", coldest);

  if (hottest==michigan)
    printf("The warmest lake is Lake Michigan with temperature of %0.2lf\n\n", hottest);
  else if(coldest==michigan)
    printf("The coldest Lake is Lake Michigan with temperature of %0.2lf\n", coldest);

  if (hottest==ontario)
    printf("The warmest lake is Lake Ontario with temperature of %0.2lf\n\n", hottest);
  else if(coldest==ontario)
    printf("The coldest Lake is Lake Ontario with temperature of %0.2lf\n", coldest);

    if (hottest==erie)
    printf("The warmest lake is Lake Erie with temperature of %0.2lf\n\n", hottest);
  else if(coldest==erie)
    printf("The coldest Lake is Lake Erie with temperature of %0.2lf\n", coldest);

    if (hottest==huron)
    printf("The warmest lake is Lake Huron with temperature of %0.2lf\n\n", hottest);
  else if(coldest==huron)
    printf("The coldest Lake is Lake Huron with temperature of %0.2lf\n", coldest);

    if (hottest==clair)
    printf("The warmest lake is Lake St. Clair with temperature of %0.2lf\n\n", hottest);
  else if(coldest==clair)
    printf("The woldest Lake is Lake St. Clair with temperature of %0.2lf\n", coldest);

    char lake[6][20] = {"Superior", "Michigan", "Huron", "Erie", "Ontario", "St. Clair"};

    for(int L = 0; L < 6; L++)
    {
        x = temp[L];

        if(x == hottest)
        {
            printf("The warmest lake is Lake %s with temperature of %0.2lf\n\n", lake[L], hottest);
        }
        else if(x == coldest)
        {
            printf("The coldest lake is Lake %s with temperature of %0.2lf\n", lake[L], coldest);
        }
    }

    for(int L = 0; L < 6; L++)
    {
        x = temp[L];

        if(x > total)
        {
            printf("Lake %s is above average temperature\n", lake[L]);
        }
        else
        {
            printf("Lake %s is below average temperature\n", lake[L]);
        }
    }
}

/* Part 4 (Beginning) */

void get_warmest_lake(double lake_data[6][3]){

  int counter;
  double warmest_lake_temp = lake_data[0][0];

  for(int i = 0; i < 6; i++){
    if(lake_data[i][0] > warmest_lake_temp){
      warmest_lake_temp = lake_data[i][0];
      counter = i;
    }
  }

  char *lake;

  if(counter == 0){
    lake = "Superior";
  }else if(counter == 1){
    lake = "Michigan";
  }else if(counter == 2){
    lake = "Huron";
  }else if(counter == 3){
    lake = "Erie";
  }else if(counter == 4){
    lake = "Ontario";
  }else if(counter == 5){
    lake = "St.Clair";
  }

  printf("The warmest lake was %s with a temperature of %.2lf in %.0lf/%.0lf\n", lake, warmest_lake_temp, lake_data[counter][1], lake_data[counter][2]);
}

void get_coldest_lake(double lake_data[6][3]){

  int counter;
  double coldest_lake_temp = lake_data[0][0];

  for(int i = 0; i < 6; i++){
    if(lake_data[i][0] < coldest_lake_temp){
      coldest_lake_temp = lake_data[i][0];
      counter = i;
    }
  }

  char *lake;

  if(counter == 0){
    lake = "Superior";
  }else if(counter == 1){
    lake = "Michigan";
  }else if(counter == 2){
    lake = "Huron";
  }else if(counter == 3){
    lake = "Erie";
  }else if(counter == 4){
    lake = "Ontario";
  }else if(counter == 5){
    lake = "St.Clair";
  }

  printf("The coldest lake was %s with a temperature of %.2lf in %.0lf/%.0lf\n", lake, coldest_lake_temp, lake_data[counter][1], lake_data[counter][2]);
}

void part4(double cold_lake_data[6][3], double warm_lake_data[6][3]){

  printf("\n");

  get_coldest_lake(cold_lake_data);
  get_warmest_lake(warm_lake_data);
}

/*Part 4 (Ending)*/

/*Part 3 (Beginning)*/

void date_year(int day, int *month, int *day_month){
  int current_month, current_day;

  if(day >= 1 && day <= 31){
    current_month = 1;
    current_day = day;
  }else if (day > 31 && day <= 59){
    current_month = 2;
    current_day = day - 31;
  }else if (day > 59 && day <= 90){
    current_month = 3;
    current_day = day - 59;
  }else if (day > 90 && day <= 120){
    current_month = 4;
    current_day = day - 90;
  }else if (day > 120 && day <= 151){
    current_month = 5;
    current_day = day - 120;
  }else if (day > 151 && day <= 181){
    current_month = 6;
    current_day = day - 151;
  }else if (day > 181 && day <= 212){
    current_month = 7;
    current_day = day - 181;
  }else if (day >= 212 && day <= 243){
    current_month = 8;
    current_day = day - 212;
  }else if (day > 243 && day <= 273){
    current_month = 9;
    current_day = day - 243;
  }else if (day > 273 && day <= 304){
    current_month = 10;
    current_day = day - 273;
  }else if (day > 304 && day <= 334){
    current_month = 11;
    current_day = day - 304;
  }else if (day > 334 && day <= 365){
    current_month = 12;
    current_day = day - 334;
  }

  *month = current_month;
  *day_month = current_day;
}

double cold(double lake_temps[], int array_length, int *day_year){

  double coldest_temp = lake_temps[0];
  int counter = 0;

  for(int i = 0; i < array_length; i++){
    if(lake_temps[i] < coldest_temp){
      coldest_temp = lake_temps[i];
      counter = i;
    }
  }

  *day_year = counter;
  return coldest_temp;
}

double warm(double lake_temps[], int array_length, int *day_year){

  double warmest_temp = lake_temps[0];
  int counter;

  for(int i = 0; i < array_length; i++){
    if(lake_temps[i] > warmest_temp){
      warmest_temp = lake_temps[i];
      counter = i;
    }
  }

  *day_year = counter;
  return warmest_temp;
}

void part3(char *str/*, double *pt_cold_lake_data, double *pt_warm_lake_data*/){

  int month, day_month, day_year_superior, day_year_michigan, day_year_huron, day_year_erie, day_year_ontario, day_year_stclair;
  int year[DAYS_IN_YEAR], day[DAYS_IN_YEAR];
  double lake_superior[DAYS_IN_YEAR], lake_michigan[DAYS_IN_YEAR], lake_huron[DAYS_IN_YEAR], lake_erie[DAYS_IN_YEAR], lake_ontario[DAYS_IN_YEAR], lake_stclair[DAYS_IN_YEAR];
  double cold_lake_data[6][3];
  double warm_lake_data[6][3];

  FILE *file = fopen(str, "r");
  for(int i = 0; i < DAYS_IN_YEAR; i++){
    fscanf (file,"%d %d %lf %lf %lf %lf %lf %lf", &year[i], &day[i], &lake_superior[i], &lake_michigan[i], &lake_huron[i], &lake_erie[i], &lake_ontario[i], &lake_stclair[i]);
  }

  fclose(file);

  double warmest_temp_superior = warm(lake_superior, DAYS_IN_YEAR, &day_year_superior);
  date_year(day_year_superior, &month, &day_month);
  warm_lake_data[0][0] = warmest_temp_superior;
  warm_lake_data[0][1] = day_month + 1;
  warm_lake_data[0][2] = month;
  printf("Lake Superior warmest temperature was %.2lf in %d/%d\n", warmest_temp_superior, day_month + 1, month);

  double warmest_temp_michigan = warm(lake_michigan, DAYS_IN_YEAR, &day_year_michigan);
  date_year(day_year_michigan, &month, &day_month);
  warm_lake_data[1][0] = warmest_temp_michigan;
  warm_lake_data[1][1] = day_month + 1;
  warm_lake_data[1][2] = month;
  printf("Lake Michigan warmest temperature was %.2lf in %d/%d\n", warmest_temp_michigan, /*day_month +*/ 1, month+1);

  double warmest_temp_huron = warm(lake_huron, DAYS_IN_YEAR, &day_year_huron);
  date_year(day_year_huron, &month, &day_month);
  warm_lake_data[2][0] = warmest_temp_huron;
  warm_lake_data[2][1] = day_month + 1;
  warm_lake_data[2][2] = month;
  printf("Lake Huron warmest temperature was %.2lf in %d/%d\n", warmest_temp_huron, day_month + 1, month);

  double warmest_temp_erie = warm(lake_erie, DAYS_IN_YEAR, &day_year_erie);
  date_year(day_year_erie, &month, &day_month);
  warm_lake_data[3][0] = warmest_temp_erie;
  warm_lake_data[3][1] = day_month + 1;
  warm_lake_data[3][2] = month;
  printf("Lake Erie warmest temperature was %.2lf in %d/%d\n", warmest_temp_erie, day_month + 1, month);

  double warmest_temp_ontario = warm(lake_ontario, DAYS_IN_YEAR, &day_year_ontario);
  date_year(day_year_ontario, &month, &day_month);
  warm_lake_data[4][0] = warmest_temp_ontario;
  warm_lake_data[4][1] = day_month + 1;
  warm_lake_data[4][2] = month;
  printf("Lake Ontario warmest temperature was %.2lf in %d/%d\n", warmest_temp_ontario, day_month + 1, month);

  double warmest_temp_stclair = warm(lake_stclair, DAYS_IN_YEAR, &day_year_stclair);
  date_year(day_year_stclair, &month, &day_month);
  warm_lake_data[5][0] = warmest_temp_stclair;
  warm_lake_data[5][1] = day_month + 1;
  warm_lake_data[5][2] = month;
  printf("Lake St.Clair warmest temperature was %.2lf in %d/%d\n", warmest_temp_stclair, day_month + 1, month);

  printf("\n");

 double coldest_temp_superior = cold(lake_superior, DAYS_IN_YEAR, &day_year_superior);
  date_year(day_year_superior, &month, &day_month);
  cold_lake_data[0][0] = coldest_temp_superior;
  cold_lake_data[0][1] = day_month + 1;
  cold_lake_data[0][2] = month;
  printf("Lake Superior coldest temperature was %.2lf in %d/%d\n", coldest_temp_superior, day_month + 1, month);

  double coldest_temp_michigan = cold(lake_michigan, DAYS_IN_YEAR, &day_year_michigan);
  date_year(day_year_michigan, &month, &day_month);
  cold_lake_data[1][0] = coldest_temp_michigan;
  cold_lake_data[1][1] = day_month + 1;
  cold_lake_data[1][2] = month;
  printf("Lake Michigan coldest temperature was %.2lf in %d/%d\n", coldest_temp_michigan, day_month + 1, month);

  double coldest_temp_huron = cold(lake_huron, DAYS_IN_YEAR, &day_year_huron);
  date_year(day_year_huron, &month, &day_month);
  cold_lake_data[2][0] = coldest_temp_huron;
  cold_lake_data[2][1] = day_month + 1;
  cold_lake_data[2][2] = month;
  printf("Lake Huron coldest temperature was %.2lf in %d/%d\n", coldest_temp_huron, day_month + 1, month);

  double coldest_temp_erie = cold(lake_erie, DAYS_IN_YEAR, &day_year_erie);
  date_year(day_year_erie, &month, &day_month);
  cold_lake_data[3][0] = coldest_temp_erie;
  cold_lake_data[3][1] = day_month + 1;
  cold_lake_data[3][2] = month;
  printf("Lake Erie coldest temperature was %.2lf in %d/%d\n", coldest_temp_erie, day_month + 1, month);

  double coldest_temp_ontario = cold(lake_ontario, DAYS_IN_YEAR, &day_year_ontario);
  date_year(day_year_ontario, &month, &day_month);
  cold_lake_data[4][0] = coldest_temp_ontario;
  cold_lake_data[4][1] = day_month + 1;
  cold_lake_data[4][2] = month;
  printf("Lake Ontario coldest temperature was %.2lf in %d/%d\n", coldest_temp_ontario, day_month + 1, month);

  double coldest_temp_stclair = cold(lake_stclair, DAYS_IN_YEAR, &day_year_stclair);
  date_year(day_year_stclair, &month, &day_month);
  cold_lake_data[5][0] = coldest_temp_stclair;
  cold_lake_data[5][1] = day_month + 1;
  cold_lake_data[5][2] = month;
  printf("Lake St.Clair coldest temperature was %.2lf in %d/%d\n", coldest_temp_stclair, day_month + 1, month);

  part4(cold_lake_data, warm_lake_data);
}

/*Part 3 (Ending)*/

void Part5(double dataset[365][8])
{
    double superior, michigan, huron, erie, ontario, clair;
    double total1 = 0, total2 = 0, total3 , total4 = 0, total5 = 0, total6 = 0, total = 0;

    for(int z = 171; z<265; z++)
    {
        total1 += dataset[z][2];
        total2 += dataset[z][3];
        total3 += dataset[z][4];
        total4 += dataset[z][5];
        total5 += dataset[z][6];
        total6 += dataset[z][7];
    }

    superior = total1/94;
    michigan = total2/94;
    huron = total3/94;
    erie = total4/94;
    ontario = total5/94;
    clair = total6/94;

    printf("Average Summer Temperatures for Each Lake:\n");
    printf("Lake Superior\t %0.2lf\n", superior);
    printf("Lake Michigan\t %0.2lf\n", michigan);
    printf("Lake Huron\t %0.2lf\n", huron);
    printf("Lake Erie\t %0.2lf\n", erie);
    printf("Lake Ontario\t %0.2lf\n", ontario);
    printf("Lake St. Clair\t %0.2lf\n", clair);


    double a[6] = {superior, michigan, huron, erie, ontario, clair};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (a[j] > a[i])
            {
                double tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    printf("\nWarmest to coldest: ");
    for (int i = 0; i < 6; i++)
    {
        if(a[i] == superior)
        {
            printf("Superior");
        }
        if(a[i] == michigan)
        {
            printf("Michigan");
        }
        if(a[i] == huron)
        {
            printf("Huron");
        }
        if(a[i] == erie)
        {
            printf("Erie");
        }
        if(a[i] == ontario)
        {
            printf("Ontario");
        }
        if(a[i] == clair)
        {
            printf("St. Clair");
        }
        if(i != 5)
        {
            printf(", ");
        }
    }
}

void Part6(double dataset[365][8])
{
    double superior, michigan, huron, erie, ontario, clair;
    double total1 = 0, total2 = 0, total3 , total4 = 0, total5 = 0, total6 = 0, total = 0;

    for(int z = 0; z<79; z++)
    {
        total1 += dataset[z][2];
        total2 += dataset[z][3];
        total3 += dataset[z][4];
        total4 += dataset[z][5];
        total5 += dataset[z][6];
        total6 += dataset[z][7];
    }

    for(int z = 354; z<365; z++)
    {
        total1 += dataset[z][2];
        total2 += dataset[z][3];
        total3 += dataset[z][4];
        total4 += dataset[z][5];
        total5 += dataset[z][6];
        total6 += dataset[z][7];
    }

    superior = total1/90;
    michigan = total2/90;
    huron = total3/90;
    erie = total4/90;
    ontario = total5/90;
    clair = total6/90;

    printf("Average Winter Temperatures for Each Lake:\n");
    printf("Lake Superior\t %0.2lf\n", superior);
    printf("Lake Michigan\t %0.2lf\n", michigan);
    printf("Lake Huron\t %0.2lf\n", huron);
    printf("Lake Erie\t %0.2lf\n", erie);
    printf("Lake Ontario\t %0.2lf\n", ontario);
    printf("Lake St. Clair\t %0.2lf\n", clair);

    double a[] = {superior, michigan, huron, erie, ontario, clair};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (a[j] < a[i])
            {
                double tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    printf("\nWarmest to coldest: ");
    for (int i = 0; i < 6; i++)
    {
        if(a[i] == superior)
        {
            printf("Superior");
        }
        if(a[i] == michigan)
        {
            printf("Michigan");
        }
        if(a[i] == huron)
        {
            printf("Huron");
        }
        if(a[i] == erie)
        {
            printf("Erie");
        }
        if(a[i] == ontario)
        {
            printf("Ontario");
        }
        if(a[i] == clair)
        {
            printf("St. Clair");
        }
        if(i != 5)
        {
            printf(", ");
        }
    }
}

void Part7(double dataset[365][8])
{
    int total1 = 0, total2 = 0, total3 = 0, total4 = 0, total5 = 0, total6 = 0, total = 0;

    for(int z = 0; z<365; z++)
    {
         if(dataset[z][2]>20)
         {
            total1 += 1;
         }
         if(dataset[z][3]>20)
         {
            total2 += 1;
         }
         if(dataset[z][4]>20)
         {
            total3 += 1;
         }
         if(dataset[z][5]>20)
         {
            total4 += 1;
         }
         if(dataset[z][6]>20)
         {
            total5 += 1;
         }
         if(dataset[z][7]>20)
         {
            total6 += 1;
         }
    }
    printf("Number of Days you can Comfortably Swim in Each Lake:\n");
    printf("Lake Superior\t %d\n", total1);
    printf("Lake Michigan\t %d\n", total2);
    printf("Lake Huron\t %d\n", total3);
    printf("Lake Erie\t %d\n", total4);
    printf("Lake Ontario\t %d\n", total5);
    printf("Lake St. Clair\t %d\n", total6);
}

void Part8(double dataset[365][8])
{
    int total1 = 0, total2 = 0, total3 = 0, total4 = 0, total5 = 0, total6 = 0;

    for(int z = 0; z<365; z++)
    {
         if(dataset[z][2]<0)
         {
            total1 += 1;
         }
         if(dataset[z][3]<0)
         {
            total2 += 1;
         }
         if(dataset[z][4]<0)
         {
            total3 += 1;
         }
         if(dataset[z][5]<0)
         {
            total4 += 1;
         }
         if(dataset[z][6]<0)
         {
            total5 += 1;
         }
         if(dataset[z][7]<0)
         {
            total6 += 1;
         }
    }
    printf("Number of Days Each Lake is Forzen, below 0 degrees:\n");
    printf("Lake Superior\t %d\n", total1);
    printf("Lake Michigan\t %d\n", total2);
    printf("Lake Huron\t %d\n", total3);
    printf("Lake Erie\t %d\n", total4);
    printf("Lake Ontario\t %d\n", total5);
    printf("Lake St. Clair\t %d\n", total6);
}

void dash()
{
    for(int i = 0; i < 25; i++)
    {
        printf("-");
    }
    printf("\n");
}

int main()
{
    double dataset[365][8];
    FILE *in;
    in = fopen("data.txt","r");

    for(int x = 0; x<365; x++)
    {
        for(int y = 0; y<8; y++)
        {
            fscanf(in, "%lf", &dataset[x][y]);
        }
    }

    printf("CPS125 - Term Project - W2019 By: Daniel & Lloyd\n\n");
    printf("**All Temperatures are in Degrees Celsius**\n");
    printf("**Day of the year is outputted as Date/Month**\n");

    printf("\nPart 1\n");
    dash();
    Part1(dataset);
    printf("\nPart 2\n");
    dash();
    Part2(dataset);
    printf("\nPart 3 & Part 4\n");
    dash();
    part3("data.txt");
    printf("\nPart 5\n");
    dash();
    Part5(dataset);
    printf("\n\nPart 6\n");
    dash();
    Part6(dataset);
    printf("\n\nPart 7\n");
    dash();
    Part7(dataset);
    printf("\nPart 8\n");
    dash();
    Part8(dataset);
    fclose(in);

    return(0);
}
