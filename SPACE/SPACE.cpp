#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

const int HEIGHT = 600;
const int WIDTH = 800;

const int SIZE = 20;
const int NUM_ITER = 1000;

sf::RectangleShape whiteCell();
sf::RectangleShape blackCell();
std::vector<std::vector<sf::RectangleShape>> fillGrid(std::vector<std::vector<sf::RectangleShape>> grid, int*);

int main(){

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "GRAVITY");

    sf::RectangleShape originCell = blackCell();
    sf::Vector2<float> pos = { WIDTH / 2 , 0};
    originCell.setPosition(pos);

    std::vector< std::vector<sf::RectangleShape> > grid;
    grid.resize(NUM_ITER);
    for (int n = 0; n < NUM_ITER; n++) {
        grid[n].resize(NUM_ITER);
    }

    int cond[8] = { 0, 0, 0, 1, 1, 1, 1, 0 };

 
    for (int i = 0; i < NUM_ITER; i++)
    {
        for (int j = 0; j < NUM_ITER; j++)
        {
            grid[i][j] = whiteCell();
        }
    }

    grid[0][NUM_ITER / 2] = originCell;
    grid = fillGrid(grid, cond);


    while (window.isOpen()){
        // Process events
        sf::Event event;
        while (window.pollEvent(event)){
            // Close window: exit
            if (event.type == sf::Event::Closed) window.close();
        }
        // Clear screen
        window.clear(sf::Color::White);

        for (int i = 0; i < NUM_ITER; i++)
        {
            for (int j = 0; j < NUM_ITER; j++)
            {
                sf::Vector2<float> temp = { float(j*2) , float(i*2) };
                grid[i][j].setPosition(temp);
                window.draw(grid[i][j]);
            }
        }

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}

std::vector<std::vector<sf::RectangleShape>> fillGrid(std::vector<std::vector<sf::RectangleShape>> grid, int* cond) {



    for (int i = 1; i < NUM_ITER-1; i++)
    {
        for (int j = 1; j < NUM_ITER -1; j++)
        {

            if (grid[i - 1][j - 1].getFillColor() == sf::Color::Black && grid[i - 1][j].getFillColor() == sf::Color::Black && grid[i - 1][j + 1].getFillColor() == sf::Color::Black) {
                if (cond[0] == 1) grid[i][j] = blackCell();
                else grid[i][j] = whiteCell();
            }
            else if (grid[i - 1][j - 1].getFillColor() == sf::Color::Black && grid[i - 1][j].getFillColor() == sf::Color::Black && grid[i - 1][j + 1].getFillColor() == sf::Color::White) {
                if (cond[1] == 1) grid[i][j] = blackCell();
                else grid[i][j] = whiteCell();
            }
            else if (grid[i - 1][j - 1].getFillColor() == sf::Color::Black && grid[i - 1][j].getFillColor() == sf::Color::White && grid[i - 1][j + 1].getFillColor() == sf::Color::Black) {
                if (cond[2] == 1) grid[i][j] = blackCell();
                else grid[i][j] = whiteCell();
            }
            else if (grid[i - 1][j - 1].getFillColor() == sf::Color::Black && grid[i - 1][j].getFillColor() == sf::Color::White && grid[i - 1][j + 1].getFillColor() == sf::Color::White) {
                if (cond[3] == 1) grid[i][j] = blackCell();
                else grid[i][j] = whiteCell();
            }
            else if (grid[i - 1][j - 1].getFillColor() == sf::Color::White && grid[i - 1][j].getFillColor() == sf::Color::Black && grid[i - 1][j + 1].getFillColor() == sf::Color::Black) {
                if (cond[4] == 1) grid[i][j] = blackCell();
                else grid[i][j] = whiteCell();
            }
            else if (grid[i - 1][j - 1].getFillColor() == sf::Color::White && grid[i - 1][j].getFillColor() == sf::Color::Black && grid[i - 1][j + 1].getFillColor() == sf::Color::White) {
                if (cond[5] == 1) grid[i][j] = blackCell();
                else grid[i][j] = whiteCell();
            }
            else if (grid[i - 1][j - 1].getFillColor() == sf::Color::White && grid[i - 1][j].getFillColor() == sf::Color::White && grid[i - 1][j + 1].getFillColor() == sf::Color::Black) {
                if (cond[6] == 1) grid[i][j] = blackCell();
                else grid[i][j] = whiteCell();
            }
            else if (grid[i - 1][j - 1].getFillColor() == sf::Color::White && grid[i - 1][j].getFillColor() == sf::Color::White && grid[i - 1][j + 1].getFillColor() == sf::Color::White) {
                if (cond[7] == 1) grid[i][j] = blackCell();
                else grid[i][j] = whiteCell();
            }
        }
    }

    return grid;
}

sf::RectangleShape blackCell() {
    sf::RectangleShape cell;
    sf::Vector2<float> sizeV = { SIZE/10,SIZE / 10 };
    cell.setSize(sizeV);
    cell.setFillColor(sf::Color::Black);

    return cell;
}

sf::RectangleShape whiteCell() {
    sf::RectangleShape cell;
    sf::Vector2<float> sizeV = { SIZE / 10, SIZE / 10 };
    cell.setSize(sizeV);
    cell.setFillColor(sf::Color::White);

    return cell;
}