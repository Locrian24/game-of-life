//BASIC GAME OF LIFE IN C++

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GAME_WIDTH = 200;
int GAME_HEIGHT = 200;
int CELL_SIZE = 5;
int NUM_CELL = GAME_WIDTH * GAME_HEIGHT;

int WINDOW_WIDTH = GAME_WIDTH * CELL_SIZE;
int WINDOW_HEIGHT = GAME_HEIGHT * CELL_SIZE;
int FPS = 60;

int SPAWN_RATE = 30;

int main()
{
    srand( time(NULL));
    std::vector<int> gameGrid;
    std::vector<int> gameOutput(NUM_CELL);
    
    gameGrid.reserve(NUM_CELL);
    
    for (int i = 0; i < NUM_CELL; i++)
    {
        gameGrid.push_back( (rand() % 100 < SPAWN_RATE) ? 1 : 0 );
    }
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game of Life");
    window.setFramerateLimit(FPS);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        window.clear();
        
        //DRAW SCREEN
        int currentCell;
        for (int x = 0; x < GAME_WIDTH; x++)
        {
            for (int y = 0; y < GAME_HEIGHT; y++)
            {
                currentCell = gameGrid[GAME_WIDTH * x + y];
                
                if (currentCell == 1)
                {
                    sf::CircleShape cell(CELL_SIZE/2);
                    cell.setFillColor(sf::Color::Green);
                    cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
                    
                    window.draw(cell);
                }
            }
        }

        // Update the window
        window.display();
        
        //GENERATE NEXT FRAME
        int currentPos, numNeighbours, outputState;
        for (int x = 1; x < GAME_WIDTH - 1; x++)
        {
            for (int y = 1; y < GAME_HEIGHT - 1; y++)
            {
                currentPos = GAME_WIDTH * x + y;
                
                numNeighbours = gameGrid[GAME_WIDTH * (x-1) + (y-1) ] + gameGrid[GAME_WIDTH * x + (y-1)] + gameGrid[GAME_WIDTH * (x+1) + (y-1)  ] +
                gameGrid[GAME_WIDTH * (x-1) + y     ] +                  0               + gameGrid[GAME_WIDTH * (x+1) +    y   ] +
                gameGrid[GAME_WIDTH * (x-1) + (y+1) ] + gameGrid[GAME_WIDTH * x + (y+1)] + gameGrid[GAME_WIDTH * (x+1) + (y+1)  ];
                
                //any live cell with less than 2 neighbours dies
                //any live cell with 2 or 3 neighbours survives
                //any live cell with more than 3 neighbours dies
                //any dead cell with exactly 3 neighbours is born
                if (numNeighbours < 2) {
                    outputState = 0;
                }
                else if (numNeighbours == 2) { //only survives if already alive
                    if (gameGrid[currentPos] == 1)
                    {
                        outputState = 1;
                    } else {
                        outputState = 0;
                    }
                }
                else if (numNeighbours == 3)
                {
                    outputState = 1;
                }
                else if (numNeighbours > 3)
                {
                    outputState = 0;
                }
                
                gameOutput[currentPos] = outputState;
            }
        }
        
        //Update the grid that is drawn
        gameGrid = gameOutput;
    }

    return 0;
}
