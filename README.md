# GhostService - Mouse Utility 👻

A lightweight C++ utility for Windows that keeps your system active by simulating subtle circular cursor movements. It is designed to run discreetly in the System Tray.

## ✨ Features
- **Minimal Resource Usage:** Built using native Windows API (`WinAPI`) and an event-based messaging system.
- **Windowless:** Runs in the background to avoid interrupting your workflow.
- **Minimal Interface:** A simple tray icon to close the application.
- **Transparency:** Open-source, simple, and well-structured code to demonstrate that no malicious actions are performed.

## 🛠 Project Structure
- `/src`: Source code (`.cpp`, `.h`).
- `/config`: Windows manifest and resource information.
- `/resources`: Icons and visual assets (e.g., `ghostservice.ico`).

## 🚀 Compilation
If you are using MinGW/g++ (MSYS2), you can compile the project by following these steps:

1. **Compile resources and icons:**
   ```bash
   windres config/resource.rc -O coff -o config/resource.res ``
2. **Compile final executable:**
   ```bash
   g++ src/main.cpp src/logic.cpp config/resource.res -o GhostService.exe -mwindows -O2 -s ``

## ⚖️ License
- This project is open-source and available under the MIT License.
