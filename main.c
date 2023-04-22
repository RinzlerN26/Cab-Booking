#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char y[]="Y", n[]="n", book[]="book", cancel[]="cancel", showbookings[]="showbookings";
char help[]="help", ext[]="exit", pickuploc[10], droploc[10], input[20];
char ghaziabad[]="Ghaziabad", agra[]="Agra", lucknow[]="Lucknow", meerut[]="Meerut";
char amrit[]="Amrit", abhinay[]="Abhinay", karan[]="Karan";
char sharma[]="Sharma", pandey[]="Pandey", singh[]="Singh";
char maruti[]="Maruti Alto", suzuki[]="Suzuki Swift", honda[]="Honda Civic";
char red[]="Red", black[]="Black", white[]="White";
char n1[]="UP17D1211", n2[]="GJ12A1156", n3[]="DL11G78645";
char booked[]="Booked", cancelled[]="Cancelled";
int i=0, j, k;
struct driverandcardetails
{
char drivername[10], driversurname[10], carmodel[20], carcolour[10], carlicensenumber[10];
};
struct driverandcardetails a[3];
struct booking_details
{
char pickup_loc[50],drop_loc[50], driver_name[10], driver_surname[10], car_model[20];
char car_colour[10], car_license_number[10], status[10];
int pickup_time, estjourneyduration, fare, distance;
};
struct booking_details x[10];
int dcd()
{
strcpy(a[0].drivername, amrit);
strcpy(a[1].drivername, abhinay);
strcpy(a[2].drivername, karan);
strcpy(a[0].driversurname, sharma);
strcpy(a[1].driversurname, pandey);
strcpy(a[2].driversurname, singh);
strcpy(a[0].carmodel, maruti);
strcpy(a[1].carmodel, suzuki);
strcpy(a[2].carmodel, honda);

strcpy(a[0].carcolour, red);
strcpy(a[1].carcolour, black);
strcpy(a[2].carcolour, white);
strcpy(a[0].carlicensenumber, n1);
strcpy(a[1].carlicensenumber, n2);
strcpy(a[2].carlicensenumber, n3);
j=rand( ) % 3;
strcpy(x[i].driver_name, a[j].drivername);
j=rand( ) % 3;
strcpy(x[i].driver_surname, a[j].driversurname);
j=rand( ) % 3;
strcpy(x[i].car_model, a[j].carmodel);
j=rand( ) % 3;
strcpy(x[i].car_colour, a[j].carcolour);
j=rand( ) % 3;
strcpy(x[i].car_license_number, a[j].carlicensenumber);
strcpy(x[i].status, booked);
return 0;
}
int fdt(char pickuploc[], char droploc[])
{
if((strcmpi(pickuploc,"Ghaziabad")==0 || strcmpi(droploc,"Ghaziabad")==0) && (strcmpi(pickuploc, "Agra")==0 || strcmpi(droploc, "Agra")==0))
{
x[i].fare=1449;
x[i].estjourneyduration=3;
x[i].distance=207;
}
else if((strcmpi(pickuploc, "Ghaziabad")==0 || strcmpi(droploc, "Ghaziabad")==0) && (strcmpi(pickuploc, "Meerut")==0 || strcmpi(droploc, "Meerut")==0))
{
x[i].fare=378;
x[i].estjourneyduration=2;
x[i].distance=54;
}
else if((strcmpi(pickuploc, "Ghaziabad")==0 || strcmpi(droploc, "Ghaziabad")==0) && (strcmpi(pickuploc, "Lucknow")==0 || strcmpi(droploc, "Lucknow")==0))
{
x[i].fare=3703;
x[i].estjourneyduration=7;
x[i].distance=529;
}

else if((strcmpi(pickuploc, "Agra")==0 || strcmpi(droploc, "Agra")==0) && (strcmpi(pickuploc, "Meerut")==0 ||strcmpi(droploc, "Meerut")==0))
{
x[i].fare=1848;
x[i].estjourneyduration=5;
x[i].distance=264;
}
else if((strcmpi(pickuploc, "Agra")==0 || strcmpi(droploc, "Agra")==0) && (strcmpi(pickuploc, "Lucknow")==0 || strcmpi(droploc, "Lucknow")==0))
{
x[i].fare=2359;
x[i].estjourneyduration=5;
x[i].distance=337;
}
else if((strcmpi(pickuploc, "Lucknow")==0 || strcmpi(droploc, "Lucknow")==0) && (strcmpi(pickuploc, "Meerut")==0 || strcmpi(droploc, "Meerut")==0))
{
x[i].fare=4116;
x[i].estjourneyduration=9;
x[i].distance=588;
}
return 0;
}
int book_cab()
{
labelA:
printf("===========================\nPickup locations available:\n===========================\nGhaziabad\nMeerut\nAgra\nLucknow\n\n");
printf("=========================\nDrop locations available:\n=========================\nGhaziabad\nMeerut\nAgra\nLucknow\n\n");
printf("Enter pickup location.\nInput>>>");
gets(input);
strcpy(pickuploc, input);
printf("Enter drop location.\nInput>>>");
gets(input);
strcpy(droploc, input);
labelB:
printf("========\nConfirm!\n========\nPickup location:%s\nDrop location:%s\nY/n?",pickuploc,droploc);
printf("\nInput>>>");
gets(input);
if(strcmpi(input, y)==0)
{
strcpy(x[i].pickup_loc, pickuploc);
strcpy(x[i].drop_loc, droploc);
}
else if(strcmpi(input, n)==0)

{
goto labelA;
}
else
{
goto labelB;
}
labelC:
printf("\nWhen to pickup(time)?\n");
printf("Input>>>");
scanf("%d",&x[i].pickup_time);
if(x[i].pickup_time>6 && x[i].pickup_time<24);
else
{
printf("\nInvalid time input! Try again.\n");
goto labelC;
}
fdt(x[i].pickup_loc, x[i].drop_loc); //Fare, distance and time.
dcd();//Driver and car details
printf("\n===================\nBooking Successful!\n===================");
printf("\nDriver name:%s %s",x[i].driver_name,x[i].driver_surname);
printf("\nCar model:%s",x[i].car_model);
printf("\nCar colour:%s",x[i].car_colour);
printf("\nCar license number:%s",x[i].car_license_number);
printf("\nFare(RS):%d",x[i].fare);
printf("\nDistance:%d",x[i].distance);
printf("\nEstimated travel time:%d",x[i].estjourneyduration);
i++;
return 0;
}
int show_bookings()
{
for(k=0; k<1; k++)
{
printf("\n================\nBooking number:%d\n================",k+1);
printf("\nStatus:%s",x[k].status);
printf("\nPickup location:%s",x[k].pickup_loc);
printf("\nDrop location:%s",x[k].drop_loc);
printf("\nDriver name:%s %s",x[k].driver_name,x[k].driver_surname);
printf("\nCar model:%s",x[k].car_model);
printf("\nCar color:%s",x[k].car_colour);
printf("\nCar license number:%s",x[k].car_license_number);
printf("\nFare(RS):%d",x[k].fare);
printf("\nDistance:%d",x[k].distance);
printf("\nEstimated travel time:%d",x[k].estjourneyduration);
}
return 0;

}
int user_input_processor(char input[])
{
if(strcmpi(input, help)==0)
{
printf("\n==========\nHelp Menu!\n==========\nEnter 'book' to book a cab.\nEnter 'showbookings' to view your current bookings.\nEnter 'cancel' to cancel a booking.\nEnter 'exit' to exit the app.\n\n");
printf("Input>>>");
gets(input);
user_input_processor(input);
}
else if(strcmpi(input, ext)==0)
{
return 0;
}
else if(strcmpi(input, book)==0)
{
book_cab();
printf("\nInput>>>");
gets(input);
user_input_processor(input);
}
else if(strcmpi(input, showbookings)==0)
{
show_bookings();
printf("\n\nInput>>> ");
gets(input);
user_input_processor(input);
}
else if(strcmpi(input,cancel)==0)
{
show_bookings();
printf("\nEnter booking number-1 to cancel.\n");
printf("Input>>> ");
scanf("%d",&k);
strcpy(x[k].status,"canceled");
puts(x[k].status);
printf("Input>>> ");
gets(input);
user_input_processor(input);
}
else
{
gets(input);
user_input_processor(input);
}
return 0;
}
int main()
{
printf("Welcome to My Cabs App Alpha.\nInput 'help' for a list of commands.\n");
printf("Input>>> ");
gets(input);
user_input_processor(input);
printf("\nThank you for choosing My Cabs App! Hope to see you soon again.");
return 0;
}

