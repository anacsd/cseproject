#ifndef ENEMY_H
#define ENEMY_H
#include<GL/gl.h>
#include <GL/glut.h>
#include <iostream>

#include <cstdlib> 
#include "hitbox.h"

class Enemy {
private:
    
    
public:
    float pointX;
    float pointY;
    float width;
    float height;
    int hp;
    Hitbox box;
    virtual ~Enemy() {}
    virtual void draw() = 0;
    virtual void update() = 0;
    Hitbox getHitBox(){
        return box;
    }
    void reduceHp(){
        hp = hp -1;
    }
    int getHp(){
        return hp;
    }
};

class smallEnemy : public Enemy {
private:
    void wkey(){
        if(pointY < 1.0f){
            pointY = pointY + 0.0055f;
        }
    }
    void skey(){
         if(pointY > -1.0f){
        pointY = pointY - 0.0055f;
        }
    }
    void akey(){
        if(pointX > -1.0f )
        pointX = pointX - 0.0055f;
     }
    void dkey(){
        if(pointX < 1.0f){
            pointX = pointX + 0.0055f;
        }
    }
public:
    smallEnemy(float x, float y,float width, float height){
            this->pointX = x;
            this->pointY = y;
            this->width = width;
            this->height = height;
            hp = 1;
            box = Hitbox(x,y,width,height);
    }
    ~smallEnemy(){
        std::cout << "small enemy destory" << std::endl;
    }
    
    void draw(){
        glColor3f(1.0f, 0.0f, 0.0f); // red

        // Draw the square
        glBegin(GL_QUADS);
            glVertex2f(pointX, pointY);           // bottom-left
            glVertex2f(pointX + width, pointY);  // bottom-right
            glVertex2f(pointX+ width, pointY + width);  // top-right
            glVertex2f(pointX, pointY + width);  // top-left
        glEnd();
    }
    
    void move(int direction){
        if(direction == 1){
            wkey();
        }
        if(direction == 2){
            wkey();
            dkey();
            
        }
        if(direction == 3){
            dkey();
            
        }
        if(direction == 4){
            dkey();
            skey();
        }
        if(direction == 5){
            skey();
            
        }
        if(direction == 6){
            skey();
            akey();
            
        }
        if(direction == 7){
            akey();
            
        }
        if(direction == 8){
            akey();
            wkey();
        }
        box.updateHitBox(pointX,pointY,width,height);
    }
    void update(){
        int random_number = (rand() % 8)+1; //make random number 1-8
        move(random_number);
    }
    //HitBox getHitBox() const;
private:
    
};

class mediumEnemy : public Enemy {
private:
    void wkey(){
        if(pointY < 1.0f){
            pointY = pointY + 0.001f;
        }
    }
    void skey(){
         if(pointY > -1.0f){
        pointY = pointY - 0.001f;
        }
    }
    void akey(){
        if(pointX > -1.0f )
        pointX = pointX - 0.001f;
     }
    void dkey(){
        if(pointX < 1.0f){
            pointX = pointX + 0.001f;
        }
    }
public:
    mediumEnemy(float x, float y,float width, float height){
            this->pointX = x;
            this->pointY = y;
            this->width = width;
            this->height = height;
            hp = 3;
            box = Hitbox(x,y,width,height);
    }
    ~mediumEnemy(){
        std::cout << "destroy midEnemy" << std::endl;
    }
    void draw(){
        // glColor3f(0.0f, 0.0f, 1.0f); // blue

        // // Draw the square
        // glBegin(GL_QUADS);
        //     glVertex2f(pointX, pointY);           // bottom-left
        //     glVertex2f(pointX + width, pointY);  // bottom-right
        //     glVertex2f(pointX + width, pointY + width);  // top-right
        //     glVertex2f(pointX, pointY + width);  // top-left
        // glEnd();

        glColor3f(0.0f, 0.0f, 1.0f);//blue
        glBegin(GL_POLYGON);
        glVertex3f(pointX, pointY+0.55f, 0.0f);
        glVertex3f(pointX+-.03, pointY+0.40f, 0.0f);
        glVertex3f(pointX+.03f, pointY+0.40f, 0.0f);
        glEnd();
        
        glColor3f(1.0f, 0.0f, 0.0f);//red
	    glBegin(GL_POLYGON);
        glVertex3f(pointX+-.03f, pointY+0.40f, 0.0f);
        glVertex3f(pointX+-.05f, pointY+0.43f, 0.0f);
        glVertex3f(pointX+.05f, pointY+0.43f, 0.0f);
        glVertex3f(pointX+.03f, pointY+0.40f, 0.0f);
        glEnd();
    }
    void move(int direction){
        if(direction == 1){
            wkey();
        }
        if(direction == 2){
            wkey();
            dkey();
            
        }
        if(direction == 3){
            dkey();
            
        }
        if(direction == 4){
            dkey();
            skey();
        }
        if(direction == 5){
            skey();
            
        }
        if(direction == 6){
            skey();
            akey();
            
        }
        if(direction == 7){
            akey();
            
        }
        if(direction == 8){
            akey();
            wkey();
        }
        box.updateHitBox(pointX,pointY,width,height);
    }
    void update(){
        int random_number = (rand() % 8)+1; //make random number 1-8
        move(random_number);
    }
    //HitBox getHitBox() const;
private:
    
};

class boss : public Enemy {
public:
    boss(float x, float y,float width, float height){
            this->pointX = x;
            this->pointY = y;
            this->width = width;
            this->height = height;
            hp = 10;
            box = Hitbox(x,y,width,height);
    }
   
    ~boss(){
       
        std::cout << "destroy boss" << std::endl;
    
    }
    void draw(){
       glColor3f(1.0f, 0.0f, 0.0f);//red
        glBegin(GL_POLYGON);
        glVertex3f(pointX+0.50, pointY+-0.00f, 0.0f);//center
        glVertex3f(pointX+0.40, pointY+-0.30f, 0.0f);//left
        glVertex3f(pointX+0.60f, pointY+-0.30f, 0.0f);//right
        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f);//white
	    glBegin(GL_POLYGON);
        glVertex3f(pointX+0.40f, pointY+-0.30f, 0.0f);
        glVertex3f(pointX+0.34f, pointY+-0.36f, 0.0f);
        glVertex3f(pointX+0.66f, pointY+-0.36f, 0.0f);
        glVertex3f(pointX+0.60f, pointY+-0.30f, 0.0f);
        glEnd();

        glColor3f(2.0f, 0.5f, 1.0f);//Lilac
        glBegin(GL_POLYGON);
        glVertex3f(pointX+0.34f, pointY+-0.36f, 0.0f);
        glVertex3f(pointX+0.34f, pointY+-0.39f, 0.0f);
        glVertex3f(pointX+0.66f, pointY+-0.39f, 0.0f);
        glVertex3f(pointX+0.66, pointY+-0.36f, 0.0f);
        glEnd();

        glColor3f(0.1f, 0.0f, 0.0f);//Brown
        glBegin(GL_POLYGON);
        glVertex3f(pointX+0.45f, pointY+-0.39f, 0.0f);
        glVertex3f(pointX+0.45f, pointY+-0.43f, 0.0f);
        glVertex3f(pointX+0.35f, pointY+-0.43f, 0.0f);
        glVertex3f(pointX+0.35f, pointY+-0.39, 0.0f);
        glEnd();

        glColor3f(0.1f, 0.0f, 0.0f);//Brown
        glBegin(GL_POLYGON);
        glVertex3f(pointX+0.55f, pointY+-0.39, 0.0f);
        glVertex3f(pointX+0.55f, pointY+-0.43f, 0.0f);
        glVertex3f(pointX+0.65f, pointY+-0.43f, 0.0f);
        glVertex3f(pointX+0.65f, pointY+-0.39f, 0.0f);
        glEnd();

        glColor3f(1.0f, 1.0f, 0.0f);//white
        glBegin(GL_POLYGON);
        glVertex3f(pointX+0.41f, pointY+-0.69f, 0.0f);
        glVertex3f(pointX+0.45f, pointY+-0.43f, 0.0f);
        glVertex3f(pointX+0.35f, pointY+-0.43f, 0.0f);
        glEnd();

        glColor3f(1.0f, 1.0f, 0.0f);//white
        glBegin(GL_POLYGON);
        glVertex3f(pointX+0.59f, pointY+-0.69f, 0.0f);
        glVertex3f(pointX+0.55f, pointY+-0.43f, 0.0f);
        glVertex3f(pointX+0.65f, pointY+-0.43f, 0.0f);
        glEnd();
    }
    
    void update(){

    }
    //HitBox getHitBox() const;
private:
    
};

#endif // ENEMY_H
