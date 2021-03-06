#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

// ���������� ��������� ��������� ��������� �������� ������. ������������ � �������� ����������, ����� ��������� �������� �� ����������� ��� ������� ������� ������� �����
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// ��������� ������ �� ���������
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;


// ����������� ����� ������, ������� ������������ ������� ������ � ��������� ��������������� �������� ����, ������� � ������� ��� ������������� � OpenGL
class Camera
{
private:
    // �������� ������
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    // ���� ������
    float Yaw;
    float Pitch;
    // ��������� ������
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

public:
    // �����������, ������������ �������
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
    // �����������, ������������ �������
    Camera(float posX = 0.0f, float posY = 0.0f, float posZ = 0.0f, float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f, float yaw = YAW, float pitch = PITCH);
   
    // ���������� ������� ����, ����������� � �������������� ����� ������ � LookAt-������� 
    glm::mat4 GetViewMatrix();
   
    float get_zoom();

    //������������ ������� ������, ���������� �� ����� ������������������ ������� �����. ��������� ������� �������� � ���� ������������� ������� ������������ (��� ��������������� ��� �� ������� ������)
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);
   

    //������������ ������� ������, ���������� �� ������� ����� � ������� ����. ������� � �������� ���������� �������� �������� ��� � ����������� X, ��� � � ����������� Y.
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = GL_TRUE);
   

    // ������������ ������� ������, ���������� �� ������� ������ ��������� ����. ���������� ������ ������� ������ �� ������������ ��� �������� 
    void ProcessMouseScroll(float yoffset);
    

private:
    // ��������� ������-����� �� (�����������) ����� ������ ������
    void updateCameraVectors();
    
};
