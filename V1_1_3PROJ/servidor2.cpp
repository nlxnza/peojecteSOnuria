#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <ctype.h>
#include <mysql.h>

int main(int argc, char *argv[])
{
	
	int sock_conn, sock_listen, ret;
	struct sockaddr_in serv_adr;
	char peticion[512];
	char respuesta[512];
	
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas 
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	int edad;
	int numero;
	char dni[10];
	char consulta [200];
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexiï¿ï\u0178³n: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//inicializar la conexion
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "game",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexiï¿ï\u0178³n: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	// consulta SQL para obtener una tabla con todos los datos
	// de la base de datos
	err=mysql_query (conn, "SELECT * FROM player");
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//recogemos el resultado de la consulta. El resultado de la
	//consulta se devuelve en una variable del tipo puntero a
	//MYSQL_RES tal y como hemos declarado anteriormente.
	//Se trata de una tabla virtual en memoria que es la copia
	//de la tabla real en disco.
	resultado = mysql_store_result (conn);
	// El resultado es una estructura matricial en memoria
	// en la que cada fila contiene los datos de una persona.
	
	// Ahora obtenemos la primera fila que se almacena en una
	// variable de tipo MYSQL_ROW
	row = mysql_fetch_row (resultado);
	// En una fila hay tantas columnas como datos tiene una
	// persona. En nuestro caso hay tres columnas: dni(row[0]),
	// nombre(row[1]) y edad (row[2]).
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
	{
		while (row !=NULL) 
		{
			// la columna 2 contiene una palabra que es la edad
			// la convertimos a entero 
			
			// las columnas 0 y 1 contienen DNI y nombre 
			printf ("ID: %s, Username: %s, Password: %s\n", row[0], row[1], row[2]);
			// obtenemos la siguiente fila
			row = mysql_fetch_row (resultado);
		}
	}
	
	
	err=mysql_query (conn, "SELECT * FROM relations");
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//recogemos el resultado de la consulta. El resultado de la
	//consulta se devuelve en una variable del tipo puntero a
	//MYSQL_RES tal y como hemos declarado anteriormente.
	//Se trata de una tabla virtual en memoria que es la copia
	//de la tabla real en disco.
	resultado = mysql_store_result (conn);
	// El resultado es una estructura matricial en memoria
	// en la que cada fila contiene los datos de una persona.
	
	// Ahora obtenemos la primera fila que se almacena en una
	// variable de tipo MYSQL_ROW
	row = mysql_fetch_row (resultado);
	// En una fila hay tantas columnas como datos tiene una
	// persona. En nuestro caso hay tres columnas: dni(row[0]),
	// nombre(row[1]) y edad (row[2]).
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
	{
		while (row !=NULL) 
		{
			// la columna 2 contiene una palabra que es la edad
			// la convertimos a entero 
			
			// las columnas 0 y 1 contienen DNI y nombre 
			printf ("Id jugador: %d, Id partida: %d, puntos: %d\n", atoi(row[0]), atoi(row[1]), atoi(row[2]));
			// obtenemos la siguiente fila
			row = mysql_fetch_row (resultado);
		}
	}
	
	err=mysql_query (conn, "SELECT * FROM games");
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//recogemos el resultado de la consulta. El resultado de la
	//consulta se devuelve en una variable del tipo puntero a
	//MYSQL_RES tal y como hemos declarado anteriormente.
	//Se trata de una tabla virtual en memoria que es la copia
	//de la tabla real en disco.
	resultado = mysql_store_result (conn);
	// El resultado es una estructura matricial en memoria
	// en la que cada fila contiene los datos de una persona.
	
	// Ahora obtenemos la primera fila que se almacena en una
	// variable de tipo MYSQL_ROW
	row = mysql_fetch_row (resultado);
	// En una fila hay tantas columnas como datos tiene una
	// persona. En nuestro caso hay tres columnas: dni(row[0]),
	// nombre(row[1]) y edad (row[2]).
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
	{
		while (row !=NULL) 
		{
			// la columna 2 contiene una palabra que es la edad
			// la convertimos a entero 
			
			// las columnas 0 y 1 contienen DNI y nombre 
			printf ("Id: %d, Ganador: %s, Durada: %d\n", atoi(row[0]), row[1], atoi(row[2]));
			// obtenemos la siguiente fila
			row = mysql_fetch_row (resultado);
		}
	}
	// INICIALITZACIONS
	// Obrim el socket
	if ((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		printf("Error creant socket");
	// Fem el bind al port
	
	
	memset(&serv_adr, 0, sizeof(serv_adr));// inicialitza a zero serv_addr
	serv_adr.sin_family = AF_INET;
	
	// asocia el socket a cualquiera de las IP de la m?quina. 
	//htonl formatea el numero que recibe al formato necesario
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	// establecemos el puerto de escucha
	serv_adr.sin_port = htons(9001);
	if (bind(sock_listen, (struct sockaddr *) &serv_adr, sizeof(serv_adr)) < 0)
		printf ("Error al bind");
	
	if (listen(sock_listen, 3) < 0)
		printf("Error en el Listen");
	
	int i;
	// Bucle infinito
	for (;;){
		printf ("Escuchando\n");
		
		sock_conn = accept(sock_listen, NULL, NULL);
		printf ("He recibido conexion\n");
		//sock_conn es el socket que usaremos para este cliente
		
		int terminar =0;
		// Entramos en un bucle para atender todas las peticiones de este cliente
		//hasta que se desconecte
		while (terminar ==0)
		{
			// Ahora recibimos la petici?n
			ret=read(sock_conn,peticion, sizeof(peticion));
			printf ("Recibido\n");
			
			// Tenemos que a?adirle la marca de fin de string 
			// para que no escriba lo que hay despues en el buffer
			peticion[ret]='\0';
			
			
			printf ("Peticion: %s\n",peticion);
			
			// vamos a ver que quieren
			char *p = strtok( peticion, "/");
			int codigo =  atoi (p);
			// Ya tenemos el c?digo de la petici?n
			char nombre[20];
			char partida[20];
			char usuario[50];
			char contrasenya[50];
			int contador=0;
			char respuesta[512];
			
			if (codigo !=0)
			{
				p = strtok( NULL, "/");
				strcpy(nombre,p);
				p = strtok( NULL, "/");
				strcpy(contrasenya,p);				// Ya tenemos el nombre
				printf ("Codigo: %d, Nombre: %s\n", codigo, nombre);
			}			
			
			
					
			if (codigo ==0) //petici?n de desconexi?n
				terminar=1;
			else if (codigo ==1) //Login
			{
				sprintf(consulta,"SELECT Name FROM player WHERE Name='%s' AND Pass='%s'",nombre,contrasenya);
				// hacemos la consulta 
				err=mysql_query(conn, consulta); 
				if (err!=0) 
				{
					printf ("Error al consultar datos de la base %u %s\n",
							mysql_errno(conn), mysql_error(conn));
					return 1; 
				}
				resultado = mysql_store_result (conn); //si lo encuentra en la base de datos sigue por ese camino
				numero=mysql_num_rows(resultado);
				row = mysql_fetch_row (resultado);
				strcpy(respuesta,"");
				if (row == NULL)
				{
					
					
					strcat(respuesta,"No se ha encontrado el usuario");
					printf ("No se ha encontrado el usuario\n");
					
					
					
				}
				else
				{
					printf ("Usuario %s encontrado.\n", row[0] );
					strcat(respuesta,"No se ha encontrado el usuario");
					
				}
			}
			else if(codigo==2) //Registrarse
				{
					MYSQL_RES *resultado;
					MYSQL_ROW row;
					char buff2[256];
					int numero,i=0;
					char consulta [80];
					int IDUs, err;
					// construimos la consulta SQL
					
					//buscamos el ultimo ID asignado a un usuario
					strcpy (consulta,"SELECT MAX(player.Identificador) FROM player");
					err=mysql_query (conn, consulta); 
					if (err!=0) {
						printf ("Error al consultar datos de la base %u %s\n",
								mysql_errno(conn), mysql_error(conn));
						strcpy (buff2,"1/0,");
						return -1;
					}
					else{
						//recogemos el resultado de la consulta resultado = mysql_store_result (conn); 
						resultado = mysql_store_result (conn);
						numero=mysql_num_rows(resultado);
						row = mysql_fetch_row (resultado);
						if (row == NULL)
						{
							printf ("No se ha obtenido ningun ID\n");
							IDUs=0;
						}
						else
						{
							IDUs=atoi(row[0])+1;//Le sumamos 1 al ultimo ID asignado para conseguir el del nuevo usuario
						}
					}
					sprintf (consulta,"INSERT INTO player(Identificador,Name,Pass,Wingame,Losegame) VALUES ('%d','%s','%s',0,0)",IDUs,nombre,contrasenya);
					// hacemos la consulta 
					err=mysql_query (conn, consulta); 
					if (err!=0) {
						printf ("Error al consultar datos de la base %u %s\n",
								mysql_errno(conn), mysql_error(conn));
						strcpy (respuesta,"1/1,");
						return -1;
					}
					else
					{
						strcpy (respuesta,"1/0,");
						return 0;
					}
					
				}
					
			else if(codigo==3) //saber si ese jugador es el ganador	
			{
				
				
				resultado=mysql_store_result(conn);
				
				err=mysql_query (conn, "select relations.points from relations where relations.points=(select max(relations.points) from relations)");
				if (err!=0)
				{
					printf ("Error al consultar datos de la base %u %s\n",
							mysql_errno(conn), mysql_error(conn));
					exit (1);
				}
				
				resultado = mysql_store_result (conn);
				
				row= mysql_fetch_row(resultado);
				
				if (row== NULL)
				{
					printf("No se han obtenido datos en la consulta\n");
				}
				else
				{
					printf("NOmbre de la persona ganadora: %s\n", row[0]);
				}
				
				mysql_close(conn);
				exit(0);
			}
			else if(codigo==4) //Te desglosa todos los jugadores presentes
			{
				strcpy(respuesta,"");
				strcpy(consulta,"SELECT * FROM player"); //Seleciona todos los jugadores de mi lista
				err=mysql_query (conn, consulta); 
				if (err!=0) {
					printf ("Error al consultar datos de la base %u %s\n",
							mysql_errno(conn), mysql_error(conn));
					exit (1);
				}
				//recogemos el resultado de la consulta 
				resultado = mysql_store_result (conn); 
				row = mysql_fetch_row (resultado);
				if (row == NULL)
					printf ("No se han obtenido datos en la consulta\n");
				else
				{
					while (row !=NULL) 
					{
						
						char respuesta1[512];
						sprintf(respuesta1,"ID: %s, Username: %s, Password: %s\n", row[0], row[1], row[2]);
						strcat(respuesta, respuesta1);
						printf ("ID: %s, Username: %s, Password: %s\n", row[0], row[1], row[2]);
						row = mysql_fetch_row (resultado);
					}
					mysql_close(conn);
					exit(0);
			}
			}	
			else if(codigo==5) //Te hace el recovey de tu contraseña introduciendole un nombre de usuairo
			{
				p = strtok( NULL, "/");
				
				strcpy (nombre, p);
				// Ya tenemos el nombre
				printf ("Codigo: %d, Nombre: %s\n", codigo, nombre);
				strcpy (consulta,"SELECT player.Pass FROM player WHERE player.Name='");
				strcat(consulta, nombre);
				/*	strcat(consulta, "'");*/
				strcat(consulta, "'");
				// hacemos la consulta 
				err=mysql_query (conn, consulta); 
				if (err!=0) {
					printf ("Error al consultar datos de la base %u %s\n",
							mysql_errno(conn), mysql_error(conn));
					exit (1);
				}
				//recogemos el resultado de la consulta 
				resultado = mysql_store_result (conn); 
				row = mysql_fetch_row (resultado);
				if (row == NULL)
				{
					printf ("No se han obtenido datos en la consulta\n");
					strcpy (respuesta, "No existe");
				}
				else
				{
					while (row !=NULL)
					{ 
						
						
						printf ("Password: %s\n", row[0] );
						strcpy(respuesta,row[0]);
						row = mysql_fetch_row (resultado);
					}
				}
//			if (codigo !=0)
//			{
//				p = strtok( NULL, "/");
//				strcpy(nombre,p);
//				p = strtok( NULL, "/");
//				strcpy(contrasenya,p);				// Ya tenemos el nombre
//				printf ("Codigo: %d, Nombre: %s\n", codigo, nombre);
////			}		
				
			}
			
			
		}
		close(sock_conn);
		
	}
}


	// INICIALITZACIONS
	// Obrim el socket

