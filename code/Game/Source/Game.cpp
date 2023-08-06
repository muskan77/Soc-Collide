#include"Game.h"
#include"defs.h"
#include"Textures.h"
#include<iostream>

Game::Game(SDL_Renderer* renderer){
    running = true;
    timer= 0;
    
    int level;
    std::cout<<"enter the level \n";
    std::cin>>level;
    initialize(renderer,level); // Initialize the game with the specified level
}

void Game::initialize(SDL_Renderer* renderer, int levelCounter){

    //Clear the list of bodies
    while(listOfBodies.size()) listOfBodies.pop_back();

    //Add player

        Bodies* B = new Bodies(10,10,20,20,0);
        B->SetColour(255,0,0);
        B->initialiseTextureAndImage(renderer);
        listOfBodies.push_back(B);



 // Add one obstacle
    if (levelCounter == 1) { //type 1 is enemyship
        gameLevel = 1;

   
    Bodies *debris = new Bodies(WIDTH/2, 5, 5, 5, 10);
        debris->SetColour(128,128,128);
        debris->SetVel(0,0.25);
        listOfBodies.push_back(debris);

    for (int i = 0; 20 * i < WIDTH - 20; i += 4) {
        Bodies *movingBody = new Bodies(WIDTH - 60, 20 * i+20, 40, 40, 1);// moving body is enemy player
        movingBody->SetColour(0, 255, 0);
        movingBody->SetVel(0, 0);
        movingBody->initialiseTextureAndImage(renderer);
        listOfBodies.push_back(movingBody);


        // Create bullets for this enemy player
        for (int j = 0; j < 4; j++) {
            Bodies *bullet = new Bodies(movingBody->GetX(), movingBody->GetY()+25, 5, 5, 6);// type 6 is enemybullet
            bullet->SetColour(0, 0, 255);  // Bullet color (blue)
            bullet->SetVel(-8, 0);  // Bullet velocity
            listOfBodies.push_back(bullet);
        }
    }



     Bodies *gameOver = new Bodies(WIDTH - 20, (HEIGHT/2) - 20, 20,20,3);//type 3 is trophy
        gameOver->SetColour(0,0,255);
        gameOver->SetVel(0,0);
        listOfBodies.push_back(gameOver);

        
    }  
    
    else if (levelCounter == 2) {
        gameLevel = 2;

        Bodies *gameOver = new Bodies(WIDTH - 20, (HEIGHT/2) - 20, 20,20,3);
        gameOver->SetColour(0,0,255);
        gameOver->SetVel(0,0);
        listOfBodies.push_back(gameOver);

    for (int i = 0; 20 * i < WIDTH - 20; i += 4) {
        Bodies *movingBody = new Bodies(WIDTH - 60, 20 * i+20, 40, 40, 1);// moving body is enemy player
        movingBody->SetColour(0, 255, 0);
        movingBody->SetVel(0, 0);
        movingBody->initialiseTextureAndImage(renderer);
        listOfBodies.push_back(movingBody);

        // Create bullets for this enemy player
        for (int j = 0; j < 4; j++) {
            Bodies *bullet = new Bodies(movingBody->GetX(), movingBody->GetY()+25, 5, 5, 6);// type 6 is enemybullet
            bullet->SetColour(0, 0, 255);  // Bullet color (blue)
            bullet->SetVel(-8, 0);  // Bullet velocity
            listOfBodies.push_back(bullet);
        }
    }

        Bodies *shield = new Bodies(WIDTH - 100, HEIGHT - 80, 20, 80, 2);
        shield->SetColour(255,255,255);
        shield->SetVel(0,-5);
        listOfBodies.push_back(shield);

    for (int i = 0; 20 * i < WIDTH - 20; i += 4) {
        Bodies *movingBody = new Bodies(WIDTH - 240, 20 * i+20, 40, 40, 1);// moving body is enemy player
        movingBody->SetColour(0, 255, 0);
        movingBody->SetVel(0, 0);
        movingBody->initialiseTextureAndImage(renderer);
        listOfBodies.push_back(movingBody);

        // Create bullets for this enemy player
        for (int j = 0; j < 4; j++) {
            Bodies *bullet = new Bodies(movingBody->GetX(), movingBody->GetY()+20, 5, 5, 6);// type 6 is enemybullet
            bullet->SetColour(0, 0, 255);  // Bullet color (blue)
            bullet->SetVel(-8, 0);  // Bullet velocity
            listOfBodies.push_back(bullet);
        }
    }
                             
    }
    else if (levelCounter == 3) {
        gameLevel = 3;

        for (int i = 0; 20 * i < WIDTH - 20; i += 4) {
        Bodies *movingBody = new Bodies(WIDTH - 60, 20 * i+20, 40, 40, 1);// moving body is enemy player
        movingBody->SetColour(0, 255, 0);
        movingBody->SetVel(-1, 0);
        movingBody->initialiseTextureAndImage(renderer);
        listOfBodies.push_back(movingBody);

        // Create bullets for this enemy player
        for (int j = 0; j < 4; j++) {
            Bodies *bullet = new Bodies(movingBody->GetX(), movingBody->GetY()+10, 5, 5, 6);// type 6 is enemybullet
            bullet->SetColour(0, 0, 255);  // Bullet color (blue)
            bullet->SetVel(-8, 0);  // Bullet velocity
            listOfBodies.push_back(bullet);
        }

        for (int j = 0; j < 4; j++) {
            Bodies *bullet = new Bodies(movingBody->GetX(), movingBody->GetY()+30, 5, 5, 6);// type 6 is enemybullet
            bullet->SetColour(0, 0, 255);  // Bullet color (blue)
            bullet->SetVel(-8, 0);  // Bullet velocity
            listOfBodies.push_back(bullet);
        }
    }

        Bodies *gameOver = new Bodies(WIDTH - 20, (HEIGHT/2) - 20, 20,20,3);
        gameOver->SetColour(0,0,255);
        gameOver->SetVel(0,0);
        listOfBodies.push_back(gameOver);
    }

    else if (levelCounter == 4) {
        gameLevel = 4;

        Bodies *debris = new Bodies(WIDTH - 20, (HEIGHT/2) - 20, 20,20,10);
        debris->SetColour(0,0,255);
        debris->SetVel(0,0.25);
        debris->initialiseTextureAndImage(renderer);
        listOfBodies.push_back(debris);

        for (int i = 0; 20 * i < WIDTH - 20; i += 4) {
        Bodies *movingBody = new Bodies(WIDTH - 60, 20*i +40, 40, 40, 1);// moving body is enemy player
        movingBody->SetColour(0, 255, 0);
        movingBody->SetVel(-1, -1);
        movingBody->initialiseTextureAndImage(renderer);
        listOfBodies.push_back(movingBody);

        // Create bullets for this enemy player
        for (int j = 0; j < 4; j++) {
            Bodies *bullet = new Bodies(movingBody->GetX(), movingBody->GetY()+10, 5, 5, 6);// type 6 is enemybullet
            bullet->SetColour(0, 0, 255);  // Bullet color (blue)
            bullet->SetVel(-8, 0);  // Bullet velocity
            listOfBodies.push_back(bullet);
        }
        }
        for (int i = 0; 20 * i < WIDTH - 20; i += 4) {
        Bodies *movingBody = new Bodies(WIDTH - 240, 20 * i+20, 40, 40, 1);// moving body is enemy player
        movingBody->SetColour(0, 255, 0);
        movingBody->SetVel(-1, -1);
        movingBody->initialiseTextureAndImage(renderer);
        listOfBodies.push_back(movingBody);

        // Create bullets for this enemy player
        for (int j = 0; j < 4; j++) {
            Bodies *bullet = new Bodies(movingBody->GetX(), movingBody->GetY()+20, 5, 5, 6);// type 6 is enemybullet
            bullet->SetColour(0, 0, 255);  // Bullet color (blue)
            bullet->SetVel(-8, 0);  // Bullet velocity
            listOfBodies.push_back(bullet);
        }
    }

        Bodies *gameOver = new Bodies(WIDTH - 20, (HEIGHT/2) - 20, 20,20,3);
        gameOver->SetColour(0,0,255);
        gameOver->SetVel(0,0);
        listOfBodies.push_back(gameOver);
    }
        

    
    else {
        gameLevel = 5;
        while(listOfBodies.size()) listOfBodies.pop_back();
    }
}

void Game::addPlayerBullet(double x, double y) {
    Bodies* bullet = new Bodies(x, y, 5, 5, 5); // Type 5 for player bullets
    bullet->SetColour(0, 255, 0);              // Bullet color (green)
    bullet->SetVel(8, 0);                      // Bullet velocity
    listOfBodies.push_back(bullet);
}

void Game::key_down(SDL_KeyboardEvent* event ,  SDL_Renderer* renderer){//when key is pressed

    if(event->repeat==0){
        // Press any key to restart game
        if(timer>RESET_TIME && !running){ 
            running = true;
            initialize(renderer,gameLevel);
        }
        switch (event->keysym.scancode){
            case SDL_SCANCODE_UP:
                listOfBodies[0]->vel_y=-5;
                addPlayerBullet(listOfBodies[0]->GetX() + listOfBodies[0]->widthOfBody(), listOfBodies[0]->GetY() + listOfBodies[0]->heightOfBody() / 2);
                //for firing bullet whenever a player moves
                break;

            case SDL_SCANCODE_DOWN:
                listOfBodies[0]->vel_y=5;
                addPlayerBullet(listOfBodies[0]->GetX() + listOfBodies[0]->widthOfBody(), listOfBodies[0]->GetY() + listOfBodies[0]->heightOfBody() / 2);
                break;

            case SDL_SCANCODE_LEFT:
                listOfBodies[0]->vel_x=-5;
                addPlayerBullet(listOfBodies[0]->GetX() + listOfBodies[0]->widthOfBody(), listOfBodies[0]->GetY() + listOfBodies[0]->heightOfBody() / 2);
                break;

            case SDL_SCANCODE_RIGHT:
                listOfBodies[0]->vel_x=5;   
                addPlayerBullet(listOfBodies[0]->GetX() + listOfBodies[0]->widthOfBody(), listOfBodies[0]->GetY() + listOfBodies[0]->heightOfBody() / 2);
                break;
            default:
                break;
        }
    }
}


void Game::key_up(SDL_KeyboardEvent* event ){//when the key stops being pressed
    if(event->repeat==0){    
        switch (event->keysym.scancode){
            case SDL_SCANCODE_UP:
                listOfBodies[0]->vel_y=0;
                break;
            case SDL_SCANCODE_DOWN:
                listOfBodies[0]->vel_y=0;
                break;
            case SDL_SCANCODE_LEFT:
                listOfBodies[0]->vel_x=0;
                break;
            case SDL_SCANCODE_RIGHT:
                listOfBodies[0]->vel_x=0;   
                break;
            default:
                break;
        }
    }
}


void Game::move(SDL_Renderer* renderer){
    if(running){
        //move the bodies
         for(long unsigned int i=0; i<listOfBodies.size();i++){
            listOfBodies[i]->move();  

            
                    if (listOfBodies[i]->giveType() == 5) { // Check if it's a player bullet
                       
                            for (long unsigned int j = 1; j < listOfBodies.size(); j++) { // Skip the player's body (index 0)
                                if (listOfBodies[j]->giveType() != 5 && listOfBodies[j]->check_col(listOfBodies[i])) {
                                    
                                    // Remove the hit enemy body and its bullets, and free memory
                                        if (listOfBodies[j]->giveType() == 6) { // If enemy bullet
                                            delete listOfBodies[j];
                                            listOfBodies.erase(listOfBodies.begin() + j);
                                            j--; // Decrement j to account for the erased element
                                        } else{ // If enemy body
                                            delete listOfBodies[i];
                                            delete listOfBodies[j];
                                            listOfBodies.erase(listOfBodies.begin() + i);
                                            listOfBodies.erase(listOfBodies.begin() + j - (j > i)); // Adjust index if j > i
                                            i--; // Decrement i to account for the erased elements
                                            j--; // Decrement j to account for the erased elements
                                        }
                                        break; // Exit the inner loop since the bodies were removed
                                    
                                }
                            }
                        
                    }



            // Update enemy bullet movement when the enemy is alive
            if (listOfBodies[i]->giveType() == 6 && listOfBodies[0]->check_col(listOfBodies[i])) {
               if (listOfBodies[0]->giveType() != 3) {
                   listOfBodies[i]->move();
               }
           }


            if (listOfBodies[i]->giveType() != 3) {
                if (listOfBodies[i]->giveType()!=0){
                    if (listOfBodies[i]->x + listOfBodies[i]->widthOfBody() + listOfBodies[i]->vel_x > WIDTH) {
                        listOfBodies[i]->vel_x = -5;
                        if (listOfBodies[i]->giveType() == 6){
                            listOfBodies[i]->vel_x = -8;
                        }
                    }
                    else if (listOfBodies[i]->x + listOfBodies[i]->vel_x < 0) {
                        if (listOfBodies[i]->giveType() == 6){
                            listOfBodies[i]->resetPos();
                        }
                        listOfBodies[i]->vel_x = -5;
                    }
                    if (listOfBodies[i]->y + listOfBodies[i]->vel_y <0) {
                        listOfBodies[i]->vel_y = 5;
                        if (listOfBodies[i]->giveType() == 6){
                            listOfBodies[i]->vel_y = -8;
                        }
                    }
                    else if (listOfBodies[i]->y + listOfBodies[i]->heightOfBody() + listOfBodies[i]->vel_y >HEIGHT) {
                        if (listOfBodies[i]->giveType() == 6){
                            listOfBodies[i]->resetPos();
                        }
                        listOfBodies[i]->vel_y = -5;
                    }                    
                    else if (listOfBodies[i]->giveType() == 2) {
                        if (listOfBodies[i]->vel_x > 0 ) {
                            listOfBodies[i]->vel_x += 0.07;
                        }
                        else if (listOfBodies[i]->vel_x < 0) {
                            listOfBodies[i]->vel_x -= 0.07;
                        }
                    }
                }
            }
            else {
                if (gameLevel == 2 || gameLevel == 3) {
                    if (listOfBodies[i]->y + listOfBodies[i]->vel_y <0) {
                        listOfBodies[i]->vel_y = 5;
                    }
                    else if (listOfBodies[i]->y + listOfBodies[i]->heightOfBody() + listOfBodies[i]->vel_y >HEIGHT) {
                        listOfBodies[i]->vel_y = -5;
                    }
                }
                if (gameLevel == 4) {
                    if (listOfBodies[2]->vel_y == 5) {
                        listOfBodies[i]->vel_y = 5;
                    }
                    else if (listOfBodies[2]->vel_y == -5) {
                        listOfBodies[i]->vel_y = -5;
                    }
                }
            }
        }

         for(long unsigned int i=1; i<listOfBodies.size();i++){
            if (listOfBodies[i]->giveType() == 5 && listOfBodies[0]->check_col(listOfBodies[i])) {
                listOfBodies.erase(listOfBodies.begin() + i);
                break; // Exit the loop since the bullet was removed
            }
         }

        //check for collision
        for(long unsigned int i=1; i<listOfBodies.size();i++){
            if(listOfBodies[0]->check_col(listOfBodies[i]))
            {
                if (listOfBodies[i]->giveType() == 1 || listOfBodies[i]->giveType() == 4 || listOfBodies[i]->giveType() == 5 || listOfBodies[i]->giveType() == 6 || listOfBodies[i]->giveType() == 10) {
                    while (listOfBodies.size()) {
                        listOfBodies.pop_back();
                    }
                    running = false;
                    timer = RESET_TIME + 1;
                    break;
                }
                else if (listOfBodies[i]->giveType() == 2) {
                    for (int u=0; u<2; u++) {
                        if (listOfBodies[0]->x-listOfBodies[0]->vel_x > 0 && listOfBodies[0]->x - listOfBodies[0]->vel_x < WIDTH) {
                            listOfBodies[0]->x -= listOfBodies[0]->vel_x;
                        }
                        else {
                           while (listOfBodies.size()) {
                                listOfBodies.pop_back();
                            }
                            running = false;
                            timer = RESET_TIME + 1;
                            break; 
                        }
                        if (listOfBodies[0]->y - listOfBodies[0]->vel_y > 0 && listOfBodies[0]->y - listOfBodies[0]->vel_y < HEIGHT) {
                            listOfBodies[0]->y -= listOfBodies[0]->vel_y;
                        }
                        else {
                           while (listOfBodies.size()) {
                                listOfBodies.pop_back();
                            }
                            running = false;
                            timer = RESET_TIME + 1;
                            break;                             
                        }
                    }
                }
                else if (listOfBodies[i]->giveType() == 8) {
                    if (listOfBodies[i]->giveColorGreen() == 215) {
                        coinCounter++;
                        if (coinCounter == 5) {
                            listOfBodies[11]->SetColour(0,0,255);
                        }
                    }
                    listOfBodies[i]->SetColour(255,0,0);
                }
                else if (listOfBodies[i]->giveType() == 7) {
                    if (listOfBodies[i]->giveColor() == 0) {
                        listOfBodies[i]->SetColour(0,255,0);
                        while (listOfBodies.size()) {
                            listOfBodies.pop_back();
                        }
                        running = false;
                        timer = RESET_TIME + 1;
                        break;          
                    }
                }
                else if (listOfBodies[i]->giveType() == 9) {
                    if (coinCounter < 5) {
                        for (int u=0; u<2; u++) {
                            if (listOfBodies[0]->x-listOfBodies[0]->vel_x > 0 && listOfBodies[0]->x - listOfBodies[0]->vel_x < WIDTH) {
                                listOfBodies[0]->x -= listOfBodies[0]->vel_x;
                            }
                            else {
                               while (listOfBodies.size()) {
                                    listOfBodies.pop_back();
                                }
                                running = false;
                                timer = RESET_TIME + 1;
                                break; 
                            }
                            if (listOfBodies[0]->y - listOfBodies[0]->vel_y > 0 && listOfBodies[0]->y - listOfBodies[0]->vel_y < HEIGHT) {
                                listOfBodies[0]->y -= listOfBodies[0]->vel_y;
                            }
                            else {
                                while (listOfBodies.size()) {
                                    listOfBodies.pop_back();
                                }
                                running = false;
                                timer = RESET_TIME + 1;
                                break;                             
                            }
                        }                        
                    }
                    else {
                        gameLevel++;
                        initialize(renderer,gameLevel);                        
                    }
                }
                else {
                    gameLevel++;
                    initialize(renderer,gameLevel);
                }
            }
        }
    }
    
    else timer++;
}



//render
void Game::render(SDL_Renderer* renderer, bool &gameEndScreen){
    if(running){

      
        if (gameLevel == 5) {
            gameEndScreen = true;
        }
        
        
        for(long unsigned int i=0; i<listOfBodies.size();i++){
            if (listOfBodies[i]->giveType() == 7) {
                if (gameLevel == 4) {
                    if (listOfBodies[i]->giveTime() % 300 <= 60) {
                        listOfBodies[i]->SetColour(255,0,0);
                    }
                    else {
                        listOfBodies[i]->SetColour(0,255,0);
                    }
                }
                else {
                    if (listOfBodies[i]->giveTime()%500 <= 150) {
                        listOfBodies[i]->SetColour(255,0,0);
                    }
                    else {
                        listOfBodies[i]->SetColour(0,255,0);
                    }
                }
            }
            listOfBodies[i]->display(renderer);
        }
    }
}