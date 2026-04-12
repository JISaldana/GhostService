# GhostService - Mouse Utility 👻

Una utilidad ligera escrita en C++ para Windows que mantiene el sistema activo simulando movimientos circulares del cursor. Diseñada para ejecutarse de forma discreta en la bandeja del sistema (System Tray).

## ✨ Características
- **Mínimo consumo de recursos:** Utiliza la API nativa de Windows (`WinAPI`) y un sistema de mensajes basado en eventos.
- **Sin ventana:** Se ejecuta en segundo plano para no interrumpir tu flujo de trabajo.
- **Interfaz minima:** Icono de la bandeja para cerrar la aplicación.
- **Transparencia:** Código abierto, sencillo y estructurado para demostrar que no realiza acciones maliciosas.

## 🛠 Estructura del Proyecto
- `/src`: Código fuente (`.cpp`, `.h`).
- `/config`: Manifiesto de Windows e información de recursos.
- `/resources`: Iconos y activos visuales.

## 🚀 Compilación
Si utilizas MinGW/g++, puedes compilar el proyecto siguiendo estos pasos:

1. **Compilar recursos e iconos:**
```bash
windres config/resource.rc -O coff -o config/resource.res
```
2. **Compilar ejecutable final:**
```bash
g++ src/main.cpp src/logic.cpp config/resource.res -o GhostService.exe -mwindows -O2 -s
```
