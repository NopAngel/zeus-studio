#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_LENGTH 256
#define LOG_FILE "./log/xlog_main.log"

void registrar_log(const char* clave, const char* valor) {
    FILE* archivo;
    time_t tiempo_actual;
    struct tm* tiempo_info;
    char tiempo_str[20];
    
    // Obtener tiempo actual
    time(&tiempo_actual);
    tiempo_info = localtime(&tiempo_actual);
    strftime(tiempo_str, sizeof(tiempo_str), "%Y-%m-%d %H:%M:%S", tiempo_info);
    
    // Abrir archivo en modo append
    archivo = fopen(LOG_FILE, "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de log\\n");
        return;
    }
    
    // Escribir el log
    fprintf(archivo, "[%s] Clave: %s | Valor: %s\\n", 
            tiempo_str, clave, valor);
    
    fclose(archivo);
}

int main() {
    // Ejemplos de uso
    registrar_log("open.py", "C:\\Users\\Nietoyface\\Documents\\Angel Folder\\editor_code__c\\test_build\\open.py");
    registrar_log("archive.js", "C:\\Users\\Nietoyface\\Documents\\Angel Folder\\editor_code__c\\test_build\\archive.js");
    
    return 0;
}