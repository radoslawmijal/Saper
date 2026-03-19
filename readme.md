 # Saper (Minesweeper) - C++ & SFML
A classic implementation of the Minesweeper game written in C++ using the SFML graphics library. The project is based on the MVC (Model-View-Controller) architecture, keeping the game logic clearly separated from the user interface.


## 🎮 Controls and Gameplay Mechanics
The gameplay follows the classic Minesweeper rules:
* **Left Mouse Button (LMB)** - Reveal the selected field.
* **Right Mouse Button (RMB)** - Place or remove a flag on an unrevealed field.

### Difficulty Levels
You can change the difficulty level before starting the game by pressing the numeric keys on your keyboard:
* `1` - EASY mode
* `2` - NORMAL mode
* `3` - HARD mode

## 🛠 Prerequisites

To successfully compile and run the project, ensure you have the following installed and configured on your system:
* A compiler supporting the **C++17** standard.
* **CMake** build system (minimum version **3.26**).
* **SFML** library (version **2.5**, required components: *graphics*, *audio*).
* An `Images` folder in the root directory of the project (CMake is configured to automatically copy it to the build directory).

## 🚀 Compilation and Running
Follow these steps to build the application using CMake:

1. Download or clone the repository to your local machine.
    ```bash
    git clone https://github.com/radoslawmijal/Saper
    cd Saper 
2. Create a build directory and navigate into it. 
   ```bash
   cmake -S . -B build
   cd build
3. Build project structure. 
   ```bash
   make
4. Run the file and have fun. 
   ```bash
   ./Saper