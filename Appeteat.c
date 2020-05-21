#include <stdio.h>
#include <string.h>
#include<windows.h>
struct Tdireccion{
	char calle[100];
	int portal;
	int piso;
	char letra[5];
};

void banner(){
	printf("\n");
	printf("     /|    ====   ====  |====== =========== |======     /|   ===========\n");
	printf("    / |   |    | |    | |            |      |          / |        |     \n");
	printf("   /__|   |    | |    | |___         |      |___      /__|        |     \n");
	printf("  /   |   |____| |____| |            |      |        /   |        |     \n");
	printf(" /    |   |      |      |            |      |       /    |        |     \n");
	printf("/     |   |      |      |______      |      |______/     |        |     \n");
}



int tiempo1(int h);
int tiempo2(int min);

int main(){
	int t1, t2;
	char usuario[50], contrasena1[50], contrasena2[50];
	int result, opcion, zona, restaurantecz1, restaurantecz2, restaurantercz3, reserva, restaurantel;
	int n1, n2, n3, n4;
	char r1[50], r2[50], r3[50], r4[50];
	int hora, minuto;
	int plato;
	int i;
	int c;
	int confirmacionDireccion;
	
	struct Tdireccion direccion[1];
	
	banner();
	printf("Le damos la bienvenida a Appeteat.\n");
	printf("Para comenzar, introduzca su nombre de usuario:");
	gets(usuario);
	printf("El nombre que ha introducido es %s", usuario);
	do{
		printf("\nIntroduzca una clave:");
		gets(contrasena1);
		printf("Introduzca otra vez su clave:");
		gets(contrasena2);
		result = strcmp(contrasena1, contrasena2);
	} while(result != 0);
	system("cls");
	do{
		printf("Escoja:\n1 - Recoger\n2 - Reservar\n3 - Llevar\n");
		scanf("%d", &opcion);
		if(opcion != 1 && opcion != 2 && opcion != 3){
			printf("Opcion no valida\n");
		}
	} while(opcion != 1 && opcion != 2 && opcion != 3);
	system("cls");
	switch(opcion){
		case 1:
			do{
			printf("¿En que zona quiere recogerlo?\nZona 1: Centro\nZona 2: Norte\nZona 3: Sur\n");
			scanf("%d", &zona);
			if(zona != 1 && zona != 2 && zona != 3){
				printf("Opcion no valida\n");
			}
		} while(zona != 1 && zona != 2 && zona != 3);
			printf("Ha elegido la zona: %d\n", zona);
			switch(zona){
				case 1:
					do{
						FILE * fentrada1;
						fentrada1 = fopen("Restaurantes Zona 1.txt", "r");
						if(fentrada1 == NULL){
							printf("Error en la apertura del fichero\n");
							return 0;
						}
						printf("¿Que restaurante prefiere? En esta zona se encuentran:\n");
						for(i=0; i<3; i++){
							fscanf(fentrada1, "%d %s", &n1, r1);
							printf("%d - %s\n", n1, r1);
						}
						fclose(fentrada1);
						scanf("%d", &restaurantecz1);
						if(restaurantecz1 != 1 && restaurantecz1 != 2 && restaurantecz1 != 3){
							printf("Opcion no valida\n");
						}
				} while(restaurantecz1 != 1 && restaurantecz1 != 2 && restaurantecz1 != 3);
					printf("Ha elegido el restaurante : %d\n", restaurantecz1);
					switch(restaurantecz1){
						case 1:
							do{
								printf("Ha elegido Casa Primavera\nLos platos que ofrece este restaurante son:\n1. Rollitos primavera(8.00 €)\n2. Pollo al limon(10.00 €)\n3. Arroz tres delicias(9.99 €)\n");
								scanf("%d", &plato);
								if(plato != 1 && plato != 2 && plato != 3){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero\n");
								}
							}while(plato != 1 && plato != 2 && plato != 3);
							t1 = tiempo1(hora);
							t2 = tiempo2(minuto);
							printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\n", t1, t2);
							banner();
							return 0;
						case 2:
							do{
								printf("Ha elegido Ginos\nLos platos que ofrece este restaurante son:\n1. Spaghetti a la carbonara(11.00 €)\n2. Lasagna de carne(10.00 €)\n3. Tiramisu (9.00 €)\n");
								scanf("%d", &plato);
								if(plato != 1 && plato != 2 && plato != 3){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero\n");
								}
							}while(plato != 1 && plato != 2 && plato != 3);
							printf("¿A que hora desea recoger su plato?");
							t1 = tiempo1(hora);
							t2 = tiempo2(minuto);
							printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\n", t1, t2);
							banner();
							return 0;
						
						case 3:
							do{
								printf("Ha elegido Goiko Grill\nLos platos que ofrece este restaurante son:\n1. Kevin Bacon (13.00 €)\n2. Costilla de cerdo(10.00 €)\n3. Chicken Finger(9.00 €)\n");
								scanf("%d", &plato);
								if(plato != 1 && plato != 2 && plato != 3){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero\n");
								}
							}while(plato != 1 && plato != 2 && plato != 3);
							t1 = tiempo1(hora);
							t2 = tiempo2(minuto);
							printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\n", t1, t2);
							banner();
							return 0;
					}
				case 2:
					do{
						FILE * fentrada2;
						fentrada2 = fopen("Restaurantes Zona 2.txt", "r");
					if(fentrada2 == NULL){
						printf("Error en la apertura del fichero\n");
						return 0;
					}
						printf("¿Que restaurante prefiere? En esta zona se encuentran:\n");
						for(i=0; i<3; i++){
							fscanf(fentrada2, "%d %s", &n2, r2);
							printf("%d - %s\n", n2, r2);
						}
						fclose(fentrada2);
						scanf("%d", &restaurantecz2);
						if(restaurantecz2 != 1 && restaurantecz2 != 2 && restaurantecz2 != 3){
							printf("Opcion no valida\n");
						}
				}while(restaurantecz2 != 1 && restaurantecz2 != 2 && restaurantecz2 != 3);
					printf("Ha elegido el restaurante : %d\n", restaurantecz2);
					switch(restaurantecz2){
						case 1:
							do{
								printf("Ha elegido Foster`s Hollywood\nLos platos que ofrece este restaurante son:\n1. Bacon & cheese fries(9.00 €)\n2. Costillas BBQ(13.00 €)\n3. Smoked burger(11.00 €)\n");
								scanf("%d", &plato);
								if(plato != 1 && plato != 2 && plato != 3){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero\n");
								}
							}while(plato != 1 && plato != 2 && plato != 3);
							t1 = tiempo1(hora);
							t2 = tiempo2(minuto);
							printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\n", t1, t2);
							banner();
							return 0;
						case 2:
							do{
								printf("Ha elegido Tagliattella\nLos platos que ofrece este restaurante son:\n1. Canelonni (12.00 €)\n2. Carpaccio (15.00 €)\n3. Provoletta (11.53 €)\n");
								scanf("%d", &plato);
								if(plato != 1 && plato != 2 && plato != 3){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero\n");
								}
							}while(plato != 1 && plato != 2 && plato != 3);
							t1 = tiempo1(hora);
							t2 = tiempo2(minuto);
							printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\n", t1, t2);
							banner();
							return 0;
						
						case 3:
							do{
								printf("Ha elegido Subway\nLos platos que ofrece este restaurante son:\n1. Bocadillo Grande (7.78 €)\n2. Bocadillo Mediano (6.50 €)\n3. Bocadillo Pequeño (5.00 €)\n");
								scanf("%d", &plato);
								if(plato != 1 && plato != 2 && plato != 3){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero\n");
								}
							}while(plato != 1 && plato != 2 && plato != 3);
							t1 = tiempo1(hora);
							t2 = tiempo2(minuto);
							printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\n", t1, t2);
							banner();
							return 0;
					}
				case 3:
					do{
						FILE * fentrada3;
						fentrada3 = fopen("Restaurantes Zona 3.txt", "r");
						if(fentrada3 == NULL){
							printf("Error en la apertura del fichero\n");
							return 0;
						}
						printf("¿Que restaurante prefiere? En esta zona se encuentran:\n");
						for(i=0; i<3; i++){
							fscanf(fentrada3, "%d %s", &n3, r3);
							printf("%d - %s\n", n3, r3);
						}
						fclose(fentrada3);
						scanf("%d", &restaurantercz3);
						if(restaurantercz3 != 1 && restaurantercz3 != 2 && restaurantercz3 != 3){
							printf("Opcion no valida\n");
						}
					} while(restaurantercz3 != 1 && restaurantercz3 != 2 && restaurantercz3 != 3);
					printf("Ha elegido el restaurante : %d\n", restaurantercz3);
					
					switch(restaurantercz3){
						case 1:
							do{
								printf("Ha elegido TGB\nLos platos que ofrece este restaurante son:\n1. BBQ Burger (6.87 €)\n2. Onion Burguer (7.00 €)\n3. Hot Dog(6.00 €)\n");
								scanf("%d", &plato);
								if(plato != 1 && plato != 2 && plato != 3){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero\n");
								}
							}while(plato != 1 && plato != 2 && plato != 3);
							t1 = tiempo1(hora);
							t2 = tiempo2(minuto);
							printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\n", t1, t2);
							banner();
							return 0;
						case 2:
							do{
								printf("Ha elegido Go Shushi\nLos platos que ofrece este restaurante son:\n1. Yakisoba Tempura (11.00 €)\n2. Gyozas (15.00 €)\n3. Mix Shushi Maki (16.00 €)\n");
								scanf("%d", &plato);
								if(plato != 1 && plato != 2 && plato != 3){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero\n");
								}
							}while(plato != 1 && plato != 2 && plato != 3);
							t1 = tiempo1(hora);
							t2 = tiempo2(minuto);
							printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\n", t1, t2);
							banner();
							return 0;
						case 3:
							do{
								printf("Ha elegido Tasty Poke\nLos platos que ofrece este restaurante son:\n1. Poke Salmon (10.00 €)\n2. Poke Atun (10.00 €)\n3. Poke Arroz y Pollo (12.00 €)\n");
								scanf("%d", &plato);
								if(plato != 1 && plato != 2 && plato != 3){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero\n");
								}
							}while(plato != 1 && plato != 2 && plato != 3);
							t1 = tiempo1(hora);
							t2 = tiempo2(minuto);
							printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\n", t1, t2);
							banner();
							return 0;
					}
				default:
					printf("Opcion no valida");	
					banner();
					return 0;
			}
		case 2:
			do{
				FILE * fentrada4;
				printf("¿En que restaurante quiere reservar?\n");
				fentrada4 = fopen("Restaurantes general.txt", "r");
				if(fentrada4 == NULL){
					printf("Error en la apertura del fichero\n");
					banner();
					return 0;
				}
				for(i=0; i<9; i++){
					fscanf(fentrada4, "%d %s", &n4, &r4);
					printf("%d - %s\n", n4, r4);
				}
				fclose(fentrada4);
				scanf("%d", &reserva);
				if(reserva != 1 && reserva != 2 && reserva != 3 && reserva != 4 && reserva != 5 && reserva != 6 && reserva != 7 && reserva != 8 && reserva != 9){
					printf("Opcion no valida\n");
				}
			} while(reserva != 1 && reserva != 2 && reserva != 3 && reserva != 4 && reserva != 5 && reserva != 6 && reserva != 7 && reserva != 8 && reserva != 9);
			printf("Ha elegido la opcion: %d\n", reserva);
			printf("¿A que hora quiere la reserva? ");
			do{
				printf("¿A que hora quiere reservar?\n");
				t1 = tiempo1(hora);
				t2 = tiempo2(minuto);
				printf("%d:%d", t1, t2);
				printf("\nPulse 1 si la hora que ha introducido es correcta. Pulse otra tecla en otro caso\n");
				scanf("%d", &c);
			}while(c != 1);
			printf("La hora de reserva ha sido introducida correctamente\n");
			banner();
			return 0;
		case 3:
			do{
				FILE * fentrada4;
				fentrada4 = fopen("Restaurantes general.txt", "r");
				if(fentrada4 == NULL){
					printf("Error en la apertura del fichero\n");
					return 0;
				}
				printf("¿Que restaurante prefiere?\n");
				for(i=0; i<9; i++){
					fscanf(fentrada4, "%d %s", &n4, &r4);
					printf("%d - %s\n", n4, r4);
				}
				fclose(fentrada4);
				scanf("%d", &restaurantel);
				if(restaurantel != 1 && restaurantel != 2 && restaurantel != 3 && restaurantel != 4 && restaurantel != 5 && restaurantel != 6 && restaurantel != 7 && restaurantel != 8 && restaurantel != 9){
					printf("Opcion no valida\n");
				}
		} while(restaurantel != 1 && restaurantel != 2 && restaurantel != 3 && restaurantel != 4 && restaurantel != 5 && restaurantel != 6 && restaurantel != 7 && restaurantel != 8 && restaurantel != 9);
			printf("Ha elegido la opcion: %d\n", restaurantel);
			switch(restaurantel){
				case 1:
					do{
							printf("Ha elegido Casa Primavera\nLos platos que ofrece este restaurante son:\n1. Rollitos primavera(8.00 €)\n2. Pollo al limon(10.00 €)\n3. Arroz tres delicias(9.99 €)\n");
							scanf("%d", &plato);
							if(plato != 1 && plato != 2 && plato != 3){
								printf("El numero no se corresponde con ningun plato. Introduzca otro numero\n");
							}
						}while(plato != 1 && plato != 2 && plato != 3);
						t1 = tiempo1(hora);
						t2 = tiempo2(minuto);
						printf("¡Perfecto! Su pedido se ha efectuado correctamente. Su pedido llegara sobre las %d:%d\n", t1, t2);
						break;
					case 2:
						do{
							printf("Ha elegido Ginos\nLos platos que ofrece este restaurante son:\n1. Spaghetti a la carbonara(11.00 €)\n2. Lasagna de carne(10.00 €)\n3. Tiramisu (9.00 €)\n");
							scanf("%d", &plato);
							if(plato != 1 && plato != 2 && plato != 3){
								printf("El numero no se corresponde con ningun plato. Introduzca otro numero\n");
							}
						}while(plato != 1 && plato != 2 && plato != 3);
						t1 = tiempo1(hora);
						t2 = tiempo2(minuto);
						printf("¡Perfecto! Su pedido se ha efectuado correctamente. Su pedido llegara sobre las %d:%d\n", t1, t2);
						break;
					case 3:
						do{
							printf("Ha elegido Goiko Grill\nLos platos que ofrece este restaurante son:\n1. Kevin Bacon (13.00 €)\n2. Costilla de cerdo(10.00 €)\n3. Chicken Finger(9.00 €)\n");
							scanf("%d", &plato);
							if(plato != 1 && plato != 2 && plato != 3){
								printf("El numero no se corresponde con ningun plato. Introduzca otro numero\n");
							}
						}while(plato != 1 && plato != 2 && plato != 3);
						t1 = tiempo1(hora);
						t2 = tiempo2(minuto);
						printf("¡Perfecto! Su pedido se ha efectuado correctamente. Su pedido llegara sobre las %d:%d\n", t1, t2);
						break;
					case 4:
						do{
							printf("Ha elegido Foster`s Hollywood\nLos platos que ofrece este restaurante son:\n1. Bacon & cheese fries(9.00 €)\n2. Costillas BBQ(13.00 €)\n3. Smoked burger(11.00 €)\n");
							scanf("%d", &plato);
							if(plato != 1 && plato != 2 && plato != 3){
								printf("El numero no se corresponde con ningun plato. Introduzca otro numero\n");
							}
						}while(plato != 1 && plato != 2 && plato != 3);
						t1 = tiempo1(hora);
						t2 = tiempo2(minuto);
						printf("¡Perfecto! Su pedido se ha efectuado correctamente. Su pedido llegara sobre las %d:%d\n", t1, t2);
						break;
					case 5:
						do{
							printf("Ha elegido Tagliattella\nLos platos que ofrece este restaurante son:\n1. Canelonni (12.00 €)\n2. Carpaccio (15.00 €)\n3. Provoletta (11.53 €)\n");
							scanf("%d", &plato);
							if(plato != 1 && plato != 2 && plato != 3){
								printf("El numero no se corresponde con ningun plato. Introduzca otro numero.\n");
							}
						}while(plato != 1 && plato != 2 && plato != 3);
						t1 = tiempo1(hora);
						t2 = tiempo2(minuto);
						printf("¡Perfecto! Su pedido se ha efectuado correctamente. Su pedido llegara sobre las %d:%d\n", t1, t2);
						break;
					case 6:
						do{
							printf("Ha elegido Subway\nLos platos que ofrece este restaurante son:\n1. Bocadillo Grande (7.78 €)\n2. Bocadillo Mediano (6.50 €)\n3. Bocadillo Pequeño (5.00 €)\n");
							scanf("%d", &plato);
							if(plato != 1 && plato != 2 && plato != 3){
								printf("El numero no se corresponde con ningun plato. Introduzca otro numero.\n");
							}
						}while(plato != 1 && plato != 2 && plato != 3);
						t1 = tiempo1(hora);
						t2 = tiempo2(minuto);
						printf("¡Perfecto! Su pedido se ha efectuado correctamente. Su pedido llegara sobre las %d:%d\n", t1, t2);
						break;
					case 7:
						do{
							printf("Ha elegido TGB\nLos platos que ofrece este restaurante son:\n1. BBQ Burger (6.87 €)\n2. Onion Burguer (7.00 €)\n3. Hot Dog(6.00 €)\n");
							scanf("%d", &plato);
							if(plato != 1 && plato != 2 && plato != 3){
								printf("El numero no se corresponde con ningun plato. Introduzca otro numero.\n");
							}
						}while(plato != 1 && plato != 2 && plato != 3);
						t1 = tiempo1(hora);
						t2 = tiempo2(minuto);
						printf("¡Perfecto! Su pedido se ha efectuado correctamente. Su pedido llegara sobre las %d:%d\n", t1, t2);
						break;
					case 8:
						do{
							printf("Ha elegido Go Shushi\nLos platos que ofrece este restaurante son:\n1. Yakisoba Tempura (11.00 €)\n2. Gyozas (15.00 €)\n3. Mix Shushi Maki (16.00 €)\n");
							scanf("%d", &plato);
							if(plato != 1 && plato != 2 && plato != 3){
								printf("El numero no se corresponde con ningun plato. Introduzca otro numero.\n");
							}
						}while(plato != 1 && plato != 2 && plato != 3);
						t1 = tiempo1(hora);
						t2 = tiempo2(minuto);
						printf("¡Perfecto! Su pedido se ha efectuado correctamente. Su pedido llegara sobre las %d:%d\n", t1, t2);
						break;
					case 9:
						do{
							printf("Ha elegido Tasty Poke\nLos platos que ofrece este restaurante son:\n1. Poke Salmon (10.00 €)\n2. Poke Atun (10.00 €)\n3. Poke Arroz y Pollo (12.00 €)\n");
							scanf("%d", &plato);
							if(plato != 1 && plato != 2 && plato != 3){
								printf("El numero no se corresponde con ningun plato. Introduzca otro numero.\n");
							}
						}while(plato != 1 && plato != 2 && plato != 3);
						t1 = tiempo1(hora);
						t2 = tiempo2(minuto);
						printf("¡Perfecto! Su pedido se ha efectuado correctamente. Su pedido llegara sobre las %d:%d\n", t1, t2);
						break;
				}	
				printf("Introduzca su calle: ");
				scanf("%s", direccion[1].calle);
				printf("Portal: ");
				scanf("%d", &direccion[1].portal);
				printf("Piso: ");
				scanf("%d", &direccion[1].piso);
				printf("Letra: ");
				scanf("%s", direccion[1].letra);
				printf("Su pedido llegara a: Calle %s, numero %d, Piso %d %s", direccion[1].calle, direccion[1].portal, direccion[1].piso, direccion[1].letra);
				banner();
				return 0;
			} while(confirmacionDireccion != 1);
			printf("Su pedido llegara sobre las %d:%d", t1, t2);
			banner();
			return 0;
}


int tiempo1(int h){
	do{
		printf("Introduzca la hora: ");
		scanf("%d", &h);
		if(h<0 && h>=24){
		printf("Por favor, intrduzca una hora real");
		}
	} while(h<0 && h>=24);
	return h;
}
int tiempo2(int min){
	do{
		printf("Introduzca los minutos: ");
		scanf("%d", &min);
		if(min<0 && min>59){
		printf("Por favor, introduzca un minuto real");
		}
	}while(min<0 && min>59);
	return min;
}
