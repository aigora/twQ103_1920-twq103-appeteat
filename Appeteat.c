#include <stdio.h>
#include <string.h>
#include<windows.h>
//lo del usuario
//linea 41
//corregir los 65165161 errores que nos salgan
struct Tusuario{
	char nombre[20];
	char apellido[20];
	char usuario[20];
	char clave[20];
};
struct Tdireccion{
	char calle[100];
	int portal;
	int piso;
	char letra;
	int codigopostal;
	
};

void banner(){
	printf("     /|    ====   ====  |====== =========== |======     /|   ===========\n");
    printf("    / |   |    | |    | |            |      |          / |        |     \n");
    printf("   /__|   |    | |    | |___         |      |___      /__|        |     \n");
    printf("  /   |   |____| |____| |            |      |        /   |        |     \n");
    printf(" /    |   |      |      |            |      |       /    |        |     \n");
    printf("/     |   |      |      |______      |      |______/     |        |     \n");
}

void lectura(){
	int i, n4, r4;
	FILE * fentrada4;
	fentrada4 = fopen("Restaurantes general.txt", "r");
	if(fentrada4 == NULL){
		printf("Error en la apertura del fichero\n");
		return 0;
		}
	for(i=0; i<9; i++){
		fscanf(fentrada4, "%d %s", &n4, &r4);
		printf("%d - %s\n", n4, r4);
	}
}

int tiempo1();
int tiempo2();

//void platos1();
//void platos2();
//void platos3();
//hay que hacer void platos hasta el 9, uno por cada restaurante

int main(){
	char usuario[50], contrasena1[50], contrasena2[50];
	int result, opcion, zona, restaurantecz1, restaurantecz2, restaurantercz3, reserva, restaurantel;
	int n1, n2, n3, n4;
	char r1[50], r2[50], r3[50], r4[50];
	int hora, minuto;
	int plato;
	int i;
	int confirmacionDireccion;
	
	struct Tdireccion direccion[1];
	
	banner();
	printf("Le damos la bienvenida a Appeteat.\n");
	printf("Introduzca 404 en cualquier momento si quiere salir de la aplicacion.\n");
	
	//printf("Pulse 1 si quiere registrarse. Pulse 2 si quiere iniciar sesion:");
	//scanf("%d", &inicio);
	/*switch(inicio){
		case 1:
			FILE * fusuario;
			fusuario = fopen("usuarios.txt", "w");
			if(fusuario == NULL){
				printf("Error en la apertura del fichero\n");
				return 0;
			}
			printf("¿Como te llamas? ");
			scanf("%c", Tusuario.nombre);
			printf("¿Cual es tu primer apellido? ");
			scanf("%c", Tusuario.apellido);
			do{
			printf("Escoja un nombre de usuario: ");
			scanf("%c", Tusuario.usuario);
			if()
			}while()
			printf("")
			break;
		case 2:
			FILE * fentrar;
			fentrar = fopen("usuarios.txt", "r");
			printf("Introduzca su nombre de usuario: ");
	}*/
	printf("Para comenzar, introduzca su nombre de usuario:");
	gets(usuario);
	if(strcmp(usuario, "404") == 0){
		banner();
		return 0;
	}
	printf("El nombre que ha introducido es %s", usuario);
	do{
		printf("\nIntroduzca una clave:");
		gets(contrasena1);
		if(strcmp(contrasena1, "404") == 0){
			banner();
			return 0;
		}
			else{
				printf("Introduzca otra vez su clave:");
				gets(contrasena2);
				result = strcmp(contrasena1, contrasena2);
				if(strcmp(contrasena2, "404") == 0){
					banner();
					return 0;
				}
			}
	} while(result != 0);

	do{
		printf("Escoja:\n1 - Recoger\n2 - Reservar\n3 - Llevar\n");
		scanf("%d", &opcion);
		if(opcion != 404 && opcion != 1 && opcion != 2 && opcion != 3){
			printf("Opcion no valida\n");
		}
	} while(opcion != 404 && opcion != 1 && opcion != 2 && opcion != 3);
	switch(opcion){
		case 404:
			banner();
			break;
			return 0;
		case 1:
			do{
			printf("¿En que zona quiere recogerlo?\nZona 1: Centro\nZona 2: Norte\nZona 3: Sur\n");
			scanf("%d", &zona);
			if(zona != 404 && zona != 1 && zona != 2 && zona != 3){
				printf("Opcion no valida\n");
			}
			if(zona == 404){
				banner();
				return 0;
			}
		} while(zona != 404 && zona != 1 && zona != 2 && zona != 3);
			printf("Ha elegido la zona: %d", zona);
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
						if(restaurantecz1 != 404 && restaurantecz1 != 1 && restaurantecz1 != 2 && restaurantecz1 != 3){
							printf("Opcion no valida\n");
						} else if(restaurantecz1 == 404){
							banner();
							return 0;
						}
				} while(restaurantecz1 != 1 && restaurantecz1 != 2 && restaurantecz1 != 3);
					printf("Ha elegido el restaurante : %d", restaurantecz1);
					printf("¿A que hora quiere recoger su pedido? ");
					tiempo1();
					tiempo2();
					switch(restaurantecz1){
						case 1:
							do{
								printf("Ha elegido Casa Primavera\nLos platos que ofrece este restaurante son:\n1. Rollitos primavera(8.00 €)\n2. Pollo al limon(10.00 €)\n3. Arroz tres delicias(9.99 €)");
								scanf("%d", &plato);
								if(plato == 404){
									banner();
									return 0;
								}
								if(plato != 1 && plato != 2 && plato != 3 && plato != 404){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero");
								}
							}while(plato != 1 && plato != 2 && plato != 3 && plato != 404);
								printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\nSu pedido permanecera hasta 20 minutos desde la hora establecida", hora, minuto);
							break;
							return 0;
						case 2:
							do{
								printf("Ha elegido Ginos\nLos platos que ofrece este restaurante son:\n1. Spaghetti a la carbonara(11.00 €)\n2. Lasagna de carne(10.00 €)\n3. Tiramisu (9.00 €)");
								scanf("%d", &plato);
								if(plato == 404){
									banner();
									return 0;
								}
								if(plato != 1 && plato != 2 && plato != 3 && plato != 404){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero");
								}
							}while(plato != 1 && plato != 2 && plato != 3 && plato != 404);
								printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %.2f\nSu pedido permanecera hasta 20 minutos desde la hora establecida", hora);
							break;
							return 0;
						
						case 3:
							do{
								printf("Ha elegido Goiko Grill\nLos platos que ofrece este restaurante son:\n1. Kevin Bacon (13.00 €)\n2. Costilla de cerdo(10.00 €)\n3. Chicken Finger(9.00 €)");
								scanf("%d", &plato);
								if(plato == 404){
									banner();
									return 0;
								}
								if(plato != 1 && plato != 2 && plato != 3 && plato != 404){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero");
								}
							}while(plato != 1 && plato != 2 && plato != 3 && plato != 404);
								printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\nSu pedido permanecera hasta 20 minutos desde la hora establecida", hora, minuto);
							break;
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
						if(restaurantecz2 != 404 && restaurantecz2 != 1 && restaurantecz2 != 2 && restaurantecz2 != 3){
							printf("Opcion no valida\n");
						}
				}while(restaurantecz2 != 404 && restaurantecz2 != 1 && restaurantecz2 != 2 && restaurantecz2 != 3);
					if(restaurantecz2 == 404){
						banner();
						break;
						return 0;
					}
						printf("Ha elegido el restaurante : %d", restaurantecz2);
					tiempo1();
					tiempo2();
					switch(restaurantecz2){
						case 1:
							do{
								printf("Ha elegido Foster`s Hollywood\nLos platos que ofrece este restaurante son:\n1. Bacon & cheese fries(9.00 €)\n2. Costillas BBQ(13.00 €)\n3. Smoked burger(11.00 €)");
								scanf("%d", &plato);
								if(plato == 404){
									banner();
									return 0;
								}
								if(plato != 1 && plato != 2 && plato != 3 && plato != 404){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero");
								}
							}while(plato != 1 && plato != 2 && plato != 3 && plato != 404);
								printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\nSu pedido permanecera hasta 20 minutos desde la hora establecida", hora, minuto);
							break;
							return 0;
						case 2:
							do{
								printf("Ha elegido Tagliattella\nLos platos que ofrece este restaurante son:\n1. Canelonni (12.00 €)\n2. Carpaccio (15.00 €)\n3. Provoletta (11.53 €)");
								scanf("%d", &plato);
								if(plato == 404){
									banner();
									return 0;
								}
								if(plato != 1 && plato != 2 && plato != 3 && plato != 404){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero");
								}
							}while(plato != 1 && plato != 2 && plato != 3 && plato != 404);
								printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %.d:%d\nSu pedido permanecera hasta 20 minutos desde la hora establecida", hora, minuto);
							break;
							banner();
							return 0;
						
						case 3:
							do{
								printf("Ha elegido Subway\nLos platos que ofrece este restaurante son:\n1. Bocadillo Grande (7.78 €)\n2. Bocadillo Mediano (6.50 €)\n3. Bocadillo Pequeño (5.00 €)");
								scanf("%d", &plato);
								if(plato == 404){
									banner();
									return 0;
								}
								if(plato != 1 && plato != 2 && plato != 3 && plato != 404){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero");
								}
							}while(plato != 1 && plato != 2 && plato != 3 && plato != 404);
								printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\nSu pedido permanecera hasta 20 minutos desde la hora establecida", hora, minuto);
							break;
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
						if(restaurantercz3 != 404 && restaurantercz3 != 1 && restaurantercz3 != 2 && restaurantercz3 != 3){
							printf("Opcion no valida\n");
						}
					} while(restaurantercz3 != 404 && restaurantercz3 != 1 && restaurantercz3 != 2 && restaurantercz3 != 3);
					printf("Ha elegido el restaurante : %d\n", restaurantercz3);
					
					switch(restaurantercz3){
						case 1:
							do{
								printf("Ha elegido TGB\nLos platos que ofrece este restaurante son:\n1. BBQ Burger (6.87 €)\n2. Onion Burguer (7.00 €)\n3. Hot Dog(6.00 €)");
								scanf("%d", &plato);
								if(plato == 404){
									banner();
									return 0;
								}
								if(plato != 1 && plato != 2 && plato != 3 && plato != 404){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero");
								}
							}while(plato != 1 && plato != 2 && plato != 3 && plato != 404);
								printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\nSu pedido permanecera hasta 20 minutos desde la hora establecida", hora, minuto);
							break;
							return 0;
						case 2:
							do{
								printf("Ha elegido Go Shushi\nLos platos que ofrece este restaurante son:\n1. Yakisoba Tempura (11.00 €)\n2. Gyozas (15.00 €)\n3. Mix Shushi Maki (16.00 €)");
								scanf("%d", &plato);
								if(plato == 404){
									banner();
									return 0;
								}
								if(plato != 1 && plato != 2 && plato != 3 && plato != 404){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero");
								}
							}while(plato != 1 && plato != 2 && plato != 3 && plato != 404);
								printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\nSu pedido permanecera hasta 20 minutos desde la hora establecida", hora, minuto);
							break;
							return 0;
						
						case 3:
							do{
								printf("Ha elegido Tasty Poke\nLos platos que ofrece este restaurante son:\n1. Poke Salmon (10.00 €)\n2. Poke Atun (10.00 €)\n3. Poke Arroz y Pollo (12.00 €)");
								scanf("%d", &plato);
								if(plato == 404){
									banner();
									return 0;
								}
								if(plato != 1 && plato != 2 && plato != 3 && plato != 404){
									printf("El numero no se corresponde con ningun plato. Introduzca otro numero");
								}
							}while(plato != 1 && plato != 2 && plato != 3 && plato != 404);
								printf("¡Perfecto! Su pedido se ha efectuado correctamente. Recurede presentarse a las %d:%d\nSu pedido permanecera hasta 20 minutos desde la hora establecida", hora, minuto);
							break;
							return 0;
					}
					
					break;
				default:
					printf("Opcion no valida");	
					break;
					return 0;
			}
		case 2:
			
			do{
				FILE * fentrada4;
				printf("¿En que restaurante quiere reservar?\n");
				lectura();
						fclose(fentrada4);
				scanf("%d", &reserva);
				if(reserva != 404 && reserva != 1 && reserva != 2 && reserva != 3 && reserva != 4 && reserva != 5 && reserva != 6 && reserva != 7 && reserva != 8 && reserva != 9){
					printf("Opcion no valida\n");
				}
			} while(reserva != 404 && reserva != 1 && reserva != 2 && reserva != 3 && reserva != 4 && reserva != 5 && reserva != 6 && reserva != 7 && reserva != 8 && reserva != 9);
				if(reserva == 404){
					break;
					return 0;
				}
			printf("Ha elegido la opcion: %d", reserva);
			printf("¿A que hora quiere la reserva? ");
			tiempo1();
			tiempo2();
			printf("La hora de reserva ha sido introducida correctamente");
			banner();
			break;
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
				lectura();
						fclose(fentrada4);
				scanf("%d", &restaurantel);
				if(restaurantel != 404 && restaurantel != 1 && restaurantel != 2 && restaurantel != 3 && restaurantel != 4 && restaurantel != 5 && restaurantel != 6 && restaurantel != 7 && restaurantel != 8 && restaurantel != 9){
					printf("Opcion no valida\n");
				}
				if(restaurantel == 404){
					banner();
					return 0;
				}
		} while(restaurantel != 404 && restaurantel != 1 && restaurantel != 2 && restaurantel != 3 && restaurantel != 4 && restaurantel != 5 && restaurantel != 6 && restaurantel != 7 && restaurantel != 8 && restaurantel != 9);
			printf("Ha elegido la opcion: %d\n", restaurantel);
			//aqui poner los platos de cada restaurante para que lo elija 
			
			do{
				printf("¿A que direccion quiere que se lo entreguemos?");
				printf("Calle:");
				gets(direccion[1].calle);
				printf("Portal:");
				scanf("%d", &direccion[1].portal);
				printf("Piso y letra:");
				scanf("%d %c", &direccion[1].piso, &direccion[1].letra);
				printf("Codigo postal:");
				scanf("%d", &direccion[1].codigopostal);
			
				printf("Su direccion es: %s %d %d %c %d", direccion[1].calle, direccion[1].portal, direccion[1].piso, direccion[1].letra, direccion[1].codigopostal);
				printf("Pulse 1 si la direccion es correcta. Pulse otra tecla si quiere introducir otra direccion: ");
				scanf("%d", &confirmacionDireccion);
				if(confirmacionDireccion == 0){
					banner();
					return 0;
				}
			} while(confirmacionDireccion != 1 && confirmacionDireccion != 0);
			tiempo1();
			tiempo2();
			printf("Su pedido llegara sobre las %d:%d", &hora, &minuto);
			break;
			banner();
			return 0;
		default:
				printf("Opcion no valida");
				break;
				return 0;
		}	
	}

int tiempo1(){
	int h;
	do{
		printf("Introduzca la hora: ");
		scanf("%d", &h);
		if(h==404){
			banner();
			return 0;
		}
		if(h<0 && h>=24){
			printf("Por favor, intrduzca una hora real");
		}
	} while(h<0 && h>=24);
	return h;
}
int tiempo2(){
	int min;
	do{
		printf("Introduzca los minutos: ");
		scanf("%d", &min);
		if(min==404){
			banner();
			return 0;
		}
		if(min<0 && min>59){
			printf("Por favor, introduzca un minuto real");
		}
	}while(min<0 && min>59);
	return min;
}
