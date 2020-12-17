#include "camera.h"

Camera::Camera()
{

}

void Camera::setCamera(float posX, float posY, float posZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ)
{
    c_upX = upX;
    c_upY = upY;
    c_upZ = upZ;
    c_position.x = posX;
    c_position.y = posY;
    c_position.z = posZ;
    c_center.x = centerX;
    c_center.y = centerY;
    c_center.z = centerZ;
    c_angle = 0.0;
    //calculate distance between the camera's position and the center
    double toSquare = pow((posX - centerX), 2) + pow((posY - centerY), 2) + pow((posZ - centerZ), 2);
    c_distance = sqrt(toSquare);
    gluLookAt(posX, posY, posZ, centerX, centerY, centerZ, upX, upY, upZ);
}

void Camera::backToStart(float posX, float posY, float posZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ)
{
    c_upX = upX;
    c_upY = upY;
    c_upZ = upZ;
    c_position.x = posX;
    c_position.y = posY;
    c_position.z = posZ;
    c_center.x = centerX;
    c_center.y = centerY;
    c_center.z = centerZ;
    c_angle = 0.0;
    //calculate distance between the camera's position and the center
    double toSquare = pow((posX - centerX), 2) + pow((posY - centerY), 2) + pow((posZ - centerZ), 2);
    c_distance = sqrt(toSquare);
}


void Camera::move(float increment)
{
    double radians = c_angle * (M_PI/180);
    double newDistance = c_distance - increment;
    c_position.x = c_center.x - newDistance*sin(radians);
    c_position.z = c_center.z + newDistance*cos(radians);
    c_distance = newDistance;
}

void Camera::rotate(float degrees)
{
    double radians = (c_angle + degrees) * (M_PI/180);
    c_center.x = c_position.x + sin(radians)*c_distance;
    c_center.z = c_position.z - cos(radians)*c_distance;
    c_angle = c_angle + degrees;
}

void Camera::update()
{
    gluLookAt(c_position.x, c_position.y, c_position.z, c_center.x, c_center.y, c_center.z, c_upX, c_upY, c_upZ);
}