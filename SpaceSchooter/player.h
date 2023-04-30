#ifndef PLAYER_H
#define PLAYER_H

#include "hitbox.h"
#include "game.h"
#include "enemy.h"

#include<GL/gl.h>
#include <GL/glut.h>
#include <iostream>

class player{
    public:
        bool w_pressed;
        bool d_pressed;
        bool s_pressed;
        bool a_pressed;
        bool isLaser = false;
        bool enter_pressed;
        float pointX;
        float pointY;
        float length;
        const float speed = 0.0015f;
        
        Hitbox box;
        
        player(float pointX,float pointY, float length){
            this->pointX = pointX;
            this->pointY = pointY;
            this->length= length;
            box = Hitbox(pointX,pointY,length,length);
            w_pressed = false;
            d_pressed = false;
            s_pressed = false;
            a_pressed = false;
            enter_pressed = false;

            
            
        }
        
        void shoot(std::vector<Enemy*> list){
            float width = pointX+(length/2.0f);
            float horizontal = 20.0f;
            int i;
            for(i=0;i<list.size();i++){
                if((list[i]->getHitBox()).intersectBox(width)){
                    list[i]->reduceHp();
                    return;
                }
            }

        }

        ~player(){
            std::cout << "player destory" << std::endl;
        }
        float getX(){
            return pointX;
        }
        float getY(){
            return pointY;
        }
        float getlength(){
            return length;
        }
        void drawTriangle(){
             glColor3f(1.0f, 0.0f, 1.0f);//Purple
    glBegin(GL_POLYGON);
        glVertex3f(pointX, pointY+-0.514f, 0.00f);
        glVertex3f(pointX+-.05, pointY+-0.65f, 0.0f);
        glVertex3f(pointX+.05f, pointY+-0.65f, 0.0f);
    glEnd();
    glColor3f(0.5f, 0.5f, 0.5f);//Violet
	 glBegin(GL_POLYGON);
        glVertex3f(pointX+-.05f, pointY+-0.65f, 0.0f);
        glVertex3f(pointX+-.08f, pointY+-0.68f, 0.0f);
        glVertex3f(pointX+.08f, pointY+-0.68f, 0.0f);
        glVertex3f(pointX+.05f, pointY+-0.65f, 0.0f);
    glEnd();
        glColor3f(2.0f, 0.5f, 1.0f);//Lilac
        glBegin(GL_POLYGON);
        glVertex3f(pointX+-.08f, pointY+-0.68f, 0.0f);
        glVertex3f(pointX+-.08f, pointY+-0.71f, 0.0f);
        glVertex3f(pointX+.08f, pointY+-0.71f, 0.0f);
        glVertex3f(pointX+.08f, pointY+-0.68f, 0.0f);
    glEnd();
       glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glBegin(GL_POLYGON);
        glVertex3f(pointX+-.07f, pointY+-0.71f, 0.0f);
        glVertex3f(pointX+-.07f, pointY+-0.73f, 0.0f);
        glVertex3f(pointX+-.03f, pointY+-0.73f, 0.0f);
        glVertex3f(pointX+-.03f, pointY+-0.71f, 0.0f);
    glEnd();
        glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glBegin(GL_POLYGON);
        glVertex3f(pointX+.07f, pointY+-0.71f, 0.0f);
        glVertex3f(pointX+.07f, pointY+-0.73f, 0.0f);
        glVertex3f(pointX+.03f, pointY+-0.73f, 0.0f);
        glVertex3f(pointX+.03f, pointY+-0.71f, 0.0f);
    glEnd();
        glColor3f(0.5f, 1.0f, 1.0f);//cyan
    glBegin(GL_POLYGON);
        glVertex3f(pointX+.05f, pointY+-0.8f, 0.0f);
        glVertex3f(pointX+.07f, pointY+-0.73f, 0.0f);
        glVertex3f(pointX+.03f, pointY+-0.73f, 0.0f);
    glEnd();
        glColor3f(0.5f, 1.0f, 1.0f);//cyan
    glBegin(GL_POLYGON);
        glVertex3f(pointX+-.05f, pointY+-0.8f, 0.0f);
        glVertex3f(pointX+-.07f, pointY+-0.73f, 0.0f);
        glVertex3f(pointX+-.03f, pointY+-0.73f, 0.0f);
    glEnd();
        glColor3f(0.0f, 0.1f, 0.1f);//Dark blue
    glBegin(GL_POLYGON);
        glVertex3f(pointX+-0.01f, pointY+-0.58f, 0.0f);
        glVertex3f(pointX+-0.01f, pointY+-0.64f, 0.0f);
        glVertex3f(pointX+0.01f, pointY+-0.64f, 0.0f);
        glVertex3f(pointX+0.01f, pointY+-0.58f, 0.0f);
    glEnd();
    if(isLaser)
    {
        glColor3d(1,1,1);
        glLineWidth(5);
        glBegin(GL_LINES);
            glVertex3f(pointX,pointY+-0.514f, 0.0f);
            glVertex3f(pointX, pointY+0.75f, 0.0f);
        glEnd();
    }
    

        }
        void print(){
            std::cout << "X: " << pointX << "Y: " << pointY << std::endl;
        }
        void wkey(){
            if(pointY < 0.98f){
                pointY = pointY + speed;
            }
        }
        void skey(){
            if(pointY > -1.0f){
                pointY = pointY - speed;
            }
        }
        void akey(){
            if(pointX >-1.0f){
                pointX = pointX - speed;
            }
        }
        void dkey(){
            if(pointX <0.98f){
                pointX = pointX + speed;
            }
        }
        void wdkey(){
            dkey();
            wkey();
        }
};

#endif 
