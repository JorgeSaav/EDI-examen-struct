#include <stdio.h>
#include <string.h>
#define N 3
#define Col_ESTA 0
#define Col_SUEL 1

void capturaDatos(struct empleados clave[N]);
int BusquedaEmpAlto(struct empleados clave[N]);
void OrdenaEmpleados(struct empleados clave[N]);
void ImprimeDatos(struct empleados clave[N]);

int main()
{
	struct empleados clave[N];
	
	struct empleados
	{
	int clav[N], posicion;
	char nombre[N][20];
	float datos[N][2];
 	};
 	
	capturaDatos(empleados);
	
	OrdenaEmpleados(empleados);
	
	ImprimeDatos(empleados);
	
	posicion=BusquedaEmpAlto(empleados);
	
	printf("Nombre del empleado mas alto: %s\n", clave[N].nombre[posicion]);
	printf("Su estatura es: %.2f\n", clave[N].datos[posicion][Col_ESTA]);	
	
	return 0;
}

void capturaDatos(struct empleados clave[N])
{
	int i;
	
	for(i=0; i<N; i++)
	{
		printf("Clave[%d]: ", i);
		scanf("%d", &clave[i]->clav);
		printf("Nombre[%d]: ", i);
		scanf("%s", &clave[i]->nombre);
		printf("Estatura[%d]: ", i);
		scanf("%f", &clave[i]->datos[i][Col_ESTA]);
		printf("sueldo[%d]: ", i);
		scanf("%f", &clave[i]->datos[i][Col_SUEL]);
	}
	
}

int BusquedaEmpAlto(struct empleados clave[N])
{
	int i, posicion=0;
	float mayor = clave[N].datos[0][Col_ESTA];
	
	for(i=0; i<N; i++)
	{
		if(clave[i].datos[0][Col_ESTA] > mayor)
		{
			mayor = clave[i].datos[0][Col_ESTA];
			posicion = i;
		}
	}
	
	return posicion;

}

void OrdenaEmpleados(struct empleados clave[N])
{
	int i, j, auxclav;
	float aux;
	char auxnom[20];
	
	for(i=0; i<N-1; i++)
	{
		for(j=0; j<N-1; j++)
		{
			if(clave[j].datos[j]Col_SUEL] < clave[j].datos[j+1][Col_SUEL])
			{
				//int sueldo
				aux = clave[j].datos[j][Col_SUEL];
				clave[j].datos[j][Col_SUEL] = clave[j].datos[j+1][Col_SUEL];
				clave[j].datos[j+1][Col_SUEL] = aux; 
				
				//int clave
				auxclav = clave[j].clav[j];
				clave[j].clav[j] = clave[j].clav[j+1];
				clave[j].clav[j+1] = auxclav;
				
				//int nombre
				strcpy(auxnom, clave[j].nombre[j]);
				strcpy(clave[j].nombre[j], clave[j].nombre[j+1]);
				strcpy(clave[j].nombre[j+1], auxnom);
					
				//int estatura
				aux = clave[j].datos[j][Col_ESTA];
				clave[j].datos[j][Col_ESTA] = clave[j].datos[j+1][Col_ESTA];
				clave[j].datos[j+1][Col_ESTA] = aux; 
			}
		}
	}
}

void ImprimeDatos(struct empleados clave[N])
{
	int i;
	
	printf("Clave	Nombre	Estatura	Sueldo\n");
	
	for(i=0; i<N; i++)
	{
		printf("%d\t", clave[i].clav[i]);
		printf("%s\t", clave[i].nombre[i]);
		printf("%.2f\t", clave[i].datos[i][Col_ESTA]);
		printf("%.2f\n", clave[i].datos[i][Col_SUEL]);	
	}
}

