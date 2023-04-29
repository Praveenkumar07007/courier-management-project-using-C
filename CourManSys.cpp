#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct password{ // data-type for storing pin
	int pin;
};
struct addcourier{ // data-type for adding courier
	int cid;
	char cname[30]; // courier name
	char sname[30]; // sender name
	char rname[30]; // reciever name
	int scontact;  // sender contact
	int rcontact;  // reciever contact
	char raddress[50]; // reciever address
	char odate[20]; // courier order date
	char dels[20]; // delivery status
	int dcharge;  // delivery charge
};
void addcourier(){ // function for adding courier
	struct addcourier addc[1];
	FILE *fp;
	fp=fopen("courierdata.txt","a"); // file for storing courier data
	printf(">> Enter courier id: ");
	scanf("%d",&addc[0].cid);
	printf(">> Enter courier name: ");
	scanf("%s",addc[0].cname);
	printf(">> Enter sender name(first): ");
	scanf("%s",addc[0].sname);
	printf(">> Enter reciever name(first): ");
	scanf("%s",addc[0].rname);
	printf(">> Enter sender contact no.: ");
	scanf("%d",&addc[0].scontact);
	printf(">> Enter reciever contact no.: ");
	scanf("%d",&addc[0].rcontact);
	printf(">> Enter delivery address(area_city): ");
	scanf("%s",addc[0].raddress);
	printf(">> Enter courier date(dd/mm/yyyy): ");
	scanf("%s",addc[0].odate);
	printf(">> Enter delivery status(pending/done): ");
	scanf("%s",addc[0].dels);
	printf(">> Enter delivery charge(Rs.): ");
	scanf("%d",&addc[0].dcharge);
	fwrite(&addc[0],sizeof(addc[0]),1,fp);
	printf("\n");
	printf("\n");
	printf("             Courier added successfully\n");
	printf("-------------------------------------------------------\n");
	printf("\n");
	fclose(fp);
}
void showcourier(){ // function for displaying pending courier
	struct addcourier addc[1];
	FILE *fp;
	fp=fopen("courierdata.txt","r");
	printf("*************************************************\n");
	printf("             ....Pending Courier....\n");
	printf("\n");
	while(fread(&addc[0],sizeof(addc[0]),1,fp)){
		int value; // for string comparison
   		value=strcmp(addc[0].dels,"pending");    
		if(value==0){
			printf("-Courier id: %d\n",addc[0].cid);
			printf("-Courier name: %s\n",addc[0].cname);
			printf("-Sender name(first): %s\n",addc[0].sname);
			printf("-Reciever name(first): %s\n",addc[0].rname);
			printf("-Sender contact no.: %d\n",addc[0].scontact);
			printf("-Reciever contact no.: %d\n",addc[0].rcontact);
			printf("-Delivery address: %s\n",addc[0].raddress);
			printf("-Courier date(dd/mm/yyyy): %s\n",addc[0].odate);
			printf("-Delivery status(pending/done): %s\n",addc[0].dels);
			printf("-Delivery charge(Rs.): %d\n",addc[0].dcharge);
			printf("--------------------------------------------\n");
			printf("\n");
		}
	}
	fclose(fp);
	printf("*************************************************\n");
}
void searchcourier(){ // function for tracking courier
	int findid; // courier id to track
	printf("Enter the courier id: ");
	scanf("%d",&findid);
	struct addcourier addc[1];
	printf("*************************************************\n");
	printf("            ....Search Output....\n");
	printf("\n");
	FILE *fp;
	fp=fopen("courierdata.txt","r");
	while(fread(&addc[0],sizeof(addc[0]),1,fp)){
		if(addc[0].cid==findid){
			printf("-Courier id: %d\n",addc[0].cid);
			printf("-Courier name: %s\n",addc[0].cname);
			printf("-Sender name(first): %s\n",addc[0].sname);
			printf("-Reciever name(first): %s\n",addc[0].rname);
			printf("-Sender contact no.: %d\n",addc[0].scontact);
			printf("-Reciever contact no.: %d\n",addc[0].rcontact);
			printf("-Delivery address: %s\n",addc[0].raddress);
			printf("-Courier date(dd/mm/yyyy): %s\n",addc[0].odate);
			printf("-Delivery status(pending/done): %s\n",addc[0].dels);
			printf("-Delivery charge(Rs.): %d\n",addc[0].dcharge);
			printf("--------------------------------------------\n");
			printf("\n");
		}
	}
	fclose(fp);
	printf("*************************************************\n");
}
void delcourier(){ // function for displaying delivered courier
	struct addcourier addc[1];
	printf("*************************************************\n");
	printf("            ....Delivered Courier....\n");
	printf("\n");
	FILE *fp;
	fp=fopen("courierdata.txt","r");
	while(fread(&addc[0],sizeof(addc[0]),1,fp)){
		int value; 
   		value=strcmp(addc[0].dels,"done");    
		if(value==0){
			printf("-Courier id: %d\n",addc[0].cid);
			printf("-Courier name: %s\n",addc[0].cname);
			printf("-Sender name(first): %s\n",addc[0].sname);
			printf("-Reciever name(first): %s\n",addc[0].rname);
			printf("-Sender contact no.: %d\n",addc[0].scontact);
			printf("-Reciever contact no.: %d\n",addc[0].rcontact);
			printf("-Delivery address: %s\n",addc[0].raddress);
			printf("-Courier date(dd/mm/yyyy): %s\n",addc[0].odate);
			printf("-Delivery status(pending/done): %s\n",addc[0].dels);
			printf("-Delivery charge(Rs.): %d\n",addc[0].dcharge);
			printf("--------------------------------------------\n");
			printf("\n");
		}
	}
	fclose(fp);
	printf("*************************************************\n");
}
void updatecourier(){ // function for updating delivery status
	struct addcourier addc[1];
	FILE *fp;
	FILE *fp2;
	fp=fopen("courierdata.txt","r");
	fp2=fopen("courierdata2.txt","w"); // file for storing coueier data temporarly
	int uid; // courier id to update
	printf("Enter courier id to update: ");
	scanf("%d",&uid);
	while(fread(&addc[0],sizeof(addc[0]),1,fp)){//loop continus till freads retun non zero value
		if(addc[0].cid==uid){
			printf("Enter updated delivery status(done): ");
			scanf("%s",addc[0].dels);
			fwrite(&addc[0],sizeof(addc[0]),1,fp2);
		}
		else{
			fwrite(&addc[0],sizeof(addc[0]),1,fp2);
		}
	}
	fclose(fp);
	fclose(fp2);
	fp=fopen("courierdata2.txt","r");
	fp2=fopen("courierdata.txt","w");
	while(fread(&addc[0],sizeof(addc[0]),1,fp)){
		fwrite(&addc[0],sizeof(addc[0]),1,fp2);
	}
	fclose(fp);
	fclose(fp2);
	printf("\n");
	printf("\n");
	printf("          Delivery Updated Successfully\n");
	printf("---------------------------------------------------\n");
	printf("\n");
}
void sortcourier(){ // function for sorting pending courier based on id
	struct addcourier addc[1],temp;
	FILE *fp;
	fp=fopen("courierdata.txt","r");
	int count=0;
	while(fread(&addc[0],sizeof(addc[0]),1,fp)){
		int value; 
   		value=strcmp(addc[0].dels,"pending");    
		if(value==0){
			count++;
		}
	}
	fclose(fp);
	int sortarr[count]; // array for storing courier id
	fp=fopen("courierdata.txt","r");
	int index=0;
	while(fread(&addc[0],sizeof(addc[0]),1,fp)){
		int value; 
   		value=strcmp(addc[0].dels,"pending");    
		if(value==0){
			sortarr[index]=addc[0].cid;
			index++;
		}
	}
	fclose(fp);
	int i,j;
	for(i=0;i<count;i++){  // sorting courier data based on courier id
		for(j=0;j<(count-i-1);j++){
			if(sortarr[j]>sortarr[j+1]){
				int temp;
				temp=sortarr[j];
				sortarr[j]=sortarr[j+1];
				sortarr[j+1]=temp;
			}
		}
	}
	FILE *fptr;
	fptr=fopen("courierdatasort.txt","w"); // file for storing sorted courier data
	for(i=0;i<count;i++){
		fp=fopen("courierdata.txt","r");
		while(fread(&addc[0],sizeof(addc[0]),1,fp)){
			if(addc[0].cid==sortarr[i]){
				fwrite(&addc[0],sizeof(addc[0]),1,fptr);
			}
		}
		fclose(fp);
	}
	fclose(fptr);
	printf("*************************************************\n");
	printf("          ....Sorted Pending Courier....\n");
	printf("\n");
	fptr=fopen("courierdatasort.txt","r");
	while(fread(&addc[0],sizeof(addc[0]),1,fptr)){
		printf("-Courier id: %d\n",addc[0].cid);
		printf("-Courier name: %s\n",addc[0].cname);
		printf("-Sender name(first): %s\n",addc[0].sname);
		printf("-Reciever name(first): %s\n",addc[0].rname);
		printf("-Sender contact no.: %d\n",addc[0].scontact);
		printf("-Reciever contact no.: %d\n",addc[0].rcontact);
		printf("-Delivery address: %s\n",addc[0].raddress);
		printf("-Courier date(dd/mm/yyyy): %s\n",addc[0].odate);
		printf("-Delivery status(pending/done): %s\n",addc[0].dels);
		printf("-Delivery charge(Rs.): %d\n",addc[0].dcharge);
		printf("--------------------------------------------\n");
		printf("\n");	
	}
	fclose(fptr);
}
int enterpin(){  // function for getting pin stored in file
	int access;
	struct password p[1];
	FILE *fp;
	fp=fopen("cpasswd.txt","r"); // file for storing the pin
	fread(&p[0],sizeof(p[0]),1,fp);
	fclose(fp);
	access=p[0].pin;
	return access;
}
void changepin(){ // function for storing the updated pin
	int task=0;
	struct password p[1];
	int upass;  // upass: current pin as input
	FILE *fp;
	fp=fopen("cpasswd.txt","r");
	printf("Enter the current pin: ");
	scanf("%d",&upass);  // upass: input for current pin
	fread(&p[0],sizeof(p[0]),1,fp);
	if(p[0].pin==upass){
		task=1;
	}
	else{
		printf("Invalid Pin, Try Again....\n");
	}
	fclose(fp);
	if(task==1){
		fp=fopen("cpasswd.txt","w");
		printf("Enter the new pin: ");
	    scanf("%d",&p[0].pin);
	    fwrite(&p[0],sizeof(p),1,fp);
		fclose(fp);
		printf("\n");
		printf("             Pin changed successfully\n");
		printf("-------------------------------------------------------\n");
		printf("\n");
	}
}
int main(){
	printf("################################################\n");
	printf("------------- LPU COURIER SERVICES -------------\n");
	printf("\n");
	int epass,apass;  // epass pin input from user, apass system pin
	apass=enterpin(); // calling function to get system pin
	printf(">>> Enter the pin number: ");
	scanf("%d",&epass);
	printf("------------------------------------------------\n");
	if(epass==apass){
		while(1){
			printf("################################################\n");
			printf("------------- LPU COURIER SERVICES -------------\n");
			printf("\n");
			printf("------------------------------------------------\n");
			printf("\n");
			printf("           ...Welcome to Dashboard...\n");
			printf("\n");
			printf("------------------------------------------------\n");
			int cmd; // cmd: command for action like: 1,2...8
			printf("### Choose action:\n\n");
			printf(">> 1 For Adding courier\n");
			printf(">> 2 For Displaying courier\n");
			printf(">> 3 For Updating delivery status\n");
			printf(">> 4 For Tracking courier\n");
			printf(">> 5 For Sorting(id) courier\n");
			printf(">> 6 For Show delivered courier\n");
			printf(">> 7 For Changing system pin\n");
			printf(">> 8 For Exiting system\n");
			printf("----------------------------\n");
			printf(">>> Enter the command: ");
			scanf("%d",&cmd);
			printf("----------------------------\n");
			switch(cmd){
				case 1:
					addcourier(); // calling function for adding courier
					break;
				case 2:
					showcourier(); // calling function for displaying pending courier
					break;
				case 3:
					updatecourier(); // calling function for updating delivery status
					break;
				case 4:
					searchcourier(); // calling function for tracking courier
					break;
				case 5:
					sortcourier(); // calling function for sorting courier based on asc. id
					break;
				case 6:
					delcourier(); // calling function for displaying delivered courier
					break;	
				case 7:
					changepin(); // calling function for changing system pin
					break;					
				case 8:
					printf("-------------------------------------------------\n");
					printf("            ...Thank You, Visit Again...\n");
					printf("                       Exited\n");
					printf("#################################################");
					exit(0);	
				default:
					printf("\n");
					printf("Invalid choice....\n");	
					printf("\n");	
			}
		}
	}
	else{
		printf("\n");
		printf("          ! INVALID PIN, TRY AGAIN....");
		printf("\n");
	}
	return 0;
}

