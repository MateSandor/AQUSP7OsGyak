#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>


int main()
{
	int i = 0;
	double a = 0;
	double b = 0;
	double c = 0;
	double x = 0;
	double y = 0;
	double diszkriminans = -1;
	double valodiResz=0;
	double elkepzeltResz=0;

	mkfifo("FIFO", S_IWUSR | S_IRUSR);
	//FIFO fájl létrehozása
	int child = fork();
	//processz kettébontása
	if(child == 0){
		int fd = open("FIFO",O_WRONLY); //fileleiro letrehozasa , pipe egyik vegenek megnyitasa irasra
		int file = open("bemenet.txt",O_RDONLY);  //fajl megnyitasa
		//FILE* fp = fopen("toread.txt","r+")
		char sor[100];
		char sorAtvietlre[100];
		char ch;
		int i = 0;
		int j = 0;

		do
		{
			read(file,&ch,1);
			strcat(sor,&ch);
			i++;
		}while(ch!= ' ' && ch != '\n');

		sor[i]='\0';
		int elsoSzam = atoi(sor);

		write(fd,sor,strlen(sor));

		printf("Elso szam: %d\n",elsoSzam);

		strcpy(sorAtvietlre,"");


		for(i=0;i<elsoSzam;i++)
		{
			j=0;
			strcpy(sor,"");

			do
			{

				read(file,&ch,1);
				if(ch != '\n'){
				strcat(sor,&ch);
				
			}
			
			}while(ch != '\n');

			strcat(sorAtvietlre,sor);
			strcat(sorAtvietlre,"\n");

			strcat(sor,"\0");


			//printf("%s\n",sor);  //LEFUTOTT MUKODIK
			
		}

		strcat(sorAtvietlre,"\0");
		printf("Gyerek: %d\n\n============================================\n\n",child); //kiirja a child erteket
		//printf("%s\n", sorAtvietlre);
		write(fd,sorAtvietlre,strlen(sorAtvietlre));

		close(fd);//lezaras
		
			}
	else if(child<0){
	printf("Error. Child kisebb mint 0");
	return 0;
		}

	else{
		FILE* fifo = fopen("FIFO","r+");
		//int fd = open("FIFO",O_RDONLY); // pipe masik oldalanak megnyitasa olvasasra
		//char ch[7]; // stringhez char array létrehozása
		//int length = read(fd,ch,sizeof(ch)-1); //fd-bol ch-ba beolvasas, ch mérete -1 hosszusagot
		//ch[length] = '\0'; // ch lezarasa
		//printf("Szulo: %s",ch);
		char sor[100];
		char ch;
		int szamok[3];
		int i = 0;
		
		fscanf(fifo,"%d",&i);

	
		int elsoSzam = i;

		FILE* kiFile = fopen("kimenet.txt", "w+");

		for(i=0;i<elsoSzam;i++)
		{
			fscanf(fifo,"%d %d %d",&szamok[0],&szamok[1],&szamok[2]);
			a=0,b=0,c=0,x=0,y=0,diszkriminans=0;

			//szamolas itt kezdodik

			a = (double)szamok[0];
			b = (double)szamok[1];
			c = (double)szamok[2];

			diszkriminans = b * b - 4 * a * c;

			    if (diszkriminans > 0) {
			        x = (-b + sqrt(diszkriminans)) / (2 * a);
			        y = (-b - sqrt(diszkriminans)) / (2 * a);
			        fprintf(kiFile,"%.0lf %.0lf %.0lf %.2lf %.2lf\n",a, b, c, x, y);
			    }

			    else if (diszkriminans == 0) {
			        x = y = -b / (2 * a);
			        fprintf(kiFile,"%.0lf %.0lf %.0lf %.2lf\n",a, b, c, x);
			    }

			    else {
			        valodiResz = -b / (2 * a);
			        elkepzeltResz = sqrt(-diszkriminans) / (2 * a);
			        fprintf(kiFile,"%.0lf %.0lf %.0lf (%.2lf+%.2lfi) (%.2lf-%.2lfi)\n",a, b, c,valodiResz, elkepzeltResz, valodiResz, elkepzeltResz);
			    }

			/*or (int k = 0; k < 3; ++k)
			{
				printf("%d ",szamok[k]);

			}
			printf("\n");*/
		}
	fclose(kiFile);
	printf("A fileba iras megtortent!\n");
	}
	return 0;
}
