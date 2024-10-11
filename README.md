Greed - Juego de Dados
Descripción
Greed es una variante del juego "Push Your Luck" desarrollado por Bob Lancaster en 1990 para MS-DOS. Es un juego de dados que combina suerte y estrategia, donde los jugadores deben decidir si continúan lanzando dados para acumular puntos o si se arriesgan a perder todo. El proyecto ha sido desarrollado en C++ como una aplicación de consola.

Características
Modo de un jugador y dos jugadores.
Gestión de puntajes y estadísticas.
Sistema de bloqueadores que elimina dados en cada ronda.
Los jugadores pueden decidir en cada ronda si seguir tirando o no.
Al duplicar los puntos, el jugador está obligado a volver a tirar los dados.
Interfaz de menú interactivo en consola.
Instalación
Para ejecutar el juego localmente, sigue estos pasos:

Clona el repositorio:

bash
Copy code
git clone https://github.com/usuario/greed-juego-de-dados.git
Compila el programa (requiere un compilador de C++):

bash
Copy code
g++ main.cpp -o Greed
Ejecuta el programa:

bash
Copy code
./Greed
Cómo Jugar
Elige el modo de juego desde el menú principal:

Modo un jugador: Ingresa tu nombre y comienza una partida.
Modo dos jugadores: Ingresa los nombres de los dos jugadores y comienza una partida.
Estadísticas: Muestra el puntaje más alto registrado.
Créditos: Muestra los nombres del equipo de desarrollo.
Salir: Cierra el juego.
Durante cada ronda:

Lanza hasta 5 dados.
Los valores de los "dados bloqueadores" no podrán utilizarse en las siguientes tiradas.
Decide si quieres seguir tirando o detenerte y conservar tus puntos.
Si todos los dados son iguales y no son bloqueadores, duplicarás tu puntaje pero deberás volver a lanzar.
El juego termina cuando se han completado tres rondas, y el jugador con mayor puntaje será el ganador.

Requisitos
Lenguaje: C++.
Entorno: Consola (programa de línea de comandos).
Compilador: Un compilador de C++ como GCC.
Contribución
Si deseas contribuir al proyecto, sigue estos pasos:

Haz un fork del repositorio.
Crea una nueva rama (git checkout -b feature/nueva-funcion).
Realiza tus cambios y haz un commit (git commit -m 'Añadir nueva función').
Envía un push a la rama (git push origin feature/nueva-funcion).
Abre un pull request en GitHub.
Estructura del Proyecto
bash
Copy code
├── src/
│   ├── main.cpp           # Archivo principal del juego
│   ├── dados.cpp          # Lógica para tirar dados
│   ├── menu.cpp           # Implementación del menú
│   ├── puntajes.cpp       # Gestión de puntajes y estadísticas
│   └── jugadores.cpp      # Funciones para manejo de jugadores
├── include/
│   ├── dados.h            # Header para los dados
│   ├── menu.h             # Header para el menú
│   └── jugadores.h        # Header para jugadores
├── README.md              # Documentación del proyecto
└── LICENSE                # Información sobre la licencia
Licencia
Este proyecto está bajo la licencia MIT. Consulta el archivo LICENSE para más detalles.

Créditos
Desarrollado por el equipo inventado:

Juan Pérez (Legajo: 12345)
María López (Legajo: 67890)
Enlaces de interés
Juego original en línea
Demostración en YouTube
