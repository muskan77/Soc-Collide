#include"Game.h"
#include"defs.h"
#include<iostream>

Game::Game(){
    running = false;
    gameover = false;
    timer= 0;
    initialize();
}
void Game::initialize(){
    //Clear the list of bodies
    while(listOfBodies.size()) listOfBodies.pop_back();

    //Add player
    Bodies* B = new Bodies(0,0,20,20,0);
    B->SetColour(255,0,0);
    listOfBodies.push_back(B);

    //Add object 1
    Bodies* obj1 = new Bodies(50,HEIGHT-140,70,10,1);
    obj1->SetColour(0,0,0);
    listOfBodies.push_back(obj1);

    //Add object 2
    Bodies* obj2 = new Bodies(WIDTH-120,HEIGHT-140,70,10,2);
    obj2->SetColour(0,0,0);
    listOfBodies.push_back(obj2);

    //Add object 3
    Bodies* obj3 = new Bodies(WIDTH/2-35,HEIGHT-140,70,10,3);
    obj3->SetColour(0,0,0);
    listOfBodies.push_back(obj3);

    //Add object 4
    Bodies* obj4 = new Bodies(WIDTH-120,60,70,10,4);
    obj4->SetColour(0,0,0);
    listOfBodies.push_back(obj4);

    //Add object 5
    Bodies* obj5 = new Bodies(WIDTH/2-35,60,70,10,5);
    obj5->SetColour(0,0,0);
    listOfBodies.push_back(obj5);

    //Add object 6
    Bodies* obj6 = new Bodies(50,60,70,10,6);
    obj6->SetColour(0,0,0);
    listOfBodies.push_back(obj6);

    //Add object 7
    Bodies* obj7 = new Bodies(WIDTH/3-35,(HEIGHT-80)/2,70,10,7);
    obj7->SetColour(0,0,0);
    listOfBodies.push_back(obj7);

    //Add object 8
    Bodies* obj8 = new Bodies(2*WIDTH/3-35,(HEIGHT-80)/2,70,10,8);
    obj8->SetColour(0,0,0);
    listOfBodies.push_back(obj8);

    //Add river
    Bodies* r = new Bodies(0,HEIGHT-80,WIDTH,80,9);
    r->SetColour(0,0,200);
    listOfBodies.push_back(r);

}

void Game::key_down(SDL_KeyboardEvent* event ){

    if(event->repeat==0){
        // Press space key to restart game
        if (event->keysym.scancode == SDL_SCANCODE_SPACE) {
                    running = true;
                    gameover = false;
                    initialize();
        }
        
        if(running){
            switch (event->keysym.scancode){
                case SDL_SCANCODE_UP:
                    listOfBodies[0]->vel_y-=5;
                    break;

                case SDL_SCANCODE_DOWN:
                    listOfBodies[0]->vel_y+=5;
                    break;

                case SDL_SCANCODE_LEFT:
                    listOfBodies[0]->vel_x-=5;
                    break;

                case SDL_SCANCODE_RIGHT:
                    listOfBodies[0]->vel_x+=5;   
                    break;
                default:
                    break;
            }
        }
    }
}


void Game::key_up(SDL_KeyboardEvent* event ){
    if(event->repeat==0){
        if(running){
            switch (event->keysym.scancode){
                case SDL_SCANCODE_UP:
                    listOfBodies[0]->vel_y+=5;
                    break;
                case SDL_SCANCODE_DOWN:
                    listOfBodies[0]->vel_y-=5;
                    break;
                case SDL_SCANCODE_LEFT:
                    listOfBodies[0]->vel_x+=5;
                    break;
                case SDL_SCANCODE_RIGHT:
                    listOfBodies[0]->vel_x-=5;   
                    break;
                default:
                    break;
            }
        }
    }
}



void Game::move(){
        if(running){    
            //move the bodies
            for(int i=0; i<listOfBodies.size();i++){
                listOfBodies[i]->move();
            }

            //check for collision
            for(int i=1; i<(listOfBodies.size())-1;i++){
                if(listOfBodies[0]->check_col(listOfBodies[i]))
                {
                    running = false;
                    break;
                }
            }

            //check for game over
            if(listOfBodies[0]->check_col(listOfBodies[9]))
            {
                gameover = true;
            }
        }
    else timer++;
}

//render
void Game::render(SDL_Renderer* renderer){
    if(running==true && gameover==false){
        for(int i=0; i<listOfBodies.size();i++){
            listOfBodies[i]->display(renderer);
        }
    }
}