#include <stdio.h>
#include <string.h>

int main(){
	char usuario[50], contrasena1[50], contrasena2[50];
	int result, opcion, zona, restaurantecz1, restaurantercz2, restaurantercz3, reserva, restaurantel;
	//int inicio;
	int n1, n2, n3, n4, n5;
	char r1[50], r2[50], r3[50], r4[50], r5[50];
	int i;
	printf("Le damos la bienvenida a Appeteat.\n");
	printf("Pulse 0 en cualquier momento si quiere salir de la aplicacion.\n");
	//printf("Pulse 1 si quiere iniciar sesion. Pulse 2 si se quiere registrar:");
	//scanf("%d", &inicio);
	printf("Para comenzar introduzca su nombre de usuario:");
	gets(usuario);
	if(strcmp(usuario, "0") == 0){
		return 0;
	}
	printf("El nombre que ha introducido es %s", usuario);
	do{
		printf("\nIntroduzca una clave:");
		gets(contrasena1);
		if(strcmp(contrasena1, "0") == 0){
			return 0;
		}
			else{
				printf("Introduzca otra vez su clave:");
				gets(contrasena2);
				result = strcmp(contrasena1, contrasena2);
				if(strcmp(contrasena2, "0") == 0){
				return 0;
				}
			}
	} while(result != 0);

	do{
		printf("Escoja:\n1 - Recoger\n2 - Reservar\n3 - Llevar\n");
		scanf("%d", &opcion);
		if(opcion != 0 && opcion != 1 && opcion != 2 && opcion != 3){
			printf("Opcion no valida\n");
		}
	} while(opcion != 0 && opcion != 1 && opcion != 2 && opcion != 3);
	switch(opcion){
		case 0:
			break;
			return 0;
		case 1:
			do{
			printf("�En que zona quieres recogerlo?\nZona 1: Centro\nZona 2: Norte\nZona 3: Sur\n");
			scanf("%d", &zona);
			if(zona != 0 && zona != 1 && zona != 2 && zona != 3){
				printf("Opcion no valida\n");
			}
		} while(zona != 0 && zona != 1 && zona != 2 && zona != 3);
			printf("Ha elegido la zona: %d", zona);
			switch(zona){
				case 0:
					break;
					return 0;
				case 1:
					do{
						FILE * fentrada1;
						fentrada1 = fopen("Restaurantes Zona 1.txt", "r");
					if(fentrada1 == NULL){
						printf("Error en la apertura del fichero\n");
						return 0;
					}
						printf("�Que restaurante prefiere? En esta zona se encuntran:\n");
						for(i=0; i<3; i++){
							fscanf(fentrada1, "%d %s", &n1, r1);
							printf("%d - %s\n", n1, r1);
						}
						fclose(fentrada1);
						scanf("%d", &restaurantecz1);
						if(restaurantecz1 != 0 && restaurantecz1 != 1 && restaurantecz1 != 2 && restaurantecz1 != 3){
							printf("Opcion no valida\n");
						} else if(restaurantecz1 == 0){
							return 0;
						}
				} while(restaurantecz1 != 1 && restaurantecz1 != 2 && restaurantecz1 != 3);
					printf("Ha elegido el restaurante : %d", restaurantecz1);
					break;
					return 0;
				case 2:
					do{
						FILE * fentrada2;
						fentrada2 = fopen("Restaurantes Zona 2.txt", "r");
					if(fentrada2 == NULL){
						printf("Error en la apertura del fichero\n");
						return 0;
					}
						printf("�Que restaurante prefiere? En esta zona se encuntran:\n");
						for(i=0; i<3; i++){
							fscanf(fentrada2, "%d %s", &n2, r2);
							printf("%d - %s\n", n2, r2);
						}
						fclose(fentrada2);
						scanf("%d", &restaurantercz2);
						if(restaurantercz2 != 0 && restaurantercz2 != 1 && restaurantercz2 != 2 && restaurantercz2 != 3){
							printf("Opcion no valida\n");
						}
				}while(restaurantercz2 != 0 && restaurantercz2 != 1 && restaurantercz2 != 2 && restaurantercz2 != 3);
					if(restaurantercz2 == 0){
						break;
						return 0;
					}
					printf("Ha elegido el restaurante : %d", restaurantercz2);
					break;
					return 0;
					//aqui pedimos los datos necesarios para la recogida
				case 3:
					do{
						FILE * fentrada3;
						fentrada3 = fopen("Restaurantes Zona 3.txt", "r");
					if(fentrada3 == NULL){
						printf("Error en la apertura del fichero\n");
						return 0;
					}
						printf("�Que restaurante prefiere? En esta zona se encuntran:\n");
						for(i=0; i<3; i++){
							fscanf(fentrada3, "%d %s", &n3, r3);
							printf("%d - %s\n", n3, r3);
						}
						fclose(fentrada3);
						scanf("%d", &restaurantercz3);
						if(restaurantercz3 != 0 && restaurantercz3 != 1 && restaurantercz3 != 2 && restaurantercz3 != 3){
							printf("Opcion no valida\n");
						}
					} while(restaurantercz3 != 0 && restaurantercz3 != 1 && restaurantercz3 != 2 && restaurantercz3 != 3);
					printf("Ha elegido el restaurante : %d\n", restaurantercz3);
					break;
					//aqui tiene que haber algo m�s
					return 0;
					//aqui pedimos los datos necesarios para la recogida
				default:
					printf("Opcion no valida");	
					//hacer un do while para que lo vuelva a pedir
					break;
					return 0;
			}
			return 0;
		case 2:
			
			do{
				FILE * fentrada4;
						fentrada4 = fopen("Restaurantes general.txt", "r");
					if(fentrada4 == NULL){
						printf("Error en la apertura del fichero\n");
						return 0;
					}
				printf("�En que restaurante quiere reservar?\n");
				for(i=0; i<9; i++){
							fscanf(fentrada4, "%d %s", &n4, r4);
							printf("%d - %s\n", n4, r4);
						}
						fclose(fentrada4);
				scanf("%d", &reserva);
				if(reserva != 0 && reserva != 1 && reserva != 2 && reserva != 3 && reserva != 4 && reserva != 5 && reserva != 6 && reserva != 7 && reserva != 8 && reserva != 9){
					printf("Opcion no valida\n");
				}
			} while(reserva != 0 && reserva != 1 && reserva != 2 && reserva != 3 && reserva != 4 && reserva != 5 && reserva != 6 && reserva != 7 && reserva != 8 && reserva != 9);
				if(reserva == 0){
					break;
					return 0;
				}
			printf("Ha elegido la opcion: %d", reserva);
			break;
			//aqui hay que seguir
			return 0;
			//aqui pedimos los datos necesarios para reservar
		case 3:
			do{
				FILE * fentrada5;
						fentrada5 = fopen("Restaurantes general.txt", "r");
					if(fentrada5 == NULL){
						printf("Error en la apertura del fichero\n");
						return 0;
					}
				printf("�Que restaurante prefiere?\n");
				for(i=0; i<9; i++){
							fscanf(fentrada5, "%d %s", &n5, r5);
							printf("%d - %s\n", n5, r5);
						}
						fclose(fentrada5);
				scanf("%d", &restaurantel);
				if(restaurantel != 0 && restaurantel != 1 && restaurantel != 2 && restaurantel != 3 && restaurantel != 4 && restaurantel != 5 && restaurantel != 6 && restaurantel != 7 && restaurantel != 8 && restaurantel != 9){
					printf("Opcion no valida\n");
				}
		} while(restaurantel != 0 && restaurantel != 1 && restaurantel != 2 && restaurantel != 3 && restaurantel != 4 && restaurantel != 5 && restaurantel != 6 && restaurantel != 7 && restaurantel != 8 && restaurantel != 9);
			printf("Ha elegido la opcion: %d\n", restaurantel);
			//aqui pedimos la direccion y mas datos
			
		default:
				printf("Opcion no valida");
				break;
				return 0;
		}	
	}