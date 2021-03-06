/*
 *  SGCannon.cpp
 *  Project1
 *
 *  Created by Brady Law on 9/21/10.
 *  Copyright 2010 Brady Law. All rights reserved.
 *
 */

#include "ShooterGame/Elements/SGCannon.h"
#include "GraphicsLib/GLWindow.h"

#ifdef __APPLE__ 
#include <OPENGL/gl.h> 
#include <OPENGL/glu.h> 
#include <GLUT/glut.h> 
#else 
#include <GL/gl.h> 
#include <GL/glu.h> 
#include <GL/glut.h> 
#endif 

#include <cmath>
#include <iostream>

void SGCannon::Draw() {
    aim_vector_ = target_ - pos_;
    GLfloat angle = atan2(aim_vector_.y, aim_vector_.x) * GLWindow::RADIANS_TO_DEGREES - 90;
    
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
        glTranslatef(pos_.x, pos_.y, 0);
        glRotatef(angle, 0, 0, 1);
        glRectf(-0.5*kWidth,
                -0.5*kHeight,
                0.5*kWidth,
                0.5*kHeight);
    glPopMatrix();
}

void SGCannon::MoveLeft() {
    cout << "Moving cannon left" << endl;
    if (pos_.x - MOVE_DISTANCE - 0.5*kWidth >= 0)
        pos_.x -= MOVE_DISTANCE;
}

void SGCannon::MoveRight() {
    cout << "Moving cannon right" << endl;
    if (pos_.x + MOVE_DISTANCE + 0.5*kWidth <= window_->width())
        pos_.x += MOVE_DISTANCE;
}

void SGCannon::set_target(const Vector2d target) {
    target_ = target;
}

void SGCannon::Tick(int time_elapsed) {
    GLMovable::Tick(time_elapsed);

    // TODO: Spawn shots on space click
}